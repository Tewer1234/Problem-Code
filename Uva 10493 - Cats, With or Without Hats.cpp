//Uva 10493 - Cats, With or Without Hats
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long int 
using namespace std;

int main() {
  int n,m;
  while (cin>>n>>m){
    int temp=-1,ans=1;
    if (!n and !m) break;
    if (n-1>=1) temp=m/(n-1)+m%(n-1);
    // cout<<temp<<"\n";
    cout<<n<<" "<<m<<" ";
    if (n==1 and m==1) cout<<"Multiple\n";
    else if ((temp-1)*(n-1)+1!=m) cout<<"Impossible\n";
    else{
      ans=(temp-1)*n+1;
      cout<<ans<<"\n";
    }
  }
  return 0;
}
