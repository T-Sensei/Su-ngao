#include <bits/stdc++.h>
#define ll long long
// #define int long long
#define TASK "INP"
using namespace std;
#define pq priority_queue <ll>
#define pqd priority_queue <bg,vector<bg>,cmp>
const int N=1e3+5,NN=8*N;
const int M=2147483647;
short n,i,j;
ll sum=0,tich=1;
int main()
{
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++)
    {
     tich*=2;
        sum+=tich;
    }
    cout<<sum;

}