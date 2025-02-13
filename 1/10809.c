#include <stdio.h>
#include <string.h>

#define ascii 97
#define length 101

int main()
{
	char s[length];
	int i,j = 0;
	int alpahbet_array[26]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	
	scanf("%s",s);
	
	for(i = 0; i<strlen(s); i++)
	{
		if(s[i]-ascii >= 0 )
		{
			if(alpahbet_array[s[i]-ascii] == -1)
				alpahbet_array[s[i]-ascii]=i;
		}
		
	}
	for(j=0; j<26; j++)
		printf("%d ",alpahbet_array[j]);
	

	return 0;
}
