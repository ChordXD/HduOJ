#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 7;
int sum[maxn<<2];
int a[maxn];
void Pushdown(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void Build(int l,int r,int rt)
{
    if(l == r)
    {
        sum[rt] = 0;
        return ;
    }
    int m = (l +r) >> 1;
    Build(l,m,rt<<1);
    Build(m+ 1,r,rt<<1|1);
    Pushdown(rt);
}

void update(int l,int r,int rt,int L)
{
    if(l == r)
    {
        sum[rt] = 1;
        return;
    }
    int m = (l+r) >> 1;
    if(L <= m) update(l,m,rt << 1,L);
    else update(m+1,r,rt << 1|1 ,L);
    Pushdown(rt);
}

int query(int l,int r,int L,int R,int rt)
{
    if(L <= l && r <= R)
    {
        return sum[rt];
    }
    int ans = 0;
    int m = (l+r) >> 1;
    if(L <= m) ans += query(l,m,L,R,rt<<1);
    if(R > m) ans+= query(m+1,r,L,R,rt<<1|1);
    return ans;
}

void solve(void)
{
    int n;
    while(~scanf("%d",&n))
    {
        Build(0,n-1,1);
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d",&a[i]);
            ans+=query(0,n-1,a[i],n-1,1);
            //printf("%d\n",ans);
            update(0,n-1,1,a[i]);
//            for(int i = 0 ; i < 20 ; i++)
//                printf("%d ",sum[i]);
//            printf("\n");
        }
        //printf("%d\n",ans);
        int newsum = ans;
        for(int i = 0 ; i < n ; i++)
        {
            ans = ans - 2 * a[i] + n - 1;
            if(ans < newsum) newsum = ans;
        }
        printf("%d\n",newsum);
    }
}

int main(void)
{
    solve();
    return 0;
}
