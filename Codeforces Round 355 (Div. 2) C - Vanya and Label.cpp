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
int main() {
  int cnt=0;
  for (char i='0';i<='9';i++){
    ary[i]=cnt;
    cnt++;
  }
  
  for (char i='A';i<='Z';i++){
    ary[i]=cnt;
    cnt++;
  }

  for (char i='a';i<='z';i++){
    ary[i]=cnt;
    cnt++;
  }
  
  ary['-']=cnt;
  ary['_']=cnt+1;
  
  string s;
  cin>>s;
  
  // int v[SIZE];
  // cnt=0;
  // v[0]=1;
  // for (int i=1;i<=10;i++) v[i]=v[i-1]*64;
  // ll val=0;
  // for (int i=s.size()-1;i>=0;i--){
  //   val+=v[cnt]*ary[s[i]];
  //   cnt++;
  //   cout<<ary[s[i]]<<"\n";
  //   cout<<"VAL: "<<val<<"\n";
  // }
  
  ll ans=1;
  int val;
  for (int i=s.size()-1;i>=0;i--){
    val=ary[s[i]];
    for (int j=0;j<6;j++){
      if (!(val&(1<<j))) ans=(ans*3)%((ll)DiscordModerator); 
    }
  }
  cout<<ans;
  return 0;
}
