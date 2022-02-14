#include<iostream>
#include<conio.h>
using namespace std;
class s_link_list
{
	private:
		struct node
		{
			node *p_address;
			int data;
			node *n_address;
			
		};
		node *tail=NULL;
		node *head=NULL;
	public:
		void insert(int &n);
		void display();
		
		
};

void s_link_list::insert(int &n)
{
  node *new_node = new node	;
  new_node->data=n;
  new_node->n_address=NULL;
  new_node->p_address=NULL;
  if(head==NULL)
  {
  	head=new_node;
  	tail=new_node;
  }
  else
	{
		tail->n_address=new_node;
        new_node->p_address=tail;
		tail=new_node;
	}
}

void s_link_list::display()
{
 system("cls");
 if(head==NULL)
 {
   cout<<"\n\nLink list is Empty...";	
 }
 else
 {
 	cout<<"\n\t\tDisplay Record:";
 	node *p=head;
 	while(p!=NULL)
	 {
	 	cout<<"\n\t Value = "<<p->data;
	 	p=p->n_address;
	 }
 }	
}



int main()
{
	int n,choice;
	s_link_list s;
	p:
	cout<<"\n\n\n\t\t\tControl Panal";
    cout<<"\n\t1.  Insert";
	cout<<"\n\n\t2.  Display";
	cout<<"\n\n\t3.  Exit";
	cout<<"\n\n\t\tEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			system("cls");
			cout<<"Enter the Value: ";
	        cin>>n;
	        s.insert(n);
			break;
		case 2:
			s.display();
			break;
		case 3:
			exit(0);
		default:
			cout<<"\n\nInvalid value........";		
	}
	getch();
	goto p;	
	
	
	
	
	
}
