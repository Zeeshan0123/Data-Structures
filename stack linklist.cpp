#include<iostream>
using namespace std;

class stack
{
	private:
		
		struct node
		{
			int info;
			node *next;
		};
		node *top=NULL;
		node *tem=NULL;
		
	public:
	
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
  node *new_node=new node;
  if(top==NULL)
  {
  	top=new_node;
  	top->next=NULL;
  	cout<<"Enter the Data:";
  	cin>>top->info;
	  return;
  }	
  
  tem=new_node;
  cout<<"Enter the Data:";
  cin>>tem->info;
  tem->next=top;
  top=tem;
  
}

void stack::pop()
{
	if(top==NULL)
	{
		cout<<"Stack under flow"<<endl;
		return;
	}
	
	tem=top;
	top=top->next;
	delete tem;
	tem=NULL;
	
	
}

void stack::display()
{
	if(top==NULL)
	{
		cout<<"Stack under flow"<<endl;
		return;
	}
	while(top!=NULL)
	{
		cout<<top->info ;
		cout<<endl;
		pop();
	}
}
