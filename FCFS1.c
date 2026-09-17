#include<stdio.h>
int main()
{
	int n;
	printf ("Enter the number of Processes:");
	scanf ("%d",&n);
	int A[n][6];
	for (int i=0;i<n;i++)
	{
		A[i][0]=i+1;
		A[i][1]=0;
		printf ("Enter Burst Time for Process P%d:",i+1);
		scanf("%d",&A[i][2]);
	}
		A[0][3]=A[0][2];
	for (int i=1;i<n;i++)
	{
		A[i][3]=A[i-1][3]+A[i][2];
	}
	for (int i=0;i<n;i++)
	{
		A[i][4]=A[i][3];
		A[i][5]=A[i][4]-A[i][2];
	}
	printf("\nPID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
	for (int i=0;i<n;i++) printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",A[i][0],A[i][1],A[i][2],A[i][3],A[i][4],A[i][5]);
	return 0;
}
