# Circular Linked List in C  
### Credits 
 
- AP24110010192 (P Harshvardhan)
- AP24110010198 (N D Brahmendra)
 
---

## Overview
This program implements a *circular singly linked list* in C.  
A circular linked list is a list where the *last node points back to the head*, forming a loop.  
No NULL pointer exists between nodes — the only NULL pointer is when the list is empty.

The program supports:
- Creating nodes (append)
- Inserting at any position
- Deleting the head node
- Finding a value
- Displaying the list
- Printing the middle element

main.c demonstrates how these functions work together.

---

## How the Code Works

### 1. Global Variables
- num1 → number of nodes in the list  
- head → pointer to the first node  
- last → pointer to the last node  

These make list operations simpler.

---

## Functions

### *create(int value)*
Adds a new node at the *end* of the circular linked list.

- If the list is empty:
  - head = last = new
  - new->next = head
- Otherwise:
  - New node points to head
  - Old last->next points to new node
  - last becomes new node

This keeps the list circular.

---

### *find(int value)*
Searches for a number in the list.

- Traverses exactly num1 nodes  
- Prints the node’s memory address if found  

No message if not found (your design).

---

### *middleElement()*
Finds the middle element using:



middle = num1 / 2



For odd counts, it adjusts upward by one.  
Then it traverses to that position and prints the middle value.

---

### *delete()*
Deletes the *first node* (head):

- If empty → prints error
- If only one node → frees it and resets everything
- If multiple:
  - Moves head to next node
  - Frees old head
  - Fixes last->next = head

Keeps the circular structure intact.

---

### *insert(int value, int pos)*
Inserts a new node at a given position:

- *pos == 1* → insert at beginning
- *pos == num1 + 1* → insert at end
- Any other position → insert in the middle

Handles all cases while preserving circular linking.

---

### *display()*
Prints the entire list using:



value->value->value->HEAD

`

- If the list is empty → prints NULL
- Otherwise prints the sequence followed by (HEAD)

It loops exactly num1 times to avoid infinite loops.

---

## *main.c Usage*

The example in main.c:

c
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
`

### Step-by-Step What Happens:

1. Creates list:
   10 -> 20 -> 30 -> 40 -> 50 -> 60 -> (HEAD)

2. Inserts *123 at position 3* →
   10 -> 20 -> 123 -> 30 -> 40 -> 50 -> 60 -> (HEAD)

3. Deletes the head (10) →
   20 -> 123 -> 30 -> 40 -> 50 -> 60 -> (HEAD)

4. Displays the list.

5. Prints the middle element.

6. Searches for the value *60*.

---

## Compilation

Compile using:

bash
gcc main.c linkedlist.c -o linkedlist


Run:

bash
./linkedlist
