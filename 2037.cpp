#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int start,end;
}poi;

bool cmp(poi a,poi b)
{
    return a.end < b.end;
}

int main(void)
{
    int n;
    while(~scanf("%d",&n),n)
    {
        poi a[n];
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d%d",&a[i].start,&a[i].end);
        }
        sort(a,a+n,cmp);
        int ans = 1;
        int endtime = a[0].end;
        for(int i = 1 ; i < n ; i++)
        {
            if(endtime <= a[i].start)
            {
                endtime = a[i].end;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}