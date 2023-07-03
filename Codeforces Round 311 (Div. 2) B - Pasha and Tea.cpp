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
#define DiscordModerator 998244353
using namespace std;
double ary[SIZE];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  double w;
  cin>>n>>w;
  for (int i=1;i<=2*n;i++) cin>>ary[i];
  
  sort(ary+1,ary+(2*n)+1);
  
  double temp;
  if (ary[1]*2<=ary[n+1]){
    if (ary[1]*3*n<=w) cout<<fixed<<setprecision(6)<<ary[1]*3*n;
    else cout<<fixed<<setprecision(6)<<w;
  }else{
    temp=ary[n+1]/2;
    if (temp*3*n<=w) cout<<fixed<<setprecision(6)<<temp*3*n;
    else cout<<fixed<<setprecision(6)<<w;
  }
  return 0;
}
