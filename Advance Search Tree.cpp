#include<iostream>
using namespace std;

class binary_tree
{
	
	private:
		struct node
		{
			int data;
			node*left;
			node*right;
		};
	public:
		node *root;
		binary_tree()
		{
			root=NULL;
		}
		void insert(node*,int);
		void display(node*);
		
		node* find_successer(node*,int);
		
		void delete1(node*,int);
};

int main()
{
	binary_tree b;
	b.insert(b.root,96);
	b.insert(b.root,21);
	b.insert(b.root,10);
	b.insert(b.root,20);
	b.insert(b.root,15);
	b.insert(b.root,27);
	b.insert(b.root,28);
	b.insert(b.root,25);
	b.insert(b.root,22);           //checks for right subtree

	
	
	b.insert(b.root,5000);
	b.insert(b.root,4500);
	b.insert(b.root,3000);
	b.insert(b.root,4800);         //checks for left subtree
	b.insert(b.root,4900);
	b.insert(b.root,4600);
	
    
	
	b.display(b.root);
	cout<<endl;
	b.delete1(b.root,4500);
	b.delete1(b.root,3000);
	b.delete1(b.root,10);
	b.delete1(b.root,4500);
	b.display(b.root);
}

void binary_tree::delete1(node *tem,int key)
{
	
    
    
	if(key>tem->data)
	{
		if(tem->right==NULL)
		{
			cout<<"NULL value not found";         
			return;
		}
		if(tem->right->data==key)
		{
	    
		if(tem->right->left==NULL &&tem->right->right==NULL)                               
		{  
		                                                                                                                                                             
		  node *tem1=tem->right;                                           
		  delete tem1;                            //alternative
		  tem1=NULL;
		  tem->right=NULL;
		  return;	
		}
		if(tem->right->left!=NULL && tem->right->right==NULL)
		{
		  node *tem2=tem->right;                                  //itha ponch gya 0
		  tem->right=tem2->left;
		  delete tem2;
		  tem2=NULL;
		  return;	
		}
		if(tem->right->left==NULL && tem->right->right!=NULL)
		{
		  node *tem2=tem->right;                                  //itha ponch gya 1
		  tem->right=tem2->right;
		  delete tem2;
		  tem2=NULL;
		  return;	
		}
		if(tem->right->left!=NULL && tem->right->right!=NULL)
		{
		  node* tem1=tem->right->right;
		  if(tem1->left==NULL)
		  {
		  	tem->right->data=tem1->data;
		  	if(tem1->right!=NULL)
			  { 
			    tem->right->right=tem1->right;      // if tem->right = NULL
			    delete tem1;
			    tem1=NULL;
			    return;
			  }
			  tem->right->right=NULL;
			  delete tem1;
			  tem1=NULL;
			  return;
			  
		  }
		  while(tem1->left->left!=NULL)
		  {
		    tem1=tem1->left;
		  }
		  tem->right->data=tem1->left->data;
		  if(tem1->left->right!=NULL)
		  {
		  	node* tem2=tem1->left;
		  	tem1->left=tem2->right;
		  	delete tem2;
		  	tem2=NULL;
		  	return;
		  }
		  node* tem2=tem1->left;
		  delete tem2;
		  tem2=NULL;
		  tem1->left=NULL;             //hello
		  return;
		}
    }
		if(tem->right!=NULL)
		{
			delete1(tem->right,key);                            
			return;
		}		
	}
	if(key<tem->data)
	{
		if(tem->left==NULL)
		{
			cout<<"NULL value not found";
			return;
		}
		if(tem->left->data==key)
	{
	    
		if(tem->left->left==NULL &&tem->left->right==NULL)                               
		{  
		                                                                                                                                                             
		  node *tem1=tem->left;                                           
		  delete tem1;                            //alternative
		  tem1=NULL;
		  tem->left=NULL;
		  return;	
		}
		if(tem->left->left!=NULL && tem->left->right==NULL)
		{
		  node *tem2=tem->left;                                  //itha ponch gya 0
		  tem->left=tem2->left;
		  delete tem2;
		  tem2=NULL;
		  return;	
		}
		if(tem->left->left==NULL && tem->left->right!=NULL)
		{
		  node *tem2=tem->left;                                  //itha ponch gya 1
		  tem->left=tem2->right;
		  delete tem2;
		  tem2=NULL;
		  return;	
		}
		if(tem->left->left!=NULL && tem->left->right!=NULL)
		{
		  node* tem1=tem->left->right;
		  if(tem1->left==NULL)
		  {
		  	tem->left->data=tem1->data;
		  	if(tem1->right!=NULL)
			  { 
			    tem->left->right=tem1->right;      // if tem->right = NULL
			    delete tem1;
			    tem1=NULL;
			    return;
			  }
			  tem->left->right=NULL;
			  delete tem1;
			  tem1=NULL;
			  return;
			  
		  }
		  while(tem1->left->left!=NULL)
		  {
		    tem1=tem1->left;
		  }
		  tem->left->data=tem1->left->data;
		  if(tem1->left->right!=NULL)
		  {
		  	node* tem2=tem1->left;
		  	tem1->left=tem2->right;
		  	delete tem2;
		  	tem2=NULL;
		  	return;
		  }
		  node* tem2=tem1->left;
		  delete tem2;
		  tem2=NULL;
		  tem1->left=NULL;             //hello
		  return;
		}
    }
		if(tem->left!=NULL)
		{
			
			delete1(tem->left,key);
			return;
		}
	}


}

void binary_tree::insert(node*tem,int key)
{
	if(root==NULL)
	{
		tem=new node;
		root=tem;
		tem->left=NULL;
		tem->right=NULL;
		tem->data=key;
		return;
	}
	if(tem->data==key)
	{
		cout<<"You have entered the same value";
		return;
	}
	if(key>tem->data)
	{
		if(tem->right!=NULL)
		{
			insert(tem->right,key);
			return;
		}
		else
		{
			tem->right=new node;
			tem->right->right=NULL;
			tem->right->left=NULL;
			tem->right->data=key;
			return;
		}
	}
	if(key<tem->data)
	{
		if(tem->left!=NULL)
		{
			insert(tem->left,key);
			return;
		}
		else
		{
			tem->left=new node;
			tem->left->right=NULL;
			tem->left->left=NULL;
			tem->left->data=key;
			return;
		}
	}
}
void  binary_tree::display(node*tem)
{
	if(root==NULL)
	{
		cout<<"NO display";
		return;
	}
	if(tem->left!=NULL)
	{
		display(tem->left);
	}
	cout<<tem->data<<" ";
	if(tem->right!=NULL)
	{
		display(tem->right);
	}
	return;
}
