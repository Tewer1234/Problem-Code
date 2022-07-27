//UVa 200 - Rare Order 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector <string> v;
vector <char> node[1000];
int lead[1000],check[1000];
vector <int> qq;
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
	string s;
	while (cin>>s){
		v.push_back(s);
	}
	for (int i=0;i<v.size();i++){
		if (v[i]=="#" or (i<=v.size()-2 and v[i+1]=="#")){
			if (v[i]=="#"){
				for (int j='A';j<='Z';j++){
					if (check[j] and !lead[j]){
						qq.push_back(j);
					}
				}
				for (int j=0,k=qq.size();j<qq.size();j++){
					int cur=qq[j];
//					cout<<char(cur)<<"\n";
					for (int cnt=0;cnt<node[cur].size();cnt++){
						int temp=node[cur][cnt];
//						cout<<char(temp)<<": "<<lead[temp]<<"\n";
						lead[temp]--;
						if (!lead[temp]){
							qq.push_back(temp);
						}
					}
				}
				for (int j=0;j<qq.size();j++){
					cout<<char(qq[j]);
				}
				cout<<"\n";
				for (int j='A';j<='Z';j++){
					node[j].clear();
					qq.clear();
				}
				memset(check,0,sizeof(check));
				memset(lead,0,sizeof(lead));
			}else{
				for (int j=0;j<v[i].size();j++){
					check[v[i][j]]=1;
				}
			}
			
		}else{
			for (int j=0,k=0;j<v[i].size() and k<v[i+1].size();j++,k++){
				check[v[i][j]]=1;
				check[v[i+1][k]]=1;
				if (v[i][j]!=v[i+1][k]){
					lead[v[i+1][k]]++;
					node[v[i][j]].push_back(v[i+1][k]);
					break;
				}
			}
		}
	}
    return 0;
}
