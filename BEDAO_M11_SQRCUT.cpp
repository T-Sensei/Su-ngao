#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=1e5+5;
short t;
ll a,b,i,j,c;
int main()
{
    if (fopen("inp.inp","r"))
    {
        freopen("inp.inp","r",stdin);
        freopen("out.out","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while (t--)
    {
        c=0;
        cin>>a>>b;
        while (a!=b)
        {
            if (a>b)    a-=b;
            else b-=a;
            c++;
        }
        cout<<c<<"\n";
    }

}
