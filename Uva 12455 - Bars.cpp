//Uva 12455 - Bars
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int ary[100000],dp[10000];
int main() {
  int t,n,p;
  cin>>t;
  while (t--){
    memset(dp,0,sizeof(dp));
    cin>>n>>p;
    for (int i=1;i<=p;i++){
      cin>>ary[i];
    }
    dp[0]=1;
    for (int i=1;i<=p;i++){
      for (int j=n;j>=ary[i];j--){
        if (j-ary[i]>=0 and dp[j-ary[i]]){
          dp[j]=1;
        }
      }
    }
    if (dp[n]) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}
