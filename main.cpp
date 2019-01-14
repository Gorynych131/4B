#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

#include "func.h"
#include "matrix.h"
#include "vector.h"


typedef struct _ARGS
{
  double *matrix;       /* матрица */
  double *vector;       /* вектор */
  double *result;       /* результирующий вектор */
  int n;                /* размер матрицы и векторов */
  int thread_num;       /* номер задачи */
  int total_threads;    /* всего задач */
} ARGS;


static long int threads_total_time = 0;
static pthread_mutex_t threads_total_time_mutex = PTHREAD_MUTEX_INITIALIZER;




static void * matrix_mult_vector_threaded (void *pa)
{
  ARGS *pargs = (ARGS*)pa;
  long int t;
  int i;

  printf ("Thread %d started\n", pargs->thread_num);
  t = get_time ();      /* время начала работы */
  for (i = 0; i < N_TESTS; i++)
  {
    matrix_mult_vector (pargs->matrix, pargs->vector,
                        pargs->result, pargs->n,
                        pargs->thread_num,
                        pargs->total_threads);
    printf ("Thread %d mult %d times\n",
            pargs->thread_num, i);
  }
  t = get_time () - t;  /* время конца работы */

  /* Суммируем времена работы */
  /* "захватить" mutex для работы с threads_total_time */
  pthread_mutex_lock (&threads_total_time_mutex);
  threads_total_time += t;
  /* "освободить" mutex */
  pthread_mutex_unlock (&threads_total_time_mutex);
  printf ("Thread %d finished, time = %ld\n",
          pargs->thread_num, t);

  return 0;
}






int main(int argc, char **argv){
   
    
    
    
    if (argc != 3
      || !(nthreads = atoi (argv[1]))
      || !(n = atoi (argv[2])))
    {
      printf ("Usage: %s nthreads n\n", argv[0]);
      return 1;
    }

  if (!(threads = (pthread_t*)
                  malloc (nthreads * sizeof (pthread_t))))
    {
      fprintf (stderr, "Not enough memory!\n");
      return 1;
    }
  if (!(args = (ARGS*) malloc (nthreads * sizeof (ARGS))))
    {
      fprintf (stderr, "Not enough memory!\n");
      return 2;
    }

    
    
    
    
    /* массив идентификаторов созданных задач */
  pthread_t * threads;
  /* массив аргументов для созданных задач */
  ARGS * args;
  /* число создаваемых задач */
  int nthreads;
  /* астрономическое время работы всего процесса */
  long int t_full;
    
    
    
    //step 1
    FILE* in = fopen("in.txt", "r");
    if (in == NULL) {
        perror("Could not open input file");
    return (-1);
    }
    // end 1
    
    
    //step 2
    int n;
    fscanf(in, "%d", &n);
    int i;    
    double *d = new double[ n * n ];
    double *a = new double[ n * n ];
    double *check = new double[ n * n ];
    
    
    
    
    one (d, n);
    
    for( i = 0; i < n * n; i++){
        fscanf(in, "%lf", &a[i]);
    }
    
    fclose(in);
    
    for(i = 0; i < n * n; i++){
        check[i] = a[i];
    }
    //end 2
    
    //step 3
    
    for (i = 0; i < n - 1; i++){
        refvecm (a, d, n, i);
    }
    
    gauss (a, n);
    mult (d, a, n);
    pmat (d, n);
    
            
    //end 3
    //check
     mult (d, check, n);
                            pmat (d, n);
                            
                            
    double *matrix = new double[ n * n ];
    double *vector = new double[ n ];
    double *result = new double[n];
    
    

/* Инициализация аргументов задач */
       
  /* Засекаем астрономическое время начала работы задач*/
  t_full = get_full_time ();
  
  //
    int yu; int o;
    for(yu = 0; i < n; yu++){
        line(a, vector, n, yu);
        
        for (i = 0; i < nthreads; i++)
        {
            args[i].matrix = check;
            args[i].vector = vector;
            args[i].result = result;
            args[i].n = n;
            args[i].thread_num = i;
            args[i].total_threads = nthreads;
        }
    
    
    
    /* Запускаем задачи */
  for (o = 0; o < nthreads; o++)
    {
      if (pthread_create (threads + o, 0,
                          matrix_mult_vector_threaded,
                          args + o))
        {
          fprintf (stderr, "cannot create thread #%d!\n",
                   o);
          return 10;
        }
    }
/* Ожидаем окончания задач */
  for (o = 0; o < nthreads; o++)
    {
      if (pthread_join (threads[o], 0))
        fprintf (stderr, "cannot wait thread #%d!\n", o);
    }
    
    pvec(result, n);
    
        
        
    }

    
   
                            
                            
                            
                            
                            
                            
                            
}
