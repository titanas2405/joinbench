#include <stdio.h>
#include "db.h"
#include "utils/list.h"
#include "utils/jb_error.h"

typedef struct test_struct {
	int        data;
	dlist_node dlnode_member;
} test_struct;


int main(void)
{
	
	test_struct t1 = { .data = 10 };
	test_struct t2 = { .data = 15 };

	dlist list;
	DlistInit(&list);
	dlist_push_tail(&list, &t1.dlnode_member);
	dlist_push_tail(&list, &t2.dlnode_member);

	dlist_iter iter;
	DlistForeach(iter, list){
		test_struct *t = DlistGetStruct(iter.cur, test_struct);
		printf("%d\n", t->data);
	}

	return STATUS_OK;
}
