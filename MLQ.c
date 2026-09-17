#include<stdio.h>
#include<limits.h>
int main()
{
	int n1,n2,n3,q;
	printf("We have the following three queues:-\n");
	printf("Queue 1: First Come First Serve Scheduling.\n");
	printf("Queue 2: Round Robin Scheduling.\n");
	printf("Queue 3: Shortest Job First Scheduling.\n");
	printf("\nQueue 1:-\n");
	printf("Enter the number of Processes: ");
	scanf("%d",&n1);
	int A[n1][7];
	for (int i=0;i<n1;i++)
	{
		A[i][0]=i+1;
		printf("Enter Arrival Time of Process P%d: ",i+1);
		scanf("%d",&A[i][1]);
		printf("Enter the Burst time of Process P%d: ",i+1);
		scanf("%d",&A[i][2]);
		A[i][3]=-1;
		A[i][6]=-1;
	}
	printf("\nQueue 2:-\n");
	printf("Enter the number of processes: ");
	scanf("%d",&n2);
	printf("Enter time quantum: ");
	scanf("%d",&q);
	int B[n2][7];
	int rem[n2];
	for (int i=0;i<n2;i++)
	{
		B[i][0]=i+1;
		printf("Enter Arrival Time of Process P%d: ",i+1);
		scanf("%d",&B[i][1]);
		printf("Enter the Burst time of Process P%d: ",i+1);
		scanf("%d",&B[i][2]);
		B[i][3]=-1;
		B[i][6]=-1;
		rem[i]=B[i][2];
	}
	printf("\nQueue 3:-\n");
	printf("Enter the number of processes: ");
	scanf("%d",&n3);
	int C[n3][7];
	for (int i=0;i<n3;i++)
	{
		C[i][0]=i+1;
		printf("Enter Arrival Time of Process P%d: ",i+1);
		scanf("%d",&C[i][1]);
		printf("Enter the Burst time of Process P%d: ",i+1);
		scanf("%d",&C[i][2]);
		C[i][3]=-1;
		C[i][6]=-1;
	}
	int clk=0;
	int donea=0;
	int doneb=0;
	int donec=0;
	while (donea<n1 || doneb<n2 || donec<n3)
	{
		int exit=0;
		for (int i=0;i<n1;i++)
		{
			if (A[i][3]==-1 && A[i][1]<=clk)
			{
				if (A[i][6]==-1) A[i][6]=clk-A[i][1];
				clk+=A[i][2];
				A[i][3]=clk;
				A[i][4]=A[i][3]-A[i][1];
				A[i][5]=A[i][4]-A[i][2];
				donea++;
				exit=1;
				break;
			}
		}
		if (exit) continue;
		for (int i=0;i<n2;i++)
		{
			if (rem[i]>0 && B[i][1]<=clk)
			{
				if (B[i][6]==-1) B[i][6]=clk-B[i][1];
				int pass = (rem[i]>q)?q:rem[i];
				clk+=pass;
				rem[i]-=pass;
				if (rem[i]==0)
				{
					B[i][3]=clk;
					B[i][4]=B[i][3]-B[i][1];
					B[i][5]=B[i][4]-B[i][2];
					doneb++;
				}
				exit=1;
				break;
			}
		}
		if (exit) continue;
		int index=-1;
		int boss=INT_MAX;
		for (int i=0;i<n3;i++)
		{
			if (C[i][3]==-1 && C[i][1]<=clk && C[i][2]<=boss)
			{
				boss=C[i][2];
				index=i;
			}
		}
		if (index!=-1)
		{
			if (C[index][6]==-1) C[index][6]=clk-C[index][1];
			clk+=C[index][2];
			C[index][3]=clk;
			C[index][4]=C[index][3]-C[index][1];
			C[index][5]=C[index][4]-C[index][2];
			donec++;
			exit=1;
		}
		if (!exit) clk++;
	}
	printf("\nQueue 1:-");
	printf("\nPID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\tRT\n");
	for (int i=0;i<n1;i++) printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",A[i][0],A[i][1],A[i][2],A[i][3],A[i][4],A[i][5],A[i][6]);
	printf("\nQueue 2:-");
	printf("\nPID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\tRT\n");
	for (int i=0;i<n2;i++) printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",B[i][0],B[i][1],B[i][2],B[i][3],B[i][4],B[i][5],B[i][6]);
	printf("\nQueue 3:-");
	printf("\nPID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\tRT\n");
	for (int i=0;i<n3;i++) printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",C[i][0],C[i][1],C[i][2],C[i][3],C[i][4],C[i][5],C[i][6]);
	return 0;
}
