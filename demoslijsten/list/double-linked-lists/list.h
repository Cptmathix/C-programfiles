struct DListNode {
	int value;
	struct DListNode* prev;
	struct DListNode* next;
};

struct DList {
	struct DListNode* first;
	struct DListNode* last;
	int length;
};

struct DList* dlist_create();
void dlist_print(struct DList* dlist);
void dlist_delete(struct DList* dlist);

void dlist_print_reverse(struct DList* dlist);
int dlist_length(struct DList* dlist);
int dlist_get(struct DList* list, int index, int* value);
void dlist_append(struct DList* dlist, int value);
void dlist_insert(struct DList* dlist, int index, int value);
int dlist_remove(struct DList* dlist, int index);

