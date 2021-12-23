#include "types.h"
#include "stat.h"
#include "user.h"

int stack[4096] __attribute__ ((aligned (4096)));
int x=0;

int main(int argc, char *argv[]){
    int tid = clone(stack);
    
    if (tid < 0)
    {
        printf(2, "error!\n");
    } else if (tid == 0)
    {
        for(;;){
            x++;
            sleep(100);
        }
    }else{
        for(;;){
            printf(1, "x = %d\n", x);
            sleep(100);
        }
    }
    
    exit();
}