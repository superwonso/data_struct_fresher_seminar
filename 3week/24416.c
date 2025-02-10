#include<stdio.h>
#include<stdlib.h>

int fib(int n);
int fibonacci(int n);

int main(){
    int n;
    scanf("%d", &n);
    printf("%d %d", fib(n), fibonacci(n));
    return 0;
}

int fib(int n){
    int *nums=(int*)malloc(sizeof(int)*n);
    nums[0]=1;
    nums[1]=1;
    for(int i=2;i<n;i++)
        nums[i]=nums[i-1]+nums[i-2];

    return nums[n-1];
};
int fibonacci(int n){
    return (n-2);
};