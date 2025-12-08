# Circular Linked List in C

## Credits – Team Members
- P Harshvardhan – AP24110010192
- N D Brahmendra – AP24110010198
- Yandrapragada Hari – AP24110010304
- Mohammed Nihal – AP24110010581
- D Manas Pranav – AP24110010596
- Shaik Roshan – AP24110010577

---

## Overview
This project implements a circular singly linked list in C and extends it with several operations including insertion, deletion, searching, finding the middle node, and a Round Robin CPU Scheduling simulation.

A circular linked list is a data structure where the last node points back to the head, forming a loop with no NULL pointers in between nodes. A NULL pointer only appears when the list is empty.

### Supported Operations:
- Create nodes (append)
- Insert at any position
- Delete (start, end, position)
- Search for a value
- Display the list
- Print the middle element
- Free memory
- Round Robin CPU Scheduling

---

## Global Variables
- num1 – number of nodes
- head – pointer to the first node
- last – pointer to the last node

---

## Functions

### create(int value)
Adds a new node at the end of the list and preserves circular structure.

### insert(int value, int pos)
Inserts a new node at the given position (start/middle/end).

### find(int value)
Searches the list by traversing exactly num1 nodes.

### middleElement()
Uses slow and fast pointers to find the middle node.

### delete()
Deletes the first node (head).

### deleteEnd()
Deletes the last node.

### deleteAtPosition(int pos)
Deletes a node from a specific position.

### display()
Prints the list in circular format:

value -> value -> ... -> HEAD


### freeList()
Frees all nodes and resets pointers.

---

## main.c – Updated Functionalities
The updated main.c demonstrates:
- Creating nodes
- Inserting at various positions
- Deleting from start/end/position
- Searching
- Middle element finding
- Displaying the list
- Round Robin Scheduler (time quantum 4)
- Freeing the list

---

## Compilation

gcc main.c linkedlist.c -o linkedlist


## Run

./linkedlist
