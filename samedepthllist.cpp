#include <iostream>
#include <queue>

using namespace std;


class TreeNode{

	int data;
	TreeNode *left;
	TreeNode *right;

public:

	TreeNode(int data){
		this->data=data;
	}

	void setLeft(TreeNode *left){
		this->left=left;
	}

	void setRight(TreeNode *right){
		this->right=right;
	}

	int getData(){
		return data;
	}

	TreeNode* getLeft(){
		return left;
	}

	TreeNode* getRight(){
		return right;
	}

};

class BST{

	TreeNode *root;

public:

	//BST() = default;

	BST(int rootval){
		root = new TreeNode(rootval);
		root->setRight(NULL);
		root->setLeft(NULL);
	}

	TreeNode* getRoot(){
		return root;
	}

	void insert(int data){
		TreeNode *temp = root;
		TreeNode *newnode = new TreeNode(data);
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

	void inorder(TreeNode *root){

		if(root!=NULL){
			inorder(root->getLeft());
			cout<<root->getData()<<"\t";
			inorder(root->getRight());
		}

	}
};


class Node{
public:
	int data;
	Node *next;
	bool visited;

	void setData(int data){
		this->data = data;
	}
	void setNext(Node* anext){
		next = anext;
	}
	Node* getNext(){
		return next;
	}
};

class LList{

	Node* head;

public:

	LList(){
		head = NULL;
	}
	void insert(int data){

		Node* newnode = new Node();
		newnode->setData(data);
		newnode->setNext(NULL);		
		//cout<<newnode->data<<endl;;
		Node *tmp = head;

		if(head==NULL){

			head = newnode;
			head->setNext(NULL);
			//cout<<head->data<<endl;
		}
		else{
			while(tmp->getNext()!=NULL){
				tmp = tmp->getNext();
			}
			tmp->setNext(newnode);
		}
	}

	Node* getHead(){
		return head;
	}

	void printlist(){
		if(head==NULL){
			cout<<"List is empty!!";
		}
		else{
			Node* tmp = head;
			while(tmp->getNext()!=NULL){
				cout<<tmp->data<<" ->";
				tmp = tmp->getNext();
			}
			cout<<tmp->data;
		}
	}


};


void sameDepthll(TreeNode *root,int level,LList *list){
	if(level==1){
		list->insert(root->getData());
	}
	else{
		if(root->getLeft()!=NULL)sameDepthll(root->getLeft(),level-1,list);
		if(root->getRight()!=NULL)sameDepthll(root->getRight(),level-1,list);
	}
}

void sameDepthllprint(TreeNode *root,int level){
	if(level==1){
		cout<<root->getData()<<endl;
	}
	else{
		if(root->getLeft()!=NULL)sameDepthllprint(root->getLeft(),level-1);
		if(root->getRight()!=NULL)sameDepthllprint(root->getRight(),level-1);
	}
}

int main(){
	BST *bst = new BST(36);
	bst->insert(19);
	bst->insert(12);
	bst->insert(25);
	bst->insert(58);
	bst->insert(45);
	bst->insert(60);
	bst->insert(75);
	TreeNode *root = bst->getRoot();
	//bst->inorder(root);
	//cout<<"\n\n";
	LList *list = new LList[4];

	//sameDepthllprint(root,4);


	for(int i=0;i<4;i++){
		sameDepthll(root,i+1,list+i);
		list[i].printlist();
		cout<<endl;
	}

}