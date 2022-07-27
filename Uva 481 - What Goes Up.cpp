//Uva 481 - What Goes Up
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;	
long long int ary[100000000],t[10000000],cnt;
long long int backtrack[10000000],tback[10000000];
void backtrackPrint(int last){
	int temp;
	if (last==0){
		return;
	}else{
		temp=backtrack[last];
		backtrackPrint(temp);
		cout<<ary[last]<<"\n";
		return;
	}
}
int main(){
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
	int n,len=0;
//	backtrack.resize(1000);
	memset(t,0x7f,sizeof(t));
	while (cin>>n){
		cnt++;
		ary[cnt]=n;
	}
	t[0]=LLONG_MIN;
	tback[0]=0;
	backtrack[0]=0;
	int l,r,mid,temp;
	for (int i=1;i<=cnt;i++){
		l=0,r=cnt;
		while (l<=r){
			mid=(l+r)/2;
			if (ary[i]>t[mid]){
				temp=mid+1;
				l=mid+1;
			}else{
				r=mid-1;		
			}
		}
		t[temp]=ary[i];
		tback[temp]=i;
		backtrack[i]=tback[temp-1];
		
	}
//	for (int i=1;i<=cnt;i++) cout<<t[i]<<" ";
//	cout<<"\n";
	
	int last=0;
	for (int i=1;i<=cnt;i++){
		l=1,r=i,temp=1;
		while (l<=r){
			mid=(l+r)/2;
			if (ary[i]>=t[mid]){
				temp=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		if (len<=temp){
			last=i;
			len=temp;
		}
	}
	cout<<len<<"\n-\n";
//	for (int i=0;i<=cnt;i++) cout<<backtrack[i]<<" ";
//	cout<<"\n";
	backtrackPrint(last);	
	return 0;
}
​
