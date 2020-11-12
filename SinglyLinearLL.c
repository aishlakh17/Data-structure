#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node
{
	int Data;
	struct Node *Next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void InsertFirst(PPNODE,int);
void Display(PNODE);
int Count(PNODE);
void InsertLast(PPNODE,int);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void InsertAtPos(PPNODE,int,int);
void DeleteAtPos(PPNODE,int);

int main()
{
	PNODE Head=NULL;
	int iRet=0;
	
	InsertFirst(&Head,30);
	InsertFirst(&Head,20);
	InsertFirst(&Head,10);
	
	Display(Head);
	printf("\n");
	
	iRet=Count(Head);
	printf("%d",iRet);
	printf("\n");
	
	InsertLast(&Head,40);
	InsertLast(&Head,50);
	Display(Head);
	printf("\n");
	
	DeleteFirst(&Head);
	Display(Head);
	printf("\n");
	
	DeleteLast(&Head);
	Display(Head);
	printf("\n");
	
	InsertAtPos(&Head,10,1);
	InsertAtPos(&Head,35,4);
	Display(Head);
	printf("\n");
	
	DeleteAtPos(&Head,4);
	Display(Head);
	printf("\n");
	return 0;
}

void InsertFirst(PPNODE First,int No)
{
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->Data=No;
	newn->Next=NULL;
	
	if(*First== NULL)
	{
		*First=newn;
	}
	else
	{
		newn->Next=*First;
		*First=newn;
		
	}
}

void Display(PNODE First)
{
	while(First != NULL)
	{
		printf("%d\t",First->Data);
		First=First->Next;
		
	}
}

int Count(PNODE First)
{
	int iCnt=0;
	
	while(First != NULL)
	{
		iCnt++;
		First=First->Next;
	}
	return iCnt;
}

void InsertLast(PPNODE First,int No)
{
	PNODE newn=NULL;
	PNODE temp=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->Data=No;
	newn->Next=NULL;
	
	if(*First==NULL)
	{
		*First=newn;
	}
	else
	{
		temp=*First;
		
		while(temp->Next != NULL)
		{
			temp=temp->Next;
		}
		temp->Next=newn;
	}
}

void DeleteFirst(PPNODE First)
{
	PNODE temp=*First;
	
	if(*First != NULL)
	{
		(*First)=(*First)->Next;
		free(temp);
	}
}

void DeleteLast(PPNODE First)
{
	PNODE temp=NULL;
	
	if(*First == NULL)
	{
		return;
	}
	else if((*First)->Next==NULL)
	{
		free(*First);
		*First=NULL;
	}
	else
	{
		temp=*First;
		
		while(temp->Next->Next != NULL)
		{
			temp=temp->Next;
		}
		
		free(temp->Next);
		
		temp->Next=NULL;
	}
}

void InsertAtPos(PPNODE First,int No,int iPos)
{
	int iSize=0,iCnt=0;
	PNODE newn=NULL;
	PNODE temp=*First;
	iSize=Count(*First);
	
	if((iPos<1)||(iPos>(iSize+1)))
	{
		return;
	}
	
	if(iPos==1)
	{
		InsertFirst(First,No);
	}
	else if(iPos==(iSize+1))
	{
		InsertLast(First,No);
	}
	else
	{
		newn=(PNODE)malloc(sizeof(NODE));
		
		newn->Next=NULL;
		newn->Data=No;
		
		for(iCnt=1;iCnt<iPos-1;iCnt++)
		{
			temp=temp->Next;
		}
		
		newn->Next=temp->Next;
		temp->Next=newn;
	}
}

void DeleteAtPos(PPNODE First,int iPos)
{
	PNODE temp=*First;
	PNODE target=NULL;
	
	int iCnt=0;
	int iSize=Count(*First);
	
	if((iPos<1)||(iPos>iSize))
	{
		return;
	}
	if(iPos==1)
	{
		DeleteLast(First);
	}
	else if(iPos==iSize)
	{
		DeleteLast(First);
	}
	else
	{
		for(iCnt=1;iCnt<iPos-1;iCnt++)
		{
			temp=temp->Next;
		}
		
		target=temp->Next;
		
		temp->Next=target->Next;
		
		free(target);
	}
}
