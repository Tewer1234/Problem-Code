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
map <int,int> mpw;
map <int,int> mph;
int main() {
  ll area;
  int w,h,n,num;
  char op;
  set <int> sw;
  set <int> sh;
  cin>>w>>h>>n;
  mpw[w]=1;
  mph[h]=1;
  sw.insert(0);
  sw.insert(w);
  sh.insert(0);
  sh.insert(h);
  for (int i=1;i<=n;i++){
    cin>>op>>num;
    if (op=='V'){
      auto it=sw.upper_bound(num);
      int lower=(*(--it));
      int upper=(*(++it));
      sw.insert(num);
      
      mpw[upper-lower]--;
      
      if (!mpw[upper-lower]) mpw.erase(upper-lower);
      mpw[abs(num-lower)]++;
      mpw[abs(upper-num)]++;
      // for (auto it:mpw) cout<<it.first<<" ***** ";
      // cout<<"\n";
      
      auto it1=mpw.end();
      auto it2=mph.end();
      it2--;
      it1--;
      int lastw=it1->first;
      int lasth=it2->first;
      // cout<<lastw<<" "<<lasth<<"\n";
      area=(ll)lastw*lasth;
    }else{
      auto it=sh.upper_bound(num);
      int lower=(*(--it));
      int upper=(*(++it));
      sh.insert(num);
      
      mph[upper-lower]--;
      
      if (!mph[upper-lower]) mph.erase(upper-lower);
      mph[abs(num-lower)]++;
      mph[abs(upper-num)]++;
      // for (auto it:mpw) cout<<it.first<<" ***** ";
      // cout<<"\n";
      
      auto it1=mpw.end();
      auto it2=mph.end();
      it2--;
      it1--;
      int lastw=it1->first;
      int lasth=it2->first;
      // cout<<lastw<<" "<<lasth<<"\n";
      area=(ll)lastw*lasth;
    }
    cout<<area<<"\n";
  }
  return 0;
}
