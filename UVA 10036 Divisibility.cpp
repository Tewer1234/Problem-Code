//Q10036 - Divisibility
//O(NK)
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int num[1000000];
bool dp[100000][1000];
int main() {
//      freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int cases,n,k;
	cin>>cases;
	for (int i=1;i<=cases;i++){
		memset(dp,false,sizeof(dp));
		cin>>n>>k;
		for (int j=1;j<=n;j++){
			cin>>num[j];
		}
		dp[1][(num[1]%k+k)%k]=true;
		for (int j=2;j<=n;j++){
			for (int r=0;r<k;r++){
				if (dp[j-1][r]){
					dp[j][((r+num[j])%k+k)%k]=true;
					dp[j][((r-num[j])%k+k)%k]=true;
				}
			}
		}
		if (dp[n][0]) cout<<"Divisible";
		else cout<<"Not divisible";
		cout<<"\n";
	}
	return 0;
}
