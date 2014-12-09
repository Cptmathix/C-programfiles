struct ListNode
{
    int value;
    struct ListNode* next;
};

struct List
{
    struct ListNode* first;
};

struct List* list_create();
void list_append(struct List* list, int value);
int list_length(struct List* list);
int list_get(struct List* list, int index, int* value);
void list_delete(struct List* list);
void list_print(struct List* list);
int list_remove(struct List* list, int index);
int list_pop(struct List* list, int* value);
void list_prepend(struct List* list, int value);
void list_insert(struct List* list, int index, int value);
void list_insert_sorted(struct List* list, int value);
