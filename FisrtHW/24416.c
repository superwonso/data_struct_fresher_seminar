#include <stdio.h>

int f[41] = { 0,1,1 };
int count_fib = 0;
int count_fib_dynamic = 0;

int fib(int n) {
	if (n == 1 || n == 2) { count_fib++; return 1; }
	else
		return(fib(n - 1) + fib(n - 2));
}

int fib_dynamic(int n) {
	for (int i = 3; i <= n; i++) {
		count_fib_dynamic++;
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

int main(void)
{
	int n;
	scanf("%d", &n);

	fib(n);
	fib_dynamic(n);

	printf("%d %d", count_fib, count_fib_dynamic);

	return 0;
}
