#ifndef SLIST
#define SLIST

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
  int data;
  struct node *next;
};

// Add element on the front of the list
void prepend(struct node **head, int x)
{
  struct node *temp = (struct node*) malloc(sizeof(struct node));
  temp->data = x;
  temp->next = *head;
  *head = temp;
}

// Insert element after the given node
void insertAfter(struct node *n, int x)
{
  if (!n) // node is not NULL
  {
    printf("Error: Givven node is NULL\n");
    return;
  }
  struct node *temp = (struct node*) malloc(sizeof(struct node));
  temp->data = x;
  temp->next = n->next;
  n->next = temp;
}

// Add element at the end of the list
void append(struct node **head, int x)
{
  struct node *temp = (struct node*) malloc(sizeof(struct node));
  struct node *current = *head;

  temp->data = x;
  temp->next = NULL;
  if(*head == NULL)
  {
    *head = temp;
    return;
  }
  while (current->next)
    current = current->next;
  current->next = temp;
}

// Deletes the first occurrence of number in linked list
void delete(struct node **head, int x)
{
  struct node *temp = *head;
  struct node *prev;

  if (temp && temp->data == x)
  {
    *head = temp->next;
    free(temp);
    return;
  }
  while (temp && temp->data != x)
  {
    prev = temp;
    temp = temp->next;
  }
  if (!temp) return;

  prev->next = temp->next;
  free(temp);
}

// Delete node at specified position
void deleteAt(struct node **head, int position)
{
  if (*head == NULL)
    return;

  struct node *temp = *head;
  if (position == 0)
  {
    *head = temp->next;
    free(temp);
    return;
  }

  for (int i = 0; i < position - 1 && !temp; i++)
    temp = temp->next;

  if (!temp || !temp->next)
    return;

  struct node *next = temp->next->next;
  free(temp->next);
  temp->next = next;
}

// Get list length
int length(struct node *head)
{
  int length = 0;
  struct node *current = head;
  while (current)
  {
    length++;
    current = current->next;
  }
  return length;
}

// Returns does
bool contains(struct node *head, int x)
{
  struct node *current = head;
  while (current)
  {
    if (current->data == x)
      return true;
    current = current->next;
  }
  return false;
}

// Delete list and free memory
void deleteList(struct node **head)
{
  struct node *current = *head;
  struct node *next;

  while (current)
  {
    next = current->next;
    free(current);
    current = next;
  }
  *head = NULL;
}

// Return how many times given number occurs in the list
int occurs(struct node *head, int x)
{
  struct node *current = head;
  int count = 0;
  while (current)
  {
    if (current->data == x)
      count++;
    current = current->next;
  }
  return count;
}

// Display list (print all elements)
void display(struct node *n)
{
  while (n != NULL)
  {
    printf("|%d| -> ", n -> data);
    n = n->next;
  }
  printf("NULL\n");
}

#endif
