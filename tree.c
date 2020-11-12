#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int Data;
	struct node* lChild;
	struct node* rChild;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE,int);
void InOrder(PNODE);
void PreOrder(PNODE);
void PostOrder(PNODE);
//int Count(PNODE);
//Bool Search(PNODE,int);

int main()
{
	PNODE Head = NULL;
	int iRet=0;
	Insert(&Head ,11);
	Insert(&Head ,21);
	Insert(&Head ,7);
	
printf("\nInOrder");
	InOrder(Head);
	printf("\nPreOrder");
	PreOrder(Head);
	
	printf("\nPostOrder");
	PostOrder(Head);
	
	// iRet=Count(Head);
	// printf("Count is %d",iRet);
	
	return 0;
}

void Insert(PPNODE First,int No)
{
	PNODE newn=NULL;
	PNODE temp=NULL;
	
	newn =(PNODE)malloc(sizeof(NODE));
	newn->Data= No;
	newn->lChild=NULL;
	newn->rChild=NULL;
	
	if(*First==NULL)
	{
		*First=newn;
	}
	else
	{
		temp = *First;
		
		while(1)
		{
			if(No>temp->Data)
			{
				if(temp->rChild==NULL)
				{
					temp->rChild=newn;
					break;
				}
				temp=temp->rChild;
			}
			else if(No<temp->Data)
			{
				if(temp->lChild==NULL)
				{
					temp->lChild=newn;
					break;
				}
				temp=temp->lChild;
			}
			else
			{
				free(newn);
				break;
			}
		}
	}
}
void InOrder(PNODE First)
{
	if(First != NULL)
	{
		InOrder(First->lChild);
		
		printf("%d\t",First->Data);
		InOrder(First->rChild);
	}
}

void PreOrder(PNODE First)
{
	if(First != NULL)
	{
		
		printf("%d\t",First->Data);
		PreOrder(First->lChild);
		PreOrder(First->rChild);
	}
}

void PostOrder(PNODE First)
{
	if(First != NULL)
	{
		
		PostOrder(First->lChild);
		PostOrder(First->rChild);
		
		printf("%d\t",First->Data);
	}
}

	