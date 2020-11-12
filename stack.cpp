#include<iostream>
using namespace std;

class stack
{
	private :
		int *Arr;
		int iSize;
		int Top;
		
	public :
		stack(int No=5)
		{
			this->iSize=No;
			this->Top = -1;
			this->Arr = new int[iSize];
		}
		
		~stack()
		{
			delete[]Arr;
		}
		
		void Push(int value)
		{
			if(Top == iSize-1)
			{
				return;
			}
			Top++;
			Arr[Top]=value;
		}
		
		int Pop()
		{
			if(Top == -1)
			{
				cout<<"stack is empty";
				return 0;
			}
			else
			{
				int No=Arr[Top];
				Top--;
				return No;
			}
		}
};

int main()
{
	stack sobj1;
	stack sobj2(3);
	
	sobj2.Push(11);
	sobj2.Push(21);
	sobj2.Push(51);
	sobj2.Push(101);
	
	cout<<sobj2.Pop()<<"\t";
	cout<<sobj2.Pop()<<"\t";
	cout<<sobj2.Pop()<<"\t";
	cout<<sobj2.Pop()<<"\t";
	
	return 0;
}