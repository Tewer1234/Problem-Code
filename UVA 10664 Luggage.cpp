//Luggage 10664
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits.h>
#include <sstream>
using namespace std;
int ary[1000000],used[100000],flag;
string temp_num[100000];
bool dfs(int pick,int sum1,int sum2,int cnt){
	if (pick!=cnt){
		sum1+=ary[pick];
	}else{
		if (sum1==sum2) return true;
		else return false;
	}
	if (dfs(pick+1,sum1,sum2,cnt)){
		return true;
	}
	if (dfs(pick+1,sum2,sum1,cnt)){
		return true;
	}
	return false;
}
int main() {
//      freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int n,cnt,temp;
	string s;
	stringstream ss;
	cin>>n;
	getline(cin,s);
	for (int i=1;i<=n;i++){
		flag=0;
		memset(used,0,sizeof(used));
		cnt=0;
		getline(cin,s);
		ss.clear();
		ss.str(s);
		while (ss>>temp_num[cnt]){
			cnt++;
		}
		for (int j=0;j<cnt;j++){
			temp=0;
			for (int k=0;k<temp_num[j].size();k++){
				temp=temp*10+(temp_num[j][k]-'0');
			}
			ary[j]=temp;
		}
		if (dfs(0,0,0,cnt)) cout<<"YES\n";
		else cout<<"NO\n";
	}
    return 0;                    
}
