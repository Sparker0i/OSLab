#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
	printf("I am a process with PID %d\n" , (int) getpid());
}
