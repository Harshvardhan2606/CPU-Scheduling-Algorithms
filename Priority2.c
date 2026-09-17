#include<stdio.h>
#include<limits.h>
int main()
{
	int n;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int A[n][8];
	for (int i=0;i<n;i++)
	{
		A[i][0]=i+1;
		printf("Enter Arrival Time for Process P%d: ",i+1);
		scanf("%d",&A[i][1]);
		printf("Enter Burst Time for Process P%d: ",i+1);
		scanf("%d",&A[i][2]);
		printf("Enter Priority for Process P%d: ",i+1);
		scanf("%d",&A[i][3]);
	}
	int clk=0;
	int rem[n];
	int done[n];
	int exit=0;
	for (int i=0;i<n;i++)
	{
		rem[i]=A[i][2];
		if (A[i][2]==0)
		{
			A[i][4]=A[i][1];
			A[i][5]=0;
			A[i][6]=0;
			A[i][7]=0;
			done[i]=1;
			exit++;
		}
		else
		{
			A[i][7]=-1;
			done[i]=0;
		}
	}
	while (exit<n)
	{
		int index=-1;
		int boss=INT_MAX;
		for (int i=0;i<n;i++)
		{
			if (A[i][1]<=clk && done[i]==0)
			{
				if (A[i][3]<boss)
				{
					boss=A[i][3];
					index=i;
				}
			}
		}
		if (index==-1) clk++;
		else
		{
			if (A[index][7]==-1) A[index][7]=clk-A[index][1];
			rem[index]--;
			clk++;
			if (rem[index]==0)
			{
				A[index][4]=clk;
				done[index]=1;
				exit++;
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		A[i][5]=A[i][4]-A[i][1];
		A[i][6]=A[i][5]-A[i][2];
	}
	printf("\nPID\t\tAT\t\tBT\t\tPriority\tCT\t\tTAT\t\tWT\t\tRT\n");
	for (int i=0;i<n;i++) printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",A[i][0],A[i][1],A[i][2],A[i][3],A[i][4],A[i][5],A[i][6],A[i][7]);
	return 0;
}
