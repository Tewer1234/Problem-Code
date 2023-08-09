#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <stack>
#define SIZE 4000050
#define ll long long int
#define pp pair<int,int>
#define pb push_back
#define DiscordModerator 1e9+7
using namespace std;
int ary[SIZE];
int presum[SIZE];
int dp[1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  int sum=0;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
  }
  
  for (int i=n;i>=1;i--){
    presum[i]=presum[i+1]+ary[i];
    dp[i]=max(presum[i+1]-dp[i+1]+ary[i],dp[i+1]);
  }
  
  cout<<presum[1]-dp[1]<<" "<<dp[1];
  return 0;
}
