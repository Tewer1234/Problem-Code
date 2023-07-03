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
using namespace std;
int ary[SIZE];
string s[SIZE];
string key[SIZE];
vector <string> ans;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n,k;
  cin>>n>>k;
  for (int i=1;i<=n;i++) cin>>s[i];
  
  int cnt=1;
  ary[1]=1;
  for (int i=1;i<=n-k+1;i++){
    if (s[i]=="YES"){
      for (int j=i;j<=i+k-1;j++){
        if (!ary[j]){
          cnt++;
          ary[j]=cnt;
        }
      }
    }else{
      for (int j=i;j<=i+k-2;j++){
        if (!ary[j]){
          cnt++;
          ary[j]=cnt;
        }
      }
      ary[i+k-1]=ary[i];
    }
  }
  
  // for (int i=1;i<=n;i++) cout<<ary[i]<<" ";
  
  int temp=1;
  for (char i='A';i<='Z';i++){
    for (char j='a';j<='z';j++){
      string t="";
      t+=i;
      t+=j;
      key[temp]=t;
      temp++;
    }
  }
  
  for (int i=1;i<=n;i++) ans.pb(key[ary[i]]);
  for (int i=0;i<n;i++) cout<<ans[i]<<" ";
  return 0;
}
