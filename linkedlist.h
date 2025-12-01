#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct NODE1 {
    int number;
    struct NODE1 *next;
};

extern int num1;
extern struct NODE1 *head;
extern struct NODE1 *last;

struct NODE1 *create(int value);
void find(int value);
void middleElement(void);
void delete(void);
void display(void);
void insert(int value, int pos);

#endif