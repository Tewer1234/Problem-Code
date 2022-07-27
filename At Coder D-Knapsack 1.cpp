//At Coder D-Knapsack 1
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;
long long int value[1000000],space[1000000],dp[1000000];
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n,w;
	cin>>n>>w;
	for (int i=1;i<=n;i++){
		cin>>space[i]>>value[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=w;j>=space[i];j--){
			dp[j]=max(dp[j],dp[j-space[i	]]+value[i]);
		}
	}
	long long int ans=0;
	for (int j=1;j<=w;j++){
		ans=max(ans,dp[j]);
	}
	cout<<ans;
	return 0;
}
