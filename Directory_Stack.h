#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode *next;
}Stack;

Stack *CreateStack ()
{
	return  NULL;
}

void Push (Stack **top, int data)
{
	Stack *temp;
	temp = (Stack*) malloc (sizeof(Stack));
	if (!temp)
	{
		return;
	}
	temp->data = data;
	temp->next = *top;
	*top = temp;
}

int IsEmptyStack (Stack *top)
{
	return top == NULL;
}

int Pop (Stack **top)
{
	int data;
	Stack *temp;
	if (IsEmptyStack(*top))
		return NULL;
	temp = *top;
	*top = (*top)->next;
	data = temp->data;
	free (temp);
	return data;
}

int Peek (Stack *top)
{
	if (IsEmptyStack(top))
		return INT_MIN;
	return top->data;
}

void DeleteStack (Stack **top)
{
	Stack *temp, *p;
	p = *top;
	while (p->next)
	{
		temp = p->next;
		p->next = temp->next;
		free (temp);
	}
	free (p);
}

void Display (Stack *top)
{
	Stack *temp = top;
	while (temp != NULL)
	{
		printf ("%d\t", temp->data);
		temp = temp->next;
	}
}
