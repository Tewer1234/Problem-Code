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
#define pb push_back()
using namespace std;
int notPrime[SIZE];
int used[SIZE];
int main() {
  for (int i=3;i*i<=10000;i+=2){
    if (!notPrime[i]){
      for (int j=i*i;j<=10000;j+=(i+i)){
        notPrime[j]=1;
      }
    }
  }
  
  int n,prime=-1;
  cin>>n;
  for (int i=n;i<=10000;i++){
    if ((i%2) and !notPrime[i]){
      prime=i;
      break;
    }
  }
  
  if (prime==-1) cout<<-1;
  else{
    cout<<prime<<"\n";
    for (int i=1;i<n/2;i++) cout<<i<<" "<<i+1<<"\n";
    for (int i=n/2;i<n;i++) cout<<i<<" "<<i+1<<"\n";
    cout<<1<<" "<<n<<"\n";
    int add=prime-n,temp=1;
    for (int i=1;i<=add;i++){
      for (int j=1;j<=10000;j++){
        if (!used[j]){
          used[j]=1;
          used[j+2]=1;
          cout<<j<<" "<<j+2<<"\n";
          break;
        }
      }
    }
    
  }
  return 0;
}
