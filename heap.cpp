#include <iostream>

using namespace std;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

class Heap{
public:
	int *arr;
	int capacity;
	int heapsize;

	Heap(int cap){
		capacity = cap;
		heapsize = 0;
		arr = new int[cap];
	}
	int getMin(){
		return arr[0];
	}

	void heapify(){
		for(int i=(heapsize-1)/2;i>=0;i--){
			if(2*i+1<heapsize && arr[2*i+1]<arr[i]){
				swap(&arr[2*i+1],&arr[i]);
			}
			if(2*i+2<heapsize && arr[2*i+2]<arr[i]){
				swap(&arr[2*i+2],&arr[i]); 
			}
		}
	}

	void decreaseKey(int idx,int newval){
		arr[idx] = newval;
		heapify();
	}

	int extractMin(){
		int root = arr[0];
		arr[0] = arr[heapsize-1];
		heapsize--;
		heapify();
		return root;
	}

	void deleteKey(int idx){
		decreaseKey(idx,-32768);
		extractMin();
	}

	void insertKey(int ele){
		heapsize++;
		arr[heapsize-1] = ele;
		heapify();
	}

	void printHeap(){
		for(int i=0;i<heapsize;i++){
			cout<<arr[i]<<"\t";
		}
	}

};


int main(void){
    Heap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout<<endl;
    h.printHeap();
    return 0;
}