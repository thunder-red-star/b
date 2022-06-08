numPrimes=$1
# using nvcc as a default compiler, may not work for other systems!
nvcc np1.c -o np1
./np1 $numPrimes