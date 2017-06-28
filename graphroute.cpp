#include <iostream>

using namespace std;

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

class Graph{
	int V;
	//LList *lists;
	bool directed;
	bool *visited;
public:

	LList *lists;

	Graph(int V,bool directed){
		this->V=V;
		visited = new bool[V];
		lists = new LList[V];
		this->directed = directed;
		for(int i=0;i<V;i++){
			lists[i].insert(i);
		}
		for(int i=0;i<V;i++){
			visited[i]=false;
		}		
	}

	void insert(int src, int dest){
		lists[src].insert(dest);
		if(!directed){
			lists[dest].insert(src);
		}
	}

	void printGraph(){
		for(int i=0;i<V;i++){
			cout<<"Vertices connected to "<<i<<endl;
			lists[i].printlist();
			cout<<endl<<endl;
		}
	}

	void DFS(Node *root){

		if(root==NULL){
			return;
		}

		cout<<root->data<<"\t";

		visited[root->data]=true;

		Node *tmp = lists[root->data].getHead();

		while(tmp!=NULL){
			
			if(visited[tmp->data]==false){
				
				DFS(tmp);
			}
			tmp = tmp->getNext();
		}

	}

};

int main(){
	Graph *graph = new Graph(7,true);
	graph->insert(0,1);
	graph->insert(0,2);
	graph->insert(0,3);
	graph->insert(1,5);
	graph->insert(1,6);
	graph->insert(6,4);
	graph->insert(4,1);
	graph->insert(2,4);
	graph->insert(3,2);
	graph->insert(3,4);
	graph->printGraph();
	cout<<"\n\n\n";
	graph->DFS(graph->lists[0].getHead());
}
