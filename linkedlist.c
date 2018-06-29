#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "linkedlist.h"

linkedlist_t* linkedlist_new() {
    linkedlist_t* list = (linkedlist_t *)malloc(sizeof(linkedlist_t));
    list->head = (linkedlist_node_t *)malloc(sizeof(linkedlist_node_t));
    list->head->value = 0;
    list->head->next = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

linkedlist_t* linkedlist_from(int count, ...) {
    va_list args;
    va_start(args, count);
    linkedlist_t* list = linkedlist_new();
    for (int i = 0; i < count; i++) {
        linkedlist_add(list, va_arg(args, int));
    }
    va_end(args);
    return list;
}

linkedlist_t* linkedlist_clone(linkedlist_t* list) {
    linkedlist_t* new = linkedlist_new();
    linkedlist_node_t* tmp_orig = list->head;
    while (tmp_orig->next != NULL) {
        linkedlist_add(new, tmp_orig->value);
        tmp_orig = tmp_orig->next;
    }
    return new;
}

void linkedlist_add(linkedlist_t* list, int value) {
    if (list->tail == NULL ) { // first element
        list->tail = (linkedlist_node_t *)malloc(sizeof(linkedlist_node_t));
        list->tail->value = value;
        list->tail->next = NULL;
        list->head->next = list->tail;
    } else {
        list->tail->next = (linkedlist_node_t *)malloc(sizeof(linkedlist_node_t));
        list->tail->next->value = value;
        list->tail->next->next = NULL;
        list->tail = list->tail->next;
    }
    list->length++;
}



void linkedlist_free(linkedlist_t* list) {
    linkedlist_clear(list);
    free(list->head);
    free(list);
}

int linkedlist_get(linkedlist_t* list, int index, int* ret) {
    if (index >= list->length) {
        return LINKEDLIST_INDEX_ERROR;
    }
    linkedlist_node_t* tmp = list->head;
    while (index >= 0) {
        tmp = tmp->next;
        index--;
    }
    *ret = tmp->value;
    return LINKEDLIST_OK;
}

int linkedlist_insert(linkedlist_t* list, int pos, int index) {
    if (index > list->length) {
        return LINKEDLIST_INDEX_ERROR;
    }
    linkedlist_node_t* prev=list->head;
    linkedlist_node_t* next=list->head->next;
    while (index > 0) {
        prev = prev->next;
        next = prev->next;
        index--;
    }
    linkedlist_node_t* curr = (linkedlist_node_t *)malloc(sizeof(linkedlist_node_t));
    curr->value = pos;
    curr->next = next;
    prev->next = curr;
    list->length++;
    return LINKEDLIST_OK;
}

void linkedlist_print(linkedlist_t* list) {
    linkedlist_node_t* tmp = list->head;
    int left = list->length;
    while (left > 0) {
        tmp = tmp->next;
        printf("%d ", tmp->value);
        left--;
    }
    printf("\n");
}

void linkedlist_clear(linkedlist_t* list) {
    linkedlist_node_t* tmp;
    while (list->head->next != NULL) {
        tmp = list->head->next->next;
        free(list->head->next);
        list->head->next = tmp;
    }
}

int linkedlist_contains(linkedlist_t* list, int value) {
    linkedlist_node_t* tmp = list->head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
        if (tmp->value == value) {
            return 1;
        }
    }
    return 0;
}

int linkedlist_first(linkedlist_t* list, int* ret) {
    return linkedlist_get(list, 0, ret);
}

int linkedlist_last(linkedlist_t* list, int* ret) {
    if (list->length == 0) {
        return LINKEDLIST_INDEX_ERROR;
    } else {
        *ret = list->tail->value;
        return LINKEDLIST_OK;
    }
}

int linkedlist_length(linkedlist_t* list) {
    return list->length;
}

int linkedlist_index_of(linkedlist_t* list, int value, int* ret) {
    linkedlist_node_t* tmp = list->head;
    int i = 0;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        if (value == tmp->value) {
            *ret = i;
            return LINKEDLIST_OK;
        }
        i++;
    }
    return LINKEDLIST_INDEX_ERROR;
}

int linkedlist_last_index_of(linkedlist_t* list, int value, int* ret) {
    linkedlist_node_t* tmp = list->head;
    int i = 0;
    int j = -1;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        if (value == tmp->value) {
            j = i;
        }
        i++;
    }
    if ( j == -1 ) {
        return LINKEDLIST_INDEX_ERROR;
    } else {
        *ret = j;
        return LINKEDLIST_OK;
    }
}

int linkedlist_remove(linkedlist_t* list, int index) {
    if (index >= list->length) {
        return LINKEDLIST_INDEX_ERROR;
    }
    linkedlist_node_t* prev = list->head;
    for (int i = 0; i < index; i++) {
        prev = prev->next;
    }
    linkedlist_node_t* next = prev->next->next;
    free(prev->next);
    prev->next = next;
    list->length--;
    return LINKEDLIST_OK;
}
