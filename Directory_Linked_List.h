#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Singly Linked List Node Declaration

typedef struct Singly
{
    int data;
    struct Singly *next;
}SLLNode;

//Singly Linked List Traversal Function

void traverseSll (SLLNode *head)
{
    SLLNode *current = head;
    int count = 0;
    while (current)
    {
        count++;
        printf ("%d\t", current->data);
        current = current->next;
    }
    printf ("\nNumber of nodes is %d.\n", count);
}

//Singly Linked List Insertion Function

void insertSll (SLLNode **head, int data, int position)
{
    int k = 1;
    SLLNode *current = *head;
    SLLNode *previous = NULL;
    SLLNode *newNode = (SLLNode*)malloc(sizeof(SLLNode));
    newNode->data = data;
    if (position == 1)
    {
        newNode->next = current;
        *head = newNode;
    }
    else
    {
        while (current && k < position)
        {
            k++;
            previous = current;
            current = current->next;
        }
        previous->next = newNode;
        newNode->next = current;
    }
}

//Singly Linked List Node Deletion Function

void deleteSllnode (SLLNode **head, int position)
{
    int k = 1;
    SLLNode *current = *head;
    SLLNode *previous = NULL;
    if (*head == NULL)
    {
        printf ("\nNo node in list!\n");
        return;
    }
    if (position == 1)
    {
        *head = (*head)->next;
        free (current);
    }
    else
    {
        while (current && k < position)
        {
            k++;
            previous = current;
            current = current->next;
        }
        if (!current)
        {
            printf ("\nPosition does not exist!\n");
        }
        else
        {
            previous->next = current->next;
            free (current);
        }
    }
}

//Singly Linked List Deletion Function

void deleteSll (SLLNode **head)
{
    SLLNode *current;
    SLLNode *temp;
    current = *head;
    while (current)
    {
        temp = current->next;
        free (current);
        current = temp;
    }
    *head = NULL;
}

//Doubly Linked List Node Declaration

typedef struct Doubly
{
    int data;
    struct Doubly *next;
    struct Doubly *prev;
}DLLNode;

//Doubly Linked List Traversal Function

void traverseDll (DLLNode *head)
{
    int count = 0;
    DLLNode *temp;
    temp = head;
    while (temp)
    {
        count++;
        printf ("%d\t", temp->data);
        temp = temp->next;
    }
    printf ("Number of nodes is %d.\n", count);
    printf ("\n");
}

//Doubly Linked List Insertion Function

void insertDll (DLLNode **head, int data, int position)
{
    int k = 1;
    DLLNode *current, *newNode, *previous;
    current = *head;
    newNode = (DLLNode*)malloc(sizeof(DLLNode));
    newNode->data = data;
    if (position == 1)
    {
        newNode->next = *head;
        newNode->prev = NULL;
        if (*head)
        {
            (*head)->prev = newNode;
        }
        *head = newNode;
    }
    else 
    {
        while (current && k < position)
        {
            k++;
            previous = current;
            current = current->next;
        }
        if (!current)    //or      if (k != position)
        {
            printf ("\nPosition does not exist!\n");
        }
        newNode->next = current;
        newNode->prev = previous;
        if (current)
        {
            current->prev = newNode;
        }
        previous->next = newNode;
    }
}

//Doubly Linked List Node Deletion Function

void deleteDllnode (DLLNode **head, int position)
{
    int k = 1;
    DLLNode *current = *head;
    DLLNode *previous = NULL;
    if (*head == NULL)
    {
        printf ("\nNo node in list!\n");
        return;
    }
    if (position == 1)
    {
        current = *head;
        (*head) = (*head)->next;
        free (current);
    }
    else
    {
        while (current && k < position)
        {
            k++;
            previous = current;
            current = current->next;
        }
        if (!current)    //or   if (k != position)
        {
            printf ("\nPosition does not exist!\n");
            return;
        }
        if (current->next)
        {
            current->next->prev = previous;
            previous->next = current->next;
        }
        else
        {
            previous->next = NULL;
        }
        free (current);
    }
}

//Circular Linked List Node Declaration

typedef struct Circular
{
    int data;
    struct Circular *next;
}CLLNode;

//Circular Linked List Traversal Function

void traverseCll (CLLNode *head)
{
    CLLNode *temp;
    int count = 0;
    temp = head;
    if (head == NULL)
    {
        printf ("\nList is empty!\n");
        return;
    }
    printf ("\nLinked list-\n");
    do
    {
        count++;
        printf ("%d\t", temp->data);
        temp = temp->next;
    }while (temp != head);    // note in the trivial case when there's only one node, if while loop is used the loop will not perform as temp == head
    
    printf ("\n");
    printf ("Number of nodes is %d.\n", count);
    printf ("\n");
}

//Circular Linked List Insertion at Front             ***IMPORTANT***

void insertFrontCll(CLLNode **head, int data)
{
    CLLNode *newNode, *current;
    newNode = (CLLNode*)malloc(sizeof(CLLNode));
    newNode->data = data;
    current = *head;
    if (*head == NULL)
    {
        newNode->next = newNode;
    }
    else
    {
        newNode->next = *head;
        while (current->next != *head)  //as we are starting from the base case current = *head
        {
            current = current->next;
        }
        current->next = newNode;
    }
    *head = newNode;
}

//Circular Linked List Insetion at End                 ***IMPORTANT***

void insertEndCll (CLLNode **head, int data)
{
    CLLNode *current = *head;
    CLLNode *newNode = (CLLNode*)malloc(sizeof(CLLNode));
    newNode->data = data;
    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
    }
    else
    {
        while (current->next != *head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }

}

