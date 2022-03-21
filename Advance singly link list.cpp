#include<iostream>
#include<conio.h>
using namespace std;

class list
{
	struct node
	{
		int info;
		node *next;
	};
	node *head=NULL;
	
	public:
		void insert();
		void display();
		void del();
};

int main()
{
	list l;
	p:
	system("cls");
	int choice;
	cout<<"\n\nEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
	    case 1:
	    	system("cls");
	    	cout<<"\n\nInsert Record:";
	    	l.insert();
	    	break;
	    case 2:
	    	system("cls");
	    	cout<<"\n\n\tDisplay Record:";
	    	l.display();
	    	break;
	    case 3:
	    	system("cls");
	    	cout<<"\n\n\tDelete Record:";
	    	l.del();
	    	break;
	    case 4:
	    	exit(0);
		default:
			system("cls");
			cout<<"\n\nWrong input:....";
	}
	getch();
	goto p;
	
}

void list::insert()
{
  node*new_node=new node;
  new_node->next=NULL;
  
  if(head==NULL)
  {
  	
  	head=new_node;
  	cout<<"\n\n\tEnter your value: ";
  	cin>>new_node->info;
  	return;	
  }
  else
  {
  	int key,count=0;
  	node *tem,*tem1;
  	
  	cout<<"\n\n\tEnter your Exact node value to insert data after that node value: ";
  	cin>>key;
  	tem=head;
  	while(tem!=NULL)
	  {
	  	if(tem->info==key)
		  {
		  	count++;
		  	if(tem->next==NULL)
			  {
			  	tem1=new_node;
			  	cout<<"\n\n\tYour value is Matched Successfully Now enter your new node value:  ";
			  	cin>>tem1->info;
			  	tem1->next=NULL;
			  	tem->next=tem1;
			  	break;
			  }
			  else
			  {
			  	tem1=new_node;
			  	cout<<"\n\n\tYour value is Matched Successfully Now enter your new node value:  ";
			  	cin>>tem1->info;
			  	tem1->next=tem->next;
			  	tem->next=tem1;
			  	break;
			  }
		  }
	  	tem=tem->next;
	  }
	  if(count==0)
	  {
	  	cout<<"\n\n\tValue doesnot Matched...";
	  }
	  
  }
}

void list::display()
{
 if(head==NULL)
 {
 	cout<<"\n\n\tLinked List is Empty...";
 }
 else
 {
 	node *tem=head;
 	while(tem!=NULL)
	 {
	 	cout<<"\n\tValue = "<<tem->info;
	 	tem=tem->next;
	 }
	 
 }	
}


void list::del()
{
 int key,count=0;
 node *tem=head;
 node *tem1=NULL;
 if(head==NULL)
 {
 	cout<<"\n\n\tLinked List is Empty...";
 }
 else
 {
 cout<<"\n\n\tEnter a Exact value to delete  ";
 cin>>key;
 while(tem!=NULL)
 {
 	if(tem->info==key)
	 {
	 	count++;
	 	head=tem->next;
	 	tem1=tem;
	 	
	 	delete tem1;
	 	cout<<"\n\n\t Record is Deleted Successfully...";
	 	break;
	 }
 	else if(tem->next->info==key)
	 {
	 	count++;
	 	tem1=tem->next;
	 	tem->next=tem1->next;
	 	delete tem1;
	 	cout<<"\n\n\t Record is Deleted Successfully...";
	 	break;
	 }
	 tem=tem->next;
 }	
 if(count==0)
	  {
	  	cout<<"\n\n\tValue doesnot Matched...";
	  	
	  }
 
 }
 
}







