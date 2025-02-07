#include <stdio.h>
#include <string.h>

int cnt1 = 1, cnt2 = 1;

int rc(int n){
    if (n==1 || n==2){ return 1;}
    else { cnt1++; return rc(n-1)+rc(n-2);}
}

int dp(int n){
    int f[n];
    f[0] = f[1] = 1;
    for(int i=3;i<n;i++){
        f[i] = f[i-1] + f[i-2]; cnt2++;
    }
    return f[n-1];
}

int main(){
    int n;
    scanf("%d",&n);

    rc(n);
    dp(n);

    printf("%d %d",cnt1, cnt2);

    return 0;
}