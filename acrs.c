/* 
Arthur Carlos da Rocha Silva
Spoj problem - JFILA14 -Fila
https://br.spoj.com/problems/JFILA14/
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
    ListNode *newNode, *aux;
    newNode = (ListNode*)malloc(sizeof(ListNode)); //allocating memory for a new node
    aux = (*inputList).data; //aux points to the first node in the list  
    if (aux == NULL) // The list in empty
    {   
        (*newNode).nextNode = (*inputList).data ; //nextNode`s next value will point to NULL
        (*newNode).nodeValue = valueToAdd; 
        (*inputList).data = newNode; //List starts at newNode
        (*inputList).size ++ ; 
    
    }
    else
    {
        while((*aux).nextNode != NULL) //aux points to the last non null node of the list
        {
            aux = (*aux).nextNode;
        }
        (*newNode).nextNode = (*aux).nextNode ; //newNode points to the following node, which is null
        (*newNode).nodeValue = valueToAdd; 
        (*aux).nextNode = newNode;   
        (*inputList).size ++ ; 

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