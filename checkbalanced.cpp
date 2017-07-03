#include <iostream>
#include <cmath>
#include <stdlib.h>
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

int height(Node *root,bool &flag){
	if(root==NULL){
		return 0;
	}
	int leftheight = height(root->getLeft(),flag);
	int rightHeight = height(root->getRight(),flag);

	//int nodeh = std::max(height(root->getLeft()),height(root->getRight()))+1;
	int nodeh = std::max(leftheight,rightHeight)+1;
	int diff = std::abs(leftheight-rightHeight);;
	if(diff>1){
		flag = false;
	}
	
	//root->setHeight(nodeh);
	return nodeh; 
}

int main(int argc, char const *argv[])
{
	bool flag = true;

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

	Node *root = bst->getRoot();
	height(root,flag);

	if(!flag){
		cout<<"Not balanced!!";
	}
	else{
		cout<<"Good job! Balanced!";
	}
	//bst->inorder(root);
	return 0;
}

