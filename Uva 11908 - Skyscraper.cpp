#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#define ll long long int
#define pb push_back
#define SIZE 1000005
#define pp pair<int,int>
using namespace std;
struct node{
  int a,b,c;
};
node ary[SIZE];
int dp[SIZE];
bool comp(node a,node b){
  return a.b<b.b;
}
int main(){
  int n,t;
  int cases=0;
  cin>>t;
  while (t--){
    cin>>n;
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;i++){
      cin>>ary[i].a>>ary[i].b>>ary[i].c;
      ary[i].b=ary[i].a+ary[i].b-1;
    }
    
    sort(ary+1,ary+n+1,comp);
    
    for (int i=1;i<=n;i++){
      int l=0,r=i-1,mid,temp=-1,tt=ary[i].a-1;
      while (l<=r){
        mid=((l+r)>>1);
        if (ary[mid].b<=tt){
          temp=mid;
          l=mid+1;
        }else r=mid-1;
      }
      
      dp[i]=max(dp[i-1],dp[max(temp,0)]+ary[i].c); 
    }
    
    cases++;
    cout<<"Case "<<cases<<": ";
    cout<<dp[n]<<"\n";
  }
  return 0;
}
