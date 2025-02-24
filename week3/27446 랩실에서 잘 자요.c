#include <stdio.h>
#include <string.h>

int main(){
    int n,m,num;
    int page[102] = {0};
    int gap[102] = {0};
    int ans = 0;

    scanf("%d %d",&n,&m);
    while (scanf("%d", &num) == 1) {  
        page[num] = 1; 
    }

    int idx = (page[1]) ? 1:0; //존재하면 1부터, 존재하지 않으면 0부터
    gap[0] = (page[1]) ? 0:1;
    gap[1] = (page[1]) ? 1:0;

    for(int i=2;i<n+1;i++){
        if(page[i]!=page[i-1]){
            idx++;
        }
        gap[idx]++;
    }
    
    for(int i=1;i<idx;i+=2){
        if (gap[i]<3){ //2개 이하일때만 이득
            gap[i+1] += gap[i] + gap[i-1];
            gap[i-1]=0;
        }
    }
    for(int i=0;i<idx+2;i+=2){
        if (gap[i]) {ans += 5 + gap[i]*2;}
    }

    printf("%d",ans);
    return 0;
}