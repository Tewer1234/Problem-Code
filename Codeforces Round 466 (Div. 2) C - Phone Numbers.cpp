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
set <char> st;
vector <char> ss;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,k,cnt=0;
  string s;
  char temp;
  cin>>n>>k>>s;
  
  for (int i=0;i<s.size();i++){
    temp=s[i];
    auto it=st.find(temp);
    if (it==st.end()){
      st.insert(temp);
      ss.pb(temp);
    }
  }
  
  sort(ss.begin(),ss.end());
  cnt=ss.size()-1;
  
  // for (int i=0;i<ss.size();i++) cout<<ss[i]<<" "<<ary[ss[i]]<<"\n";
  
  int pos=0;
  if (n<k){
    cout<<s;
    for (int i=1;i<=k-n;i++) cout<<ss[0];
  }else{
    int check=1;
    for (int i=min(n,k)-1;i>=0;i--){
      if (s[i]!=ss[cnt]){
        for (int j=0;j<ss.size();j++){
          if (ss[j]>s[i]){
            s[i]=ss[j];
            // cout<<ss[j]<<"\n";
            pos=i;
            check=0;
            break;
          }
        }
      }
      if (!check) break;
    }
    
    for (int i=0;i<k;i++){
      if (i>pos) cout<<ss[0];
      else cout<<s[i];
    }
  }
  return 0;
}
