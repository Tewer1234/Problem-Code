//Uva 195 - Anagram
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int ans_cnt;
int tbl[1000],order[1000];
char temp[100000],path[100000];
string s[100000],ans[100000];
void dfs(int depth,int len){
	if (depth==len){
		ans_cnt++;
		ans[ans_cnt]=path;
		return;
	}
	for (char i='A';i<='z';i++){
		if ((i>='a' and i<='z') or (i>='A' and i<='Z')){
			if (tbl[i]){
				tbl[i]--;
				path[depth]=i;
				dfs(depth+1,len);
				tbl[i]++;
			}
		}
	}
}
bool comp(string a,string b){
	int len=a.size();
	for (int i=0;i<len;i++){
		if (order[a[i]]<order[b[i]]){
			return true;
		}else if (order[a[i]]>order[b[i]]){
		  return false;
		}
	}
}
int main() {
	int n,cnt=0,tmp=0;
	string s1;
	for (char i='A';i<='Z';i++){
		order[i]=tmp;
		order[i+32]=tmp+1;
		tmp+=2;
	}
// 	for (char i='A';i<='Z';i++){
// 	  cout<<i<<": "<<order[i]<<"\n";
// 	  cout<<(char)(i+32)<<": "<<order[i+32]<<"\n";
// 	}
	cin>>n;
	for (int i=1;i<=n;i++){
		memset(temp,0,sizeof(temp));
		int same=0;
		cin>>s1;
		for (int j=0;j<s1.size();j++){
			temp[j]=s1[j];
		}
		sort(temp,temp+s1.size());
		for (int j=1;j<=cnt;j++){
			if (temp==s[j]){
				same=1;
				break;
			}
		}
		if (!same){
			cnt++;
			s[cnt]=temp;
		}
	}
// 	for (int i=1;i<=cnt;i++) cout<<s[i]<<"\n";
	for (int i=1;i<=cnt;i++){
		ans_cnt=0;
		memset(tbl,0,sizeof(tbl));
		memset(path,0,sizeof(path));
		for (int j=0;j<s[i].size();j++){
			tbl[s[i][j]]++;
		}
		dfs(0,s[i].size());
		stable_sort(ans+1,ans+ans_cnt+1,comp);
		for (int j=1;j<=ans_cnt;j++){
			cout<<ans[j]<<"\n";
		}
	}
	return 0;
}
