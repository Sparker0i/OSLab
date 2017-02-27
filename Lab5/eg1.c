#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void main()
{
	int shmid , status;
	int *a , *b;
	int i;
	
	shmid = shmget(IPC_PRIVATE , 2 * sizeof(int) , 0777|IPC_CREAT);
	
	if (fork() == 0)
	{
		b = (int *) shmat(shmid , 0 , 0);
		for (i = 0; i < 10; ++i)
		{
			sleep(2);
			printf("Child Reads : %d %d\n" , b[0] , b[1]);
		}
		
		shmdt(b);
	}
	else
	{
		a = (int *) shmat(shmid , 0 , 0);
		a[0] = 0;
		a[1] = 1;
		for (i = 0; i < 10; ++i)
		{
			sleep(2);
			a[0] += a[1];
			a[1] += a[0];
			printf("Parent Writes : %d %d\n" , a[0] , a[1]);
		}
		wait(&status);
		shmdt(a);
		shmctl(shmid , IPC_RMID , 0);
	}
}
