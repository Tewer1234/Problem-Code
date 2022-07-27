#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
int cnt,h,w,d_value[1000][1000],correspond_dir[100]={2,3,0,1},used[1000],ary[10000],convert[1000][1000],flag,temp_r,temp_c;
int dx[100]={-1,0,1,0};
int dy[100]={0,-1,0,1};
string puzzle[1000][1000];
void dfs(int depth){
	if (depth==cnt*cnt){
		int temp=0;
		// for (int i=0;i<cnt*cnt;i++){
		// 	cout<<ary[i]<<" ";
		// }
		// cout<<"\n";
		for (int k=0;k<cnt;k++){
			for (int i=0;i<h;i++){
			  for (int j=temp;j<temp+cnt;j++){
			    cout<<puzzle[ary[j]][i];
			  }
			  cout<<"\n";
			}
			temp+=cnt;
		}
		return;
	}
	for (int i=0;i<cnt*cnt;i++){
		if (!used[i]){
			int is_ok=0,is_ok1=1;
			for (int j=0;j<2;j++){
				temp_r=depth/cnt+dx[j],temp_c=depth%cnt+dy[j];
				if ((temp_r>=0 and temp_r<cnt*cnt) and (temp_c>=0 and temp_c<cnt*cnt)){
					if (d_value[i][j]!=0){
						if (j==0){
							if (d_value[i][j]==d_value[ary[depth-cnt]][correspond_dir[j]]*-1){
								is_ok++;
							}
						}else{
							if (d_value[i][j]==d_value[ary[depth-1]][correspond_dir[j]]*-1){
								is_ok++;
							}
						}
					}
				}else{
					if (d_value[i][j]==0){
					  is_ok++;
					}
				}
			}
			if ((depth+1)%(cnt*cnt)==0){
				if (d_value[i][2]!=0) is_ok1=0;
			}
			if ((depth/(cnt*cnt))+1==cnt*cnt){
				if (d_value[i][3]!=0) is_ok1=0;
			}
			if (is_ok==2 and is_ok1==1){
				used[i]=1;
				ary[depth]=i;
				dfs(depth+1);
				used[i]=0;
			}
		}
	}
}
int main(int argc, char** argv) {
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
    	cin>>cnt>>h>>w;
    	getline(cin,puzzle[888][888]);
    	for (int j=0;j<cnt*cnt;j++){
    		for (int k=0;k<h;k++){ 
    			getline(cin,puzzle[j][k]);
			}
			for (int k=0;k<4;k++){
				cin>>d_value[j][k];
			}
			getline(cin,puzzle[888][888]);
			getline(cin,puzzle[888][888]);
		}
		dfs(0);
		if (i!=n) cout<<"\n";
	}
    return 0;
}
