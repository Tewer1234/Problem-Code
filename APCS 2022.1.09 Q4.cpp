//APCS 2022/1/9 Q4
//https://zerojudge.tw/ShowProblem?problemid=h084
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
long long int h[10000000],w[10000000];
bool check(int n,int k,long long int num){
	int pos=1,flag=1,poster=1,cnt=0;
	while (flag){
		if (h[pos]<num) cnt=0;
		else{
			cnt++;
			if (cnt==w[poster]){
				cnt=0;
				poster++;
				if (poster>k){
					flag=0;
					break;
				}
			}
		}
		pos++;
		if (pos>n) break;
	}
	if (!flag) return true;
	else return false;
	
}
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n,k;
	long long int p=LLONG_MAX,q=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>h[i];
		p=min(p,h[i]);
		q=max(q,h[i]);
	}
	for (int i=1;i<=k;i++){
		cin>>w[i];
	}
	long long int ans=0;
	while (p<=q){
		long long int mid=(p+q)/2;
		if (check(n,k,mid)){
			p=mid+1;
			ans=max(ans,mid);
		}else{
			q=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
