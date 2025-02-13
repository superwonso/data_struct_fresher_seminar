#include <stdio.h>

int main()
{
	int N , K =0;
	int chk1=0, chk2=0, cnt=0;
	int arr[5000]={0};
	scanf("%d %d", &N, &K);
	for(int i = 0; i<N; i++)
	{
		arr[i]=1;
	}
	
	printf("<");
	
	while(1)
	{
		chk1++; 
		if(chk1 >= N)
			chk1 = 0;
			
		if(arr[chk1]==1) 
		{
			chk2++;  
		}
			
			
		if(chk2==K)
		{
			arr[chk1]=0;
			if(chk1==0)
				printf("%d", N);
			else
				printf("%d", chk1);
			cnt++;
			chk2=0;
			if(cnt < N)
				printf(", ");
		}
			
		if(cnt==N) break;
	}
	printf(">");
	
	return 0;
}
