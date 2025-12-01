#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void){
    create(10);
    create(20);
    create(30);
    create(40);
    create(50);
    create(60);
    insert(123, 3);

    delete();
    display();
    middleElement();
    find(60);
}