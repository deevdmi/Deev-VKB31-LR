#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cstdlib>
#define MP make_pair
using namespace std;
vector<int> p;
int find_set(int x){return(x==p[x])?x:p[x]=find_set(p[x]);}
void unite_set(int x, int y){
x=find_set(x);y=find_set(y);if(x==y)return;
if(rand()%2)swap(x,y);
p[x]=y;}
int main(){
int n,m,i,j,k,s=0,w;long long ans=0;
cin>>n>>m;
p.resize(n+1);for(k=1;k<=n;++k)p[k]=k;
pair<int,pair<int, int>>r[m];
for(k=0;k<m;++k){cin>>i>>j>>w;r[k]=MP(w,MP(i,j));}
sort(r, r+m);
for(k=0;k<m&&s<n-1;++k){
i=find_set(r[k].second.first);
j=find_set(r[k].second.second);
if(i!=j){
ans+=r[k].first;s++;unite_set(i,j);}}
cout<<ans;
return 0;}