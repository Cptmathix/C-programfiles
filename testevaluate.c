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
	
	return 1;
}
