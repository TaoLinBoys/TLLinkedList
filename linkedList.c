#include <stdio.h>
#include <stdlib.h>
struct node {int i; struct node *next;};

void print_list(struct node *n)
{
  printf("[");
  while( n->next != NULL ){
    printf("%d, ", n->i);
    n = n->next;
  }
  printf("%d]\n", n->i);
}


int main(){
  return 0;
}
