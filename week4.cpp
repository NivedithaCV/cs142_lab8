//BINARY SEARCH TREE
//library
#include<iostream>
using namespace std;

class Node		//node
{	public:
	int data;	//value
	Node*left;	//pounter to left
	Node*right;	//pointer to right
	Node*parent;
	Node(int value)	//default constructor
	{
		data=value;
		left=NULL;
		right=NULL;
		parent=NULL;
	}
};

class bst			//defining binary search tree
{	public:
	Node*root;int i=0;		//head of bst
	bst()
	{
		root=NULL;
		int i=0;	
	}
	
	void insert(int value)	//function to insert
	{
	insertHelper(root,value);
	}
	void insertHelper(Node*curr,int value)	//inserting function
	{
	
		if(curr==NULL)		//checks if end
		{
			curr=new Node(value);//insert node
			
			if(root==NULL)	//checks if root is null
			root=curr;	//if assigns
			return;
		}
		else		//if not end
		{
			if(value<curr->data)	//checks the value is less than current nodes data
			{
				if(curr->left==NULL)	//if end new node inserted
				{curr->left=new Node(value);
				curr->left->parent=curr;}
				else 
				insertHelper(curr->left,value);	//else move to left
			}
			else				//checks if greater than or equal to
			{
				if(curr->right==NULL)	//checks if node is leaf
				{curr->right=new Node(value);	//inserting node at the leaf
				curr->right->parent=curr;}
				else
				insertHelper(curr->right,value);	//else moves to right
			}
		}
	}

	void display()		//display function
	{
		display2(root);	//recurtion
		cout<<endl;
	}
	void display2(Node*curr)
	{	
		if(curr==NULL)		//if at the end stop
		return;
		display2(curr->left);	//moving to the left and prints
		cout<<curr->data<<" ";
		display2(curr->right);	//move to the right
		
	}
	void search(int value){
         
	if(search2(root,value)==NULL)	//checks if any node is returned
	cout<<"not found"<<endl;
	else
	cout<<"found"<<endl;
    	}
    	Node*search2(Node *curr, int value)
	{
        // Are you the value? or Are you NULL?  if yes return curr
       // if(curr == NULL || curr->data == value ) return curr;
        // else you search in right or left. 
        // Left
        if(value < curr->data)  search2(curr->left, value);
        // Right
        else  search2(curr->right, value);
	 if(curr == NULL || curr->data == value )
	 return curr;
        // else 
    	}

	int find_min(int value)			//to execute the funnction
	{
				Node *current = search1(root,value);
			    Node *min = find_min1(current);	//finding min of the subtree with value
			    cout<<endl;
			    return min->data;
		}
		Node *find_min1(Node *current)
		{
			if(current->left == NULL ){	//checking through left edge
				return current;	
			}
			else if(current == NULL){
			    return NULL;
			}
			else return find_min1(current->left);
		}

		void deleteNode(int value)
		{
			Node *current = search1(root,value);	//find node to delt
				
			if(current == NULL){	//if no value
				return;
			}
			else{
		
				if(current->left == NULL){ 
					replace_at_parent1(current->right,current);
				}
				else if(current->right == NULL){ 
					replace_at_parent1(current->left,current);
				}
				else{ 
					Node *temp = find_min1(current->right);
					
					if(current == root){		//if the value is in root
						current->data = temp->data;
						replace_at_parent1(NULL,temp);
						delete temp;
					}
					else{				//for rest cases
						replace_at_parent1(temp,current);	//replace temp parent
						temp->parent = current->parent;	//replacing temp left
						temp->left = current->left;
						delete temp;
					}
				}
			}
			
		}
		
		void replace_at_parent(int valu,int valu){
			Node *rep = search1(root,valu);
			Node *current = search1(root,valu);
			replace_at_parent1(current,rep);
		}
		void replace_at_parent1(Node *A,Node *B){
			
			if(B == root){			//if roo replaces
				root = A;	
			}
			else if(A == root){		//if root is replaced
				return;
			}
			else{	//finding position of node that current will replace
				if(B->data > B->parent->data){
					if(A == NULL){
						B->parent->right = NULL;
					}
			        	else{	//the step of replacing
			            		B->parent->right = A;
    						if(A->data > A->parent->data){
    							A->parent->right = NULL;
    						}
						
    						else A->parent->left = NULL;	//current parent child will be null
			
    						A->parent = B->parent;
			        	}
					
				}
				else{
					if(A == NULL){
						B->parent->left = NULL;
					}
					else{	//the step of replacing
						
						B->parent->left = A;
						if(A->data>A->parent->data){
							A->parent->right = NULL;
						}
						
						else A->parent->left = NULL;	//current parent child will be null
						
						A->parent = B->parent;       
					}
				
				}
}	
	int count()
	{
			return count2(root);			
	}
		int count2(Node *current)
			{
			
			if(current == NULL){	//no elements
				return 0;
			}
			else{	//adding 
				return count2(current->left)+1+count2(current->right);
			}
}

	int height(){
		    return height1(root);
		}
		int height1(Node* current){  
            if (current == NULL)  
                return 0;  
            else
            {  
                int leftheight = height1(current->left);  
                int rightheight = height1(current->right); 
                if (leftheight > rightheight)  
                    return(leftheight + 1);  
                else return(rightheight + 1);  
            } 
} 
	
};

int main()		//main function
{
	 bst b1;Node*n;
	b1.insert(3);
	b1.insert(5);
	b1.insert(6);
	b1.insert(45);
	b1.insert(10);
	b1.insert(8);
	b1.insert(5);
	b1.insert(4);
	b1.display();	//call for the dispaly function
	b1.search(45);	//call for the search function	
	b1.findmin(3);
	b1.replace_at_parent(6,4);
	b1.deleteNode(8);
	cout<<"no of elements"<<count()<<endl;
	cout<<"height"<<height()<<endl;
	return 0;
}
