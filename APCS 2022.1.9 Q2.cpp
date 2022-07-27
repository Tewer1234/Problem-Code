//https://zerojudge.tw/ShowProblem?problemid=f606
//APCS 2022.1.9 Q2
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
long long int s[100000],t[100000];
int order[100000],lost_round[100000],win[100000],lost[100000];
int wcnt,lcnt;
int comp(int p1,int p2,long long int s1,long long int s2,long long int t1,long long int t2){
	long long int total,total1;
	total=s1*t1;
	total1=s2*t2;
	if (total>=total1){
		s[p1]=s1+(s2*t2)/(2*t1);
		t[p1]=t1+(s2*t2)/(2*s1);
		s[p2]=s2+(s2/2);
		t[p2]=t2+(t2/2);
		return 1;
	}else{
		s[p2]=s2+(s1*t1)/(2*t2);
		t[p2]=t2+(s1*t1)/(2*s2);
		s[p1]=s1+(s1/2);
		t[p1]=t1+(t1/2);
		return 2;
	}
}
int solve(int n,int m){
	int minus=0;
	for (int i=1;i<=n;i+=2){
		wcnt++;
		if (i+1<=n){
			if (comp(order[i],order[i+1],s[order[i]],s[order[i+1]],t[order[i]],t[order[i+1]])==1){
				win[wcnt]=order[i];
				lost_round[order[i+1]]++;
				if (lost_round[order[i+1]]<m){
					lcnt++;
					lost[lcnt]=order[i+1];
				}else{
					minus++;
				}
			}else{
				win[wcnt]=order[i+1];
				lost_round[order[i]]++;
				if (lost_round[order[i]]<m){
					lcnt++;
					lost[lcnt]=order[i];
				}else{
					minus++;
				}
			}
		}else{
			win[wcnt]=order[i];
		}
	}
	return minus;
}
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>s[i];
	}
	for (int i=1;i<=n;i++){
		cin>>t[i];
	}
	for (int i=1;i<=n;i++){
		cin>>order[i];
	}
	int left=n;
	while (left>1){
//		for (int i=1;i<=left;i++){
//			cout<<order[i]<<" ";
//		}
//		cout<<"\n";
//		for (int i=1;i<=n;i++){
//			cout<<s[i]<<" ";
//		}
//		cout<<"\n";
//		for (int i=1;i<=n;i++){
//			cout<<t[i]<<" ";		
//		}
//		cout<<"\n";
		wcnt=lcnt=0;
		left-=solve(left,m);
		for (int i=1;i<=wcnt;i++){
			order[i]=win[i];
		}
		for (int i=wcnt+1,j=1;i<=wcnt+lcnt;i++,j++){
			order[i]=lost[j];
		}
//		for (int i=1;i<=n;i++){
//			cout<<lost_round[i]<<" ";
//		}
//		cout<<"\n\n";
	}
	cout<<order[1]<<"\n";
	return 0;
}
