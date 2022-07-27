//Uva 562 - Dividing Coins
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int dp[1000000];
int ary[1000000];
int main() {
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n,m;
	cin>>n;
	for (int cases=1;cases<=n;cases++){
		memset(dp,0,sizeof(dp));
		int total=0;
		cin>>m;
		for (int i=1;i<=m;i++){
			cin>>ary[i];
			total+=ary[i];
		}
		dp[0]=1;
		for (int i=1;i<=m;i++){
			for (int j=total;j>=ary[i];j--){
				if (dp[j-ary[i]]){
					dp[j]=1;
				}
			}
		}
		int dif=INT_MAX,temp,flag=0;
		for (int i=total;i>=0;i--){
			if (dp[i]){
				temp=total-i;
				dif=min(abs(i-temp),dif);
			}
		}
		cout<<dif;
		cout<<'\n';
	}
	return 0;
}
