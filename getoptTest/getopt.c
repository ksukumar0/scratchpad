#include <stdio.h>

// Program to illustrate the getopt() 
// function in C 

#include <stdio.h> 
#include <unistd.h> 
#include <pthread.h>

static int count = 0;

struct argPassStruct{
    int argc;
    char **argv;
};

void printArgs(void *ptr)
{
    struct argPassStruct *s = (struct argPassStruct *) ptr;
    char **argv = s->argv;
    printf("Argc= %d\nArgv: \n",s->argc);
    //printf("Argc= %d\nArgv= %s\n",s->argc, *(argv));
    int i = 0;
    while(argv[i] != 0)
    {
        //printf("%s\n",argv[i]);
        i++;
    }

}

pthread_mutex_t lock;

void *fnptr(void *ptr)
{
    pthread_mutex_lock(&lock);
    optind = 1;
    count++;
    printf("Thread ID: %ld\n", pthread_self());

    int argc = ((struct argPassStruct *) ptr)->argc;
    char **argv = ((struct argPassStruct *) ptr)->argv;
    printArgs(ptr);
    int opt;
    // put ':' in the starting of the 
    // string so that program can
    //distinguish between '?' and ':' 
	//original
	//while((opt = getopt(argc, argv, “:if:lrx”)) != -1)
	while((opt = getopt(argc, argv, ":if:lrxo::")) != -1 )
    {
        printf("opt: %c\n",(char) opt);
        switch(opt)
        {
            case 'i':
            case 'l':
            case 'r':
                printf("option: %c\n", opt);
                break;
            case 'f':
                printf("filename: %s\n", optarg);
                break;
            case ':':
                   printf("option needs a value\n");
                   break;
            case '?':
                   printf("unknown option: %c\n", optopt);
                   break;
            case 'o':
                   printf("option: o\nArgument:%s\n",optarg);
                   break;
        }
    }
    pthread_mutex_unlock(&lock);

    // optind is for the extra arguments 
    // which are not parsed 
    //for(; optind < argc; optind++){
    //    printf("extra arguments: %s\n", argv[optind]);
    //}

    //printf("optind: %d\nopterr: %d\noptopt: %d\nopt:%d\n",optind,opterr,optopt,opt);
}

int main(int argc, char *argv[])
{
#define MAX_WORKER_THREADS 8
    pthread_t thread[MAX_WORKER_THREADS];
    struct argPassStruct s[MAX_WORKER_THREADS];
    //char **av = {"./getopt","-f","file.txt","-i","-oargs"};
    char av[] = "-f";
    int i;
    printf("Creating %d Threads\n", MAX_WORKER_THREADS);
    for(i=0;i<MAX_WORKER_THREADS;i++)
    {
        s[i].argc = argc;
        s[i].argv = argv;
        pthread_create(&thread[i],NULL,fnptr,(void *) &s[i]);
    }
    for(i=0;i<MAX_WORKER_THREADS;i++)
    {
        pthread_join(thread[i], 0);
    }
    printf("total number of threads are %d\n", count);
    return 0;
}

