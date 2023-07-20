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
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,t,p;
  cin>>t;
  while (t--){
    cin>>n>>p;
    
    int edges=2*n+p,cnt=2;
    for (int i=2;i<=n;i++){
      cout<<1<<" "<<i<<"\n";
      edges--;
    }
    
    int temp=3;
    while (edges>0){
      cout<<cnt<<" "<<temp<<"\n";
      temp++;
      if (temp>n){
        cnt++;
        temp=cnt+1;
      }
      edges--;
    }
  }
  return 0;
}
