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
using namespace std;
typedef pair<int,int> pp;
string s[100000];
map <string,int> mp;
set <string> check;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,ans=0;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>s[i];
    mp[s[i]]++;
  }
  for (int i=1;i<=n;i++){
    // mp.erase(s[i]);
    check.clear();
    for (int j=0;j<s[i].size();j++){
      int len=s[i].size()-1-j;
      if (len<=j){
        string l=s[i].substr(0,j+1);
        string r=s[i].substr(j+1,len);
        string temp=s[i].substr(len,j+1-len);
        string t=r+temp;
        if (l==t){
          auto it1=mp.find(temp);
          if (it1!=mp.end() and r.size()>0){
            // cout<<l<<" "<<r<<" "<<temp<<"\n";
            string last1=l+r+temp,last2=temp+s[i];
            // cout<<last1<<"\n";
            auto it2=check.find(last1);
            if (it2==check.end()){
              check.insert(last1);
              check.insert(last2);
              ans++;
            }
          }
        }
      }
    }
  }
  // for (auto it:check) cout<<it<<"\n";
  cout<<ans;
  return 0;
}

