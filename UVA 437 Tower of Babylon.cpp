#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int dp[10000000],ary[100];
struct node{
	int x,y,z;
};
node coords[10000000];
bool comp(node a,node b){
	if (a.x<b.x) return true;
	else if (a.x==b.x){
		if (a.y<b.y) return true;
	}
	return false;
}
int main() {
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n,cnt,x,y,z,cases=1,ans;
	while (cin>>n and n!=0){
		cnt=1;
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				cin>>ary[j];
			}
			for (int j=1;j<=3;j++){
				for (int k=1;k<=3;k++){
					for (int p=1;p<=3;p++){
						if (j!=k and j!=p and k!=p){
							coords[cnt].x=ary[j];
							coords[cnt].y=ary[k];
							coords[cnt].z=ary[p];
							cnt++;
						}
					}
				}
			}
		}
		
		sort(coords+1,coords+cnt,comp);
//		for (int i=1;i<cnt;i++){
//			cout<<coords[i].x<<' '<<coords[i].y<<" "<<coords[i].z<<'\n';
//		}
		for (int i=1;i<cnt;i++){
			for (int j=0;j<i;j++){
				if (coords[i].x>coords[j].x and coords[i].y>coords[j].y){
					dp[i]=max(dp[i],dp[j]+coords[i].z);
				}
			}
		}
		ans=0;
		for (int i=1;i<cnt;i++){
			ans=max(dp[i],ans);
		}
		cout<<"Case "<<cases<<": maximum height = "<<ans<<"\n";
		cases++;
	}
	return 0;
}
