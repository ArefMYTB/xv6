#include "types.h"
#include "stat.h"
#include "user.h"

#define PAGESIZE 4096

int 
thread_create(void(*fn)(void *), void *arg)
{

    //Allocating 2 * pageSize for ptr in heap of father process
    void *fptr = malloc(2* (PAGESIZE)); // multiply by 2 for a situation to make it align manually
    void *stack;

    if(fptr == 0)
    return -1;

    int mod = (uint)fptr % PAGESIZE;

    // for assigning page-allined space to stack so that start of stack is multiple of 4096
    if(mod == 0)
        stack = fptr; // is align
    else
        stack = fptr + (PAGESIZE - mod); // make align
    
    int thread_id = clone((void*)stack); // clone is out threat_create

    //clone fail cenario
    if(thread_id < 0)
        printf(1, "clone failed\n");

    //child
    else if(thread_id == 0){
        //call the function passed to thread_create
        (fn)(arg);
        //free space when fuction is finished
        free(stack);
        exit();
    }
        return thread_id; 

}












