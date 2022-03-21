#include<iostream>
#include<conio.h>
using namespace std;

class doubly_link_list
{
	private:
		struct node
		{
			
			node *next;
			int data;
			node *previous;
		};
		node *head=NULL;
		node *tail=NULL;
	public:
		void insert(int &n);
		void display();
		void r_display();
		void sum_count_avg();
		void search(int &n);
		void update(int &n);
};


int main()
{
	int choice;
	int n;
	doubly_link_list l;
	p:
	
	cout<<"\n\n\n\t\t\tControl Panal";
	cout<<"\n\t1.Insert";
	cout<<"\n\t2.Display";
	cout<<"\n\t3.Reverse_Display";
	cout<<"\n\t4.Sum,Count,Average";
	cout<<"\n\t5.Search";
	cout<<"\n\t6.Exit";
	cout<<"\n\n\n\tEnter your choice:  ";
	cin>>choice;
	switch(choice) {
	case 1:
		system("cls");
		cout<<"\n\n\t\t\t\tInsert Record: ";
        cout<<"\n\n\tEnter the value: ";
        cin>>n;
		l.insert(n);
		break;		
	case 2:
		l.display();
	    break;
	case 3:
		l.r_display();
	    break; 
	case 4:
	     l.sum_count_avg();
	     break;
	case 5:
		system("cls");
		cout<<"\n\n\t\t\t\tSearch Record: ";
        cout<<"\n\n\tEnter the value: ";
        cin>>n;
		l.search(n);
		break;
	case 6:
		system("cls");
		cout<<"\n\n\t\t\t\tUpdate Record: ";
        cout<<"\n\n\tEnter the value: ";
        cin>>n;
		l.update(n);
		break;
	case 7:
		exit(0);
	default:
		cout<<"\n\n\t\tYou have Entered the wrong input-------invalid value..."<<endl;
		
    }
    getch();
	goto p;	
}

void doubly_link_list::insert(int &n)
{
	node *new_node = new node;
	new_node -> data = n;
	new_node-> next=NULL;
	new_node-> previous=NULL;
	
	if(head==NULL)
	{
		head=new_node;
		tail=new_node;
	}
	else
	{
		tail -> next = new_node;
		new_node->previous=tail;
		tail=new_node;
	}
}

void doubly_link_list::display()
{
	
	system("cls");
	cout<<"\n\n\t\t\t\tDisplay Record: ";
	if(head==NULL)
	{
		cout<<"\n\n\tDoubly linked list is empty.....";
		
	}
	else
	{
		node *ptr=head;
		while(ptr!=NULL)
		{
			
			cout<<"\n\nValue = "<<ptr->data;
			ptr=ptr->next;
		}
    }	
}

void doubly_link_list::r_display()
{
	system("cls");
	cout<<"\n\n\t\t\t\tReverse Display Record: ";
	if(head==NULL)
	{
		cout<<"\n\n\tDoubly linked list is empty.....";
		
	}
	else
	{
		node *ptr=tail;
		while(ptr!=NULL)
		{
			
			cout<<"\n\nValue = "<<ptr->data;
			ptr=ptr->previous;
		}
    }
}

void doubly_link_list::sum_count_avg()
{
	int count=0,sum=0;
	float avg;
	if(head==NULL)
	{
		cout<<"\n\n\tlinked list is  empty... ";
	}
	else
	{
		
		node *ptr=head;
	    while(ptr!=NULL)
	   {
		 count++;
		 sum=sum+ptr->data;
		 ptr=ptr->next;
	   }
	   avg=sum/count;
	   cout<<"\n\n\tTotal Node = "<<count;
	   cout<<"\n\n\tSum = "<<sum;
	   cout<<"\n\n\tAverage = "<<avg;
	}
}

void doubly_link_list::search(int &n)
{
	if(head==NULL)
	{
		cout<<"\n\n\tlinked list is  empty... ";
	}	
	
	int count=0;
	node *ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==n)
		{
			cout<<"\n\n\tValue "<<n<<" is found..";
			count++;
			break;
		}
		ptr=ptr->next;
	}
	if(count=0)
	{
		cout<<"\n\n\tValue "<<n<<" not found..";
	}
}

void doubly_link_list::update(int &n)
{
	if(head==NULL)
	{
		cout<<"\n\n\tLinked list is Empty....";
	}
	else
	{
		int count=0;
		node *ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->data==n)
			{
				cout<<"\n\n\tValue is "<<n<<" is found Successfully....";
				int a;
				cout<<"\n\n\tEnter Your new value: ";
				cin>>a;
				ptr->data=a;
				cout<<"\n\n\t\tYour value has been updated successfully....";
				count++;
				break;
			}
			ptr=ptr->next;
		}
		if(count==0)
		{
			cout<<"\n\n\tValue is "<<n<<" is  not found ";
		}
	}
}





