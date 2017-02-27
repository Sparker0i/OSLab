#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main()
{
	int shmid , status;
	int *a , *b;
	int i;
	
	shmid = shmget(IPC_PRIVATE , 2 * sizeof(int) , 0777|IPC_CREAT);
	
	if (fork() == 0)
	{
		b = (int *) shmat(shmid , 0 , 0);
		while (b[1] != 1)
			sleep(1);
		for (i = 0; i < b[0]; ++i)
		{
			if (i % 2 == 1)
			{
				printf("%d " , i);
			}
		}
		shmdt(b);
	}
	else
	{
		a = (int *) shmat(shmid , 0 , 0);
		a[1] = 0;
		scanf("%d" , &a[0]);
		a[1] = 1;
		sleep(1);
		wait(&status);
		shmdt(a);
		shmctl(shmid , IPC_RMID , 0);
	}
}

