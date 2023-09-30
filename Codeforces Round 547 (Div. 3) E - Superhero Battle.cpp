#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
#define ll long long int
#define SIZE 400005
#define pp pair<int,int>
#define DiscordModerator 1e9+7
using namespace std;
ll ary[SIZE];
ll pre[SIZE];
int main() {
    ll health,n;
    cin>>health>>n;
    for (int i=1;i<=n;i++){
      cin>>ary[i];
      pre[i]=pre[i-1]+ary[i];
    }
    
    ll ans;
    int flag=1;
    for (int i=1;i<=n;i++){
      if (-pre[i]>=health){
        flag=0;
        ans=i;
        break;
      }
    }
    
    if (!flag) cout<<ans;
    else{
      if (pre[n]>=0) cout<<-1;
      else{
        ll sum=pre[n];
        ll ans=LLONG_MAX;
        ll res,l;
        for (int i=1;i<=n;i++){
          res=abs((health+pre[i])/sum)+bool(abs(health+pre[i])%sum);
          //cout<<res<<" ";
          l=health+(sum*res+pre[i]);
          //cout<<l<<" "<<pre[i]<<" "<<sum<<" "<<sum*res+pre[i]<<"\n";
          // cout<<l<<" "<<res<<" "<<max((ll)0,abs(res))*n+i<<"\n";
          if (l<=0){
            ans=min(ans,max((ll)0,abs(res))*n+i);
          }
        }
        
        if (ans!=LLONG_MAX) cout<<ans;
        else cout<<-1;
      }
    }
    
    return 0;
}
