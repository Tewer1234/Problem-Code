//Uva 11957 - Checkers
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[1000][1000];
int used[1000][1000],moves[100][100]={{-1,-1},{-1,1},{-2,-2},{-2,2}};
string s[100000];
int main() {
  int t,n,cases=1;
  ll ans;
  cin>>t;
  while (t--){
    int tempx,tempy;
    memset(dp,0,sizeof(dp));
    memset(used,0,sizeof(used));
    cin>>n;
    for (int i=0;i<n;i++){
      cin>>s[i];
      for (int j=0;j<s[i].size();j++){
        if (s[i][j]=='W'){
          dp[i][j]=1;
          used[i][j]=1;
        }else if (s[i][j]=='B'){
          used[i][j]=2;
        }
      }
    }
    for (int i=n-1;i>=0;i--){
      for (int j=0;j<n;j++){
        if (used[i][j]==1){
          for (int k=0;k<2;k++){
            tempx=i+moves[k][0];
            tempy=j+moves[k][1];
            if ((tempx>=0 and tempx<n) and (tempy>=0 and tempy<n)){
              if (used[tempx][tempy]!=2){
                used[tempx][tempy]=1;
                dp[tempx][tempy]+=(dp[i][j]%1000007);
              }else{
                if (!k) tempx=i+moves[2][0],tempy=j+moves[2][1];
                else tempx=i+moves[3][0],tempy=j+moves[3][1];
                if ((tempx>=0 and tempx<n) and (tempy>=0 and tempy<n)){
                  if (used[tempx][tempy]!=2){
                    used[tempx][tempy]=1;
                    dp[tempx][tempy]+=(dp[i][j]%1000007);
                  }
                }
              }
            }
          }
        }
      }
    }
    ans=0;
    // for (int i=0;i<n;i++){
    //   for (int j=0;j<n;j++){
    //     cout<<dp[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
    for (int i=0;i<n;i++){
      ans+=(dp[0][i]%1000007);
    }
    cout<<"Case "<<cases<<": "<<ans%1000007<<"\n";
    cases++;
  }
  return 0;
} 
