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
	

int main()
{
	int i=0;
	struct Process arr[] = {{1,7} , {2 , 4} , {3 , 6} ,{4,2} ,{5, 8}};
	int n = sizeof(arr) / 	sizeof(arr[0]);
	qsort((void*)arr, n, sizeof(arr[0]), compare);
	return 0;	
}
