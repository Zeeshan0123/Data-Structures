#include<iostream>
using namespace std;

struct node
{
	int data;
	node*left;
	node*right;
	int left_bit;
	int right_bit;
	
};
class thread
{
	public:
		node*dummy;
		node*root;
	thread() 
	{
		
		root=NULL;
		dummy=new node;
		dummy->left=dummy;
		dummy->right=dummy;
		dummy->left_bit=0;
	    dummy->right_bit=1;
	}
	void insert(node*,int);
	void display(node*);

};
int main()
{
	thread obj;
	obj.insert(obj.root,60);
	obj.insert(obj.root,10);
	obj.insert(obj.root,20);
	obj.insert(obj.root,7);
	obj.insert(obj.root,9);
	obj.insert(obj.root,8);
	obj.insert(obj.root,15);
	obj.insert(obj.root,5);
	obj.display(obj.root);
}

void  thread::display(node*tem)
{
	if(root==NULL)
	{
		cout<<"NO display";
		return;
	}
	if(tem->left_bit!= 0)
	{
		display(tem->left);
	}
	cout<<tem->data<<" ";
	if(tem->right_bit!=0)
	{
		display(tem->right);
	}
	return;
}

void thread::insert(node*tem,int key)
{
	if(root==NULL)
	{
		root=new node;
		root->data=key;
		root->left_bit=0;
		root->right_bit=0;
		dummy->left=root;
		dummy->left_bit=1;
		root->left=dummy;
		root->right=dummy;
		return;
	}
	
	if(tem->data==key)
	{
		cout<<"Duplicate";
		return;
	}
	
	if(key<tem->data)
	{
		if(tem->left_bit==0)
		{
			node*n=new node;
			n->data=key;
			n->left=tem->left;
			n->left_bit=tem->left_bit;
			n->right=tem;
			n->right_bit=0;
			tem->left=n;
			tem->left_bit=1;
			return;
		}
		insert(tem->left,key);
	}
	
	if(key>tem->data)
	{
		if(tem->right_bit==0)
		{
			node*n=new node;
			n->data=key;
			n->right=tem->right;          //means points to dummy
			n->right_bit=tem->right_bit;  
			n->left=tem;
			n->left_bit=0;
			tem->right=n;
			tem->right_bit=1;
			return;
		}
		insert(tem->right,key);
	}
	
} 














