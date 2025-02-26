//회전하는 큐
#include<stdio.h>
#define MIN(a, b) ((a<b)? a:b)
int main(){
    int N, M, curr=0, count=0;
    scanf("%d %d", &N, &M);

    int find[M], nums[N];
    for(int i=0;i<N;i++)
        nums[i]=i+1;

    for(int i=0;i<M;i++)
        scanf("%d", &find[i]);

    for(int i=0;i<M;i++){
        if((find[i]==nums[curr])&&(nums[curr]!=0)){
            nums[curr]=0;
            curr++;
        }
        else{
            int lm=0, rm=0;
            int lc=curr, rc=curr;
            while(nums[rc]!=find[i]){
                rc++;
                if(rc>N-1) rc=0;
                if(nums[rc]==0) continue;
                rm++;
            }
            while(nums[lc]!=find[i]){
                lc--;
                if(lc<0) lc=N-1;
                if(nums[lc]==0) continue;
                lm++;
            }
            if(MIN(lm,rm)==lm){
                count+=lm;
                curr=lc;
            }
            else{
                count+=rm;
                curr=rc;
            }
            nums[curr]=0;
            while(nums[curr]==0){
                curr++;
                if(curr>N-1)
                    curr=0;
                }
        }
    }
    printf("\n%d", count);
    return 0;
}
