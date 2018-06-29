#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define LINKEDLIST_OK 0
#define LINKEDLIST_INDEX_ERROR 1

typedef struct linkedlist_node linkedlist_node_t;
typedef struct linkedlist linkedlist_t;
//typedef bool (*find_cb)(int value);

struct linkedlist_node {
    int value;
    linkedlist_node_t* next;
};

struct linkedlist {
    linkedlist_node_t* head; // dummy head
    linkedlist_node_t* tail;
    int length;
};


linkedlist_t* linkedlist_new();
linkedlist_t* linkedlist_from(int count, ...);
linkedlist_t* linkedlist_clone(linkedlist_t* list);
void linkedlist_free(linkedlist_t* list);
void linkedlist_add(linkedlist_t* list, int value);
int linkedlist_insert(linkedlist_t* list, int value, int index);
int linkedlist_get(linkedlist_t* list, int index, int* ret);
void linkedlist_print(linkedlist_t* list);
void linkedlist_clear(linkedlist_t* list);
int linkedlist_contains(linkedlist_t* list, int value);
int linkedlist_first(linkedlist_t* list, int* ret);
int linkedlist_last(linkedlist_t* list, int* ret);
int linkedlist_length(linkedlist_t* list);
int linkedlist_index_of(linkedlist_t* list, int value, int* ret);
int linkedlist_last_index_of(linkedlist_t* list, int value, int* ret);
int linkedlist_remove(linkedlist_t* list, int index);

#endif /* LINKEDLIST_H */
