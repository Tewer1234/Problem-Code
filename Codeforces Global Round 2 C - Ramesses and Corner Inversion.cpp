#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#define SIZE 400005
#define ll long long int
#define pp pair<ll,int>
#define pb push_back
#define DiscordModerator 998244353
using namespace std;
int ary[1005][1005];
int bry[1005][1005];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int r,c;
  cin>>r>>c;
  for (int i=1;i<=r;i++){
    for (int j=1;j<=c;j++){
      cin>>ary[i][j];
    }
  }
  
  for (int i=1;i<=r;i++){
    for (int j=1;j<=c;j++){
      cin>>bry[i][j];
    }
  }
  
  if (r>=2 and c>=2){
    for (int i=1;i<r;i++){
      for (int j=1;j<c;j++){
        if (ary[i][j]!=bry[i][j]){
          for (int k=i;k<=i+1;k++){
            for (int l=j;l<=j+1;l++){
              ary[k][l]=!(ary[k][l]);
            }
          }
        }
      }
    }
  }
  // for (int i=1;i<=r;i++){
  //   for (int j=1;j<=c;j++){
  //     cout<<ary[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  int flag=1;
  for (int i=1;i<=r;i++){
    for (int j=1;j<=c;j++){
      if (ary[i][j]!=bry[i][j]){
        flag=0;
        break;
      }
      if (!flag) break;
    }
  }
  
  if (!flag) cout<<"NO";
  else cout<<"YES";
  return 0;
}
