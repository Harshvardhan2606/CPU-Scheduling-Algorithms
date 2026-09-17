#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int A[n][6];
	for (int i=0;i<n;i++)
	{
		A[i][0]=i+1;
		printf("Enter Arrival Time of P%d:",i+1);
		scanf("%d",&A[i][1]);
		printf("Enter Burst Time of P%d:",i+1);
		scanf("%d",&A[i][2]);
	}
	int R[n][6];
	for (int i=0;i<n;i++) R[i][1]=A[i][1];
	for (int i=0;i<n-1;i++)
	{
		for (int j=0;j<n-i-1;j++)
		{
			if (R[j][1]>R[j+1][1])
			{
				int t=R[j][1];
				R[j][1]=R[j+1][1];
				R[j+1][1]=t;
			}
		}
	}
	int added[n];
	for (int i=0;i<n;i++) added[i]=0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (R[i][1]==A[j][1] && added[j]==0)
			{
				R[i][0]=A[j][0];
				R[i][2]=A[j][2];
				added[j]=1;
				break;
			}
		}
	}
	int clk=0;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		if (R[i][1]==0) arr[i]=1;
		else arr[i]=0;
	}
	int t=0;
	while (t<n)
	{
		for (int i=0;i<n;i++)
		{
			if (R[i][1]<=clk) arr[i]=1;
		}
		if (arr[t]==1)
		{
			clk+=R[t][2];
			R[t][3]=clk;
			t++;
		}
		else clk++;
	}
	for (int i=0;i<n;i++)
	{
		R[i][4]=R[i][3]-R[i][1];
		R[i][5]=R[i][4]-R[i][2];
	}	
	printf("\nPID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
	for (int i=0;i<n;i++) printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",R[i][0],R[i][1],R[i][2],R[i][3],R[i][4],R[i][5]);
	return 0;
}
