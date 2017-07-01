#include <iostream>

using namespace std;

class Node{

	int data;
	Node *left;
	Node *right;

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
			cout<<root->getData()<<"\t";
			inorder(root->getRight());
		}

	}
};

int height(Node *root){
	if(root==NULL){
		return 0;
	}
	return std::max(height(root->getLeft()),height(root->getRight()))+1;
}

Node* construct(int a[],int l, int r){

	if(l>r){return NULL;}
	int mid = (l+r)/2;
	Node *n = new Node(a[mid]);
	n->setLeft(construct(a,l,mid-1));
	n->setRight(construct(a,mid+1,r));
	return n;

}

	void inorder(Node *root){

		if(root!=NULL){
			inorder(root->getLeft());
			cout<<root->getData()<<"\t";
			inorder(root->getRight());
		}

	}

int main(void){

	int n;
	cin>>n;
	int a[n];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	Node *root = construct(a,0,n-1);
	inorder(root);

	cout<<endl<<height(root)<<endl;
	return 0;
}