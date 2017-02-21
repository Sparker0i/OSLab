#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
	int childpid;
	int count1 = 0, count2 = 0;
	printf("Before it forks\n");
	childpid = fork();
	if (childpid == 0)
	{
		printf("This is a child process with PID %d\n" , getpid());
		while (count1 < 10)
		{
			printf("Child Process %d\n" , count1);
			sleep(2);
			count1++;
		}
	}
	else
	{
		printf("This is a parent process with PID %d\n" , getpid());
		while (count2 < 10)
		{
			printf("Parent Process %d\n" , count2);
			sleep(2);
			count2++;
		}
	}
}
