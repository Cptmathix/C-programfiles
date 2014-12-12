#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include <assert.h>

int test_list()
{
	puts("starting tests");
	
	puts("##########################################");	
	puts("starting linked list tests");
	puts("##########################################");
	
	int value = 0;
	struct List *list = list_create();
	
	puts("empty list created");
	
	if (list_length(list) != 0) {
		printf("list_length of empty list should be zero\n");
		return 0;
	}

	puts("list_length ok");
	
	// Insert value 101 and test functions
	list_insert(list, 0, 101);
	if (list_length(list) != 1) {
		printf("list_length should be 1\n");
		return 0;
	}

	if (list_get(list, 0, &value) == 0) {
		printf("Error in list_get (1)\n");
		return 0;
	}
	if (value != 101) {
		printf("list_get should return value 101\n");
		return 0;
	}

	// Insert value 202 and test functions
	list_insert(list, 0, 202);
	if (list_length(list) != 2) {
		printf("list_length should return 2\n");
		return 0;
	}

	if (list_get(list, 0, &value) == 0) {
		printf("Error in list_length (2)\n");
		return 0;
	}
	if (value != 202) {
		printf("list_get should return 202\n");
		return 0;
	}

	puts("list_get ok");
	
	// Test remove function
	if (list_remove(list, 1) == 0) {
		printf("Error in list_remove\n");
		return 0;
	}
	if (list_length(list) != 1) {
		printf("list_length should return 1 (after remove)\n");
		return 0;
	}
	
	if (list_remove(list, 1) != 0) {
		printf("Error in list_remove\n");
		return 0;
	}
	if (list_length(list) != 1) {
		printf("list_length should return 1 (after remove)\n");
		return 0;
	}
	
	if (list_remove(list, 0) == 0) {
		printf("Error in list_remove\n");
		return 0;
	}
	
	if (list_length(list) != 0) {
		printf("list_length should return 0 (after remove)\n");
		return 0;
	}
	
	if (list_remove(list, 0) != 0) {
		printf("Error in list_remove\n");
		return 0;
	}
	
	if (list_length(list) != 0) {
		printf("list_length should return 0 (after remove)\n");
		return 0;
	}
	
	puts("list_remove ok");

	// Test pop function
	if (list_pop(list, &value) != 0) {
		printf("Error in list_pop\n");
		return 0;
	}
	
	list_append(list, 202);
	
	if (list_pop(list, &value) == 0) {
		printf("Error in list_pop\n");
		return 0;
	}

	if (value != 202) {
		printf("list_pop should return 202\n");
		return 0;
	}

	if (list_length(list) != 0) {
		printf("list_length should return 0 (after pop)\n");
		return 0;
	}

	puts("list_pop ok");

	// test list_append()
	
	list_append(list, -5);
	list_append(list, 0);
	list_append(list, 15);
	
	if (list_length(list) != 3) {
		printf("list_length should return 0 (after pop)\n");
		return 0;
	}
	
	if (list_get(list, 0, &value) != 1) {
		printf("Error in list_append\n");
		return 0;
	}
	
	if (value != -5) {
		printf("list_get should return -5\n");
		return 0;
	}
	
	if (list_get(list, 1, &value) != 1) {
		printf("Error in list_append\n");
		return 0;
	}
	
	if (value != 0) {
		printf("list_get should return 0\n");
		return 0;
	}

	if (list_get(list, 2, &value) != 1) {
		printf("Error in list_append\n");
		return 0;
	}
	
	if (value != 15) {
		printf("list_get should return 15\n");
		return 0;
	}
	
	if (list_pop(list, &value) == 0) {
		printf("Error in list_pop\n");
		return 0;
	}
	
	if (list_pop(list, &value) == 0) {
		printf("Error in list_pop\n");
		return 0;
	}
	
	if (list_pop(list, &value) == 0) {
		printf("Error in list_pop\n");
		return 0;
	}
	
	if (list_get(list, 0, &value) != 0) {
		printf("Error in list_get\n");
		return 0;
	}
	
	puts("list_append ok");
	
	// test list_prepend
	
	list_prepend(list, -5);
	list_prepend(list, 0);
	list_prepend(list, 15);
	
	if (list_length(list) != 3) {
		printf("list_length should return 0 (after pop)\n");
		return 0;
	}
	
	if (list_get(list, 0, &value) != 1) {
		printf("Error in list_append\n");
		return 0;
	}
	
	if (value != 15) {
		printf("list_get should return 15\n");
		return 0;
	}
	
	if (list_get(list, 1, &value) != 1) {
		printf("Error in list_append\n");
		return 0;
	}
	
	if (value != 0) {
		printf("list_get should return 0\n");
		return 0;
	}

	if (list_get(list, 2, &value) != 1) {
		printf("Error in list_append\n");
		return 0;
	}
	
	if (value != -5) {
		printf("list_get should return -5\n");
		return 0;
	}
	
	puts("list_prepend ok");
	
	// test list insert
	
	list_insert(list, -5, 0);
	
	if (list_length(list) != 4) {
		printf("list_length should return 4\n");
		return 0;
	}
	
	if (list_get(list, 0, &value) != 1) {
		printf("Error in list_append\n");
		return 0;
	}
	
	if (value != 0) {
		printf("list_get should return 0\n");
		return 0;
	}
	
	list_insert(list, 2, 100);

	if (list_length(list) != 5) {
		printf("list_length should return 5\n");
		return 0;
	}
	
	if (list_get(list, 2, &value) != 1) {
		printf("Error in list_append\n");
		return 0;
	}
	
	if (value != 100) {
		printf("list_get should return 100\n");
		return 0;
	}
	
	list_insert(list, 10, 500);
	
	if (list_length(list) != 6) {
		printf("list_length should return 6\n");
		return 0;
	}

	if (list_get(list, 5, &value) != 1) {
		printf("Error in list_append\n");
		return 0;
	}
	
	if (value != 500) {
		printf("list_get should return 500\n");
		return 0;
	}
	
	puts("list_insert ok");
	
	// test insert sorted
	
	for (int i = 0; i<6; i++)
		list_remove(list, 0);
	
	for (int i = 0; i<5; i++)
		list_append(list, i);
	
	list_append(list, 6);
	
	if (list_length(list) != 6) {
		printf("list_length should return 6\n");
		return 0;
	}
	
	list_insert_sorted(list, -1);
	list_insert_sorted(list, 5);
	list_insert_sorted(list, 7);
	
	for (int i = -1; i<8; i++)
	{
		list_get(list, i+1, &value);
		if (value != i)
			printf("error in list insert sorted\n");
	}
	
	// test print and  print reversed
	
	puts("list_insert_sorted ok");
	
	puts("print current list, should be sorted");
	
	list_print(list);
	
	puts("printing reversed list");
	
	list_print_reverse(list);
	
	puts("check print and print_reversed for yourself!");
	
	// test list remove all
	
	for (int i = 0; i<9; i++)
		list_remove(list, 0);
	
	for (int i = 0; i<5; i++)
		list_append(list, 5);
	
	list_remove_all(list, 5);
	
	if (list_length(list) != 0) {
		printf("list_length should return 0 (list remove all doesn't work\n");
		return 0;
	}
	
	for (int i = 0; i<9; i++)
		list_remove(list, 0);
	
	for (int i = 0; i<5; i++)
		list_append(list, 5);
	
	list_insert(list, -1, 0);
	list_remove_all(list, 5);
	
	if (list_length(list) != 1) {
		printf("list_length should return 1 (list remove all doesn't work\n");
		return 0;
	}
	
	for (int i = 0; i<9; i++)
		list_remove(list, 0);
	
	for (int i = 0; i<5; i++)
		list_append(list, 5);
	
	list_insert(list, 3, 0);
	list_remove_all(list, 5);
	
	if (list_length(list) != 1) {
		printf("list_length should return 1 (list remove all doesn't work\n");
		return 0;
	}
	
	for (int i = 0; i<9; i++)
		list_remove(list, 0);
	
	for (int i = 0; i<5; i++)
		list_append(list, 5);
	
	list_insert(list, 10, 0);
	list_remove_all(list, 5);
	
	if (list_length(list) != 1) {
		printf("list_length should return 1 (list remove all doesn't work\n");
		return 0;
	}
	
	puts("list_remove_all ok");

	puts("##########################################");	
	puts("all tests of linked lists completed");
	puts("##########################################");
	puts("------------------------------------------");
	
	list_delete(list);
	
	return 1;
}


