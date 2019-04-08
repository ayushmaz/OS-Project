#include<stdio.h>
#include<stdbool.h>
#include<conio.h>

struct Process
{
	int process_id;
	int burst_time;
};

int compare(void *p, void *q)  
{ 
    int a = ((struct Process *)p)->burst_time; 
    int b = ((struct Process *)q)->burst_time;  
    return (a - b); 
} 

void processWaitTime( struct Process arr[] , int n , int wt[])
{
	int i;
	
	wt[0] = 0; // initializing the 'process 1' waiting time as 0. 
	for(i = 0 ; i< n ; i++)
	{
		wt[i] = arr[i-1].burst_time + wt[i-1];
	}
	
}

void turnAroundTime(struct Process arr[] , int n , int wt[] , int tat[])
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		tat[i] = wt[i] + arr[i].burst_time; 
	}
}

void computePriority(int priority[] , int n , int wt[] , struct Process arr[])
{
	int i;
	for(i = 0; i< n ; i++)
	{
		priority[i] = 1 + (wt[i]/arr[i].burst_time);
	}

	
}

void averageTime(struct Process arr[] , int n)
{
	int wt[n] , tat[n], priority[n],i ;
	
	processWaitTime(arr , n , wt); //function call 
	
	turnAroundTime(arr , n , wt , tat) ; //function call
	
	computePriority(priority, n , wt , arr);
	
	printf(" Process\t Burst Time\t Waiting Time\t Turn Around Time\t Priority\n");
	
	for(i = 0 ; i< n ; i++){
		printf("   %d \t\t     %d \t\t     %d \t\t     %d \t\t       \t    %d\n" , arr[i].process_id,arr[i].burst_time,wt[i] , tat[i],priority[i]);}
	
}
	

int main()
{
	int i,k;
	x:
	printf("Enter the number of processes you want to enter : ");
	scanf("%d" , &k);
	if(k<=0)
	{
		printf("\nError! Enter Positive Values\n");
		goto x;
	}
	struct Process arr[k];
	for(i=0 ; i<k;i++)
	{
		y:
		printf("PROCESS %d\n" , i+1);
		printf("ENTER THE PROCESS ID : ");
		scanf("%d" , &arr[i].process_id);
		if(arr[i].process_id<=0)
		{
			printf("\nInvalid Process ID\n");
			goto y;
		}
		z:
		printf("ENTER THE BURST TIME : ");
		scanf("%d",&arr[i].burst_time);
		if(arr[i].burst_time<=0)
		{
			printf("\nInvalid Burst Time\n");
			goto z;
		}
	}
	int n = sizeof(arr) / 	sizeof(arr[0]);
	qsort((void*)arr, n, sizeof(arr[0]), compare);
	return 0;	
}
