//Uva 10198 Counting
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int dp[10000][10000],places[10000];
void solve(int i,int num,int multiply){
	int temp,pos;
	for (int j=1;j<=places[num];j++){
		dp[i][j]=dp[i][j]+dp[num][j]*multiply;
	}
	for (int j=1;j<=places[num];j++){
		temp=dp[i][j];
		pos=j+1;
		while (temp>=10){
			dp[i][pos]+=temp/10;
			dp[i][j]%=10;
			temp/=10;
			pos++;
		}
		pos--;
		places[i]=max(places[i],pos);
	}
}
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n;
	dp[1][1]=2;
	dp[2][1]=5;
	dp[3][1]=3,dp[3][2]=1;
	places[1]=1;
	places[2]=1;
	places[3]=2;
	for (int i=4;i<=1000;i++){
		solve(i,i-1,2);
//		for (int j=1;j<=places[i];j++) cout<<dp[i][j];
//		cout<<"\n";
		solve(i,i-2,1);
//		for (int j=1;j<=places[i];j++) cout<<dp[i][j];
//		cout<<"\n";
		solve(i,i-3,1);
//		for (int j=places[i];j>=1;j--) cout<<dp[i][j];
//		cout<<"\n";
	}
//	cout<<places[1]<<"\n";
	while (cin>>n){
//		cout<<places[n]<<"\n";
		for (int i=places[n];i>=1;i--){
			cout<<dp[n][i];
		}
		cout<<"\n";
	}
	return 0;
}
​
​
