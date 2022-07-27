//Uva 10721 Bar Codes
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
long long int dp[100][100][100];
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	for (int i=1;i<=50;i++){
		dp[0][0][i]=1;
	}
	for (int i=1;i<=50;i++){
		for (int j=1;j<=i;j++){
			for (int k=1;k<=50;k++){
//				cout<<i<<" "<<j<<" "<<k<<": \n";
				int temp=k;
				for (int l=1;l<=k;l++){
					if (i-l>=0){
//						cout<<i-l<<" "<<j-1<<" "<<temp<<"\n";
						dp[i][j][k]+=dp[i-l][j-1][temp];
					}
				}
			}
		}
	}
	int n,k,m;
	while (cin>>n>>k>>m){
		cout<<dp[n][k][m]<<"\n";
	}
	return 0;
}
