#include <thread.h>
#include "stacktrace.h"

int myfuncA(){
 register int stp asm("sp");
 int * stackPointer=stp;
 int i=5;
 int k=4;
 int j=3;
 int l=2;
 int m=1;
 printf("Before myfuncA returns\n\r");
 printf("The top of the stack %d\n\r",stackPointer[0]);
 printf("The second entry of the stack %d\n\r",stackPointer[1]);
 printf("The third  entry of the stack %d\n\r",stackPointer[2]);
 printf("The fourth entry of the stack %d\n\r",stackPointer[3]);
 printf("The fifth  entry of the stack %d\n\r",stackPointer[4]);
 printf("Overholt is a fine rye whiskey and this shows that we can make shell commands in Xinu!\n\r");
 return 0;
}

int myprogA(){
register int stp asm("sp");

//asm("mov %[stack],sp": [stack] "=r" (stp));
int * stackPointer=stp;
int i=5;
int k=4;
int j=3;
int l=2;
int m=1;
printf("Before I call myfuncA()\n\r");
printf("The top of the stack %d\n\r",stackPointer[0]);
printf("The second entry of the stack %d\n\r",stackPointer[1]);
printf("The third  entry of the stack %d\n\r",stackPointer[2]);
printf("The fourth entry of the stack %d\n\r",stackPointer[3]);
printf("The fifth  entry of the stack %d\n\r",stackPointer[4]);
myfuncA();
return 0;
}

void callProg(){
    int myprogA();
    resume(create(myprogA,1024,20,"my_proc_1",1));	
//myprogA();

}
