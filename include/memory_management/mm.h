/*
 *
 * mm.h
 *	  Fundamental memory management definitions.
 *
 */

#ifndef JOINBENCH_INCLUDE_MEMORY_MANAGEMENT_MM_H
#define JOINBENCH_INCLUDE_MEMORY_MANAGEMENT_MM_H


/*
 * MemoryContext is a pointer to the MemoryContextData struct 
 */
typedef MemoryContextData * MemoryContext 


typedef struct MemoryContextMethods
{
	/*
	 * Function to handle memory allocation requests of 'size' to allocate
	 * memory into the given 'context'.  The function must handle flags
	 */
	void *(*alloc) (MemoryContext context, Size size, int flags);

	/*
	 * Function to handle a size change request for an existing allocation.
	 * The implementation must handle flags
	 */
	void *(*realloc) (void *pointer, Size size, int flags);

	/*
	 * Invalidate all previous allocations in the given memory context and
	 * prepare the context for a new set of allocations.  Implementations may
	 * optionally free() excess memory back to the OS during this time.
	 */
	void (*reset) (MemoryContext context);

	/* Free all memory consumed by the given MemoryContext. */
	void (*delete_context) (MemoryContext context);

	/* Return the MemoryContext that the given pointer belongs to. */
	MemoryContext (*get_chunk_context) (void *pointer);

	/*
	 * Return the number of bytes consumed by the given pointer within its
	 * memory context, including the overhead of alignment and chunk headers.
	 */
	Size (*get_chunk_space) (void *pointer);

	/*
	 * Return true if the given MemoryContext has not had any allocations
	 * since it was created or last reset.
	 */
	bool (*is_empty) (MemoryContext context);

} MemoryContextMethods;



typedef struct MemoryContextData{
	
	const MemoryContextMethods *Methods;
    
    Size mem_allocated;	
	
	MemoryContext parent;
	
	MemoryContext first_child;
	
	const char *ident;
	
	const char *name;

} MemoryContextData;


/*
 * MemoryContextIsValid
 *		True iff memory context is valid.
 */
 
#define MemoryContextIsValid(context) \
	(context) != NULL 
#endif		

#endif	/* JOINBENCH_INCLUDE_MEMORY_MANAGEMENT_MM_H */
