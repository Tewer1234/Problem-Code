//Uva 586 - Instant Complexity
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
int ans[1000],ary[1000],coef[1000];
void O(int level,string times){
	int num,temp[100]={0},tempNum;
	string s,c;
	while (cin>>s){
		if (s=="LOOP"){
			cin>>c;
			if (c=="n"){
				O(level+1,c);
			}else{
				O(level,c);
			}
			for (int i=0;i<=10;i++){
				temp[i]+=coef[i];
			}
			memset(coef,0,sizeof(coef));
		}else if (s=="OP"){
			cin>>num;
			temp[level]+=num;
		}else{
			if (times!="n"){
				tempNum=0;
				for (int i=0;i<times.size();i++){
					tempNum=tempNum*10+(times[i]-'0');
				}
				for (int i=level;i<=10;i++){
					temp[i]*=tempNum;
				}
			}
			for (int i=0;i<=10;i++){
				coef[i]+=temp[i];
			}
			return;
		}
	}
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n,cnt;
	string s;          
	cin>>n;
	for (int cases=1;cases<=n;cases++){	                                    
		memset(coef,0,sizeof(coef));
		cnt=0;
		string begin;
		cin>>begin;
		O(0,"1");
		cout<<"Program #"<<cases<<"\n";
		cout<<"Runtime = ";
		int first=1;
		for (int i=10;i>=0;i--){
			if (coef[i]){
				cnt++;
				ans[cnt]=i;
			}
		}
		if (!cnt) cout<<0;
		else{
			for (int i=1;i<=cnt;i++){
				if (i!=1) cout<<"+";
				if ((ans[i]==0) or (coef[ans[i]]!=1)) cout<<coef[ans[i]];
				if (ans[i] and coef[ans[i]]!=1) cout<<"*n";
				else if (ans[i]!=0 and coef[ans[i]]==1) cout<<"n";
				if (ans[i] and ans[i]!=1) cout<<"^"<<ans[i];
			}
		}
		cout<<"\n\n";
//		for (int i=0;i<=10;i++) cout<<ary[i]<<" ";
//		cout<<"\n";
	}
	return 0;
}
