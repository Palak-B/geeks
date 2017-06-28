#include <iostream>
#include <cstdlib>
using namespace std;

struct listNode{
	int data;
	struct listNode *next;
};

struct listcom
{
	struct listNode *header;
	
};

struct graph{

	int V;
	struct listcom *array;

};
struct graph* createGraph(int V){

	struct graph* newgraph = (struct graph*)malloc(sizeof(struct graph));
	newgraph->V = V;
	struct listcom* array = (struct listcom*)malloc(V*sizeof(struct listcom));
	newgraph->array = array;

	for(int i=0;i<V;i++){
		newgraph->array[i].header=NULL;
	}

	return newgraph;
}
void createEdge(struct graph *graph,int src, int dest)
{
	struct listNode *newnode = (struct listNode*)malloc(sizeof(struct listNode));
	newnode->data = dest;
	newnode->next = graph->array[src].header;
	graph->array[src].header = newnode;

	struct listNode *newnode2 = (struct listNode*)malloc(sizeof(struct listNode));
	newnode2->data = src;
	newnode2->next = graph->array[dest].header;
	graph->array[dest].header = newnode2;
};

void printGraph(struct graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct listNode* pCrawl = graph->array[v].header;
        cout<<"\n Adjacency list of vertex "<<v<< "\n head ";
        while (pCrawl)
        {
            //printf("-> %d", pCrawl->data);
            cout<<"-> "<<pCrawl->data;
            pCrawl = pCrawl->next;
        }
        cout<<endl;
    }
}

int main(void){
	int V=5;
	struct graph* graph = createGraph(V);
	createEdge(graph,0,1);
	createEdge(graph,0,4);
	createEdge(graph,1,2);
	createEdge(graph,1,3);
	createEdge(graph,1,4);
	createEdge(graph,2,3);
	createEdge(graph,3,4);
	printGraph(graph);
}