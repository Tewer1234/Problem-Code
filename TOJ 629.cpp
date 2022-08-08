//TOJ 629
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#define ll long long int 
#define pb push_back
using namespace std;
typedef pair<ll,ll> pp;
pp t1,t2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q,op,k,road,a;
  ll den,num,res;
  char s;
  cin>>q;
  t1.first=t2.first=1;
  t1.second=t2.second=0;
  while (q--){
    cin>>op;
    if (op==1){
      cin>>k;
      res=max(t1.first*k+t1.second,t2.first*k+t2.second);
      cout<<res<<"\n";
    }else if (op==2){
      cin>>road>>s>>a;
      if (s=='+'){
        if (road==1) t1.second+=a;
        else t2.second+=a;
      }else{
        if (road==1) t1.first*=a,t1.second*=a;
        else t2.first*=a,t2.second*=a;
      }
    }else{
      den=t1.first-t2.first, num=t2.second-t1.second;
      if (!den or (num%den!=0)) cout<<"no\n";
      else cout<<num/den<<"\n";
    }
  }
  return 0;
}

