//Uva 258 - Mirror Maze
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int r,c,sx,sy,ex,ey,dir,flag,reach;
int used[1000][1000],moves[100][100]={{-1,0},{0,1},{1,0},{0,-1}};
int cdir[100][100]={{1,0,3,2},{3,2,1,0}};
string s[10000];
void setValue(int i,int j){
    if (flag){
        ex=i;
        ey=j;
    }else{
        sx=i;
        sy=j;
        if (i==0) dir=2;
        else if (i==r-1) dir=0;
        else if (j==0) dir=1;
        else dir=3;
        flag=1;
    }
}
void dfs(int posx,int posy,int face){
//    cout<<"\n";
//    cout<<posx<<" "<<posy<<" "<<face<<"\n";
//    for (int i=0;i<r;i++){
//        cout<<s[i]<<"\n";
//    }
//    cout<<"\n";
    if (reach) return;
    int tempx=posx+moves[face][0],tempy=posy+moves[face][1];
    while (s[tempx][tempy]=='.' or (used[tempx][tempy] and (s[tempx][tempy]=='/' or s[tempx][tempy]=='\\'))){
        if (tempx==ex and tempy==ey){
            for (int i=0;i<r;i++){
                cout<<s[i]<<"\n";
            }
            reach=1;
            return;
        }
        posx=tempx,posy=tempy;
        if (s[tempx][tempy]=='/') face=cdir[0][face];
        else if (s[tempx][tempy]=='\\') face=cdir[1][face];
        tempx=posx+moves[face][0];
        tempy=posy+moves[face][1];
//        cout<<tempx<<" "<<tempy<<"\n";
    }
//    cout<<tempx<<" "<<tempy<<"\n";
    posx=tempx,posy=tempy;
    if (s[posx][posy]=='*') return;
    else{
        char original=s[posx][posy];
        if (!used[posx][posy]){
//            cout<<posx<<" "<<posy<<"\n";
            used[posx][posy]=1;
            if (original=='/'){
                s[posx][posy]='/';
                dfs(posx,posy,cdir[0][face]);
            }else{
                s[posx][posy]='\\';
                dfs(posx,posy,cdir[1][face]);
            }
            if (!reach){
                if (original=='/'){
                    s[posx][posy]='\\';
                    dfs(posx,posy,cdir[1][face]);
                }
                else{
                    s[posx][posy]='/';
                    dfs(posx,posy,cdir[0][face]);
                }
            }
            used[posx][posy]=0;
            s[posx][posy]=original;
        }
    }
}
 
int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
    int first=1;
    while (cin>>c>>r){
        flag=reach=0;
        memset(used,0,sizeof(used));
        if (r<0 and c<0) break;
        else{
        	if (first) first=0;
        	else cout<<"\n";
		}
        for (int i=0;i<r;i++){
            cin>>s[i];
        }
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                if ((i==0 or i==r-1) and (j>0 and j<c-1) and s[i][j]=='.'){
                    setValue(i,j);
                }else{
                    if ((j==0 or j==c-1) and s[i][j]=='.'){
                        setValue(i,j);
                    }
                }
            }
        }
        dfs(sx,sy,dir);
    }
    return 0;
}
