#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#define ll long long int 
using namespace std;
typedef pair<int,int> pp;
struct node{
  int grid[10][10];
  int dis;
};
int ary[100][100];
node qq[1000000];
int bfs(){
  int temp=0,flag=1;
  string s="";
  char c;
  node cur,nxt;
  map <string,int> mp;
  for (int i=1;i<=9;i++){
    qq[temp].dis=0;
    for (int j=1;j<=3;j++){
      for (int k=1;k<=3;k++){
        qq[temp].grid[j][k]=ary[j][k];
        c=ary[j][k]+'0';
        s+=c;
      }
    }
    mp[s]++;
    s="";
    temp++;
  }
  for (int i=0,j=temp;i<j;i++){
    cur=qq[i];
    flag=1;
    for (int k=1;k<=3;k++){
      for (int l=1;l<=3;l++){
        if (cur.grid[k][l]>0){
          flag=0;
          break;
        }
      }
      if (!flag) break;
    }
    if (flag) return cur.dis;
    for (int k=1;k<=3;k++){
      for (int l=1;l<=3;l++){
        nxt=cur;
        nxt.dis++;
        // for (int row=1;row<=3;row++){
        //   for (int col=1;col<=3;col++){
        //     nxt.grid[row][col]=cur.grid[row][col];
        //   }
        // }
        for (int row=1;row<=3;row++){
          nxt.grid[row][l]=(cur.grid[row][l]+1)%4;
        }
        for (int col=1;col<=3;col++){
          nxt.grid[k][col]=(cur.grid[k][col]+1)%4;
        }
        s="";
        for (int row=1;row<=3;row++){
          for (int col=1;col<=3;col++){
            c=nxt.grid[row][col]+'0';
            s+=c;
          }
        }
        auto it=mp.find(s);
        if (it==mp.end()){
          // cout<<s<<"\n";
          mp[s]++;
          qq[j]=nxt;
          j++;
        }
      }
    }
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i=1;i<=3;i++){
    for (int j=1;j<=3;j++){
      cin>>ary[i][j];
    }
  }
  cout<<bfs();
  return 0;
}
