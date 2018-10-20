#include<stdio.h>
#include<string.h>
char a[1000];
int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        int k = strlen(a);
        if(k < 8 || k > 16)
        {
            puts("NO");
            continue;
        }
        int b,c,d,e;
        b = c = d = e = 0;
        for(int i = 0 ; i < k ; i++)
        {
            if(a[i]>= '0' && a[i] <= '9')
                b = 1;
            else if(a[i] >= 'a' && a[i] <= 'z')
                c = 1;
            else if(a[i] >= 'A' && a[i] <= 'Z')
                d = 1;
            else e = 1;
        }
        if(b+c+d+e >= 3)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}