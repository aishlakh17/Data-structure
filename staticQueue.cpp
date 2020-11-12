#include<iostream>
using namespace std;

template <class T>
class Queue
{
	private:
		T *Arr;
		int Size;
		int Front;
		int Rare;
		
	public:
		Queue(int);
		~Queue();
		void Enqueue(T);
		T Dequeue();
		void Display();
};

template <class T>
Queue <T> :: Queue(int Length)
{
	this->Size=Length;
	Arr=new T[Size];
	Front = -1;
	Rare = -1;
}

template <class T>
Queue<T> :: ~Queue()
{
	delete []Arr;
}

template <class T>
void Queue<T> :: Enqueue(T No)
{
	if(((Front==0)&&(Rare==Size-1))||(Rare ==(Front-1)%(Size-1)))
	{
		cout<<"Queue is FULL";
		return;
	}
	else if(Front== -1)
	{
		Front=0;
		Rare=0;
		
		Arr[Rare]=No;
	}
	else if((Rare==Size-1)&&(Front != 0))
	{
		Rare=0;
		Arr[Rare]=No;
	}
	else
	{
		Rare++;
		Arr[Rare]=No;
	}
}

template <class T>
T Queue<T> :: Dequeue()
{
	T temp;
	
	if(Front==-1)
	{
		cout<<"Queue is empty";
		return -1;
	}
	
	temp=Arr[Front];
	
	if(Front==Rare)
	{
		Front=-1;
		Rare =-1;
	}
	else if(Front==Size-1)
	{
		Front=0;
	}
	else
	{
		Front++;
	}
	
	return temp;
}

int main()
{
	Queue <int>iObj(4);
	Queue<float>fObj(5);
	
	iObj.Enqueue(11);
	cout<<iObj.Dequeue();
	
	return 0;
	
}