int test_dlist()
{
	puts("##########################################");	
	puts("starting double linked list tests");
	puts("##########################################");
	
	int value = 0;
	struct DList *dlist = dlist_create();
	
	puts("empty double list created");
	
	if (dlist_length(dlist) != 0) {
		printf("dlist_length of empty list should be zero\n");
		return 0;
	}

	puts("dlist_length ok");
	
	// Insert value 101 and test functions
	dlist_insert(dlist, 0, 101);
	if (dlist_length(dlist) != 1) {
		printf("dlist_length should be 1\n");
		return 0;
	}

	if (dlist_get(dlist, 0, &value) == 0) {
		printf("Error in dlist_get (1)\n");
		return 0;
	}
	if (value != 101) {
		printf("dlist_get should return value 101\n");
		return 0;
	}

	// Insert value 202 and test functions
	dlist_insert(dlist, 0, 202);
	if (dlist_length(dlist) != 2) {
		printf("dlist_length should return 2\n");
		return 0;
	}

	if (dlist_get(dlist, 0, &value) == 0) {
		printf("Error in dlist_length (2)\n");
		return 0;
	}
	if (value != 202) {
		printf("dlist_get should return 202\n");
		return 0;
	}

	puts("dlist_get ok");
	
	// Test remove function

	if (dlist_remove(dlist, 1) == 0) {
		printf("Error in dlist_remove\n");
		return 0;
	}

	if (dlist_length(dlist) != 1) {
		printf("dlist_length should return 1 (after remove)\n");
		return 0;
	}

	if (dlist_remove(dlist, 1) != 0) {
		printf("Error in dlist_remove\n");
		return 0;
	}

	if (dlist_length(dlist) != 1) {
		printf("dlist_length should return 1 (after remove)\n");
		return 0;
	}

	if (dlist_remove(dlist, 0) == 0) {
		printf("Error in dlist_remove\n");
		return 0;
	}

	if (dlist_length(dlist) != 0) {
		printf("dlist_length should return 0 (after remove)\n");
		return 0;
	}

	if (dlist_remove(dlist, 0) != 0) {
		printf("Error in dlist_remove\n");
		return 0;
	}

	if (dlist_length(dlist) != 0) {
		printf("dlist_length should return 0 (after remove)\n");
		return 0;
	}
	
	puts("dlist_remove ok");
	
	// test dlist_append()
	
	dlist_append(dlist, -5);
	dlist_append(dlist, 1);
	dlist_append(dlist, 15);
	
	if (dlist_length(dlist) != 3) {
		printf("dlist_length should return 0\n");
		return 0;
	}
	
	if (dlist_get(dlist, 0, &value) != 1) {
		printf("Error in dlist_append\n");
		return 0;
	}
	
	if (value != -5) {
		printf("dlist_get should return -5\n");
		return 0;
	}
	
	if (dlist_get(dlist, 1, &value) != 1) {
		printf("Error in dlist_append\n");
		return 0;
	}
	
	if (value != 1) {
		printf("dlist_get should return 1\n");
		return 0;
	}

	if (dlist_get(dlist, 2, &value) != 1) {
		printf("Error in dlist_append\n");
		return 0;
	}
	
	if (value != 15) {
		printf("dlist_get should return 15\n");
		return 0;
	}
	
	puts("dlist_append ok");
	
	// test dlist insert
	
	dlist_insert(dlist, -5, 0);
	
	if (dlist_length(dlist) != 4) {
		printf("dlist_length should return 4\n");
		return 0;
	}
	
	if (dlist_get(dlist, 0, &value) != 1) {
		printf("Error in dlist_append\n");
		return 0;
	}
	
	if (value != 0) {
		printf("dlist_get should return 0\n");
		return 0;
	}
	
	dlist_insert(dlist, 1, 100);

	if (dlist_length(dlist) != 5) {
		printf("dlist_length should return 5\n");
		return 0;
	}
	
	if (dlist_get(dlist, 1, &value) != 1) {
		printf("Error in dlist_append\n");
		return 0;
	}
	
	if (value != 100) {
		printf("dlist_get should return 100\n");
		return 0;
	}
	
	dlist_insert(dlist, 10, 500);
	
	if (dlist_length(dlist) != 6) {
		printf("dlist_length should return 6\n");
		return 0;
	}

	if (dlist_get(dlist, 5, &value) != 1) {
		printf("Error in dlist_append\n");
		return 0;
	}
	
	if (value != 500) {
		printf("dlist_get should return 500\n");
		return 0;
	}
	
	puts("dlist_insert ok");
	
	// test print and  print reversed
	
	puts("print current dlist");
	
	dlist_print(dlist);
	
	puts("printing reversed dlist");
	
	dlist_print_reverse(dlist);
	
	puts("check print and print_reversed for yourself!");
		
	puts("##########################################");	
	puts("all tests of double linked lists completed");
	puts("##########################################");
	puts("------------------------------------------");
	
	dlist_delete(dlist);

	return 1;
}


