#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
long long int dp[120001][5][5];
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	dp[1][0][0]=1;
	dp[1][1][0]=1;
	dp[1][0][1]=1;
	for (int i=2;i<=120000;i++){
		for (int j=0;j<2;j++){
			for (int k=0;k<3;k++){
				if (k>=1){
					dp[i][j][k]=( dp[i-1][j][k-1])%100000007;
				}else{
					for (int l=0;l<=j;l++){
						for (int m=0;m<3;m++){
							dp[i][j][k]=(dp[i][j][k]+dp[i-1][l][m])%100000007;
						}
					}
				}
			}
		}
	}
	int n;
	long long ans=0;
	cin>>n;
	for (int i=0;i<2;i++){
		for (int j=0;j<3;j++){
			ans=(ans+dp[n][i][j])%100000007;
		}
	}
	cout<<ans;
	return 0;
}
