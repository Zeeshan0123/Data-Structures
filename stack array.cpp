#include<iostream>
using namespace std;

class stack
{
	private:
		int *top;
		int *stk;
		int size;
	public:
	stack()
	{

		cout<<"Enter the size of array";
		cin>>size;
		top=NULL;
		stk=new int[size];
		
	}	
	
	void push();
	void pop();
	void display();
};

int main()
{
	
/*	
	stack st;
	st.push();
	st.push();
	st.push();
	st.display(); */
	
	int choice;
	stack st;
	p:
	cout<<"press 1 to Push:"<<endl;
	cout<<"press 2 to Pop:"<<endl;
	cout<<"press 3 to Display:"<<endl;
	cout<<"Enter Choice:";
	cin>>choice;
	switch(choice)
	{
	  case 1:
	  	 st.push();
	  	 break;
	  case 2:
	  	 st.pop();
	  	 break;
	  case 3:
	  	 st.display();
	  	 break;
	  	
	default:
		cout<<"Wrong input";
		break;
}
goto p;
	
}

void stack::push()
{
	if(top == stk+size-1)
	{
		cout<<"OverFlow";
		return;
	}
	if(top==NULL)
	{
	  top=stk;
	  cout<<"Enter value:";
	  cin>>*top;
	  return;
	}
	top++;
	cout<<"Enter value:";
	cin>>*top;
	
	
}

void stack::pop()
{
	if(top==NULL)
	{
		cout<<"Stack under flow";
		return;
	}
	if(top==stk)
	{
		cout<<"pop is completed";
		top=NULL;
		return;
	}
	top--;
	cout<<"pop is completed";
	
}

void stack::display()
{
	while(top!=NULL)
	{
		cout<<*top<<endl;
		pop();
	}
}
