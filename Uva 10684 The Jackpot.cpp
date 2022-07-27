//Uva 10684 The Jackpot
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int ary[100000],dp[100000];
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n;
	while (cin>>n and n){
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++){
			cin>>ary[i];
		}
		for (int i=1;i<=n;i++){
			dp[i]=max(0,dp[i-1])+ary[i];
		}
		int ans=INT_MIN;
		for (int i=1;i<=n;i++){
			ans=max(ans,dp[i]);
		}
		if (ans<=0) cout<<"Losing streak.\n";
		else cout<<"The maximum winning streak is "<<ans<<".\n";
	}
	return 0;
}
​
