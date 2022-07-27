//Uva 11624 Fire
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int used[5000][5000],f_used[5000][5000],picked[100000];
int moves[100][100]={{-1,0},{0,1},{1,0},{0,-1}};
string grid[10000];
struct node{
	int x,y,time;
};
node qq[10000000],fire[10000000],ary[10000000];
int bfs(int sx,int sy,int r,int c,int n,int temp){
	int spread=0,spread1=temp,cnt;
	node cur,next;
	qq[0].x=sx;
	qq[0].y=sy;
	qq[0].time=0;
	used[sx][sy]=1;
	for (int i=0,j=1;i<j;i++){
		cnt=0;
		cur=qq[i];
		if (cur.x==0 or cur.x==r-1 or cur.y==0 or cur.y==c-1) return cur.time+1;
//		cout<<"\n";
//		for (int k=0;k<r;k++) cout<<grid[k]<<"\n";
//		cout<<"\n";
		for (int k=0;k<4;k++){
			next=cur;
			next.x+=moves[k][0];
			next.y+=moves[k][1];
			next.time++;
			if ((next.x>=0 and next.x<r) and (next.y>=0 and next.y<c)){
				if (!f_used[next.x][next.y] and !used[next.x][next.y] and grid[next.x][next.y]!='#'){
					ary[cnt]=next;
					cnt++;
				}
			}	
		}
		if (!picked[cur.time]){
			picked[cur.time]=1;
			for (int k=spread;k<spread1;k++){
				for (int p=0;p<4;p++){
					next=fire[k];
					next.x+=moves[p][0];
					next.y+=moves[p][1];
					if ((next.x>=0 and next.x<r) and (next.y>=0 and next.y<c)){
						if (!f_used[next.x][next.y] and grid[next.x][next.y]!='#'){
							f_used[next.x][next.y]=1;
//							grid[next.x][next.y]='F';
							fire[temp]=next;
							temp++;
						}
					}
				}
			}
			spread=spread1;
			spread1=temp;
		}
		for (int k=0;k<cnt;k++){
			if (!f_used[ary[k].x][ary[k].y]){
				used[ary[k].x][ary[k].y]=1;
//				grid[ary[k].x][ary[k].y]='J';
				qq[j]=ary[k];
				j++;
			}
		}
	}
	return -1;
}
int main(int argc, char** argv) {
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n,r,c,sx,sy,temp,ans;
	cin>>n;
	while (n--){
		memset(picked,0,sizeof(picked));
		memset(used,0,sizeof(used));
		memset(f_used,0,sizeof(f_used));
		temp=0;
		cin>>r>>c;
		for (int i=0;i<r;i++){
			cin>>grid[i];
			for (int j=0;j<grid[i].size();j++){
				if (grid[i][j]=='J'){
					sx=i;
					sy=j;
				}else if (grid[i][j]=='F'){
					fire[temp].x=i;
					fire[temp].y=j;
					f_used[i][j]=1;
					temp++;
				}
			}
		}
		ans=bfs(sx,sy,r,c,n,temp);
		if (ans==-1) cout<<"IMPOSSIBLE\n";
		else cout<<ans<<"\n";
	}
	return 0;
}
