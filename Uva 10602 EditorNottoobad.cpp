//Uva 10602 EditorNottoobad
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct node{
	string word,temp;
};
node s[1000000];
bool comp(node a,node b){
	if (a.word<b.word) return true;
	return false;
}
int main() {
//	freopen("C:\\Users\\Almond\\Desktop\\ctest.txt","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
	int ans,cases,n,dif,len,check;
	cin>>cases;
	while (cases--){
		ans=0;
		len=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>s[i].word;
			s[i].temp=s[i].word;
			if (s[i].word.size()>len) len=s[i].word.size();
		}
		for (int i=1;i<=n;i++){
			if (s[i].word.size()<len){
				dif=len-s[i].word.size();
				for (int j=1;j<=dif;j++){
					s[i].temp+=" ";
				}
			}
		}
		sort(s+1,s+n+1,comp);
		ans+=s[1].word.size();
		for (int i=2;i<=n;i++){
			for (int j=0;j<len;j++){
				if (s[i].temp[j]!=' ' and s[i].temp[j]!=s[i-1].temp[j]){
					check=j;
					break;
				}
			}
			dif=s[i].word.size()-check;
			ans+=dif;
		}
		cout<<ans<<"\n";
		for (int i=1;i<=n;i++){
//			cout<<s[i].word;
//			if (i!=n) cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
