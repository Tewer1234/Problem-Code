//Uva 10702 - Travelling Salesman
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int ary[1001][1001],valid[1000],dp[1001][1001];
int main() {
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int c,s,e,t;
	while (cin>>c>>s>>e>>t){
		memset(dp,0xc0,sizeof(dp));
		if (!c and !s and !e and !t) break;
		for (int i=1;i<=c;i++){
			for (int j=1;j<=c;j++){
				cin>>ary[i][j];
			}
		}
		for (int i=1;i<=e;i++){
			cin>>valid[i];
		}
		for (int i=1;i<=c;i++){
			if (s!=i){
				dp[1][i]=ary[s][i];
			}
		}
		for (int i=2;i<=t;i++){
			for (int j=1;j<=c;j++){
				for (int k=1;k<=c;k++){
					if (dp[i-1][j]>=0 and j!=k){
						dp[i][k]=max(dp[i][k],dp[i-1][j]+ary[j][k]);
					}
				}
			}
		}
//		for (int i=1;i<=t;i++){
//			for (int j=1;j<=c;j++){
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
		int ans=0;
		for (int i=1;i<=e;i++){
			ans=max(ans,dp[t][valid[i]]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
