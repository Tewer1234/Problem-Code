//Q11258 - String Partition 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
long long int dp[1000000];
int num[1000][1000]; 
int main() {
//      freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n,dig;
	long long int sum;
	string s;
	cin>>n;
	for (int i=1;i<=n;i++){
		memset(num,0,sizeof(num));
		memset(dp,0,sizeof(dp));
		cin>>s;
		//Get sum of every segment possible
		for (int j=0;j<s.size();j++){
			sum=0;
			for (int k=j;k<s.size();k++){
				dig=s[k]-'0';
				sum=sum*10+dig;
				if (sum>INT_MAX) break;
				else num[j][k]=sum;
			}
		}
		//Find the maximum sum
		for (int j=0;j<s.size();j++){
			dp[j]=num[0][j];
			for (int k=0;k<j;k++){
//				cout<<k+1<<" "<<j<<"\n";
//				cout<<dp[j]<<" "<<dp[k]+num[k+1][j]<<"\n";
				dp[j]=max(dp[j],dp[k]+num[k+1][j]);
			}
//			cout<<j<<": "<<dp[j]<<"\n";
		}
		cout<<dp[s.size()-1]<<"\n";
//		cout<<num[0][9]<<" "<<num[10][19]<<"\n";
//		cout<<num[20][29]<<" "<<num[30][39]<<"\n";
//		cout<<num[40][49]<<" "<<num[50][52]<<"\n";
	}
	return 0;
