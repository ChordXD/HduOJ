#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define maxn  222222
int a[maxn<<2];
int l,w,n;
void pushup(int rt)
{
    a[rt] = max(a[rt<<1],a[rt<<1|1]);
}

int query(int l,int r,int rt,int want)
{
    if(l==r)
    {
        a[rt]-=want;
        return l;
    }
    int mid = (l + r)>>1;
    int ans;
    if(a[rt<<1]>=want)
        ans = query(l,mid,rt<<1,want);
    else
        ans = query(mid+1,r,rt<<1|1,want);
    pushup(rt);
    return ans;

}

void solve(void)
{
    while(~scanf("%d%d%d",&l,&w,&n))
    {
        if(n <= l)
            l = n;
        for(int i = 0 ; i <= l << 2 ; i++)
            a[i] = w;
        //printf("yes\n");
        while(n--)
        {
            int temp;
            scanf("%d",&temp);
            if(a[1]< temp)
            {
                puts("-1");
            }
            else
            {
                printf("%d\n",query(1,l,1,temp));
            }
        }
    }
}

int main(void)
{
    solve();
    return 0;
}
