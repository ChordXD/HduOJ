#include<bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 7;

int Max[maxn<<2];

int mmax(int a,int b){return (a > b ? a : b);}

void Pushup(int rt)
{
    Max[rt] =  mmax(Max[rt<<1],Max[rt<<1|1]);
}

void build(int l,int r,int rt)
{
    if(l == r)
    {
        scanf("%d",&Max[rt]);
        return;
    }
    int m = (l+r) >> 1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    Pushup(rt);
}

void update(int p,int aim,int l,int r,int rt)
{
    if(l==r)
    {
        Max[rt] =aim;
        return;
    }
    int m = (l +r) >> 1;
    if(p <= m) update(p,aim,l,m,rt<<1);
    else update(p,aim,m+1,r,rt<<1|1);
    Pushup(rt);
}

int query(int L,int R,int l,int r,int rt)
{
    if(L <= l&& r <= R)
    {
        return Max[rt];
    }
    int m = (l+r) >> 1;
    int ans = -inf;
    if(L <= m) ans = mmax(ans,query(L,R,l,m,rt<<1));
    if(R > m) ans = mmax(ans,query(L,R,m+1,r,rt<<1|1));
    return ans;
}

void solve(void)
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        build(1,n,1);
        while(m--)
        {
            char t[2];
            int a,b;
            scanf("%s%d%d",t,&a,&b);
            if(t[0]=='Q')
            {
                printf("%d\n",query(a,b,1,n,1));
            }
            else
            {
                update(a,b,1,n,1);
            }
        }
    }
}

int main(void)
{
    solve();
    return 0;
}
