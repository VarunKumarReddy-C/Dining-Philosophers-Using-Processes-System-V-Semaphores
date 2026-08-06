#include"header.h"
void main()
{
	int id=semget(IPC_PRIVATE,5,IPC_CREAT|0664);
	if(id<0)
	{
		perror("semget");
		return;
	}
	int i,left,right,j,pid;
	struct sembuf v;
	for(i=0;i<5;i++)
		semctl(id,i,SETVAL,1);
	for(i=0;i<5;i++)
	{
		pid=fork();
		if(pid==0)
		{
			left=i;
			right=(1+i)%5;
			for(j=0;j<5;j++)
			{
				printf("Philosopher %d is Thinking\n",i);
				sleep(1);
				printf("Philosopher %d is Hungry\n",i);
				if(i%2==0)
				{
					v.sem_num=left;
					v.sem_op=-1;
					v.sem_flg=0;
					semop(id,&v,1);
					v.sem_num=right;
					v.sem_op=-1;
					v.sem_flg=0;
					semop(id,&v,1);
				}
				else
				{
					v.sem_num=right;
					v.sem_op=-1;
					v.sem_flg=0;
					semop(id,&v,1);
					v.sem_num=left;
					v.sem_op=-1;
					v.sem_flg=0;
					semop(id,&v,1);

				}
				printf("Philosopher %d picked Fork %d and Fork %d\n",i,left,right);
				printf("Philosopher %d is Eating\n",i);
				sleep(2);
				v.sem_num=left;
				v.sem_op=1;
				v.sem_flg=0;
				semop(id,&v,1);
				v.sem_num=right;
				v.sem_op=1;
				v.sem_flg=0;
				semop(id,&v,1);
				printf("Philosopher %d released Fork %d and Fork %d\n",i,left,right);
				printf("Philosopher %d Finished Eating\n",i);
			}
			exit(0);
		}
	}
	for(i=0;i<5;i++)
		wait(NULL);
	semctl(id,0,IPC_RMID);
}
