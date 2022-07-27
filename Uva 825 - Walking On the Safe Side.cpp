//Uva 825 - Walking On the Safe Side
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <sstream>
int ary[10000000];
int dp[1000][1000],check[1000][1000];
int moves[100][100]={{1,0},{0,1}};
using namespace std;
int main() {
  int r,c,n,first=1;
  string s;
  cin>>n;
  while (n--){
    cin>>r>>c;
    memset(dp,0,sizeof(dp));
    memset(check,0,sizeof(check));
    getline(cin,s);
    for (int i=1;i<=r;i++){
      int cnt=0,posx;
      string temp;
      stringstream ss;
      memset(ary,0,sizeof(ary));
      getline(cin,s);
      // cout<<s<<"\n";
      ss.str(s);
      while (ss>>temp){
        for (int j=0;j<temp.size();j++){
          ary[cnt]=ary[cnt]*10+(temp[j]-'0');
        }
        // cout<<ary[cnt]<<"\n";
        cnt++;
      }
      posx=ary[0];
      for (int j=1;j<cnt;j++){
        check[posx][ary[j]]=1;
      }
    }
    if (first) first=0;
    else cout<<"\n";
    int ex=r-1,ey=c-1;
    dp[1][1]=1;
    for (int i=1;i<=r;i++){
      for (int j=1;j<=c;j++){
        for (int k=0;k<2;k++){
          int tempx=i+moves[k][0],tempy=j+moves[k][1];
          if ((tempx>=1 and tempx<=r) and (tempy>=1 and tempy<=c) and !check[tempx][tempy]){
            dp[tempx][tempy]+=dp[i][j];
          }
        }
      }
    }
    // for (int i=1;i<=r;i++){
    //   for (int j=1;j<=c;j++){
    //     cout<<dp[i][j]<<' ';
    //   }
    //   cout<<"\n";
    // }
    cout<<dp[r][c]<<"\n";
  }
  return 0;
}
