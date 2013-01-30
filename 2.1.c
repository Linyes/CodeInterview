#include <stdio.h>
#include <string.h> /* memset */ 
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

/* Add the new node at head */
void push(struct node** head, int new_data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = new_data;
	temp->next = *head;
	*head = temp;
}

void printList(struct node *node)
{
	while (node) {
		printf("%d", node->data);
		if (node->next != NULL)
			printf("->");
		node = node->next;
	}
	printf("\n");
}

void removeDup (struct node *start)
{
	struct node *ptr1, *ptr2, *dup;
	ptr1 = start;
	
	/* Every time a new prt1, it is compare all node after it to remove duplicate */
	while (ptr1 != NULL && ptr1->next != NULL) {
		ptr2 = ptr1;
		while (ptr2->next != NULL) {
			if (ptr1->data == ptr2->next->data) {
				dup = ptr2->next;
				ptr2->next = dup->next;
				free(dup);
			}
			else {
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}

int main(int argc, char *argv[])
{
	struct node *start = NULL;
	
	/* The linked list is:
	10->12->11->11->12->11->10*/
	push(&start, 10);
  	push(&start, 11);
  	push(&start, 12);
  	push(&start, 11);
  	push(&start, 11);
  	push(&start, 12);
  	push(&start, 10);

	printf("\nBefore removing duplicates \n");
	printList(start);	
	
	removeDup(start);
	
	printf("After removing duplicated \n");
	printList(start);
	
	return 0;

}
