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
string s[SIZE];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n,m;
  cin>>n>>m;
  for (int i=0;i<n;i++) cin>>s[i];
  
  int ans=INT_MAX,temp;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      for (int k=0;k<n;k++){
        int let=1e5,num=1e5,sym=1e5;
        if (i!=j and j!=k and i!=k){
          for (int l=0;l<m;l++){
            temp=min(l,m-l);
            if (s[i][l]>='a' and s[i][l]<='z') let=min(let,temp);
            if (s[j][l]>='0' and s[j][l]<='9') num=min(num,temp);
            if (s[k][l]=='#' or s[k][l]=='*' or s[k][l]=='&') sym=min(sym,temp);
          }
          
          ans=min(ans,let+num+sym);
        }
      }
    }
  }
  
  cout<<ans;
  return 0;
}
