#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        if(n%(m + 1) == 0){
            printf("second\n");
        }
        else printf("first\n");
    }
    return 0;
}