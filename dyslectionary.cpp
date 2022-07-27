#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <sstream>
#define ll long long int 
using namespace std;
typedef pair<int,int> pp;
string s[10000000];
vector <string> words;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int first=1;
  string t,temp;
  while (cin>>t){
    words.clear();
    map <string,string> mp;
    words.push_back(t);
    getline(cin,t);
    while (getline(cin,t)){
      if (!t.size()) break;
      words.push_back(t);
    }
    if (first) first=0;
    else cout<<"\n";
    int len=0,tlen;
    for (int i=0;i<words.size();i++){
      temp="";
      for (int j=words[i].size()-1;j>=0;j--){
        temp+=words[i][j];
      }
      tlen=words[i].size();
      len=max(len,tlen);
      mp[temp]=words[i];
      
    }
    for (auto it:mp){
      cout<<setw(len)<<it.second<<"\n";
    }
  }
  return 0;
}
