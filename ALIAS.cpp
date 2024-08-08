//I'm still the same person with the same name. But with a different mindset and a new game!
//----------------------------------------------------
// When you are serious about your dreams:
/* Be ready to be alone
            to be laughed
            to lose friends
            to face the world
            to fail
            to be depressed
        and disrespected!
                            */

//=================================

#include <bits/stdc++.h>
#define ll long long
// #define int long long
#define TASK "INP"
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=1e3+5,NN=1e5+5;
const ll M=1e9;
int m,n,i,j,q;
unordered_map <string,int> mp;
struct bg{int ke;ll ts;}
vector <bg> g[N];

signed main()  
{
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int k=0;
    for (i=1;i<=m;i++)
    {
        string s,t;
        int z;
        cin>>s>>t>>z;
        if (mp[s]==0)
        {
            k++;
            mp[s]=k;
        }
        if (mp[t]==0)
        {
            k++;
            mp[t]=k;
        }
        g[mp[s]].push_back({mp[t],z});
    }

}
