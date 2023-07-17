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
int ary[SIZE];
queue <int> r;
queue <int> d;
map <int,int> mp;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  string s;
  cin>>n>>s;
  
  for (int i=0;i<s.size();i++){
    if (s[i]=='D') d.push(i);
    else r.push(i);
  }
  
  int flag=1,ans;
  int cnt=n;
  while (flag){
    if (d.empty() or r.empty()){
      if (d.empty()) ans=2;
      else ans=1;
      flag=0;
      break;
    }
    if (r.front()<d.front()) r.push(cnt);
    else d.push(cnt);
    
    cnt++;
    // cout<<cnt-n<<"\n";
    // cout<<"FRONT: "<<d.front()<<" "<<d.back()<<"\n";
    // cout<<"BACK: "<<r.front()<<" "<<r.back()<<"\n";
    
    if (!r.empty()) r.pop();
    if (!d.empty()) d.pop();
    
  }
  
  if (ans==1) cout<<"D";
  else cout<<"R";
  return 0;
}
