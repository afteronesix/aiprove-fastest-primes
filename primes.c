#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    int n;
    if(scanf("%d",&n)!=1) return 0;
    if(n<2){ printf("0\n"); return 0; }
    int m=(n+1)/2; /* odds 1,3,5..n -> index i = (2i+1) */
    unsigned char *c=malloc(m);
    memset(c,1,m);
    c[0]=0; /* 1 is not prime */
    for(int i=3;(long)i*i<=n;i+=2)
        if(c[i/2]) for(long j=(long)i*i;j<=n;j+=2*i) c[j/2]=0;
    long cnt=1; /* prime 2 */
    for(int i=1;i<m;i++) cnt+=c[i];
    printf("%ld\n",cnt);
    return 0;
}
