#include <iostream>
#include <cstring>
using namespace std;

char* compress(char* a,char* b){
	//char b[100];
	int idx=0;
	int i=0;
	while(i<strlen(a)){
		int count = 0;
		int j=i+1;
		while(a[i]==a[j]){
			count++;
			j++;
		}
		b[idx]=a[i];
		idx++;
		if(count>0){
			b[idx]=count+1+'0';
			idx++;
		}				
		i+=count+1;

	}
	return b;
}

int main(void){

	char a[100];
	char b[100];
	cin>>a;
	compress(a,b);
	cout<<b;
}