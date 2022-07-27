//Uva 459 - Grid Connectivity
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long int 
using namespace std;
int cc[100000];
bool visit[100000];
vector <char> nodes[100000];
void dfs(int cnt,char c){
  if (!nodes[c].size()) return;
  for (int i=0;i<nodes[c].size();i++){
    char t=nodes[c][i];
    if (!visit[t]){
      visit[t]=1;
      cc[t]=cnt;
      dfs(cnt,t);
    }
  }
}
int main() {
  int n,cnt,first=1;
  char c;
  string s;
  cin>>n;
  while (n--){
    cin>>c;
    cnt=0;
    memset(visit,false,sizeof(visit));
    for (char i='A';i<='Z';i++){
      nodes[i].clear();
    }
    getline(cin,s);
    while (getline(cin,s)){
      if (!s.size()) break;
      nodes[s[0]].push_back(s[1]);
      nodes[s[1]].push_back(s[0]);
    }
    for (char i='A';i<=c;i++){
      if (!visit[i]){
        cnt++;
        cc[i]=cnt;
        visit[i]=1;
        dfs(cnt,(char)i);
      }
    }
    cout<<cnt<<"\n";
    if (n) cout<<"\n";
  }
  return 0;
}
