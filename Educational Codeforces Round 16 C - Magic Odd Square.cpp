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
int ary[55][55];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  
  int cnt=1,temp=1,tt;
  int mid=n/2+1;
  
  for (int i=1;i<=mid;i++){
    for (int j=mid-i+1;j<=mid+i-1;j++){
      ary[i][j]=cnt;
      cnt+=2;
    }
  }
  
  tt=n/2-1;
  for (int i=mid+1;i<=n;i++){
    for (int j=mid-tt;j<=mid+tt;j++){
      ary[i][j]=cnt;
      cnt+=2;
    }
    tt--;
  }
  
  cnt=2;
  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++){
      if (!ary[i][j]){
        ary[i][j]=cnt;
        cnt+=2;
      }
    }
  }
  
  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++){
      cout<<ary[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
