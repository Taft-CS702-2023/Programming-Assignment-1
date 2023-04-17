#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
    printf("This is the parent process\n");
    int *arr = malloc(10 * sizeof(int));
    if(arr == NULL)
    {
        printf("Error while allocating memory\n");
        exit(EXIT_FAILURE);
    }
    pid_t pid = fork();
    if(pid == -1)
    {
        printf("Something went wrong when creating child process\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        printf("This is the child process\n");
        free(arr);
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Parent process is waiting for child process to terminate\n");
        wait(NULL);
        printf("aborting parent process\n");
        abort();
        free(arr);
        
        exit(EXIT_SUCCESS);
    }
}
