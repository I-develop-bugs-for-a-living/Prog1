/*
 * Compile:         make X
 * Run:             ./X
 * Compile and Run: make X && ./X
 */
#include "base.h" // prog1lib

int main(void){
    int random_number = i_rnd(101);
    printsln("Guess my number:");
    int guess = i_input();
    while (guess != random_number) {
        if (guess < random_number){
            printsln("Too Small!");
        } else if (guess > random_number) {
            printsln("Too Large!");
        }
        guess = i_input();
    }
    printsln("Match!");
}