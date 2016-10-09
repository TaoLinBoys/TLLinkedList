#include <stdio.h>
#include <stdlib.h>
struct node {int var; struct node *next;};

void print_list(struct node *n)
{
  printf("[");
  while( n->next != NULL ){
    printf("%d, ", n->var);
    n = n->next;
  }
  printf("%d]\n", n->var);
}

struct node * insert_front(struct node *start, int i)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));;
  newNode->var = i;
  newNode->next = start;
  return newNode;
}

struct node * free_list(struct node *n)
{
  struct node *beginning = n;
  
  while(n != NULL){
    struct node *nextNode = n->next;
    free(n);
    n = nextNode;
  }
  
  return beginning;
}

struct node * Node(int i, struct node *next)
{
  struct node *tempNode = (struct node *)malloc(sizeof(struct node));
  tempNode->var = i;
  tempNode->next = next;
  return tempNode;
}

void testprint_list()
{
  printf("____________print_list\n");
  struct node *node3 = Node(2, NULL);
  struct node *node2 = Node(1, node3);
  struct node *node1 = Node(0, node2);
  print_list(node1);
  free_list(node1);
  printf("\n");
}

void testinsert_front()
{
  printf("____________insert_front\n");
  struct node *node4 = Node(3, NULL);
  struct node *node3 = Node(2, node4);
  struct node *node2 = Node(1, node3);
  struct node *node1 = Node(0, node2);
  print_list(node1);
  printf("inserting a 7 in front\n");
  print_list(insert_front(node1, 7));
  free_list(node1);
}


int main()
{
  testprint_list();
  testinsert_front();
  return 0;
}
