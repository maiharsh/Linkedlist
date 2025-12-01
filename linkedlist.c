#include <stdio.h>
#include <stdlib.h>

int num1 = 0;

struct NODE1 {
    int number;
    struct NODE1 *next;
};

struct NODE1 *head = NULL;
struct NODE1 *last = NULL;

struct NODE1 *create(int value){
    struct NODE1 *new = (struct NODE1 *)malloc(sizeof(struct NODE1));
    new->number = value;
    if(num1 == 0){
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

void find(int value){
    struct NODE1 *temp=head;
    for(int i=0;i<num1;i++){
        if(temp->number==value){
            printf("Location At (%p) For Element (%d).\n", temp, temp->number);
            return;
        }
        temp = temp->next;
    }
}

void middleElement(void){
    struct NODE1 *t=head;
    int temp = num1/2;
    if(num1-temp!=num1) ++temp;
    for(int i=1;i<temp;i++){
        t=t->next;
    }
    printf("Middle Element Is: %d\n", t->number);
}

void delete(void){
    if(num1==0){
        printf("Error! Linked List Is Empty.\n");
        return;
    } else if(num1==1){
        struct NODE1 *temp = head;
        free(temp);
        head=NULL;
        last=NULL;
    } else {
        struct NODE1 *temp = head;
        head = head->next;
        free(temp);
        last->next = head;
    }
    num1--;
}

void insert(int value, int pos){
    if(pos < 1 || pos > num1 + 1){
        printf("Invalid Position!\n");
        return;
    }

    struct NODE1 *new = (struct NODE1 *)malloc(sizeof(struct NODE1));
    new->number = value;

    if(pos == 1){
        if(num1 == 0){
            head = new;
            last = new;
            new->next = head;
        } else {
            new->next = head;
            last->next = new;
            head = new;
        }
        num1++;
        return;
    }

    if(pos == num1 + 1){
        new->next = head;
        last->next = new;
        last = new;
        num1++;
        return;
    }

    struct NODE1 *temp = head;
    for(int i = 1; i < pos - 1; i++){
        temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
    num1++;
}

void display(void){
    struct NODE1 *temp=head;
    for(int i=0;i<num1;i++){
        printf("%d->", temp->number);
        temp = temp->next;
    }
    if(num1==0){
        printf("NULL\n");
    } else {
        printf("%d(HEAD)\n", head->number);
    }
}