#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void roundRobinScheduler() {
    printf("\n=== ROUND ROBIN SCHEDULER ===\n\n");
    
    printf("Creating processes:\n");
    create(10);
    create(5);
    create(8);
    create(3);
    display();
    
    printf("\nSimulating Round Robin (Time Quantum = 4):\n");
    
    int timeQuantum = 4;
    int totalTime = 0;
    int processCount = num1;
    
    while (!isEmpty()) {
        struct NODE *current = head;
        printf("\nCurrent process: %dms\n", current->number);
        
        if (current->number <= timeQuantum) {
            printf("Process completes\n");
            totalTime += current->number;
            delete();
        } else {
            printf("Runs for %dms, Remaining: %dms\n", 
                   timeQuantum, current->number - timeQuantum);
            current->number -= timeQuantum;
            totalTime += timeQuantum;
            head = head->next;
            last = last->next;
        }
        
        if (!isEmpty()) {
            printf("Remaining: ");
            display();
        }
    }
    
    printf("\nTotal time: %dms\n", totalTime);
    printf("All done!\n");
}

int main() {
    printf("=== CIRCULAR LIST ===\n\n");
    
    printf("1. Create list:\n");
    create(10);
    create(20);
    create(30);
    create(40);
    create(50);
    display();
    
    printf("\n2. Insert 5 at start:\n");
    insert(5, 1);
    display();
    
    printf("\n3. Insert 25 at pos 4:\n");
    insert(25, 4);
    display();
    
    printf("\n4. Search for 30:\n");
    find(30);
    
    printf("\n5. Find middle:\n");
    middleElement();
    
    printf("\n6. Delete from start:\n");
    delete();
    display();
    
    printf("\n7. Delete from pos 3:\n");
    deleteAtPosition(3);
    display();
    
    printf("\n8. Delete from end:\n");
    deleteEnd();
    display();
    
    roundRobinScheduler();
    
    freeList();
    return 0;
}
