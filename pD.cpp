#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#define ll long long int 
#define pb push_back
#define inf 1e18
using namespace std;
typedef pair<int,int> pp;
ll ary[1000000];
int moves[100][100]={{-1,0,1},{-1,0,1}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>ary[i];
  if (n<=2) cout<<0;
  else{
    ll ans=inf;
    for (int i=0;i<3;i++){
      for (int j=0;j<3;j++){
        ll a1=ary[1]+moves[0][i];
        ll a2=ary[2]+moves[1][j];
        ll prev=a2;
        ll cnt=abs(moves[0][i])+abs(moves[1][j]);
        for (int k=3;k<=n;k++){
          ll ai=prev+(a2-a1);
          if (abs(ai-ary[k])==1){
            cnt++;
          }else if (abs(ai-ary[k])>1){
            cnt=inf;
            break;
          }
          prev=ai;
        }
        ans=min(ans,cnt);
      }
    }
    cout<<(ans==inf ? -1: ans);
  }
  return 0;
}

