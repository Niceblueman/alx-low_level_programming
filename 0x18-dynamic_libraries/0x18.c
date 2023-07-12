#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the custom implementation of rand
int rand() {
    return 42;
}

// Define the custom implementation of srand
void srand(unsigned int seed) {
    // Ignore the seed value
    // You can add custom logic here if needed
}