#include <stdio.h>
#include <stdlib.h>

struct node
{
   int value;
   struct node *next;
   int count;
};

void *SafeMalloc(size_t size)
{
   void *ptr;
   if((ptr = malloc(size)) == NULL)
   {
      printf("Error out of memory\n");
      exit(EXIT_FAILURE);
   }
   return ptr;
}

struct node *CreateList(int num_elem, struct node *head)
{
   struct node *ptr = NULL;
   int val;
   for(int iter = 0; iter < num_elem; ++iter)
   {
      printf("Enter Value %i\n", &val);
      ptr = (struct node *)SafeMalloc(sizeof(struct node));
      ptr->value = val;
      ptr->count = 1;
      ptr->next = head;
      head = ptr;
   }
   return head;
}
void printList(struct node *head)
{

}
int main(void)
{

}
