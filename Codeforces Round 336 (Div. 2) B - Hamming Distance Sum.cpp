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
using namespace std;
int ary[SIZE];
int preb[SIZE],pre1[SIZE];
vector <int> st;
vector <int> ed;
int main() {
  string a,b;
  cin>>a>>b;
  
  a=" "+a;
  b=" "+b;
  for (int i=1;i<a.size();i++){
    if (a[i]=='1') pre1[i]=pre1[i-1]+1;
    else pre1[i]=pre1[i-1];
  }
  
  for (int i=1;i<b.size();i++){
    if (b[i]=='1') preb[i]=preb[i-1]+1;
    else preb[i]=preb[i-1];
  }
  
  // for (int i=1;i<a.size();i++){
  //   cout<<pre1[i]<<"\n";
  // }
  // cout<<"\n";
  // for (int i=1;i<b.size();i++){
  //   cout<<preb[i]<<"\n";
  // }
  
  
  int cnt=1;
  for (int i=1;i<b.size();i++){
    ed.pb(cnt);
    if (cnt!=a.size()-1) cnt++;
  }
  
  cnt=1;
  for (int i=1;i<b.size();i++){
    if (i>b.size()-a.size()+1) cnt++;
    st.pb(cnt);
  }
  
  ll ans=0;
  for (int i=0;i<b.size()-1;i++){
    int dif=0;
    if (b[i+1]=='1') dif=abs(ed[i]-st[i]+1);
    // else dif=preb[i]*(abs(ed[i]-st[i]+1));
    // cout<<i+1<<": "<<st[i]<<" "<<ed[i]<<" "<<abs(pre1[ed[i]]-pre1[st[i]-1])<<" ";
    // cout<<dif<<"\n";
    ans+=abs((ll)pre1[ed[i]]-pre1[st[i]-1]-dif);
  }
  cout<<ans;
  return 0;
}

