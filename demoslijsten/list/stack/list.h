struct StackNode {
	int value;
	struct StackNode *next;
};

struct Stack {
	struct StackNode* top;
};

struct Stack* stack_create();
void stack_print(struct Stack* stack);

void stack_push(struct Stack* stack, int x);
int stack_pop(struct Stack* stack, int *value);
int stack_isempty(struct Stack* stack);
void stack_delete(struct Stack* stack);


int evaluate(char* formula, int* result);

