#include <stdio.h>  
#include <string.h>
#include <pthread.h>  
  
pthread_rwlock_t	rwlock;
int count = 0;

/*线程一*/  
void thread_1(void)  
{  
    char *ch = NULL;
    while(1)
    {  
	pthread_rwlock_wrlock(&rwlock);
        printf("This is a pthread_1 : %d\n", count);  
	pthread_rwlock_unlock(&rwlock);
    }
}  
  
/*线程二*/  
void thread_2(void)
{
    while(1)
    {
	pthread_rwlock_rdlock(&rwlock);
	count++;
        printf("This is a pthread_2 : %d\n", count);  
	pthread_rwlock_unlock(&rwlock);
    }
}  
  
int main(void)  
{  
    pthread_t id_1,id_2;  
    int ret;  
/*创建线程一*/  
    ret=pthread_create(&id_1,NULL,(void  *) thread_1,NULL);  
    if(ret!=0)  
    {  
        printf("Create pthread error!\n");  
	return -1;  
    }  
/*创建线程二*/  
    ret=pthread_create(&id_2,NULL,(void  *) thread_2,NULL);  
    if(ret!=0)  
    {  
        printf("Create pthread error!\n");  
    	return -1;  
    }  
/*等待线程结束*/  
    pthread_join(id_1,NULL);  
    pthread_join(id_2,NULL);  
    return 0;  
}
