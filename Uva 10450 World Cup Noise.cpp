//Uva 10450 World Cup Noise
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
long long dp[1000][1000];
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n,beats;
	cin>>n;
	dp[0][0]=1;
	for (int i=1;i<=100;i++){
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		dp[i][1]=dp[i-1][0];
	}
	for (int cases=1;cases<=n;cases++){
		cin>>beats;
		cout<<"Scenario #"<<cases<<":\n";
		cout<<dp[beats][0]+dp[beats][1]<<"\n\n";
	}
	return 0;
} 
