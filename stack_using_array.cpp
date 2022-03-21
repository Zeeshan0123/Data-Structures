#include<iostream>
#include<conio.h>
using namespace std; 

class stack_array
{
	int *a;
	int top;
	int capacity;
	public:
		
		stack_array()
		{
			int cap;
			cout<<"\n\n\tEnter the capacity of Array for stack:";
		    cin>>cap;
		    this->capacity=cap;
     		a = new int[capacity];
			int top=-1;
			
		}
		void push();
		void pull();
		
};

int main()
{
	
	stack_array a;
	
	p:
  int choice;
	cout<<"\n\nEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
	    case 1:
	    	system("cls");
	    	cout<<"\n\nPush Data:";
	    	a.push();
	    	break;
	    case 2:
	    	cout<<"\n\nPull Data:";
	    	a.pull();
	    	break;
	    case 3:
	    	exit(0);
		default:
			system("cls");
			cout<<"\n\nWrong input:....";
	}
	getch();
	goto p;	
}

void stack_array::push( )
{
	
	if(top==capacity-1)
	{
		cout<<"\n\tStack is overflow";	
		return;
	}
	else
	{
		int data;
		cout<<"\n\tEnter your data:";
		cin>>data;
		top++;
		a[top]=data;
		
	}
}

void stack_array::pull()
{
	if(top==-1)
	{
		cout<<"\n\tStack is downflow";
		return;
	}
	int res=a[top];
	top--;
	cout<<"Poped element is:"<<res;
	
}
