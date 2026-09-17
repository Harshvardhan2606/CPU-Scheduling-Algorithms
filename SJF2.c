#include<stdio.h>
#include<limits.h>
int main()
{
	int n;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int A[n][6];
	for (int i=0;i<n;i++)
	{
		A[i][0]=i+1;
		printf("Enter Arrival Time of process P%d: ",i+1);
		scanf("%d",&A[i][1]);
		printf("Enter Burst Time of process P%d: ",i+1);
		scanf("%d",&A[i][2]);
	}
	int done[n];
	for (int i=0;i<n;i++) done[i]=0;
	int clk=0;
	int rem=n;
	while (rem!=0)
	{
		int index=-1;
		int fast=INT_MAX;
		for (int i=0;i<n;i++)
		{
			if (A[i][1]<=clk && done[i]==0)
			{
				if (A[i][2]<fast)
				{
					fast =A[i][2];
					index=i;
				}
			}
		}
		if (index==-1) clk++;
		else
		{
			clk+=A[index][2];
			A[index][3]=clk;
			A[index][4]=A[index][3]-A[index][1];
			A[index][5]=A[index][4]-A[index][2];
			done[index]=1;
			rem--;
		}
	}
	printf("\nPID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
	for (int i=0;i<n;i++) printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",A[i][0],A[i][1],A[i][2],A[i][3],A[i][4],A[i][5]);
	return 0;
}
