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
using namespace std;
int ary[SIZE];
vector <int> t;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<=2*n;i++) cin>>ary[i];
  sort(ary+1,ary+(2*n)+1);
  
  // for (int i=1;i<=2*n;i++) cout<<ary[i]<<" ";
  
  int ans=INT_MAX,temp;
  for (int i=1;i<2*n;i++){
    for (int j=i+1;j<=2*n;j++){
      t.clear();
      for (int k=1;k<=2*n;k++){
        if (k!=i and k!=j){
          t.pb(ary[k]);
        }
      }
      
      temp=0;
      for (int k=0;k<t.size();k++){
        temp+=(abs(t[k]-t[k+1]));
        k++;
      }
      ans=min(ans,temp);
    }
  }
  cout<<ans;
  return 0;
}
