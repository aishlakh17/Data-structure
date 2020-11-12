#include<iostream>
#include<malloc.h>
using namespace std;

template <class T>
struct node
{
	T Data;
	struct node *Next;
};

template <class T>
class Queue
{
	private:
		struct node<T> *Head;
		struct node<T> *Tail;
		
	public:
		Queue();
		void Enqueue(T);
		T Dequeue();
		void Display();
};

template <class T>
Queue <T>::Queue()
{
	Head=NULL;
	Tail=NULL;
}

template <class T>
void Queue<T> :: Enqueue(T No)
{
	struct node<T> *newn=NULL;
	
	newn=(struct node<T>*)malloc(sizeof(struct node<T>));
	
	newn->Data=No;
	newn->Next=NULL;
	
	if((Head==NULL)&&(Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		Tail->Next=newn;
		Tail=Tail->Next;
	}
}

template <class T>
T Queue<T> :: Dequeue()
{
	if((Head== NULL)&&(Tail==NULL))
	{
		return -1;
	}
	
	if(Head==Tail)
	{
		T temp;
		temp=Head->Data;
		free(Head);
		Head=NULL;
		Tail=NULL;
		
		return temp;
	}
	else
	{
		T temp;
		temp=Head->Data;
		struct node<T> *ptr =NULL;
		ptr=Head;
		Head =Head->Next;
		free(ptr);
		return temp;
	}
}

template <class T>
void Queue<T> :: Display()
{
	struct node<T> *temp=Head;
	
	while(temp != NULL)
	{
		cout<<"\t";
		cout<<temp->Data;
	
		temp=temp->Next;
	}
	cout<<"\n";
}

int main()
{
	Queue <int> iObj;
	Queue<char> cObj;
	
	iObj.Enqueue(11);
	
	iObj.Enqueue(21);
	
	iObj.Enqueue(51);
	
	cout<<iObj.Dequeue();
	iObj.Display();
	
	cObj.Enqueue('P');
	cObj.Enqueue('Q');
	cObj.Enqueue('R');
	
	cObj.Display();
	
	return 0;
}
	