//Circular Linked List Deletion from Front      ***IMPORTANT***

void deleteFrontCll (CLLNode **head)
{
    CLLNode *temp = *head;
    CLLNode *current = *head;
    if (*head == NULL)
    {
        printf ("\nEmpty list!\n");
        return;
    }
    if ((*head)->next == *head) //when there's only one node
    {
        (*head) = NULL;
        return;
    }
    while (current->next != *head)
    {
        current = current->next;
    }
    *head = (*head)->next;
    current->next = *head;
    free (temp);
}

//Circular Linked List Deletion from End      ***IMPORTANT***

void deleteEndCll (CLLNode **head)
{
    CLLNode *current, *previous;
    current = *head;
    if (*head == NULL)
    {
        printf ("\nEmpty list!\n");
        return;
    }
    if ((*head)->next == *head) //when there's only one node
    {
        (*head) = NULL;
        return;
    }
    while (current->next != *head)
    {
        previous = current;
        current = current->next;
    }
    previous->next = *head;
    free (current);

}




//                                           ***EXEMPLAR CODES***



//FUNCTION TO FIND THE N'TH NODE FROM THE LAST OF A SINGLY LINKED LIST

//We use two pointers - nNode and aux. At first both point to the head node and we make the aux
//pointer to move to the n th node from head and only then the nNode starts moving till the aux
//reaches end. By then, the nNode points to the n th node from the last of the linked list.
//We can think of this like first we are making the difference of positions between the last
//and the n'th node from last node as the difference of the aux and nNode pointers. And then
//we shift the position of that difference through the list.
//    A B C D E F G H I
//    1 2 3 4 5 6 7 8 9
//    9 8 7 6 5 4 3 2 1        we are to find 3'rd node from last
//                |
//Difference of G and I node is 2.
//    A B C D E F G H I
//    1 2 3 4 5 6 7 8 9
//    9 8 7 6 5 4 3 2 1 
//    |
//(aux,nNode)                   INITIALLY (1, SEE CODE)

//    A B C D E F G H I
//    1 2 3 4 5 6 7 8 9
//    9 8 7 6 5 4 3 2 1 
//    |   |
//  nNode aux                   AFTER MOVING THE AUX TO THE n'TH NODE FROM HEAD (2, SEE CODE)

//    A B C D E F G H I
//    1 2 3 4 5 6 7 8 9
//    9 8 7 6 5 4 3 2 1 
//      |   |
//   nNode aux                  AFTER BUILDING THE PROPER DIFFERENCE WE SHIFT THE POINTERS (3, SEE CODE)

//    A B C D E F G H I
//    1 2 3 4 5 6 7 8 9
//    9 8 7 6 5 4 3 2 1 
//        |   |
//     nNode aux

//    A B C D E F G H I
//    1 2 3 4 5 6 7 8 9
//    9 8 7 6 5 4 3 2 1 
//          |   |
//       nNode aux

//    A B C D E F G H I
//    1 2 3 4 5 6 7 8 9
//    9 8 7 6 5 4 3 2 1 
//            |   |
//         nNode aux

//    A B C D E F G H I
//    1 2 3 4 5 6 7 8 9
//    9 8 7 6 5 4 3 2 1 
//              |   |
//           nNode aux

//    A B C D E F G H I
//    1 2 3 4 5 6 7 8 9
//    9 8 7 6 5 4 3 2 1 
//                |   |
//             nNode aux        WHEN aux REACHES THE END nNode POINTS TO THE n'TH NODE FORM LAST      (4, SEE CODE)

//TC = O(n)     SC = O(1)


void nthFromEnd(SLLNode *head, int n)
{
    SLLNode *nNode = head;           //1
    SLLNode *aux = head;             //1
    int count = 0;
    if (!head)
    {
        while (count < n)                       //2
        {
            if (!aux)                       
            {
                printf ("\nNode number out of bound!\n");
                return;
            }
            aux = aux->next;
            count++;
        }                                       //2
        while(aux)                              //3
        {
            nNode = nNode->next;
            aux = aux->next;
        }                                       //3
        printf ("\n%d no. node from last contains data %d.\n", n, nNode->data);     //4
    }
}

// FUNCTION TO FIND WHETHER THERE IS A LOOP IN THE LINKED LIST (FLOYD CYCLE FINDING ALGORITHM)

// We have to find whether there's a loop in the linked list or not. If we use a slow and a fast pointer to move through the linked
// list, then they are bound to meet at some point if there's a loop. We can think of a tortoise and a rabbit running on a track.
// Rabbit will catch the tortoise at some lap if the track is circular or there's a loop.

// TC = O(n)    SC = O(1)

int hasLoop (SLLNode *head)
{
    SLLNode *slow = head;
    SLLNode *fast = head;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
        return 0;
    }
}

//FUNCTION TO FIND THE START NODE OF THE LOOP IN THE LINKED LIST

//After finding the loop in the linked list, we initialize the slow pointer to head and from that point both slow and fast pointer 
//moves one node at a time. The point at which they meet is the start of the loop.
//TC = O(n) SC = O(1)

SLLNode *findStartofLooop (SLLNode *head)
{
    SLLNode *slow = head;
    SLLNode *fast = head;
    int hasLoop = 0;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            hasLoop = 1;
            break;
        }
    }
    if (hasLoop)
    {
        slow = head;
        while (slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    return nullptr;
}

