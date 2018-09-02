/* 
Arthur Carlos da Rocha Silva
Spoj problem - JFILA14 -Fila
https://br.spoj.com/problems/JFILA14/
Improved. Now it does not return "time limit.." on spoj
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNodes
{
    struct ListNodes *nextNode; //points to the following node
    long int nodeValue; //the value in the node
} ListNode ;

typedef struct Lists
{
    ListNode *data; //Points to the first node of the list  
    ListNode *lastNode;
    long int size;  
} List ;

List* createList()
{
    List *newList ;
    newList = (List*)malloc(sizeof(List)); //THIS MIGHT BE WRONG
    if (newList != NULL)
    {
        (*newList).size = 0;
        (*newList).data = NULL; 
        (*newList).lastNode = NULL; 
    }
    return newList; 
} // createList function

void removeFromList(List *inputList, long int valueToRemove)
{
    ListNode *aux, *anterior; 
    aux = (*inputList).data; // aux will now point to the first node of the input list
    anterior = NULL;
    while(aux != NULL) //aux will loop throgh the list till it points to a null node
    {
        if ((*aux).nodeValue == valueToRemove) //if the value in the current node is the value to be removed
        {
            if (anterior == NULL) //if it is the first value of the list (anterior is still NULL)
            {
                (*inputList).data = (*aux).nextNode; //the first node of the list will now be the aux`s next node
            }
            else
            {
                (*anterior).nextNode = (*aux).nextNode; //the node anteiror to the one to be removed will point to the following
            }
            (*inputList).size = (*inputList).size - 1; 
            break; 
        }
    	anterior = aux; //anterior will point to the current node
        aux = (*aux).nextNode; // aux will now point to the next node in the list
    }
}// removeFromList function

void addToList(List *inputList, long int valueToAdd)
{
    ListNode *newNode;
    newNode = (ListNode*)malloc(sizeof(ListNode));
    if ((*inputList).data  == NULL) //if the list is empty
    {
        (*newNode).nextNode = NULL; //the new node will point to null
        inputList->lastNode = newNode; //the last node of the list will point to the new node
        (*newNode).nodeValue = valueToAdd; 
        (*inputList).data = newNode; //the beginning of the list will be the new node
        (*inputList).size ++;
    }
    else 
    {
        (*newNode).nextNode = NULL ; 
        (*newNode).nodeValue = valueToAdd;
        inputList->lastNode->nextNode = newNode; //the last element of the list will point to the new node
        (*inputList).lastNode = newNode; //the new node will now be the last element of the upgrated list
        (*inputList).size ++;

    }
}//addToList

void printList(List *inputList)
{ 
    ListNode *aux = (*inputList).data ;
    while(aux != NULL)
    {
        printf("%li ",(*aux).nodeValue);
        aux = (*aux).nextNode; 
    }
}
int main()
{  
    List *identifiers = createList();
    long int initialNumber;
    long int remainingNumber; 
    long int currentIdentifier; 
    scanf("%li", &initialNumber);
    for(int i = 0; i < initialNumber ; i ++ ) //adding input values to the list of identifiers
    {   
        scanf("%li",&currentIdentifier);
        addToList(identifiers,currentIdentifier); 

    } 
    //loop for each value separet by space run addToList
    scanf("%li",&remainingNumber);
    for(int i = 0; i < remainingNumber ; i ++ ) 
    { 
        scanf("%li", &currentIdentifier);
        removeFromList(identifiers,currentIdentifier);  
    } 
    //loop for each value separet by space run removeFromList
    printList(identifiers);
    return 0; 
}