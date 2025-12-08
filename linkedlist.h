#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int number;
    struct NODE *next;
};

extern int num1;
extern struct NODE *head;
extern struct NODE *last;

struct NODE *create(int value);
void find(int value);
void middleElement(void);
void delete(void);
void display(void);
void insert(int value, int pos);
void deleteEnd(void);
void deleteAtPosition(int pos);
void freeList(void);
int isEmpty(void);

#endif
