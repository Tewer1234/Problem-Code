//Uva 147 - Dollars
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int amount[100]={0,5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[50][50000];
int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
	string s;
	int temp;
	ll ans;
	for (int i=1;i<12;i++){
		dp[i][0]=1;
	}
	for (int i=1;i<12;i++){
		for (int j=1;j<=30005;j++){
			if (j>=amount[i]){
				dp[i][j]=dp[i-1][j]+dp[i][j-amount[i]];
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	while (cin>>s and s!="0.00"){
	  ans=0,temp=0;
	  for (int i=0;i<s.size();i++){
	    if (s[i]>='0' and s[i]<='9') temp=temp*10+(s[i]-'0');
	  }
	  cout<<setw(6)<<s;
		cout<<setw(17)<<dp[11][temp]<<"\n";
	}
    return 0;
}
