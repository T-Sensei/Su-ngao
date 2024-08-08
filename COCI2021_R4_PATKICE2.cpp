#include<bits/stdc++.h>
using namespace std; 
#define             ll  long long
#define             int long long
#define             db  double 
#define             fi  first
#define             se  second
#define     FOR(i,a,b)  for(int i=(int)(a);i<=(int)(b);i++)
#define    FORD(i,a,b)  for(int i=(int)(a);i>=(int)(b);i--)
#define        MASK(i)   (1ll<<(i))
#define       c_bit(i)  __builtin_popcountll(i)  //đếm số bit đang bật
#define       BIT(x,i)  ((x) & MASK(i))  //TRẠNG THÁI CỦA BIT THỨ I TRONG X
#define    set_on(x,i)  ((x) | MASK(i)) // bật bit thứ i trong x
#define   set_off(x,i)  ((x) & ~MASK(i)) //tắt bit thứ i trong x
#define             pb  push_back
#define           TASK  "COCI2021_R4_PATKICE2"

template <class X, class Y>
    bool minimize (X &x, const Y &y)
    {
        if (x>y)
        {
            x=y;
            return 1;
        }
        else return 0;
    }
template <class X, class Y>
    bool maximize(X &x, const Y &y)
    {
        if (x<y)
        {
            x=y;
            return 1;
        }
        else return 0;
    }
template <class T>
    T Abs(const T &x)
    {
        return (x<0 ? -x : x);
    }

const int sm =1e9+7,sm2=1e9+7; 

ll gcd(int a,int b){return __gcd(a,b);} 
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
void add (ll &x, const ll &y) {x+=y; if (x>=sm) x-=sm;}
void sub (ll &x, const ll &y) {x-=y; if (x<0) x+=sm;}

const int xx[] = {0,0, 0, -1, 1};
const int yy[] = {0,1, -1, 0, 0};

const db PI = acos(-1);
const ll inf = 1e18;
const int N = 2000+5 ,base=331;
bool mtt = 0 ;
int test = 1 ;  

//------Starting-------
int n,m;
char a[N][N];
pair <int,int> st,en;

void doc()
{
    cin>>n>>m;
    FOR(i,1,n) FOR(j,1,m)
    {
        cin>>a[i][j];
        if (a[i][j]=='o')   st={i,j};
        if (a[i][j]=='x')   en={i,j};
    }
}

struct bg
{
    int x,y;
    ll ts;
};

struct cmp
{
    bool operator()(bg a,bg b)
    {
        return a.ts>b.ts;
    }
};

ll f[N][N];
int dd[N][N];

bool nt(int nx,int ny)
{
    return (nx>=1 and ny>=1 and nx<=n and ny<=m);
}

void dij(int i,int j)
{
    priority_queue <bg,vector<bg>,cmp> h;
    h.push({i,j,0});
    FOR(x,1,n)  FOR(y,1,m)  f[x][y]=inf;
    f[i][j] = 0;
    while (!h.empty())
    {
        int x=h.top().x;
        int y=h.top().y;
        h.pop();
        if (dd[x][y]==1)    continue;
        dd[x][y]=1;
        if (a[x][y]=='o')
        {
            FOR(i,1,4)
            {
                int nx=x+xx[i],ny=y+yy[i];
                if (f[nx][ny]>f[x][y] and dd[nx][ny]==0 and nt(nx,ny))
                {
                    f[nx][ny]=f[x][y];
                    h.push({nx,ny,f[nx][ny]});
                }
            }
            continue;
        }
        int real=0;
        if (a[x][y]=='^')   real=3;
        if (a[x][y]=='<')   real=2;
        if (a[x][y]=='>')   real=1;
        if (a[x][y]=='v')   real=4;
        FOR(i,1,4)
        {
            int nx=xx[i]+x,ny=yy[i]+y;
            if (i==real)
            {
                if (f[nx][ny]>f[x][y] and dd[nx][ny]==0 and nt(nx,ny))
                {
                    f[nx][ny]=f[x][y];
                    h.push({nx,ny,f[nx][ny]});
                }
            }
            else 
            {
                if (f[nx][ny]>f[x][y]+1 and dd[nx][ny]==0 and nt(nx,ny))
                {
                    f[nx][ny]=f[x][y]+1;
                    h.push({nx,ny,f[nx][ny]});
                }
            }
        }   
    }
}

void sub1()
{
    dij(st.fi,st.se);
    cout<<f[en.fi][en.se];
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    else if (fopen("INP.INP","r"))
    {
        freopen("INP.INP","r",stdin);
        freopen("INP.OUT","w",stdout);
    }
    if(mtt) cin>>test;
    while (test--)
    {
        doc();
        sub1();
    }

}