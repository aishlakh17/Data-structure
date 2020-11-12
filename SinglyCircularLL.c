#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
	int Data;
	struct node *Next;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE,PPNODE,int);
void InsertLast(PPNODE,PPNODE,int);
void Display(PNODE,PNODE);
int Count(PNODE,PNODE);
void DeleteFirst(PPNODE,PPNODE);
void DeleteLast(PPNODE,PPNODE);
void InsertAtPos(PPNODE,PPNODE,int,int);
void DeleteAtPos(PPNODE,PPNODE,int);

int main()
{
	PNODE Head=NULL;
	PNODE Tail=NULL;
	int iRet=0;
	
	InsertFirst(&Head,&Tail,51);
	InsertFirst(&Head,&Tail,21);
	InsertFirst(&Head,&Tail,11);
	
	InsertLast(&Head,&Tail,101);
	InsertLast(&Head,&Tail,111);
	Display(Head,Tail);
	printf("\n");
	
	iRet=Count(Head,Tail);
	printf("No of nodes %d ",iRet);
	printf("\n");
	
	DeleteFirst(&Head,&Tail);
	DeleteLast(&Head,&Tail);
	Display(Head,Tail);
	printf("\n");
	
	iRet=Count(Head,Tail);
	printf("No of nodes %d  ",iRet);
	printf("\n");
	InsertFirst(&Head,&Tail,11);
	InsertAtPos(&Head,&Tail,25,3);
	Display(Head,Tail);
	printf("\n");
	
	DeleteAtPos(&Head,&Tail,3);
	Display(Head,Tail);
	
	return 0;
}

void InsertFirst(PPNODE First,PPNODE Last,int No)
{
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->Data=No;
	newn->Next=NULL;
	
	if((*First==NULL)&&(*Last==NULL))
	{
		*First=newn;
		*Last=newn;
	}
	else
	{
		newn->Next=*First;
		*First=newn;
	}
	(*Last)->Next=(*First);
}

void InsertLast(PPNODE First,PPNODE Last,int No)
{
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->Data=No;
	newn->Next=NULL;
	
	if((*First==NULL)&&(*Last==NULL))
	{
		*First=newn;
		*Last=newn;
	}
	else
	{
		(*Last)->Next=newn;
		(*Last)=(*Last)->Next;
	}
	(*Last)->Next=(*First);
}

void Display(PNODE First,PNODE Last)
{
	if((First==NULL)&&(Last==NULL))
	{
		return;
	}
	
	do
	{
		printf("%d\t",First->Data);
		First=First->Next;
	}while(First != Last->Next);
}

int Count(PNODE First,PNODE Last)
{
	int iCnt=0;
	
	if((First==NULL)&&(Last==NULL))
	{
		return -1;
	}
	
	do
	{
		iCnt++;
		First=First->Next;
	}while(First != Last->Next);
	
	return iCnt;
}

void DeleteFirst(PPNODE First,PPNODE Last)
{
	if((*First==NULL)&&(*Last==NULL))
	{
		return;
	}
	else if(*First == *Last)	
	{
		free(First);
		*First=NULL;
		*Last=NULL;
	}
	else
	{
		(*First)=(*First)->Next;
		free((*Last)->Next);
		(*Last)->Next=(*First);
	}
}

void DeleteLast(PPNODE First,PPNODE Last)
{
	PNODE temp=NULL;
	
	if((*First==NULL)&&(*Last==NULL))
	{
		return;
	}
	else if(*First == *Last)
	{
		free(*Last);
		*First=NULL;
		*Last=NULL;
	}
	else
	{
		temp=*First;
		
		while(temp->Next != (*Last))
		{
			temp=temp->Next;
		}
		
		free(*Last);
		*Last=temp;
		(*Last)->Next=(*First);
	}
}

void InsertAtPos(PPNODE First,PPNODE Last,int No,int iPos)
{
	int i=0,iSize=0;
	PNODE temp=NULL;
	PNODE newn=NULL;
	
	iSize=Count(*First,*Last);
	
	if((iPos<1)||(iPos>iSize+1))
	{
		return;
	}
	if(iPos==1)
	{
		InsertFirst(First,Last,No);
	}
	else if(iPos==iSize+1)
	{
		InsertLast(First,Last,No);
	}
	else
	{
		temp=*First;
		
		for(i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		
		newn=(PNODE)malloc(sizeof(NODE));
		newn->Data=No;
		newn->Next=NULL;
		
		newn->Next=temp->Next;
		temp->Next=newn;
	}
}

void DeleteAtPos(PPNODE First,PPNODE Last,int iPos)
{
	PNODE temp1=NULL,temp2=NULL;
	int i=0,iSize=0;
	
	iSize=Count(*First,*Last);
	
	if((iPos<1)||(iPos>iSize))
	{
		return;
	}
	
	if(iPos==1)
	{
		DeleteFirst(First,Last);
	}
	else if(iPos==iSize)
	{
		DeleteLast(First,Last);
	}
	else
	{
		temp1=*First;
		
		for(i=1;i<iPos-1;i++)
		{
			temp1=temp1->Next;
		}
		temp2=temp1->Next;
		temp1->Next=temp2->Next;
		free(temp2);
	}
}

