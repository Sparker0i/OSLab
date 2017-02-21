#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
	int pid;
	printf("I am a process with PID %d\n" , getpid());
	pid = fork();
	printf("Fork returned %d\n" , pid);
	printf("I am a process with PID %d\n" , getpid());
	pid = fork();
	printf("Fork returned %d\n" , pid);
	printf("I am a process with PID %d\n" , getpid());
}

