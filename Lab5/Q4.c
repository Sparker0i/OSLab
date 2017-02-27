//AADITYA MENON
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

void main()
{
	int shmid_i , shmid_flag , status;
	int *flag;
	char *a , *b;
	int i;
	
	shmid_i = shmget(IPC_PRIVATE , 100 * sizeof(char) , 0777|IPC_CREAT);
	shmid_flag = shmget(IPC_PRIVATE , 1 * sizeof(int) , 0777|IPC_CREAT);
	
	if (fork() == 0)
	{
		flag = (int *) shmat(shmid_flag , 0 , 0);
		b = (char *) shmat(shmid_i , 0 , 0);
		while (*flag != 1)
			sleep(1);
		for (i = 0; i < strlen(b) ; ++i)
		{
			if (b[i] >= 97 && b[i] <= 123)
				b[i] = b[i] - 32;
		}
		printf("%s\n" , b);
		shmdt(b);
		shmdt(flag);
	}
	else
	{
		flag = (int *) shmat(shmid_flag , 0 , 0);
		a = (char *) shmat(shmid_i , 0 , 0);
		*flag = 0;
		gets(a);
		*flag = 1;
		sleep(1);
		wait(&status);
		shmdt(a);
		shmctl(shmid_flag , IPC_RMID , 0);
		shmctl(shmid_i , IPC_RMID , 0);
	}
}

