#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
	int pid;
	printf("I am a process with PID %d\n" , getpid());
	pid = fork();
	if (pid < 0)
		perror("Fork Failed");
	else if (pid == 0)
		printf("I am the child with PID %d\n" , getpid());
	else
		printf("I am the parent with PID %d\n" , getpid());
	pid = fork();
	if (pid < 0)
		perror("Fork Failed");
	else if (pid == 0)
		printf("I am the child with PID %d\n" , getpid());
	else
		printf("I am the parent with PID %d\n" , getpid());
}
