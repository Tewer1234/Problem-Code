//Uva 11157 Dynamic Frog
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct node{
	long long int pos;
	char stone;
};
node ary[1000000];
bool used[1000000];
int main() {
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	long long int cases,n,d,p,f1,f2,ans,temp;
	char s,c;
	cin>>cases;
	for (int k=1;k<=cases;k++){
		memset(used,true,sizeof(used));
		temp=1;
		f1=0;
		f2=0;
		ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>s>>c>>p;
			ary[i].stone=s;
			ary[i].pos=p;
		}
		n++;
		ary[n].stone='B';
		ary[n].pos=d;
		while (1){
//			cout<<f1<<" "<<f2<<" "<<ans<<"\n";
			if (f1==d and f2==d) break;
			if (ary[temp].stone=='B'){
				ans=max(max(ans,(ary[temp].pos-f1)),(ary[temp].pos-f2));
				f1=ary[temp].pos;
				f2=ary[temp].pos;
				used[temp]=false;
			}else{
				if (f1<=f2){
					ans=max(ans,(ary[temp].pos-f1));
					f1=ary[temp].pos;
				}else{
					ans=max(ans,(ary[temp].pos-f2));
					f2=ary[temp].pos;
				}
				used[temp]=false;
			}
			temp++;
		}
		cout<<"Case "<<k<<": "<<ans;
		if (k!=cases) cout<<"\n";
	}
	return 0;
}
