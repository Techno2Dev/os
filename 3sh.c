#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define K 2
int A [5][5];
int B [5][5];
int C [5][5];

struct v {
   int i;
  int j;
}*data;

void *matrix(void *param);
int main()
 {

   int M,N,i,j, count=0;
    printf("\nenter number of rows and column");
    scanf("%d%d",&M,&N);
    printf("enter %d elements of first matrix",M*N);
    for(i=0;i<M;i++)
     {
       for(j=0;j<N;j++)
        {
              scanf("%d",&A[i][j]);
            }
    }
    printf("enter %d elements of second matrix",M*N);
    for(i=0;i<M;i++)
     {
       for(j=0;j<N;j++)
        {
              scanf("%d",&B[i][j]);
            }
    }
   for(i=0;i<M;i++)
    {
      for(j=0;j<N;j++)
       {

         struct v *data = (struct v *) malloc(sizeof(struct v));
         data->i=i;
         data->j=j;
         pthread_t tid;
         pthread_create(&tid,NULL,matrix,data);
         pthread_join(tid, NULL);
          printf("thread num:%d\n",count);
         count++;
      }
   }

  
   for(i = 0; i < M; i++) {
      for(j = 0; j < N; j++) {
         printf("%d ", C[i][j]);
      }
      printf("\n");
   }
}

void *matrix(void *param)
 {
   struct v *data = param;
   int n, sum = 0;
   for(n = 0; n< K; n++){
      sum += A[data->i][n] * B[n][data->j];
   }
   C[data->i][data->j] = sum;
    pthread_exit(0);
}
