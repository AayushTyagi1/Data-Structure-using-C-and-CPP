#include<stdio.h>
struct LL
{
	int val;
	struct LL *next;
};
typedef struct LL SLL;
void *insertAtFirst(SLL **ptrForhead,int no)
{
	/* create a new node */
	SLL * node=(SLL*)malloc(sizeof(SLL));
	node->val=no;
	/* update the next pointer of the new node */
	node->next=*ptrForhead;
   /*	update the head pointer to point to the ne node */
  	*ptrForhead=node;

}
void *insertAtLast(SLL **ptrForhead,int no)
{
	/* create a new node */
	SLL * node=(SLL*)malloc(sizeof(SLL));
	node->val=no;
	SLL *temp= *ptrForhead;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	/* update the next pointer of last node to the new node  */
	temp->next=node;
    /*	update the next node of the new node to NULL */
    node->next=NULL;
}
void *insertAtMiddle(SLL **ptrForhead,int no)
{
	/* create a new node */
	SLL * node=(SLL*)malloc(sizeof(SLL));
	node->val=no;
	SLL *slow = *ptrForhead, *fast = *ptrForhead;
	/* find middle node */
	while((fast->next!=NULL)&&(fast->next->next!=NULL))
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	/* update the next pointer of the new node */
	node->next=slow->next;
	/* update the next node of the middle node to the new node */
    slow->next=node;
}
void *deleteFromFirst(SLL **ptrForhead)
{
	/* give the reference of the first node to a temporary node */
	SLL *temp = *ptrForhead;
	/* update the head node to the next node */
	*ptrForhead = (*ptrForhead)->next;
    /*	free the deleted node */
  	free(temp);
}
void *deleteFromLast(SLL **ptrForhead)
{
    /* give the reference of the first node to a temporary node */
	SLL *temp1 = *ptrForhead;
	while(temp1->next->next!=NULL)
	{
		temp1=temp1->next;
	}
	/* update the next pointer of last node to the new node  */
	SLL *temp2=temp1->next;
	temp1->next=NULL;
    /*	free the deleted node */
    free(temp2);
}
void *deleteFromMiddle(SLL **ptrForhead)
{
	/* find middle node */
	SLL *slow = *ptrForhead, *fast = *ptrForhead;
	while((fast->next!=NULL)&&(fast->next->next!=NULL))
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	/* give the reference of the first node to the node to be deleted*/
	SLL *temp = slow->next;
	/* update the next node of the middle node to the new node */
    slow->next=slow->next->next;
    free(temp);
}
void printSLL(SLL *temp)
{
	while(temp!=NULL)
	{
		printf("%d ",temp->val);
		temp=temp->next;
	}
}
int main()
{
	SLL * node=(SLL*)malloc(sizeof(SLL));
	node->val=2;
	node->next=NULL;
	SLL *head=node;
	insertAtFirst(&head,1);
	insertAtLast(&head,4);
	insertAtLast(&head,5);
	insertAtLast(&head,6);
	insertAtLast(&head,7);
	insertAtLast(&head,8);
	insertAtLast(&head,9);
	insertAtLast(&head,10);
	insertAtMiddle(&head,3);
	printSLL(head);
	deleteFromFirst(&head);
	deleteFromMiddle(&head);
	deleteFromLast(&head);
	printf("\nAfter deletion\n");
	printSLL(head);
	return 0;
}
