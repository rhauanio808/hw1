/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  // create temp node to track and sort input list
  Node* temp = in;

  // base case: stop if list is empty
  if (temp == NULL) {
    return;
  }

  in = in->next; // move to next input

  temp->next = NULL; // detach current node to sort
  
  // recursive step: sort the list
  split(in, odds, evens);
  
    // check if current value is even or odd
    if (temp->value % 2 == 0) {
      // sort to even list
      temp->next = evens; // add node to front of sorted list 
      evens = temp; // update head 
    }
    else {
      // sort to odd list
      temp->next = odds; // link to list
      odds = temp; // update head
    }
}

/* If you needed a helper function, write it here */
