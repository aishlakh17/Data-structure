#include<iostream>
using namespace std;

typedef struct node
{
	int Data;
	struct node* Next;
	struct node* Prev;
}NODE,*PNODE;

class DoublyCLL
{
	private:
	PNODE Head;
	PNODE Tail;
	int Size;
	
	public:
		DoublyCLL();
		~DoublyCLL();
		
		void InsertFirst(int);
		void InsertLast(int);
		void InsertAtPos(int,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		void DisplayF();
		void DisplayB();
		int Count();
};

int main()
{
	DoublyCLL dobj1;
	DoublyCLL *dobj2 = NULL;
	dobj2 = new DoublyCLL();
	
	dobj1.InsertFirst(11);
	dobj1.InsertLast(21);
	dobj1.InsertLast(51);
	dobj1.InsertLast(111);
	dobj2->InsertFirst(101);
	dobj2->InsertLast(201);
	dobj2->InsertLast(301);
	dobj1.DisplayF();
	cout<<"\n";
	dobj1.DisplayB();
	cout<<"\n";
	dobj2->DisplayF();
	cout<<"\n";
	
	dobj2->DisplayB();
	cout<<"\n";
	int iRet=0;
	
	iRet=dobj1.Count();
	cout<<"dobj1 count :"<<iRet;
	cout<<"\n";
	iRet=dobj2->Count();
	cout<<"dobj2 count :"<<iRet;
	
	delete dobj2;
	dobj1.InsertAtPos(51,3);
	cout<<"\n";
	dobj1.DisplayF();
	dobj1.DeleteAtPos(3);
	cout<<"\n";
	dobj1.DisplayB();
	
	return 0;
}

DoublyCLL :: DoublyCLL()
{
	this->Head = NULL;
	this->Tail=NULL;
	this->Size=0;
}

void DoublyCLL :: InsertFirst(int No)
{
	PNODE newn = NULL;
	newn = new NODE;
	
	newn->Data=No;
	newn->Next=NULL;
	newn->Prev=NULL;
	
	if((this->Head ==NULL)||(this->Tail==NULL))
	{
		Head= newn;
		Tail=newn;
	}
	else
	{
		newn->Next=Head;
		Head->Prev=newn;
		Head=newn;
	}
	Tail->Next=Head;
	Head->Prev=Tail;
	Size++;
}

void DoublyCLL :: InsertLast(int No)
{
	PNODE newn = NULL;
	newn = new NODE;
	
	newn->Data=No;
	newn->Next=NULL;
	newn->Prev=NULL;
	
	if((this->Head ==NULL)||(this->Tail==NULL))
	{
		Head= newn;
		Tail=newn;
	}
	else
	{
		Tail->Next=newn;
		newn->Prev=Tail;
		Tail=newn;
	}
	Tail->Next=Head;
	Head->Prev =Tail;
	Size++;
}

int DoublyCLL :: Count()
{
	return Size;
}

void DoublyCLL :: InsertAtPos(int iNo,int iPos)
{
	if((iPos>Size+1)||(iPos < 1))
	{
		return;
	}
	
	if(iPos==1)
	{
		InsertFirst(iNo);
	}
	else if(iPos==Size+1)
	{
		InsertLast(iNo);
	}
	else
	{
		PNODE temp = Head;
		PNODE newn = new NODE;
		
		newn->Data=iNo;
		newn->Next=NULL;
		newn->Prev=NULL;
		
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		newn->Next=temp->Next;
		temp->Next->Prev=newn;
		temp->Next=newn;
		newn->Prev = temp;
		Size++;
	}
}

void DoublyCLL :: DisplayF()
{
	PNODE temp =Head;
	
	for(int i=1;i<=Size;i++)
	{
		cout<<temp->Data<<"\t";
		temp=temp->Next;
	}
	temp=Head;
	cout<<"\n";
	do
	{
		cout<<temp->Data<<"\t";
		temp=temp->Next;
	}while(temp != Tail->Next);
	
}

void DoublyCLL :: DisplayB()
{
	PNODE temp = Tail;
	
	for(int i=1;i<=Size;i++)
	{
		cout<<temp->Data<<"\t";
		temp =temp->Prev;
	}
	cout<<"\n";
	temp=Tail;
	do{
		cout<<temp->Data<<"\t";
		temp=temp->Prev;
	}while(temp != Head->Prev);
}

void DoublyCLL :: DeleteFirst()
{
	if((Head==NULL)&&(Tail==NULL))
	{
		return;
	}
	else if(Head==Tail)
	{
		delete Head;
		Head = NULL;
		Tail=NULL;
		Size--;
	}
	else
	{
		Head=Head->Next;
		delete Head->Prev;
		Tail->Next=Head;
		Head->Prev = Tail;
		Size--;
	}
}

void DoublyCLL :: DeleteLast()
{
	if((Head==NULL)&&(Tail==NULL))
	{
		return;
	}
	else if(Head==Tail)
	{
		delete Tail;
		Head= NULL;
		Tail= NULL;
	}
	else
	{
		Tail = Tail->Prev;
		delete Tail->Next;
		Tail->Next=Head;
		Head->Prev =Tail;
	}
	Size--;
}

void DoublyCLL :: DeleteAtPos(int iPos)
{
	if((iPos<1)||(iPos>Size))
	{
		return;
	}
	
	if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==Size)
	{
		DeleteLast();
	}
	else
	{
		PNODE temp=Head;
		
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		
		temp->Next= temp->Next->Next;
		delete temp->Next->Prev;
		temp->Next->Prev=temp;
		Size--;
	}
}

DoublyCLL :: ~DoublyCLL()
{
	PNODE temp =Head;
	for(int i=1;i<=Size;i++)
	{
		temp=Head;
		Head=Head->Next;
		delete temp;
	}
}
	
	
	




	
		
	