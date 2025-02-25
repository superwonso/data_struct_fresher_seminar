#include <stdio.h>
int main()
{
	int n, m;
	int index=0; //커서 위치 
	scanf("%d %d", &n, &m);
	int queue[n]; //n까지 들어있는 큐 
	int arr[m]; //뽑아낼 값의 배열 
	int count = 0; //출력할  값  
	int right_rot = 0;
	int left_rot = 0; 
	for (int i = 0; i<n; i++)
	{
		queue[i] = i+1; //큐 초기화 
	}
	for (int j = 0; j<m; j++)
	{
		scanf("%d", &arr[j]);
	}
	
	for (int k = 0; k<m; k++)
	{
		while(queue[index] != arr[k]) //일치할 때까지  
		{
			if(queue[index] != 0) 
				right_rot++;
			index++;
			
			if(index == n)
				index = 0;
		}
		queue[index] = 0;
		
		left_rot = n - right_rot-k;
		
		if(right_rot > left_rot)
			count = count + left_rot;
		else
			count = count + right_rot;
		right_rot = 0;

	}
	
	printf("%d", count);
	
    return 0;
}
