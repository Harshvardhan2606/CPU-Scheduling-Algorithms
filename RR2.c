#include<stdio.h>
int main()
{
	int n,q;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the duration of quanta: ");
	scanf("%d",&q);
	int A[n][7];
	for (int i=0;i<n;i++)
	{
		A[i][0]=i+1;
		printf("Enter Arrival Time of Process P%d : ",i+1);
		scanf("%d",&A[i][1]);
		printf("Enter Burst Time of Process P%d : ",i+1);
		scanf("%d",&A[i][2]);
	}
	int rem[n];
	int done=0;
	int clk=0;
	for (int i=0;i<n;i++)
	{
		rem[i]=A[i][2];
		if (A[i][2]==0)
		{
			A[i][3]=A[i][1];
			A[i][4]=0;
			A[i][5]=0;
			A[i][6]=0;
			done++;
		}
		else A[i][6]=-1;
	}
	while (done<n)
	{
		int ready=0;
		for (int i=0;i<n;i++)
		{
			if (A[i][1]<=clk && rem[i]>0)
			{
				ready=1;
				break;
			}
		}
		if (ready)
		{
			for (int i=0;i<n;i++)
			{
				if (A[i][1]<=clk && rem[i]>0)
				{
					if (A[i][6]==-1) A[i][6]=clk-A[i][1];
					if (rem[i]>q)
					{
						clk+=q;
						rem[i]-=q;
					}
					else
					{
						clk+=rem[i];
						rem[i]=0;
						A[i][3]=clk;
						done++;
					}
				}
			}
		}
		else clk++;
	}
	for (int i=0;i<n;i++)
	{
		A[i][4]=A[i][3]-A[i][1];
		A[i][5]=A[i][4]-A[i][2];
	}
	printf("\nPID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\tRT\n");
	for (int i=0;i<n;i++) printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",A[i][0],A[i][1],A[i][2],A[i][3],A[i][4],A[i][5],A[i][6]);
	return 0;	
}
