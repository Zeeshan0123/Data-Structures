#include<iostream>
#include<conio.h>
using namespace std;

class Lk_queue
{
	private:
		
	struct node
	{
		int info;
		node *next;
	};
	node *front=NULL;
	node *rear=NULL;
	
	public:
		void Enqueue();
		void Display();
		void Dequeue();
};

int main()
{
	int choice;
	Lk_queue l;
	p:
	cout<<"\n\tEnter your Choice:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			l.Enqueue();
			break;
		case 2:
			l.Dequeue();
			break;
		case 3:
			l.Display();
			break;
		default:
			cout<<"Wrong input.";
			break;
	}
	getch();
	goto p;
	
	
}

void Lk_queue::Enqueue()
{
	node *new_node = new node;
	new_node->next=NULL;
	cout<<"Enter value:";
	cin>>new_node->info;
	if(front==NULL && rear==NULL)
	{
		front=new_node;
		rear=new_node;
		return;
	}
	rear->next=new_node;
	rear=new_node;
	
}

void Lk_queue::Display()
{
	node *tem=front;
	if(front==NULL && rear==NULL)
	{
		cout<<"Link list is empty: ";
		return;
	}
	while(tem!=NULL)
	{
			
         	cout<<tem->info<<" ";
         	tem=tem->next;
	  	
	}
	
}

void Lk_queue::Dequeue()
{
	node *tem=NULL;
	if(front==rear)
	{
		delete front;
		front=NULL;
		rear=NULL;
		return;
	}
	tem=front;
	front=front->next;
	delete tem;
}











