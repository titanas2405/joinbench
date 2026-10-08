/*
 * list.c
 *	  support for error handling 
 */
 
#include "db.h"
#include "utils/list.h"
#include "utils/jb_error.h"


void DlistCheck(const dlist *list)
{
    const dlist_node *cur;

    if (list == NULL)
        Elog(ERROR, "doubly linked list head address is NULL");

    /* zeroed list = never initialized = fine */
    if (list->head.next == NULL && list->head.prev == NULL)
        return;

    /* walk forward */
    for (cur = list->head.next; cur != &list->head; cur = cur->next)
    {
        if (cur == NULL || cur->next == NULL || cur->prev == NULL ||
            cur->prev->next != cur || cur->next->prev != cur)
            Elog(ERROR, "doubly linked list is corrupted");
    }

    /* walk backward */
    for (cur = list->head.prev; cur != &list->head; cur = cur->prev)
    {
        if (cur == NULL || cur->next == NULL || cur->prev == NULL ||
            cur->prev->next != cur || cur->next->prev != cur)
            Elog(ERROR, "doubly linked list is corrupted");
    }
}
