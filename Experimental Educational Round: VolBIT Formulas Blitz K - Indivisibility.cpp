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
vector <int> divnum;
vector <int> d;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n,tt;
  cin>>n;
  
  n-=(n/2+n/3+n/5+n/7+n/30+n/42+n/70+n/105-n/210-n/6-n/10-n/14-n/15-n/21-n/35);
  cout<<n;
  return 0;
}
