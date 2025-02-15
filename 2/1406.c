#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct dlistnode
{
	char data;
 	struct dlistnode* next;
	struct dlistnode* prev;
}dlistnode;

void print(dlistnode* n)
{
	dlistnode* temp = n;
	temp=temp->next;
	while(temp)
	{
    	printf("%c",temp->data);
    	temp=temp->next;
	}
	printf("\n");
}

int main()
{
	dlistnode* head = (dlistnode*)malloc(sizeof(dlistnode));
  	head->data='!';
  	head->prev=head->next=NULL;
  	dlistnode* cur = head;
  	char t;
  	while((t=getchar())!='\n')
	{
    	dlistnode* newdlistnode = (dlistnode*)malloc(sizeof(dlistnode));
    	newdlistnode->data=t;
    	newdlistnode->prev=cur;
    	newdlistnode->next=NULL;
    	cur->next=newdlistnode;
    	cur=newdlistnode;
  	}
  	int n;
  	scanf("%d",&n);
  	for(int i=0;i<n;i++)
	{
    	//print(head);
    	char c;
    	scanf(" %c",&c);
    	switch(c)
		{		
			case 'L':
			{
	        	if(cur->prev) cur=cur->prev;
    	    		break;
      		}
			case 'D':
			{
        		if(cur->next) cur=cur->next;
        			break;
     	 	}
		  	case 'B':
		  	{
   		 		if(cur->prev==NULL) continue;
   	    	 	dlistnode* del = (dlistnode*)malloc(sizeof(dlistnode));
       		 	del=cur;
        		cur=del->prev;
        		if(del->next) 
				{
       		   		cur->next=del->next;
       		  		del->next->prev=cur;
        	  		del->prev=NULL;}
        		else
				{
					cur->next=NULL;
				}
        		free(del);
        		break;
      		}
			case 'P':
			{
        		char tmp;
        		scanf(" %c",&tmp);
        		dlistnode* newdlistnode = (dlistnode*)malloc(sizeof(dlistnode));
        		newdlistnode->data=tmp;
        		newdlistnode->prev=cur;
       		 	if(cur->next)
				{
       		   		newdlistnode->next=cur->next;
        	  		cur->next->prev=newdlistnode;
        		}	
				else
				{
        	  		newdlistnode->next=NULL;
        		}
        		cur->next=newdlistnode;
        		cur=cur->next;
        		break;
      		}
    	}
	}
  	head=head->next;
  	while(head)
	{
    	printf("%c",head->data);
    	head=head->next;
  	}
}
