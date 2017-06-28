#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
	char a[100];
	char b[100];

	cin>>a>>b;
	
	if(abs(strlen(a)-strlen(b))==1){
		if(strlen(b)>strlen(a)){
			int i=0;
			int j=0;
			int count=0;
			while(i<strlen(b)){
				if(a[i]==b[j]){
					i++;
					j++;
				}
				else{
					count++;
					j++;
				}
			}
			if(count>1){
				cout<<"Nope";
			}
			else{
				cout<<"Yeah";
			}
		}
		else{
			int i=0;
			int j=0;
			int count=0;
			while(i<strlen(a)){
				if(a[i]==b[j]){
					i++;
					j++;
				}
				else{
					count++;
					i++;
				}
			}
			if(count>1){
				cout<<"Nope";
			}
			else{
				cout<<"Yeah";
			}			
		}
	}
	else if(strlen(a)==strlen(b)){
		int count=0;
		for(int i=0;i<strlen(a);i++){
			if(a[i]!=b[i]){
				count++;
			}
		}
		if(count<=1){cout<<"Yeah";}
		else{cout<<"nope";}
	}
	else{
		cout<<"Nope";
	}
}