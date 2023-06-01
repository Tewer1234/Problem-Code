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
#define pb push_back()
using namespace std;
pp t[SIZE];
int used[SIZE];
bool comp(pp a,pp b){
  if (a.first<b.first) return true;
  else if (a.first==b.first and a.second<b.second) return true;
  else return false;
}
int main() {
  int n;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>t[i].first>>t[i].second;
  
  sort(t+1,t+n+1,comp);
  
  pp cur;
  int templ=t[1].first,tempr=t[1].second,first=1,pos,flag=0;
  used[1]=1;
  for (int i=2;i<=n;i++){
    cur=t[i];
    if (cur.first>tempr){
      used[i]=1;
      templ=cur.first;
      tempr=cur.second;
    }else{
      if (first){
        first=0;
        pos=i;
      }
    }
  }
  
  if (!first){
    templ=t[pos].first,tempr=t[pos].second;
    used[pos]=1;
    for (int i=pos+1;i<=n;i++){
      cur=t[i];
      if (!used[i] and cur.first>tempr){
        used[i]=1;
        templ=cur.first;
        tempr=cur.second;
      }
    }
  }
  
  for (int i=1;i<=n;i++){
    if (!used[i]){
      flag=1;
      break;
    }
  }
  
  if (flag) cout<<"NO";
  else cout<<"YES";
  return 0;
}
