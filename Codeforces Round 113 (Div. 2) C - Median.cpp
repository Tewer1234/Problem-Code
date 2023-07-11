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
#define SIZE 400005
#define ll long long int
#define pp pair<int,int>
#define pb push_back
#define DiscordModerator 1e9+7
using namespace std;
int ary[SIZE];
int main() {
  int n,x;
  int upper=0;
  int lower=0;
  int same=0;
  cin>>n>>x;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
    if (ary[i]<x) lower++;
    else if (ary[i]==x) same++;
    else upper++;
  }
  
  if (lower==upper){
    if (same) cout<<0;
    else cout<<1;
  }else{
    int ans=0,flag=1;
    while (flag){
      int mid=(lower+upper+same+1)/2;
      int l=lower+1;
      int r=lower+same;
      if (l<=mid and mid<=r){
        cout<<ans;
        flag=0;
        break;
      }else{
        same++;
        ans++;
      }
    }
  }
  
  return 0;
}
