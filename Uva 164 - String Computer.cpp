//Uva 164 - String Computer
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int r,c,dp[1000][1000],cur,moves[100][100]={{0,-1},{-1,-1},{-1,0}};
string s,t;
void backtrack(int row,int col){
  if (!row and !col) return;
  else{
  // 	cout<<row<<" "<<col<<"\n";
  	int temp=INT_MAX,tempx,tempy,op;
  	if (s[row]==t[col]){
  		backtrack(row-1,col-1);
  		cur++;
	  }else{
			for (int i=0;i<3;i++){
				tempx=row+moves[i][0];
				tempy=col+moves[i][1];
				if ((tempx>=0 and tempx<=r) and (tempy>=0 and tempy<=c)){
					if (temp>dp[tempx][tempy]){
						op=i;
						temp=dp[tempx][tempy];
					}
				}
			}	
			backtrack(row+moves[op][0],col+moves[op][1]);
//			cout<<op<<" ";
			if (!op){
				cur++;
				cout<<"I"<<t[col];
				if (cur<10) cout<<"0";
				cout<<cur;
			}else if (op==1){
				cur++;
				cout<<"C"<<t[col];
				if (cur<10) cout<<"0";
				cout<<cur;
			}else{
				cout<<"D"<<s[row];
				if (cur+1<10) cout<<"0";
				cout<<cur+1;
			}
	  }
  }
}
int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
    while (cin>>s and s!="#"){
        memset(dp,0,sizeof(dp));
        cin>>t;
        s=" "+s;
        t=" "+t;
        cur=0;
        for (int i=0;i<s.size();i++){
            dp[i][0]=i;
        }
        for (int i=0;i<t.size();i++){
            dp[0][i]=i;
        }
        dp[0][0]=0;
        for (int i=1;i<s.size();i++){
            for (int j=1;j<t.size();j++){
                if (t[j]==s[i]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }
        // for (int i=0;i<s.size();i++){
        //     for (int j=0;j<t.size();j++){
        //         cout<<setw(4)<<dp[i][j];
        //     }
        //     cout<<"\n";
        // }
        r=s.size()-1,c=t.size()-1;
        backtrack(r,c);
        cout<<"E\n";
    }
    return 0;
}
