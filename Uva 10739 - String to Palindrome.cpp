//Uva 10739 - String to Palindrome
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#define ll long long int 
using namespace std;
int dp[1005][1005];
int main() {
  int n,t=0;
  string s;
  cin>>n;
  while (n--){
    memset(dp,0,sizeof(dp));
    cin>>s;
    s=" "+s;
    for (int i=s.size()-1;i>=1;i--){
      for (int j=i+1;j<s.size();j++){
        int temp=j-i,steps;
        if (s[j-temp]==s[j]){
          dp[i][j]=dp[i+1][j-1];
        }else{
          steps=min(dp[i][j-1],min(dp[i+1][j-1],dp[i+1][j]))+1;
          dp[i][j]=steps;
        }
      }
    }
    // for (int i=1;i<s.size();i++){
    //   for (int j=1;j<s.size();j++){
    //     cout<<dp[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
    t++;
    cout<<"Case "<<t<<": "<<dp[1][s.size()-1]<<"\n";
  }
  return 0;
}
​
