#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main()
{
	int pid;
	if ((pid = fork()) < 0)
		exit(1);
	if (pid == 0)
	{
		printf("Value of PID : %d\n" , getpid());
		execlp("/bin/ls" , "-l" , NULL);
		exit(1);
	}
}
