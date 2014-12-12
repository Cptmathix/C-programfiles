#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include <assert.h>

int test_list()
{
	puts("starting test");
	
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

	puts("list_insert and list_get ok");
	
	// Test remove function
	if (list_remove(list, 1) == 0) {
		printf("Error in list_remove\n");
		return 0;
	}
	if (list_length(list) != 1) {
		printf("list_length should return 1 (after remove)\n");
		return 0;
	}
	
	list_print(list);
	
	if (list_remove(list, 1) != 0) {
		printf("Error in list_remove\n");
		return 0;
	}
	if (list_length(list) != 1) {
		printf("list_length should return 1 (after remove)\n");
		return 0;
	}
	
	list_print(list);
	
	if (list_remove(list, 0) == 0) {
		printf("Error in list_remove\n");
		return 0;
	}
	
	if (list_length(list) != 0) {
		printf("list_length should return 1 (after remove)\n");
		return 0;
	}
	
	list_print(list);
	
	if (list_remove(list, 0) != 0) {
		printf("Error in list_remove\n");
		return 0;
	}
	
	if (list_length(list) != 0) {
		printf("list_length should return 1 (after remove)\n");
		return 0;
	}
	puts("list_remove ok");

	// Test pop function
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
	
	//
	

	return 1;
}


int test_dlist()
{
	// TODO: Add your own test functions (!!)

	return 1;
}


int test_stack()
{
	// TODO: Add your own test functions (!!)

	return 1;
}


int test_evaluate()
{
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
	
	return 1;
}


int main(int argc, char *argv[])
{
	test_list();
	test_dlist();
	test_stack();
	test_evaluate();

	return 0;
}

