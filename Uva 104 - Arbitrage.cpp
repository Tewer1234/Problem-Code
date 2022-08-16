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
#define inf -1e15
using namespace std;
typedef pair<int,int> pp;
int parent[100][100][100];
double dp[100][100][100];
vector <double> nodes[1000];
void rec(int moves,int i,int j){
  if (!moves){
    cout<<i;
  }else{
    rec(moves-1,i,parent[i][j][moves]);
    cout<<" "<<j;
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,pos;
  while (cin>>n){
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;i++){
      dp[i][i][0]=1;
      parent[i][i][0]=0;
      nodes[i].clear();
      nodes[i].resize(1000);
    }
    for (int i=1;i<=n;i++){
      pos=1;
      nodes[i][i]=1;
      for (int j=1;j<n;j++){
        if (pos==i) pos++;
        cin>>nodes[i][pos];
        // cout<<i<<" "<<pos<<": "<<nodes[i][pos]<<"\n";
        pos++;
      }
    }
    
    for (int change=1;change<=n;change++){
      for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
          for (int j=1;j<=n;j++){
            double cost=dp[i][k][change-1]*nodes[k][j];
            if (cost>dp[i][j][change]){
              dp[i][j][change]=max(dp[i][j][change],cost);
              parent[i][j][change]=k;
            }
          }
        }
      }
    }
    int moves=INT_MAX,last=1;
    
    for (int i=1;i<=n;i++){
      for (int j=1;j<=n;j++){
        double profit=dp[i][i][j]-1.0;
        if (profit>0.01){
          if (moves>j){
            moves=j;
            last=i;
          }
        }
      }
    }
    // cout<<moves<<"\n";
    if (moves==INT_MAX) cout<<"no arbitrage sequence exists\n";
    else{
      // cout<<last<<" "<<parent[last][last][moves-1]<<"\n";
      // last=parent[last][moves-1];
      // cout<<parent[last][moves-2]<<"\n";
      rec(moves,last,last);
      cout<<"\n";
    }
  }
  return 0;
}
