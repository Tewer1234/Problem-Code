//Uva 679 - Dropping Balls
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n,depth,balls,ans,mod,add,cur;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>depth>>balls;
    ans=1,mod=1,add=1,cur=1;
    for (int j=1;j<depth;j++){
      mod*=2;
      int temp=balls%mod,left,right;
      left=cur,right=cur+add;
      if (left==temp){
        cur=left;
        ans*=2;
      }else{
        cur=right;
        ans=ans*2+1;
      }
      add*=2;
    }
    cout<<ans<<"\n";
  }
  return 0;
}  return 0;
}
