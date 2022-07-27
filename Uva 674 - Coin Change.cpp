//Uva 674 - Coin Change
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int amount[100]={0,1,5,10,25,50};
long long int dp[10][10000];
int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
	int n;
	for (int i=0;i<6;i++){
		dp[i][0]=1;
	}
	for (int i=1;i<6;i++){
		for (int j=1;j<=7489;j++){
			if (j>=amount[i]){
				dp[i][j]=dp[i-1][j]+dp[i][j-amount[i]];
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
//	for (int i=0;i<6;i++){
//		for (int j=0;j<=10;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while (cin>>n){
		cout<<dp[5][n]<<"\n";
	}
    return 0;
}
​
