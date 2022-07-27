//TOJ 575 - vector 連習
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector <int> v[1000005];
int temp[1000005];
void merge(int pos,int p,int q){
	int mid=(p+q)/2;
	if (p>=q) return;
	for (int i=p,j=mid+1,k=p;k<=q;k++){
		if (i>mid){
			temp[k]=v[pos][j];
			j++;
		}else if (j>q){
			temp[k]=v[pos][i];
			i++;
		}else if (v[pos][i]<v[pos][j]){
			temp[k]=v[pos][i];
			i++;
		}else{
			temp[k]=v[pos][j];
			j++;
		}
	}
	for (int i=p;i<=q;i++){
		v[pos][i]=temp[i];
	}
}
void msort(int pos,int p,int q){
	int mid=(p+q)/2;
	if (p>=q) return;
	msort(pos,p,mid);
	msort(pos,mid+1,q);
	merge(pos,p,q);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k,a,b;
	cin>>n>>k;
	for (int i=1;i<=k;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=1;i<=n;i++){
		msort(i,0,v[i].size()-1);
		for (int j=0;j<v[i].size();j++){
			cout<<v[i][j];
			if (j!=v[i].size()-1) cout<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
