//TOJ 472
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int ary[10000000];
long long int lside[10000000],rside[10000000];
int temp[10000000];
void merge(int p,int q){
	int mid=(p+q)/2;
	int l=0,r=q-mid;
	for (int i=p,j=mid+1,k=p;k<=q;k++){
		if (i<=mid and (j>q or ary[i]<ary[j])){
			temp[k]=ary[i];
			i++;
			rside[temp[k]]+=r;
			l++;
		}else{
			temp[k]=ary[j];
			j++;
			lside[temp[k]]+=l;
			r--;
		}
	}
	for (int i=p;i<=q;i++){
		ary[i]=temp[i];
	}
}
void msort(int l,int r){
	int mid=(l+r)/2;
	if (l==r) return;
	msort(l,mid);
	msort(mid+1,r);
	merge(l,r);
}
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	long long int ans=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ary[i];
	}
	msort(1,n);
//	for (int i=1;i<=n;i++) cout<<ary[i]<<" ";
//	cout<<"\n";
	for (int i=1;i<=n;i++){
//		cout<<lside[i]<<" "<<rside[i]<<"\n";
		ans+=(lside[i]*rside[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
