#include <iostream>

using namespace std;

void swap(int *a,int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

int main(void){
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}



}
