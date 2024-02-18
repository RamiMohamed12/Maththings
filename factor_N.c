#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long modPow(long base, long exp, long mod) {
    long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

void factorize(long N) {
    long g, r, gcd_val, x, y;
    srand(time(NULL));
    
    while (1) {
        g = rand() % N;
        if (gcd(g, N) == 1) {
            printf("Chosen g: %ld\n", g);
            for (r = 2; r < N; r++) {
                if (modPow(g, r, N) == 1) {
                    if (r % 2 == 0) {
                        x = modPow(g, r/2, N) + 1;
                        y = modPow(g, r/2, N) - 1;
                        gcd_val = gcd(x, N);
                        if (gcd_val > 1 && gcd_val < N) {
                            printf("One factor is: %ld\n", gcd_val);
                            printf("Another factor is: %ld\n", N / gcd_val);
                            return;
                        }
                    }
                    break;
                }
            }
        }
    }
}

int main() {
    long N;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter N (product of two primes): ");
    scanf("%ld", &N);

    start = clock(); // Start the timer
    factorize(N);
    end = clock(); // End the timer

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate the elapsed time
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
