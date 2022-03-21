#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};


class BST
{
 private:
  node *temp,*temp2;
  int var;

public:
	node *root;
BST()
{
  root=temp=temp2=NULL;
}
node* insert(node*&,int);
void traverse(node*);
node* del(node*&,int);
node*find_imd_successor(node*);
int height(node*);
int balance_fact(node*);
node* single_right_rot(node*);
node* single_left_rot(node*);
node* right_left_D_rot(node*);
node* left_right_D_rot(node*);
node* check_balance(node*,int);
};

int main()
{
	BST obj;
	obj.insert(obj.root,96);
	obj.insert(obj.root,21);
	obj.insert(obj.root,10);
	obj.insert(obj.root,20);
	obj.insert(obj.root,15);
	obj.insert(obj.root,5000);
	obj.insert(obj.root,4500);
	obj.insert(obj.root,3000);
	obj.insert(obj.root,4800);         //checks for left subtree
	obj.insert(obj.root,4900);
	obj.insert(obj.root,4600);
	obj.traverse(obj.root);
	obj.del(obj.root,4500);
	obj.del(obj.root,3000);
	obj.del(obj.root,10);
	obj.del(obj.root,4500);
	cout<<endl;
	obj.traverse(obj.root);
}
node* BST::single_right_rot(node*ptr)
{
	node*tem=ptr->right;
	ptr->right=tem->left;
	tem->left=ptr;
	ptr=tem;
	return tem;
}

node* BST::single_left_rot(node*ptr)
{
	node*tem=ptr->left;
	ptr->left=tem->right;
	tem->right=ptr;
	ptr=tem;
	return tem;
}

node* BST::right_left_D_rot(node*ptr)
{
	node*tem=ptr->right;
   ptr->right = single_left_rot(tem);
   cout<<"Right-Left Rotation";
   return single_right_rot(ptr);
}

node* BST::left_right_D_rot(node*ptr)
{
	node*tem=ptr->left;
   ptr->left = single_right_rot(tem);
   cout<<"leftt-right Rotation";
   return single_left_rot(ptr);
}

int BST::height(node*ptr)
{
	if(ptr==NULL)
	{
	  return 0;
	}
	else
	{
		int left=height(ptr->left);
		int right=height(ptr->right);
		if(left>right)
		{
			return left+1;
		}
		else
		{
			return right+1;
		}	
	}	
} 

int BST::balance_fact(node*ptr)
{
	int left=0;
	int right=0;
	if(ptr!=NULL)
	{
		if(ptr->left!=NULL)
		{
			left=height(ptr->left);
		}
		if(ptr->right!=NULL)
		{
			right=height(ptr->right);
		}
	}
	return left-right;
}

node *BST::check_balance(node *tem,int key)
{
	int bal1=balance_fact(tem);
	
		if(bal1==-2)
		{
			if(key<tem->left->data)
			{
				single_right_rot(tem);
				//lft lft case
				
			}
			else
			{
				left_right_D_rot(tem);                                       
				
				//left right case
			}
		}
		if(bal1==2)
		{
			if(key>tem->right->data)
			{
				single_left_rot(tem);	//right right case
			}
			else
		 	{ 
		    	right_left_D_rot(tem);
			              //right left	
			}
		}
		
	
	return tem;
 }
 

node* BST:: insert(node*&ptr,int key)
{
	if(ptr==NULL)
	{
		ptr=new node;
		ptr->left=NULL;
		ptr->right=NULL;
		ptr->data=key;
		return ptr;
	}
	if(key==ptr->data)
	{
		cout<<"\nNumber already exist:";
	}
	else if(key>ptr->data)
	{
		ptr->right=insert(ptr->right,key);
		ptr=check_balance(ptr,key);
	}
	else if(key<ptr->data)
	{
		ptr->left=insert(ptr->left,key);
		ptr=check_balance(ptr,key);
	}
	return ptr;	
}

node* BST::del(node*&ptr,int key)
{
	if(root==NULL)
	{
		cout<<"\nTree doesnot exist Error during deletion";
		return NULL;
	}
	if(ptr==NULL)
	{
		cout<<"\nValue doesnot exist Error during deletion";
		return NULL;
	}
	if(ptr->data==key)
	{
		if(ptr->left==NULL && ptr->right==NULL)
		{
			if(ptr==root)
			{
				root=NULL;
				delete ptr;
				ptr=NULL;
				
			}
			else
			{
			delete ptr;
			ptr=NULL;
			}
		}
		else if(ptr->left==NULL)
		{
		    node*tem=ptr;
			ptr=ptr->right;
			delete tem;
			tem=NULL;
		}
		else if(ptr->right==NULL)
		{
			node*tem=ptr;
			ptr=ptr->left;
			delete tem;
			tem=NULL;
		}
		else
		{
			node*tem=find_imd_successor(ptr->right);
			int new_data=tem->data;
			del(root,tem->data);
			ptr->data=new_data;
		}
	}
	else if(key>ptr->data)
	{
		ptr->right=del(ptr->right,key);
	}
	else if(key<ptr->data)
	{
		ptr->left=del(ptr->left,key);
	}
	                                                  //Checking Balance
	    if(height(ptr->left) - height(ptr->right) == 2)
          {
            // right right case
            if(height(ptr->left->left) - height(ptr->left->right) == 1)                           
                return single_left_rot(ptr);
            // right left case
            else
                 return right_left_D_rot(ptr);
          }
        // If right node is deleted, left case
        else if(height(ptr->left) - height(ptr->right) == -2)
        {
            // left left case
            if(height(ptr->right->right) - height(ptr->right->left) == 1)
                return single_right_rot(ptr);
            // left right case
            else
                return left_right_D_rot(ptr);
        }
        return ptr;
}

node* BST::find_imd_successor(node*find)
{
	if(find->left==NULL)
	{
		return find;
	}
	find_imd_successor(find->left);
}

void BST::traverse(node*ptr)
{
	if(root==NULL)
	{
		cout<<"\nTree is Empty Error during Traversal:";
		return;
	}
	if(ptr->left!=NULL)
	{
		traverse(ptr->left);
	}
	cout<<ptr->data<<" ";
	if(ptr->right!=NULL)
	{
		traverse(ptr->right);
	}
}









