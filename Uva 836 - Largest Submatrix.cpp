#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#define ll long long int 
#define pb push_back
#define inf -1e6
using namespace std;
typedef pair<int,int> pp;
int psum[1000][1000];
string s[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,rows,ans,tempans,first=1;
  string s1;
  cin>>n;
  getline(cin,s1);
  getline(cin,s1);
  while (n--){
    rows=ans=0;
    memset(dp,0,sizeof(dp));
    memset(psum,0,sizeof(psum));
    while (getline(cin,s1)){
      if (!s1.size()) break;
      s1=" "+s1;
      rows++;
      s[rows]=s1;
    }
    if (first) first=0;
    else cout<<"\n";
    
    for (int i=1;i<=rows;i++){
      for (int j=1;j<=rows;j++){
        if (s[i][j]=='0') psum[i][j]=psum[i-1][j]+inf;
        else psum[i][j]+=psum[i-1][j]+1;
      }
    }
    
    // for (int i=1;i<=rows;i++){
    //   for (int j=1;j<=rows;j++){
    //     cout<<psum[i][j]<<' ';
    //   }
    //   cout<<"\n";
    // }cout<<"\n";
    
    int temp=0,flag;
    for (int i=1;i<=rows;i++){
      for (int j=i;j<=rows;j++){
        temp=0;
        for (int k=1;k<=rows;k++){
          // if (s[i][k]=='1' and s[j][k]=='1'){
            // cout<<i<<" "<<j<<" "<<k<<": "<<temp<<" + "<<psum[j][k]-psum[i-1][k]<<" = ";
            temp=temp+(psum[j][k]-psum[i-1][k]);
            ans=max(ans,temp);
            if (temp<0) temp=0;
            // cout<<temp<<"\n";
            // cout<<i<<" "<<j<<" "<<k<<": "<<dp[j][k-1]+psum[j][k]-psum[i-1][k]<<"\n";
            // dp[j][k]=max(dp[j][k],max(0,dp[j][k-1])+(psum[j][k]-psum[i-1][k]));
          // }
        }
      }
    }
    cout<<ans<<"\n";
    // for (int i=1;i<=rows;i++){
    //   for (int j=1;j<=rows;j++){
    //     cout<<dp[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
  }
  return 0;
}
