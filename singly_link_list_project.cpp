#include<iostream>
#include<conio.h>
using namespace std;
class s_link_list
{
	private:
		struct node
		{
			int data;
			node *n_address;
			
		};
		node *head=NULL;
	public:
		void insert(int &n);
		void display();
		void search();
		
};

void s_link_list::insert(int &n)
{
  node *new_node = new node	;
  new_node->data=n;
  new_node->n_address=NULL;
  if(head==NULL)
  {
  	head=new_node;
  }
  else
	{
		node *ptr=head;
		while(ptr->n_address!=NULL)
		{
			ptr=ptr->n_address;
		}
		ptr->n_address=new_node;
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

void s_link_list::search()
{
	int n,count=0;
  cout<<"\n\nSearch Record:";
  cout<<"\nEnter Value: ";
  cin>>n;
  node *ptr=head;
  while(ptr!=NULL)
  {
  	if(n==ptr->data)
	  {
	  	cout<<"\n\nValue is: "<<n;
	  	cout<<"\nSearch Record Seccessfully.......";
	  	getch();
	  	count++;
	  }
	ptr=ptr->n_address; 
  }
  
  if(count==0)
  {
  	cout<<"Value not found: "<<n;
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
	cout<<"\n\n\t3.  Search";
	cout<<"\n\n\t4.  Exit";
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
			s.search();
		case 4:
			exit(0);
		default:
			cout<<"\n\nInvalid value........";		
	}
	getch();
	goto p;	
	
	
	
	
	
}
