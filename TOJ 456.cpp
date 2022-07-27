//TOJ 456
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector <long long int> v[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,w,h,x=0,y=0;
	long long int ans=LLONG_MIN,temp=0;
	cin>>n>>m>>h>>w;
	v[0].resize(m*2);
	for (int i=1;i<=n;i++){
		v[i].resize(m*2);
		for (int j=1;j<=m;j++){
			cin>>v[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			v[i][j]+=v[i][j-1];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			v[i][j]+=v[i-1][j];
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++){
//			cout<<v[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			temp=0;
			if ((i+h-1>=1 and i+h-1<=n) and (j+w-1>=1 and j+w-1<=m)){
				temp=v[i+h-1][j+w-1]-(v[i-1][j+w-1]+v[i+h-1][j-1])+v[i-1][j-1];
				if (temp>ans){
				  x=i;
				  y=j;
				  ans=temp;
				}else if (temp==ans){
				  if (x<i or (x==i and y<j)){
				  	x=i;
				  	y=j;
				  }
				}
			}
		}
	}
	cout<<x-1<<" "<<y-1<<" "<<ans<<"\n";
	return 0;
}

//1 2 3 4
//2 4 8 6
//1 2 3 4
//
//
//1 2 3 4
//3 6 11 10
//4 8 14 14
//
//
//1 3 6 10
//2 6 14 20
//1 3 6 10
//
//1 3 6 10
//3 9 20 30
//4 12 26 40


