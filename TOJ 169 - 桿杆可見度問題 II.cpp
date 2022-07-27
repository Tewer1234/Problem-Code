#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;
int height[100000000],amount[100000000],top;
//void clear(){
//	top=0;
//}
bool is_empty_stack(){
	return top==0;
}
int main(){
	int n,input;
	while (cin>>n){
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);	
		top=0;
		for (int i=1;i<=n;i++){
			cin>>input;
			int count=0;
			while (!is_empty_stack() and input>height[top-1]){
				count+=amount[top-1];
				top--;
			}
			amount[top]=count+1;
            height[top]=input;
			cout<<amount[top]-1;
			if (i!=n) cout<<" ";
			top++;
		}
		cout<<"\n";
	}
	return 0;
}
Collapse




