//Uva 845 Gas Station Numbers
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int tbl[1000][1000],correspond[100]={0,1,5,3,4,2,9,7,8,6};
int main() {
//    freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	int d,flag;
	string s,comp,ans;
	while (cin>>s and s!="."){
		memset(tbl,0,sizeof(tbl));
		flag=1;
		comp="";
		ans="";
		for (int i=0;i<s.size();i++){
			if (s[i]!='.'){
				comp+=s[i];
			}
		}
		for (int i=comp.size()-1;i>=0;i--){
			d=comp[i]-'0';
			for (int j=0;j<10;j++){
				tbl[i][j]+=tbl[i+1][j];
			}
			tbl[i][d]++;
			if (d==2 or d==5 or d==6 or d==9) tbl[i][correspond[d]]++;
		}
		int pos=-1,num=-1;
		for (int i=comp.size()-1;i>=0;i--){
			d=comp[i]-'0';
			for (int j=d+1;j<10;j++){
				if (tbl[i][j]){
					pos=i;
					num=j;
					tbl[i][j]--;
					if (j==2 or j==5 or j==6 or j==9) tbl[i][correspond[j]]--;
					flag=0;
					break;
				}
			}
			if (!flag) break;
		}
		if (!flag){
			for (int i=0;i<pos;i++) ans+=comp[i];
			ans+=(num+'0');
			for (int j=0;j<10;j++){
				while (tbl[pos][j]>0){
					tbl[pos][j]--;
					if (j==2 or j==5 or j==6 or j==9) tbl[pos][correspond[j]]--;
					ans+=(j+'0');
				}
			}
			int len=ans.size();
			ans.insert(len-1,".");
			cout<<ans<<"\n";
		}else{
			cout<<"The price cannot be raised.\n";
		}
	}
	return 0;
} 
