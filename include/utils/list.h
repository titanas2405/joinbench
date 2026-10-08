/*
 *
 * ilist.h
 *		integrated/inline doubly
 * 
 */

#ifndef JOINBENCH_INCLUDE_UTILS_LIST_H
#define JOINBENCH_INCLUDE_UTILS_LIST_H

#define container_of(struct_type, membername, member_ptr) \
	(struct_type *) ((char *) (member_ptr) - offsetof(struct_type, membername))


typedef struct dlist_node dlist_node;

struct dlist_node
{
	dlist_node *prev;
	dlist_node *next;
};

typedef struct dlist_iter
{
	dlist_node *cur;
	dlist_node *end;
} dlist_iter;


typedef struct dlist
{
	dlist_node head;
} dlist;

extern void DlistCheck(const dlist *list);

#define dlnode_member dl_node


static inline void
DlistInit(dlist * _dlist)
{
	_dlist->head.next = _dlist->head.prev = &_dlist->head;
}


static inline void
DlistInsertAfter(dlist_node * after,dlist_node * node)
{	
	node->next = after->next;
	node->prev = after;
	
	after->next = node;
	node->next->prev = node;
}


static inline void
DlistInsertBefore(dlist_node *before, dlist_node *node)
{	
	node->next = before;
	node->prev = before->prev;
	
	before->prev = node;
	node->prev->next = node;
	
}

static inline void
DlistDeleteNode(dlist_node *node)
{	
	node->prev->next = node->next;
	node->next->prev = node->prev;
	
	node->next = NULL;
	node->prev = NULL;
}

static inline void
dlist_push_tail(dlist * _dlist, dlist_node *node)
{
	
	if (_dlist->head.next == NULL){
		DlistInit(_dlist);
	}
	
	
	node->next = &_dlist->head;
	node->prev = _dlist->head.prev;
	
	node->next->prev = node;
	node->prev->next = node;
	
	DlistCheck(_dlist);
}


static inline void
dlist_push_head(dlist * _dlist, dlist_node *node)
{
	
	if (_dlist->head.next == NULL){
		DlistInit(_dlist);
	}
	
	
	node->next = &_dlist->head;
	node->prev = _dlist->head.prev;
	
	node->next->prev = node;
	node->prev->next = node;
	
	DlistCheck(_dlist);
}

#define DlistForeach(iter, _dlist) \
	for (StaticAssertVariableIsOfTypeMacro(iter, dlist_iter), \
		 StaticAssertVariableIsOfTypeMacro(_dlist, dlist), \
		 (iter).end = &_dlist.head, \
		 (iter).cur = (iter).end->next ? (iter).end->next : (iter).end;	 \
		 (iter).cur != (iter).end; \
		 (iter).cur = (iter).cur->next)
		 
#define DlistGetStruct(node,struct_type) \
		container_of(struct_type, dl_node, node)
	
#endif	/* JOINBENCH_INCLUDE_UTILS_LIST_H */
