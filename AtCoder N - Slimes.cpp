//https://atcoder.jp/contests/dp/tasks/dp_n
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long int 
using namespace std;
ll ary[1000000],psum[1000000],dp[1000][1000];
int main() {
  int n;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
    psum[i]=psum[i-1]+ary[i];
  }
  for (int i=1;i<=n;i++){
    for (int j=i;j<=n;j++){
      if (i!=j) dp[i][j]=LLONG_MAX;
    }
  }
  for (int i=n;i>=1;i--){
    for (int j=i+1;j<=n;j++){
      for (int k=i;k<j;k++){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+(psum[j]-psum[i-1]));
      }
    }
  }
  cout<<dp[1][n];
  return 0;
}
