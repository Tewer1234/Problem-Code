#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <typeinfo>
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
#define SIZE 400005
using namespace std;
typedef pair<int,int> pp;
vector <int> ary[200005];
string s[200005];
map <string,int> val;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  int cnt=0,ans=0;
  cin>>k>>n;
  for (int i=1;i<=n;i++){
    cin>>s[i];
  }
  
  int dif=0,l=1,r=0;
  for (int i=1;i<=n;i++){
    auto it=val.find(s[i]);
    if (it==val.end()){
      val[s[i]]=i;
      dif=i-l+1;
      if (dif==k){
        ans++;
        val.erase(s[l]);
        l++;
      }
    }else{
      while (s[l] != s[i]){
        val.erase(s[l]);
        l++;
      }
      l++;
    }
    
  }
  cout<<ans;
  return 0; 
}
