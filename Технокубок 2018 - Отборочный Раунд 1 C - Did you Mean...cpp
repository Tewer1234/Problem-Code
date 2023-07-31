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
char vowel[100]={'a','e','i','o','u'};
map <char,int> mp;
vector <int> ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  string s;
  char c;
  cin>>s;
  
  if (s.size()<=2){
    cout<<s;
    return 0;
  }
  
  for (int i=0;i<s.size()-2;i++){
    int flag=1;
    mp.clear();
    for (int j=i;j<=i+2;j++) mp[s[j]]++;
    for (auto it:mp){
      for (int j=0;j<5;j++){
        if (vowel[j]==it.first){
          flag=0;
          break;
        }
      }
    }
    
    if (flag and mp.size()!=1) ary[i+2]=1,i=i+1;
  }
  
  for (int i=0;i<s.size();i++){
    if (ary[i]) cout<<" ";
    cout<<s[i];
  }
  return 0;
}
