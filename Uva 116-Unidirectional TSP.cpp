//Uva 116-Unidirectional TSP
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct node{
	int value,pos;
};
bool comp (node a,node b){
	if (a.value<b.value) return true;
	else if (a.value==b.value){
		if (a.pos<b.pos) return true;
	}
	return false;
}
long long int ary[1000][1000],dp[1000][1000],from[1000][1000];
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int m,n;
	while (cin>>m>>n){
		memset(dp,0,sizeof(dp));
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				cin>>ary[i][j];
			}
		}
		for (int i=0;i<m;i++){
			dp[i][n-1]=ary[i][n-1];
		}
		for (int i=n-1;i>=0;i--){
			for (int j=0;j<m;j++){
				node index[10];
				index[0].pos=(j-1+m)%m;
				index[0].value=dp[index[0].pos][i+1];
				index[1].pos=j;
				index[1].value=dp[index[1].pos][i+1];
				index[2].pos=(j+1)%m;
				index[2].value=dp[index[2].pos][i+1];
				sort(index,index+3,comp);
				dp[j][i]=ary[j][i]+dp[index[0].pos][i+1];
				from[j][i]=index[0].pos;
			}
		}
		int pos;
		long long int ans=LLONG_MAX;
		for (int i=0;i<m;i++){
			ans=min(ans,dp[i][0]);
		}
		for (int i=0;i<m;i++){
			if (dp[i][0]==ans){
				pos=i;
				break;
			}
		}
		cout<<pos+1;
		for (int i=0;i<n-1;i++){
		  if (i+1!=n) cout<<" ";
			cout<<from[pos][i]+1;
			pos=from[pos][i];
		// 	if (n>=2 and i!=n-2) cout<<" ";
		}
		cout<<"\n";
//		for (int i=0;i<m;i++){
//			for (int j=0;j<n;j++){
//				cout<<from[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
//		cout<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
} 
