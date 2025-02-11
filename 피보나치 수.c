#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int a = 0,b = n - 2;
	int arr[40] = { 1,1,0 };
	for (int i = 2;i < n;i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	a = arr[n - 1];
	printf("%d %d", a, b);
}