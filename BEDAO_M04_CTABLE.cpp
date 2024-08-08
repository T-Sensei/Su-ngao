#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=1e5+5;
int m,n,i,j;
string s[N];
struct bg 
{
    int x;
    int y;
};
vector <bg> g[30];
int ct(bg u,bg v)
{
    return (abs(u.x-v.x)+abs(u.y-v.y));
}
int main()
{
    if (fopen("inp.inp","r"))
    {
        freopen("inp.inp","r",stdin);
        freopen("out.out","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    for (i=1;i<=m;i++)
    {
        cin>>s[i];
    }
    for (i=1;i<=m;i++)
    {
        for ( j=0;j<n;j++)
        {
            int bien=s[i][j]-'a'+1;
            g[bien].push_back({i,j+1});
        }
    }
    int mi=INT_MAX;
    for (i=1;i<=26;i++)
    {
        if (g[i].size()>=2)
        {
            for(j=0;j<g[i].size()-1;j++)
            {
                for (int p=j+1;p<g[i].size();p++)
                {
                    mi=min(mi,ct(g[i][j],g[i][p]));
                }
            }
        }
    }
    cout<<mi;

}
