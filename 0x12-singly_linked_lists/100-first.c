#include<stdio.h>

/**
 * beforemain - Apply the constructor attribute to beforemain()
 */
void beforemain(void) __attribute__ ((constructor));

/**
 * beforemain - a function that start before main
 */
void beforemain(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
