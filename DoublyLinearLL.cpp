

#include<iostream>
using namespace std;

typedef struct node
{
	int Data;
	struct node *Next;
	struct node *Prev;
}NODE,*PNODE;

class DoublyLL
{
	private:
		PNODE Head;
		int Size;
		
	public:
		DoublyLL();
		~DoublyLL();
		
		void DisplayF();
		int Count();
		void InsertFirst(int);
		void InsertLast(int);
		void InsertAtPos(int,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		void DisplayB();
};

int main()
{
	DoublyLL dobj1;
	DoublyLL dobj2;
	dobj1.InsertFirst(51);
	dobj1.InsertFirst(21);
	dobj1.InsertFirst(11);
	dobj1.InsertLast(101);
	
	dobj1.DisplayF();
	cout<<"\n";
	dobj1.DisplayB();
	cout<<"\n"<<dobj1.Count()<<"\n";
	dobj2.InsertFirst(20);
	dobj2.InsertFirst(10);
	
	dobj2.DisplayF();
	cout<<"\n"<<dobj2.Count()<<"\n";
	dobj1.DeleteAtPos(3);
	cout<<"\n";
	dobj1.DisplayF();
	
	dobj2.DeleteFirst();
	cout<<"\n";
	dobj2.DisplayF();
	cout<<"\n";
	dobj2.DisplayB();
	dobj2.DeleteAtPos(1);
	dobj1.InsertAtPos(31,2);
	return 0;
}

DoublyLL :: DoublyLL()
{
	this->Head = NULL;
	this->Size = 0;
}

void DoublyLL :: InsertFirst(int No)
{
	PNODE newn = NULL;
	newn = new NODE;
	
	newn->Data = No;
	newn ->Next = NULL;
	newn ->Prev = NULL;
	
	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		newn-> Next = Head;
		newn -> Prev = newn;
		Head = newn;
	}
	Size++;
}

void DoublyLL :: InsertLast(int No)
{
	PNODE newn = NULL;
	newn = new NODE;
	 
	newn ->Data = No;
	newn->Next = NULL;
	newn ->Prev = NULL;
	
	if(this -> Head == NULL)
	{
		Head = newn;
	}
	else
	{
		PNODE temp = Head;
		
		while(temp ->Next + NULL)
		{
			temp = temp ->Next;
		}
		temp ->Next = newn;
		newn ->Prev = temp;
	}
	Size++;
}

void DoublyLL :: DeleteFirst()
{
	if(Head == NULL)
	{
		return;
	}
	else if(Head -> Next == NULL)
	{
		delete Head;
		Head = NULL;
	}
	else
	{
		Head = Head ->Next;
		delete(Head -> Prev);
		Head -> Prev = NULL;
	}
	Size --;
}

void DoublyLL :: DeleteLast()
{
	if(Head == NULL)
	{
		return;
	}
	else if(Head -> Next == NULL)
	{
		delete Head;
		Head = NULL;
	}
	else
	{
		PNODE temp = Head;
		
		while(temp -> Next != NULL)
		{
			temp = temp -> Next;
		}
		temp->Prev->Next = NULL;
		delete temp;
	}
	Size--;
}

int DoublyLL :: Count()
{
	return (this->Size);
}

void DoublyLL :: DisplayF()
{
	PNODE temp =Head;
	
	while(temp != NULL)
	{
			cout<<temp -> Data<<"\t";
			temp=temp -> Next;
	}
}

void DoublyLL :: DisplayB()
{
	PNODE temp = Head;
	
	while(temp -> Next != NULL)
	{
			temp=temp->Next;
	}
	
	while(temp != NULL)
	{
		cout <<temp->Data <<"\t";
		temp=temp->Prev;
	}
	
}

void DoublyLL :: InsertAtPos(int iNo,int iPos)
{
		if((iPos < 1) ||(iPos>Size+1))
		{
			return;
		}
		
		if(iPos == 1)
		{
			this->InsertFirst(iNo);
		}
		else if(iPos == Size+1)
		{
			this->InsertLast(iNo);
		}
		else
		{
			PNODE temp=Head;
			
			for(int i=1;i<iPos-1;i++)
			{
				temp = temp->Next;
			}
			PNODE newn = NULL;
			newn = new NODE;
			
			newn->Data = iNo;
			newn->Next =NULL;
			newn->Prev = NULL;
			
			newn->Next=temp->Next;
			temp->Next->Prev=newn;
			newn->Prev=temp;
			
			Size++;
		}
}

void DoublyLL :: DeleteAtPos(int iPos)
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
		PNODE temp = Head;
		
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		temp->Next = temp->Next->Next;
		delete temp->Next->Prev;
		temp->Next->Prev=temp;
		
		Size--;
	}
}

DoublyLL :: ~DoublyLL()
{
	PNODE temp;
	
	while(Head != NULL)
	{
		temp=Head;
		Head=Head->Next;
		delete temp;
	}
}
			
	