#include<stdio.h>
 
int f[41] = { 0,1,1 };
int c1 = 0;
int c2 = 0;
 
int fib(int n) {
    if (n == 1 || n == 2) {
        c1++;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}
 
int fibonacci(int n) 
{
    for (int i = 3; i <= n; i++) 
	{
        c2++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}
 
int main() 
{
    int n;
    scanf("%d", &n);
    fib(n);
    fibonacci(n);
    printf("%d %d", c1, c2);
	return 0;
}
