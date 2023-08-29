#include <stdio.h>
#include <stdbool.h>
#define MAX_PROCESSES 10
struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int turnaround_time;
    int waiting_time;
};
void fcfs(struct Process processes[],int n)
{
	int time=0,i;
	for(i=0;i<n;i++)
	{
		printf("Process %d starts at %d and ends at %d\n",i+1,time,time+processes[i].burst_time);
	processes[i].turnaround_time	+= time + processes[i].burst_time -processes[i].arrival_time ;
    processes[i].waiting_time += processes[i].turnaround_time-processes[i].burst_time ;
    time += processes[i].burst_time;
	}
	printf("P\tTT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\n",i+1,processes[i].turnaround_time,processes[i].waiting_time);
	}
}
void sjf(struct Process processes[],int n)
{
	int sum=0,time,smallest,i;
	for(i=0;i<n;i++)
	sum+=processes[i].burst_time;
	processes[9].burst_time=999;
	for(time=0;time<sum;)
	{
		smallest=9;
		for(i=0;i<n;i++)
		{
			if (processes[i].arrival_time <= time && processes[i].burst_time > 0 && processes[i].burst_time < processes[smallest].burst_time)
        smallest = i;
		}
		printf("Process %d starts at %d and ends at %d\n",smallest+1,time,time+processes[smallest].burst_time);
	processes[smallest].turnaround_time	+= time + processes[smallest].burst_time -processes[smallest].arrival_time ;
    processes[smallest].waiting_time += processes[smallest].turnaround_time-processes[smallest].burst_time ;
    time += processes[smallest].burst_time;
    processes[smallest].burst_time = 0;
	}
	printf("P\tTT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\n",i+1,processes[i].turnaround_time,processes[i].waiting_time);
	}
	
}
void pri(struct Process processes[],int n)
{
	int sum=0,time,smallest,i;
	for(i=0;i<n;i++)
	sum+=processes[i].burst_time;
	processes[9].priority=100;
	for(time=0;time<sum;)
	{
		smallest=9;
		for(i=0;i<n;i++)
		{
			if (processes[i].arrival_time <= time && processes[i].burst_time > 0 && processes[i].priority < processes[smallest].priority)
        smallest = i;
		}
		printf("Process %d starts at %d and ends at %d\n",smallest+1,time,time+processes[smallest].burst_time);
	processes[smallest].turnaround_time	+= time + processes[smallest].burst_time -processes[smallest].arrival_time ;
    processes[smallest].waiting_time += processes[smallest].turnaround_time-processes[smallest].burst_time ;
    time += processes[smallest].burst_time;
    processes[smallest].priority = 100;
	}
	printf("P\tTT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\n",i+1,processes[i].turnaround_time,processes[i].waiting_time);
	}
}
int main() {
    int n,i,choice;
    struct Process processes[MAX_PROCESSES];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].turnaround_time = 0;
        processes[i].waiting_time = 0;
    }
fcfs(processes,n);
}
