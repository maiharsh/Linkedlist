#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int num1 = 0;
struct NODE *head = NULL;
struct NODE *last = NULL;

struct NODE *create(int value) {
    struct NODE *new = (struct NODE *)malloc(sizeof(struct NODE));
    new->number = value;
    
    if (num1 == 0) {
        head = new;
        last = new;
        new->next = head;
    } else {
        new->next = head;
        last->next = new;
        last = new;
    }
    num1++;
    return new;
}

void find(int value) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    
    struct NODE *temp = head;
    for (int i = 0; i < num1; i++) {
        if (temp->number == value) {
            printf("Found %d at pos %d\n", value, i + 1);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found\n", value);
}

void middleElement(void) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    
    struct NODE *slow = head;
    struct NODE *fast = head;
    
    do {
        fast = fast->next;
        if (fast != head) {
            fast = fast->next;
            slow = slow->next;
        }
    } while (fast != head && fast->next != head);
    
    printf("Middle: %d\n", slow->number);
}

void delete(void) {
    if (num1 == 0) {
        printf("List empty\n");
        return;
    }
    
    if (num1 == 1) {
        free(head);
        head = NULL;
        last = NULL;
    } else {
        struct NODE *temp = head;
        head = head->next;
        last->next = head;
        free(temp);
    }
    num1--;
}

void insert(int value, int pos) {
    if (pos < 1 || pos > num1 + 1) {
        printf("Invalid pos\n");
        return;
    }

    struct NODE *new = (struct NODE *)malloc(sizeof(struct NODE));
    new->number = value;

    if (pos == 1) {
        if (num1 == 0) {
            head = new;
            last = new;
            new->next = head;
        } else {
            new->next = head;
            last->next = new;
            head = new;
        }
    } else if (pos == num1 + 1) {
        new->next = head;
        last->next = new;
        last = new;
    } else {
        struct NODE *temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;
    }
    num1++;
}

void display(void) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    
    struct NODE *temp = head;
    for (int i = 0; i < num1; i++) {
        printf("%d->", temp->number);
        temp = temp->next;
    }
    printf("%d(HEAD)\n", head->number);
}

void deleteEnd(void) {
    if (num1 == 0) {
        printf("List empty\n");
        return;
    }
    
    if (num1 == 1) {
        free(head);
        head = NULL;
        last = NULL;
    } else {
        struct NODE *temp = head;
        struct NODE *prev = NULL;
        
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        
        prev->next = head;
        last = prev;
        free(temp);
    }
    num1--;
}

void deleteAtPosition(int pos) {
    if (pos < 1 || pos > num1) {
        printf("Invalid pos\n");
        return;
    }
    
    if (pos == 1) {
        delete();
        return;
    }
    
    if (pos == num1) {
        deleteEnd();
        return;
    }
    
    struct NODE *temp = head;
    struct NODE *prev = NULL;
    
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = temp->next;
    free(temp);
    num1--;
}

void freeList(void) {
    if (head == NULL) return;
    
    struct NODE *temp = head;
    struct NODE *nextNode;
    
    for (int i = 0; i < num1; i++) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    
    head = NULL;
    last = NULL;
    num1 = 0;
}

int isEmpty(void) {
    return head == NULL;
}
