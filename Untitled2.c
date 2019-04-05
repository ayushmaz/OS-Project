#include<stdio.h>
#include<stdbool.h>
#include<conio.h>

struct Process
{
	int process_id;
	int burst_time;
};

void sorting(struct Process temp[] ,  int n)
{
	int a;
	int i , j ;
	temp[n].burst_time=9999;
	for(j= 0 ; j < n; j++)
	{
		for(i = 0 ; i<=j ; i++)
		{
			if(temp[i].burst_time > temp[i+1].burst_time)
			{
			a = temp[i+1].burst_time;
			temp[i+1].burst_time = temp[i].burst_time;
			temp[i].burst_time = a;
			}
		}
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
	
}
int main()
{
	int i=0;
	struct Process arr[] = {{1,7} , {2 , 4} , {3 , 6} ,{4,2} ,{5, 8}};
	int n = sizeof(arr) / 	sizeof(arr[0]);
	sorting(arr,n);
	return 0;	
}
