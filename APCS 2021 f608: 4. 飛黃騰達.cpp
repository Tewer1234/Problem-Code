//APCS 2021 f608: 4. 飛黃騰達
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int ary[1000005],dp[1000005];
struct node{
	int x,y;
};
node coords[10000000];
bool comp(node a,node b){
	if (a.x<b.x) return true;
	else if (a.x==b.x){
		if (a.y<b.y) return true;
	}
	return false;
}
int binarySearch(int p,int q,int k){
	int pos=-1;
	while (p<=q){
		int mid=(p+q)/2;
		if (dp[mid]>k){
			pos=mid;
			q=mid-1;
		}else{
			p=mid+1;
		}
	}
	return pos;
}
int main() {
	memset(dp,0x3f,sizeof(dp));
	dp[0]=-1;
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>coords[i].x>>coords[i].y;
	}
	sort(coords+1,coords+n+1,comp);
	for (int i=1;i<=n;i++){
		ary[i]=coords[i].y;
	}
	int ans=0,k;
	for (int i=1;i<=n;i++){
		k=binarySearch(0,n,ary[i]);
		if (k!=-1) dp[k]=ary[i];
	}
	for (int i=1;i<=n;i++){
		int p=1,q=i,temp=1;
		k=ary[i];
		while (p<=q){
			int mid=(p+q)/2;
			if (dp[mid]<=k){
				temp=mid;
				p=mid+1;
			}else{
				q=mid-1;
			}
		}
		ans=max(ans,temp);
	}
	cout<<ans;
	return 0;
}
