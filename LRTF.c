//question no.12 by prasanth
#include<stdio.h>
int main()
{	
	int pid[3];//={2132,2102,2453};//process id
	int bt[3];//={2,4,8};//burst time
	int at[3];//={0,0,0};//arrival time
	int c1=0,c2=0,c3=0;
	printf("Longest remaining time first: \n");

	for(int i1 =0; i1<3; i1++){
		printf("\n");		
		printf("Enter process id: ");
		scanf("%d",&pid[i1]);
		printf("Enter Burst Time for P%d: ",i1+1);
		scanf("%d",&bt[i1]);
		printf("Enter Arrival Time for P%d: ",i1+1);
		scanf("%d",&at[i1]);	
	}

	for(int i=2;i>=0;i--)
	
	{	
	  for(int j=bt[i];j>0;j--)
	  {
	
		if(bt[i]>bt[i-1] && bt[i]>bt[i-2])
		{
			bt[i]--;
			c1=c1+1;
			
		}
		else if(bt[i]==bt[i-1])
		{
			if(pid[i]>pid[i-1])
			{
				bt[i-1]--;
				c2=c2+1;
			}
			else
			{
			bt[i]--;
			c1=c1+1;
			}
		}
		else if(bt[i]==bt[i-2])
		{	if(pid[i]>pid[i-2])
			{
				bt[i-2]--;
				c3=c3+1;
			}
			else
			{
			bt[i]--;
			c1=c1+1;
			}
		}

		else if(bt[i-1]==bt[i-2])
		{
			if(pid[i-1]<pid[i-2])
			{
				bt[i-1]--;
				c2=c2+1;
			}
			else
			{
			bt[i-2]--;
			c3=c3+1;
			}
		}
		
	  }
	}

int avg_tat=(c1+c2+c3)/3;
printf("average TAT :%d\n",avg_tat);
int wt1=c1-bt[0];
int wt2=c2-bt[1];
int wt3=c3-bt[2];
int avg_wt=(wt1+wt2+wt3)/3;
printf("average waiting time:%d\n",avg_wt);

}