int test_stack()
{
	puts("##########################################");	
	puts("if evaluate works, stack should work too!");
	puts("##########################################");	
	puts("------------------------------------------");
	

	return 1;
}


int test_evaluate()
{
	puts("##########################################");	
	puts("starting evaluate tests");
	puts("##########################################");
	
	int value;

	// Test 1
	if (evaluate("10", &value) == 0) {
		printf("Error evaluating string\n");
		return 0;
	}
	
	puts("test 1 evaluate ok");
	
	if (value != 10) {
		printf("Evaluate returned wrong result\n");
		return 0;
	}
	
	puts("test 1 value ok");

	// Test 2
	if (evaluate("6 4 + 10 *", &value) == 0) {
		printf("Error evaluating string\n");
		return 0;
	}
	
	puts("test 2 evaluate ok");
	
	if (value != 100) {
		printf("Evaluate returned wrong result\n");
		return 0;
	}
	
	puts("test 2 value ok");

	// Test 3
	if (evaluate("101 44 +", &value) == 0) {
		printf("Error evaluating string\n");
		return 0;
	}
	
	puts("test 3 evaluate ok");
	
	if (value != 145) {
		printf("Evaluate returned wrong result\n");
		return 0;
	}
	
	puts("test 3 value ok");
	
	// Test 4
	if (evaluate("1 5 + 2 /", &value) == 0) {
		printf("Error evaluating string\n");
		return 0;
	}
	
	puts("test 4 evaluate ok");
	
	if (value != 3) {
		printf("Evaluate returned wrong result\n");
		return 0;
	}
	
	puts("test 4 value ok");
	
	// Test 5
	if (evaluate("1 2 - 5 - 15 5 / +", &value) == 0) {
		printf("Error evaluating string\n");
		return 0;
	}
	
	puts("test 5 evaluate ok");
	
	if (value != -3) {
		printf("Evaluate returned wrong result\n");
		return 0;
	}
	
	puts("test 5 value ok");

	// Test 6
	if (evaluate("5 2 2 - /", &value) != 0) {
		printf("Error you may not divide by zero\n");
		return 0;
	}
	
	puts("test 6 evaluate ok");
	
	// Test 7
	if (evaluate("-5 10 *", &value) == 0) {
		printf("Error evaluating string\n");
		return 0;
	}
	
	puts("test 7 evaluate ok");
	
	if (value != -50) {
		printf("Evaluate returned wrong result\n");
		return 0;
	}
	
	puts("test 7 value ok");
	
	// Test 8
	if (evaluate("70 -7 /", &value) == 0) {
		printf("Error evaluating string\n");
		return 0;
	}
	
	puts("test 8 evaluate ok");
	
	if (value != -10) {
		printf("Evaluate returned wrong result\n");
		return 0;
	}
	
	puts("test 8 value ok");
	
	// Test 9
	if (evaluate("", &value) != 0) {
		printf("Error there should be no result\n");
		return 0;
	}
	
	puts("test 9 evaluate ok");

	// Test 10
	if (evaluate("0 2 +", &value) == 0) {
		printf("Error evaluating string\n");
		return 0;
	}
	
	puts("test 10 evaluate ok");
	
	if (value != 2) {
		printf("Evaluate returned wrong result\n");
		return 0;
	}
	
	puts("test 10 value ok");
	
	// Test 11
	if (evaluate("0 2 + 9 * 6 - 5 5 /", &value) != 0) {
		printf("Error there should be no result\n");
		return 0;
	}
	
	puts("test 11 evaluate ok");
	
	puts("##########################################");	
	puts("all tests of evaluate (and stack) completed");
	puts("##########################################");
	puts("------------------------------------------");
	
	return 1;
}


int main(int argc, char *argv[])
{
	test_list();
	test_dlist();
	test_stack();
	test_evaluate();
	
	puts("##########################################");	
	puts("all tests have been completed!!");
	puts("##########################################");

	return 0;
}

