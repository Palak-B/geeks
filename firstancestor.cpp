#include <iostream>
#include <stack>
using namespace std;

class Node{

	int data;
	Node *left;
	Node *right;
	int height;

public:

	Node(int data){
		this->data=data;
	}

	void setLeft(Node *left){
		this->left=left;
	}

	void setRight(Node *right){
		this->right=right;
	}

	void setHeight(int height){
		this->height = height;
	}

	int getHeight(){
		return height;
	}

	int getData(){
		return data;
	}

	Node* getLeft(){
		return left;
	}

	Node* getRight(){
		return right;
	}

};

class BST{

	Node *root;

public:

	//BST() = default;

	BST(int rootval){
		root = new Node(rootval);
		root->setRight(NULL);
		root->setLeft(NULL);
	}

	Node* getRoot(){
		return root;
	}

	void insert(int data){
		Node *temp = root;
		Node *newnode = new Node(data);
		while(temp!=NULL){
			if(temp->getData()<data){
				if(temp->getRight()!=NULL){
					temp = temp->getRight();
				}
				else{
					temp->setRight(newnode);
					break;
				}
			}
			else if(temp->getData()>data){
				if(temp->getLeft()!=NULL){
					temp=temp->getLeft();
				}
				else{
					temp->setLeft(newnode);
					break;
				}
			}
		}
	}

	void inorder(Node *root){

		if(root!=NULL){
			inorder(root->getLeft());
			cout<<"At height: "<<root->getHeight()<<"\n"<<root->getData()<<"\n\n";
			inorder(root->getRight());
		}

	}
};

void searchfirst(Node *root,int val,bool *b){

	if(root==NULL){
		return;
	}
	if(root->getData()==val){
		*b = true;
	}
	if(root->getRight()!=NULL){
		searchfirst(root->getRight(),val,b);
	}
	if(root->getLeft()!=NULL){
		searchfirst(root->getLeft(),val,b);
	}
}

void searchsecond(Node *root,int val,bool *b){

	if(root==NULL){
		return;
	}
	if(root->getData()==val){
		*b = true;
	}
	if(root->getRight()!=NULL){
		searchsecond(root->getRight(),val,b);
	}
	if(root->getLeft()!=NULL){
		searchsecond(root->getLeft(),val,b);
	}
}

void fca(Node *root,int first,int second,stack<int> *s){
	bool b1=false;
	bool b2 = false;
	searchfirst(root,first,&b1);
	searchsecond(root,second,&b2);
	if(b1&&b2){
		s->push(root->getData());
	}
	
		if(root->getRight()!=NULL)
			fca(root->getRight(),first,second,s);
		if(root->getLeft()!=NULL)
			fca(root->getLeft(),first,second,s);
	
}

int main(){
	//cout<<"here\n";
	BST *bst = new BST(36);
	bst->insert(19);
	bst->insert(58);
	bst->insert(12);
	bst->insert(25);
	bst->insert(45);
	bst->insert(60);
	bst->insert(75);
	//bst->insert(90);
	//bst->insert(95);
	//cout<<"here\n";
	Node *root = bst->getRoot();
	//cout<<"here";
	stack<int> *s = new stack<int>();
	fca(root,75,58,s);
	cout<<"here\n";
	//s->pop();
	cout<<s->top()<<"\n";

	return 0;
}