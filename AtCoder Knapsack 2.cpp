//AtCoder Knapsack 2
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
bool used[1000000];
long long int v[100000],s[100000],dp[100000],sum[1000][1000];
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    memset(dp,0x3f,sizeof(dp));
    long long int n,w,
    total=0;
    cin>>n>>w;
    for (int i=1;i<=n;i++){
        cin>>s[i]>>v[i];
        total+=v[i];
    }
    dp[0]=0;
    used[0]=true;
    for (int i=1;i<=n;i++){
        for (int j=100000;j>=v[i];j--){
//        	if (j-v[i]==30) cout<<j<<"\n";
           if (used[j-v[i]]){
		   		dp[j]=min(dp[j],dp[j-v[i]]+s[i]);
				used[j]=true;
			}
		}
    }
    long long int ans=0;
    for (int i=1;i<=total;i++){
        if (dp[i]<=w){
            ans=i;
        }
//        cout<<i<<": "<<dp[i]<<"\n";
    }
    cout<<ans;
    return 0;
}
