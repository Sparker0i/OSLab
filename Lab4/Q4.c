#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	int n = 5;
	int i = 0;
	
	printf("Creating %d children\n", n);
	printf("I am a parent, my PID is %d\n" , getpid());
	
	for (i = 0; i < n; ++i)
	{
		pid_t pid = fork();
		if (pid == 0)
		{
			printf("I am a child, my PID is %d, parent PID is %d\n" , getpid() , getppid());
			exit(0);	
		}
	}
}
