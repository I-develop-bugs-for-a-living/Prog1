<<<<<<< HEAD
/*
Compile: make primes
Run: ./primes
make primes && ./primes
*/

#include "Base.h" //include prog1lib  
/*
    Prints the primes in the given interval [lower, upper)].
*/
int print_primes_in_intervall(int lower, int upper){
    
    int prime = lower;
    if (upper > lower){
        if(prime < 2) 
            prime = 2;;
        }
        int count = 0;
        while (prime < upper){  
            int i = 2;
            bool is_a_prime = true;
            while(i <= (prime >> 1)){
                    if( prime % i == 0 ){
                    is_a_prime = false;
                    break;
                }
                i++;
            }
            if(is_a_prime) {
                count++;
                printf("Die %2d. Primzahl im Intervall: [%d,%d)] ist: %2d\n", count, lower, upper, prime);
            }
            prime++;
        }
        return count;
}

void test_print_primes_in_intervall(){
    test_equal_i(print_primes_in_intervall(0, 10), 4);
    test_equal_i(print_primes_in_intervall(10, 20), 4);
    test_equal_i(print_primes_in_intervall(20, 30), 2);
    test_equal_i(print_primes_in_intervall(600, 700), 16);
    test_equal_i(print_primes_in_intervall(-10, 0), 0);
    test_equal_i(print_primes_in_intervall(50, 100), 10);
    test_equal_i(print_primes_in_intervall(50, 50), 0);
    test_equal_i(print_primes_in_intervall(80, 50), 0);
}

int main(void){
    test_print_primes_in_intervall();
    return 0;
}


=======
/*
Compile: make primes
Run: ./primes
make primes && ./primes
*/
/*"fatal error: bas.eh: No such file or directory" da base.h falsch geschrieben wurde konnte der Compiler kein Adresse für die libary finden.*/
#include "base.h" //include prog1lib  
/*
    Prints the primes in the given interval [lower, upper)].
*/
int print_primes_in_intervall(int lower, int upper){
    int prime = lower;
    /*"‘prime’ undeclared (first use in this function)", da die Variable prime in dem If-Statment definiert ist und damit nur für den Fall, dass das if-statment wahr ist definiert ist*/
    if ( upper > lower) {
        if(prime < 2) 
            prime = 2;;
        }
        int count = 0;
        while (prime < upper){  
            int i = 2
            bool is_a_prime = true;
            while(i <= (prime >> 1)){
                    if( prime % i = 0 ){
                    is_a_prime = false;
                    break;
                }
                i++;
            }
            if(is_a_prime)
                count++;
                printf("Die %2d. Primzahl im Intervall: [%d,%d)] ist: %2d\n", count, lower, upper, prime);
            prime++;
        }
        return count;
    }
}

void test_print_primes_in_intervall(){
    test_equal_i(print_primes_in_intervall(0, 10), 4);
    test_equal_i(print_primes_in_intervall(10, 20), 4);
    test_equal_i(print_primes_in_intervall(20, 30), 2);
    test_equal_i(print_primes_in_intervall(600, 700), 16);
    test_equal_i(print_primes_in_intervall(-10, 0), 0);
    test_equal_i(print_primes_in_intervall(50, 100), 10);
    test_equal_i(print_primes_in_intervall(50, 50), 0);
    test_equal_i(print_primes_in_intervall(80, 50), 0);
}

int main(void){
    test_print_primes_in_intervall();
    return 0;
}


>>>>>>> d0c02ad8a49113f835b449f0074b7d510f131094
