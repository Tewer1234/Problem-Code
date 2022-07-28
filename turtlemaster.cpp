#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <queue>
#define ll long long int 
using namespace std;
typedef pair<int,int> pp;
string s[100000];
int moves[100][100]={{-1,0},{0,1},{1,0},{0,-1}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int curx,cury,ex,ey,dir=1;
  string t;
  for (int i=0;i<8;i++){
    cin>>s[i];
    for (int j=0;j<s[i].size();j++){
      if (s[i][j]=='T'){
        curx=i;
        cury=j;
      }else if (s[i][j]=='D'){
        ex=i;
        ey=j;
      }
    }
  }
  cin>>t;
  int tempx,tempy,flag=0;
  for (int i=0;i<t.size();i++){
    // cout<<curx<<' '<<cury<<" "<<dir<<" "<<t[i]<<"\n";
    if (t[i]=='F'){
      tempx=curx+moves[dir][0];
      tempy=cury+moves[dir][1];
      if ((tempx>=0 and tempx<8) and (tempy>=0 and tempy<8) and s[tempx][tempy]!='I' and s[tempx][tempy]!='C'){
        curx=tempx;
        cury=tempy;
      }else{
        break;
      }
    }else if (t[i]=='L'){
      dir=(dir+3)%4;
    }else if (t[i]=='R'){
      dir=(dir+1)%4;
    }else{
      tempx=curx+moves[dir][0];
      tempy=cury+moves[dir][1];
      // cout<<tempx<<' '<<tempy<<" "<<s[tempx][tempy]<<"\n";
      if ((tempx>=0 and tempx<8) and (tempy>=0 and tempy<8) and s[tempx][tempy]=='I'){
        s[tempx][tempy]='.';
      }else{
        break;
      }
    }
  }
  if (!flag and (curx>=0 and curx<8) and (cury>=0 and cury<8) and s[curx][cury]=='D') flag=1;
  if (!flag) cout<<"Bug!";
  else cout<<"Diamond!";
  return 0;
}
