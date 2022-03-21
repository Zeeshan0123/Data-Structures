#include<iostream>
using namespace std;

class binary_tree
{
	
	private:
		struct node
		{
			int data;
			node *left;
			node *right;
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
	b.insert(b.root,10);
	b.insert(b.root,20);
	b.insert(b.root,7);
	b.insert(b.root,9);
	b.insert(b.root,8);
	b.insert(b.root,15);
	b.insert(b.root,5);
    
	
	b.display(b.root);
	cout<<endl;
	b.delete1(b.root,7);
	b.display(b.root);
	b.delete1(b.root,20);
	cout<<endl;
	b.display(b.root);
	b.delete1(b.root,9);
	cout<<endl;
	b.display(b.root);
}

//void binary_tree::find_successer(node *tem,int key)
//{
//	if(root==NULL)
//	{
//		cout<<"Tree is empty";
//		return;
//	}
//	if(tem->data==key)
//	{
//		cout<<"Yes value is found "<<tem->data;
//		if(tem->right!=NULL)
//		{
//			node *tem2=tem->right;
//			while(tem2->left!=NULL)
//			{
//				tem2=tem2->left;
//			}
//			cout<<"Successor is"<<tem2->data;
//		}
//		else
//		{
//			void binary_tree::new_search(node *tem)
//			{
//		       if(root==NULL)
//	            {
//		          cout<<"Tree is empty";
//		          return;
//	            }
//        	if(tem->info==key)
//	        {
//		    cout<<"Yes value is found "<<tem->info;
//		    return;
//	        }
//         	if(tem->info>key)
//	        {
//		        if(tem->right==NULL)
//		        {
//			        cout<<"NULL value not found";
//			        return;
//		        }
//		        if(tem->right!=NULL)
//		        {
//			        search(tem->left,key);
//			        return;
//		        }		
//	        }
//	        if(tem->info<key)
//         	{
//		       if(tem->left==NULL)
//		        {
//			        cout<<"NULL value not found";
//			        return;
//		        }
//		        if(tem->left!=NULL)
//	         	{
//		         	search(tem->left,key);
//			        return;
//		        }
//	        }
//				
//	        }				
//		}
//			
//	}
//
//	if(tem->data>key)
//	{
//		if(tem->right==NULL)
//		{
//			cout<<"NULL value not found";
//			return;
//		}
//		if(tem->right!=NULL)
//		{
//			find_successer(tem->right,key);
//			return;
//		}		
//	}
//	if(tem->data<key)
//	{
//		if(tem->left==NULL)
//		{
//			cout<<"NULL value not found";
//			return;
//		}
//		if(tem->left!=NULL)
//		{
//			find_successer(tem->left,key);
//			return;
//		}
//	}	
//}
//node* Binary_Tree::find_successor(int key){
//	node *temp = search(key , root);
//	node* successor=NULL;
//	if(temp==NULL){
//		cout<<"Key not Found "<<endl;
//		return NULL;
//	}
//		if(temp->right != NULL){
//			temp = temp->right;
//		while(temp->left != NULL){
//		temp=temp->left;
//		}
//		return temp;
//	}
//	
//	else{
//		node *temp2 = root;   
//		while(temp2 != temp){
//		              
//		if(temp2->info > temp->info){
//			successor = temp2;
//			temp2 = temp2->left;
//		}
//		else{
//			temp2 =  temp2->right;
//		}
//		
//	}
//	return successor;
//}
void binary_tree::delete1(node *tem,int key)
{
	if(root==NULL)
	{
		cout<<"Tree is empty";
		return;
	}
	if(tem->right->data==key)
	{
		if(tem->right->left!=NULL && tem->right->right!=NULL)
		{
		  node* tem1=tem->right->right;
		  while(tem1->left->left!=NULL)
		  {
		    tem1=tem1->left;
		  }
		  tem->right->data=tem1->left->data;
		  node* tem2=tem1->left;
		  if(tem2->right!=NULL)
		  {
		  	tem1->left=tem2->right;
		  	delete tem2;
		  	tem2=NULL;
		  	return;
		  }
		  delete tem2;
		  tem2=NULL;
		  return;
		}
		if(tem->right->left==NULL &&tem->right->right!=NULL)
		{
		  node *tem1=tem->right;
		  tem->right=tem1->right;
		  delete tem1;
		  tem1=NULL;
		  return;	
		}
		if(tem->right->left!=NULL && tem->right->right==NULL)
		{
		   node*tem1=tem->right;
		   tem->right=tem1->left;
		   delete tem1;
		   tem1=NULL;
		  return;	
		}
		if(tem->right->left==NULL &&tem->right->right==NULL)
		{
		  node *tem1=tem->right;
		  delete tem1;
		  tem1=NULL;
		  tem->right=NULL;
		  return;	
		}
	}
	
	if(tem->left->data==key)
	{
		if(tem->left->left!=NULL && tem->left->right!=NULL)
		{
		  node* tem1=tem->left->right;
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
		
		if(tem->left->left!=NULL &&tem->left->right==NULL)
		{
		  node *tem2=tem->right;
		  tem->left=tem2->right;
		  delete tem2;
		  tem2=NULL;
		  return;	
		}
		if(tem->left->left==NULL &&tem->left->right!=NULL)
		{
		   node*tem2=tem->left;
		   tem->left=tem2->right;
		   delete tem2;                   //hello2
		   tem2=NULL;
		   return;	
		}
		if(tem->left->left==NULL &&tem->left->right==NULL)                               
		{                                                                                                                                                                
		  node *tem1=tem->left;                                           
		  delete tem1;
		  tem1=NULL;
		  tem->right=NULL;
		  return;	
		}
		  
		
		
	}
	
	
	
	if(key>tem->data)
	{
		if(tem->right==NULL)
		{
			cout<<"NULL value not found";
			return;
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


