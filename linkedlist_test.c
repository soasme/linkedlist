#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include "linkedlist.h"

void test_initialize_empty_linkedlist() {
    linkedlist_t* linkedlist = linkedlist_new();
    assert(linkedlist_length(linkedlist) == 0);
    assert(linkedlist->head->next == NULL);
    assert(linkedlist->tail == NULL);
    linkedlist_free(linkedlist);
}

void test_initialize_linkedlist_from_integers() {
    int x;

    linkedlist_t* linkedlist = linkedlist_from(0);
    assert(linkedlist_length(linkedlist) == 0);
    linkedlist_free(linkedlist);

    linkedlist = linkedlist_from(1, 2, 3);
    assert(linkedlist_length(linkedlist) == 1);
    linkedlist_free(linkedlist);

    linkedlist = linkedlist_from(2, 2);
    assert(linkedlist_length(linkedlist) == 2);
    linkedlist_free(linkedlist);

    linkedlist = linkedlist_from(3, 1, 2, 3);
    assert(linkedlist_length(linkedlist) == 3);
    assert(linkedlist->head->next->value == 1);
    assert(linkedlist->head->next->next->value == 2);
    assert(linkedlist->head->next->next->next->value == 3);
    assert(linkedlist->head->next->next->next == linkedlist->tail);
    linkedlist_free(linkedlist);
}

void test_add_value_to_linkedlist() {
    linkedlist_t* linkedlist = linkedlist_new();
    linkedlist_add(linkedlist, 1);
    assert(linkedlist_length(linkedlist) == 1);
    assert(linkedlist->head->next->value == 1);
    assert(linkedlist->head->next->next == NULL);
    assert(linkedlist->head->next == linkedlist->tail);
    linkedlist_free(linkedlist);
}

void test_add_value_to_one_position_linkedlist() {
    int x;
    linkedlist_t* linkedlist = linkedlist_from(3, 1, 2, 3);
    linkedlist_insert(linkedlist, 0, 0);
    assert(linkedlist_length(linkedlist) == 4);
    assert(linkedlist_get(linkedlist, 0, &x) == LINKEDLIST_OK);
    assert(x == 0);
    linkedlist_insert(linkedlist, 4, 4);
    assert(linkedlist_get(linkedlist, 4, &x) == LINKEDLIST_OK);
    assert(x == 4);
    linkedlist_insert(linkedlist, 10, 10);
    assert(linkedlist_get(linkedlist, 10, &x) == LINKEDLIST_INDEX_ERROR);
    assert(x == 4); // not changed.
    linkedlist_free(linkedlist);
}

void test_access_index_into_linkedlist() {
    linkedlist_t* linkedlist = linkedlist_from(3, 1, 2, 3);
    int x;
    assert(linkedlist_get(linkedlist, 0, &x) == LINKEDLIST_OK);
    assert(x == 1);
    assert(linkedlist_get(linkedlist, 1, &x) == LINKEDLIST_OK);
    assert(x == 2);
    assert(linkedlist_get(linkedlist, 2, &x) == LINKEDLIST_OK);
    assert(x == 3);
    assert(linkedlist_get(linkedlist, 3, &x) == LINKEDLIST_INDEX_ERROR);
    assert(x == 3); // not changed.
    linkedlist_free(linkedlist);
}

void test_clone() {
    linkedlist_t* linkedlist = linkedlist_from(3, 1, 2, 3);
    linkedlist_t* new = linkedlist_clone(linkedlist);
    assert(linkedlist_length(new) == 3);
    linkedlist_free(linkedlist);
    linkedlist_free(new);
}

void test_contains() {
    linkedlist_t* linkedlist = linkedlist_from(3, 1, 2, 3);
    assert(linkedlist_contains(linkedlist, 0) == 0);
    assert(linkedlist_contains(linkedlist, 1) == 1);
    assert(linkedlist_contains(linkedlist, 2) == 1);
    assert(linkedlist_contains(linkedlist, 3) == 1);
    assert(linkedlist_contains(linkedlist, 4) == 0);
    linkedlist_free(linkedlist);
}

void test_first() {
    linkedlist_t* linkedlist = linkedlist_from(3, 1, 2, 3);
    int x;
    assert(linkedlist_first(linkedlist, &x) == LINKEDLIST_OK);
    assert(x == 1);
    linkedlist_free(linkedlist);

    linkedlist = linkedlist_new();
    assert(linkedlist_first(linkedlist, &x) == LINKEDLIST_INDEX_ERROR);
    linkedlist_free(linkedlist);
}

void test_last() {
    linkedlist_t* linkedlist = linkedlist_from(3, 1, 2, 3);
    int x;
    assert(linkedlist_last(linkedlist, &x) == LINKEDLIST_OK);
    assert(x == 3);
    linkedlist_free(linkedlist);

    linkedlist = linkedlist_new();
    assert(linkedlist_last(linkedlist, &x) == LINKEDLIST_INDEX_ERROR);
    linkedlist_free(linkedlist);
}

void test_index_of() {
    linkedlist_t* linkedlist = linkedlist_from(3, 1, 1, 2);
    int x;
    assert(linkedlist_index_of(linkedlist, 1, &x) == LINKEDLIST_OK);
    assert(x == 0);
    linkedlist_free(linkedlist);

    linkedlist = linkedlist_new();
    assert(linkedlist_index_of(linkedlist, 3, &x) == LINKEDLIST_INDEX_ERROR);
    linkedlist_free(linkedlist);
}

void test_last_index_of() {
    linkedlist_t* linkedlist = linkedlist_from(3, 1, 1, 2);
    int x;
    assert(linkedlist_last_index_of(linkedlist, 1, &x) == LINKEDLIST_OK);
    assert(x == 1);
    linkedlist_free(linkedlist);

    linkedlist = linkedlist_new();
    assert(linkedlist_last_index_of(linkedlist, 3, &x) == LINKEDLIST_INDEX_ERROR);
    linkedlist_free(linkedlist);
}

void test_remove() {
    linkedlist_t* linkedlist = linkedlist_from(3, 1, 1, 2);
    assert(linkedlist_length(linkedlist) == 3);
    assert(linkedlist_remove(linkedlist, 2) == LINKEDLIST_OK);
    assert(linkedlist_length(linkedlist) == 2);
    assert(linkedlist_remove(linkedlist, 1) == LINKEDLIST_OK);
    assert(linkedlist_length(linkedlist) == 1);
    assert(linkedlist_remove(linkedlist, 0) == LINKEDLIST_OK);
    assert(linkedlist_length(linkedlist) == 0);
    assert(linkedlist_remove(linkedlist, 0) == LINKEDLIST_INDEX_ERROR);
    linkedlist_free(linkedlist);
}

int main(int argc, char** argv) {
    test_initialize_empty_linkedlist();
    test_initialize_linkedlist_from_integers();
    test_add_value_to_linkedlist();
    test_add_value_to_one_position_linkedlist();
    test_access_index_into_linkedlist();
    test_clone();
    test_contains();
    test_first();
    test_last();
    test_index_of();
    test_last_index_of();
    test_remove();
}

