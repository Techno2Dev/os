#include<stdio.h>
#include<semaphore.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
pthread_mutex_t work_mutex[5];
void* phil1()
{
  while (1)
   {
      pthread_mutex_lock(&work_mutex[0]);
      pthread_mutex_lock(&work_mutex[1]);
      printf("\nphil1 is eating");
      sleep(3);
      pthread_mutex_unlock(&work_mutex[0]);
      pthread_mutex_unlock(&work_mutex[1]);
      printf("\nphil1 realeasing fork");
      printf("\nphil1 is thinking");
    }
    pthread_exit(0);
}
void* phil2()
{
  while (1)
   {
      pthread_mutex_lock(&work_mutex[1]);
      pthread_mutex_lock(&work_mutex[2]);
      printf("\nphil2 is eating");
      sleep(3);
      pthread_mutex_unlock(&work_mutex[1]);
      pthread_mutex_unlock(&work_mutex[2]);
      printf("\nphil2 realeasing fork");
      printf("\nphil2 is thinking");
    }
    pthread_exit(0);
}

void* phil3()
{
  while (1)
   {
      pthread_mutex_lock(&work_mutex[2]);
      pthread_mutex_lock(&work_mutex[3]);
      printf("\nphil3 is eating");
      sleep(3);
      pthread_mutex_unlock(&work_mutex[2]);
      pthread_mutex_unlock(&work_mutex[3]);
      printf("\nphil3 realeasing fork");
      printf("\nphil3 is thinking");
    }
    pthread_exit(0);
}


void* phil4()
{
  while (1)
   {
      pthread_mutex_lock(&work_mutex[3]);
      pthread_mutex_lock(&work_mutex[4]);
      printf("\nphil3 is eating");
      sleep(3);
      pthread_mutex_unlock(&work_mutex[3]);
      pthread_mutex_unlock(&work_mutex[4]);
      printf("\nphil3 realeasing fork");
      printf("\nphil3 is thinking");
    }
    pthread_exit(0);
}

void* phil5()
{
  while (1)
   {
      pthread_mutex_lock(&work_mutex[4]);
      pthread_mutex_lock(&work_mutex[5]);
      printf("\nphil5 is eating");
      sleep(3);
      pthread_mutex_unlock(&work_mutex[4]);
      pthread_mutex_unlock(&work_mutex[5]);
      printf("\nphil5 realeasing fork");
      printf("\nphil5 is thinking");
    }
    pthread_exit(0);
}
int main()
{
      int res,i;
      pthread_t ph1,ph2,ph3,ph4,ph5;
      for(i=0;i<5;i++)
      {
        res=pthread_mutex_init(&work_mutex[i],NULL);
        if (res!=0)
         {
           printf("\nmutex not initilize");
            }
      }
      pthread_create(&ph1,NULL,phil1,NULL);
      pthread_create(&ph2,NULL,phil2,NULL);
      pthread_create(&ph3,NULL,phil3,NULL);
        pthread_create(&ph4,NULL,phil4,NULL);
        pthread_create(&ph5,NULL,phil5,NULL);
      pthread_join(ph1,NULL);
      pthread_join(ph2,NULL);
      pthread_join(ph3,NULL);
      pthread_join(ph4,NULL);
      pthread_join(ph5,NULL);
      return 0;
}
