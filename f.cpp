#include<iostream>
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
int main()
{
	int n;
	s_link_list s;
	
	cout<<"Enter the Value: ";
	cin>>n;
	s.insert(n);
}
