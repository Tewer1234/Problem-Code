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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  
  //Case 1: Wrong Answer
  if (n<=5) cout<<-1<<"\n";
  else if (n==6){
    for (int i=2;i<=4;i++) cout<<1<<" "<<i<<"\n";
    cout<<"2 5\n2 6\n";
  }else{
    for (int i=2;i<=5;i++) cout<<1<<" "<<i<<"\n";
    for (int i=6;i<=n;i++) cout<<3<<" "<<i<<"\n";
  }
  
  //Case 2: Right Answer
  for (int i=2;i<=n;i++) cout<<1<<" "<<i<<"\n";
  return 0;
}
