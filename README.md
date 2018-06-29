# linkedlist

This project implements data structure LinkedList with integers as it's node value. It has only two source files:

* `linkedlist.h`
* `linkedlist.c`

Feel free to use it in your project. It's under MIT license.

## Getting Started

Place `linkedlist.h` and `linkedlist.c` in your project.
Include header file in your source file.

```
#include "linkedlist.h"
```

[![asciicast](https://asciinema.org/a/189306.png)](https://asciinema.org/a/189306)

## Usage

Create a new LinkedList:

```
linkedlist_t* linkedlist = linkedlist_new();
```

Create a new LinkedList from N integers. N is the first argument. You need to provide N arguments. Extra arguments will be ignored. Insufficient argument will cause undefined values populated into LinkedList:

```
linkedlist_t* linkedlist = linkedlist_from(0);
linkedlist_t* linkedlist = linkedlist_from(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

// WARNING: The 3rd value will be garbbage integer
linkedlist_t* linkedlist = linkedlist_from(3, 0, 1); 
```

Create a new LinkedList from existing LinkedList:

```
linkedlist_t* linkedlist = linkedlist_from(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
linkedlist_t* newlinkedlist = linkedlist_clone(linkedlist);
```

Free LinkedList:

```
linkedlist_t* linkedlist = linkedlist_from(10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
linkedlist_free(linkedlist);
```

Add an integer to the end of LinkedList:

```
linkedlist_add(linkedlist, 1);
```

Add an integer to any place in LinkedList. Note that the index should be valid, otherwise it would return `LINKEDLIST_INDEX_ERROR`. Below example shows inserting element `10` to index `0`.

```
linkedlist_insert(linkedlist, 10, 0);
```

Get integer value from LinkedList by `index`. It returns `LINKEDLIST_OK` when success and `LINKEDLIST_INDEX_ERROR` when failed:

```
int value;
if (linkedlist_get(list, &value) != LINKEDLIST_OK) {
    printf("something goes wrong\n");
    exit(1);
} else {
    printf("yes, the value is %d\n", value);
}
```

Two shortcuts for getting `first` and `last` element in Linkedlist have similar behaviour:

```
int first, last;

if (linkedlist_first(list, &value) != LINKEDLIST_OK) {
    printf("something goes wrong\n");
    exit(1);
} else {
    printf("yes, the first value is %d\n", value);
}

if (linkedlist_last(list, &value) != LINKEDLIST_OK) {
    printf("something goes wrong\n");
    exit(1);
} else {
    printf("yes, the last value is %d\n", value);
}
```

Get length of LinkedList:

```
int length = linkedlist_length(linkedlist);
```

Get index by value. It returns `LINKEDLIST_OK` when success and `LINKEDLIST_INDEX_ERROR` when failed:

```
int index;

if (linkedlist_index_of(list, 0, &index) != LINKEDLIST_OK) {
    printf("something goes wrong\n");
    exit(1);
} else {
    printf("yes, 0 is at %d.\n", value);
}
```

Also, a `last_index_of` is useful when searching from end. It returns `LINKEDLIST_OK` when success and `LINKEDLIST_INDEX_ERROR` when failed. Due to the nature of LinkedList, `last_index_of` needs to iterate through the entire LinkedList.:

```
int index;

if (linkedlist_last_index_of(list, 0, &index) != LINKEDLIST_OK) {
    printf("something goes wrong\n");
    exit(1);
} else {
    printf("yes, 0 is at %d.\n", value);
}
```

Remove an element by index. Below example removes the first element in LinkedList:

```
linkedlist_remove(list, 0);
```

Check if an element in in LinkedList:

```
if (linkedlist_contains(list, 1)) {
    printf("yes, list has element 1\n");
}
```

Remove all elements.

```
linkedlist_clear(list);
```
