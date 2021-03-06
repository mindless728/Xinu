#include <stddef.h>

/*return page table address*/
void * get_page_table_addr(void){
    //TODO code goes here, herp derp
    return (void *)0;
}

/*return the physical address*/
void * get_page_table_addr_phys(void){
    //TODO code goes here herp derp
    return (void *)0;
}

/*sets address of the page table to use*/
void * set_page_table_addr(void * table){
    //TODO code goes here herp derp
    return (void *)0;
}

/**
Turn on the MMU by loading a 1 i the first bit of co procerssor 15.
Hopefully.

**/

void mmu_enable(void){
    asm(
        "mrc p15, 0, r0, c1, c0, 0\n"
        //or with 0x1 to set LSB, after this MMU is turned on!
        "orr r0, r0, #0x1\n"
        "mcr p15, 0, r0, c1, c0, 0"
    );
}

/**
Turn the MMU off by loading a 0 in the first bit of co processor 15.
Hopefully.
**/
void mmu_disable(void){
    asm(
        "mrc p15, 0, r0, c1, c0, 0\n"
        //and with ~(0x1) to unset LSB, after this MMU is turned off!
        "and r0, r0, #0xFFFFFFFE\n"
        "mcr p15, 0, r0, c1, c0, 0\n"
    );
}

void mmu_init(void){

}

unsigned int mmu_is_enabled(void){
    asm("mrc p15, 0, r0, c1, c0, 0");
    register int r0 asm("r0");

    unsigned int * mmu = r0;

    return *mmu;
}
