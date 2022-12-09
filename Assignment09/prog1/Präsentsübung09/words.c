/*
Compile: make words
Run: ./words
make words && ./words
*/

#include "base.h"

// Returns the address of the first character of the word (if any).
// Words are separated by one or more spaces, commas, or dots.
// The end of the string ('\0') also ends a word.
char* find_word_start(char* s) {
    require_not_null(s);
    while (*s != '\0') {
        char c = *s;
        if (c != ' ' && c != '.' && c != ',') return s;
        s++;
    }
    return s;
}

// Returns the address of the first character after the word.
// Words are separated by one or more spaces, commas, or dots.
// The end of the string ('\0') also ends a word.
char* find_word_end(char* s) {
    require_not_null(s);
    while (*s != '\0') {
        char c = *s;
        if (c == ' ' || c == '.' || c == ',') return s;
        s++;
    }
    return s;
}

// Represents a word.
typedef struct {
    char* start; // inclusive (first character of word)
    char* end; // exclusive (first character after word)
} Word;

// Returns the first word in s. May be empty.
Word first_word(char* s) {
    require_not_null(s);
    // todo: implement using the above functions
    Word w = { s, s };
    return w;
}

// Returns the next word after w. May be empty.
Word next_word(Word w) {
    // todo: implement using the above functions
    return w;
}

// Checks if the word is empty.
bool is_empty_word(Word w) {
    return w.end == w.start;
}

// Prints a word followed by a line break.
void print_word(Word w) {
    int n = (int)(w.end - w.start);
    printf("%.*s\n", n, w.start); // todo: explain
}

// Counts the number of words in s.
int count_words(char* s) {
    require_not_null(s);
    int n = 0;
    for (Word w = first_word(s); !is_empty_word(w); w = next_word(w)) {
        // todo: implement
    }
    return n;
}

// Gets an array of words and the length (number of elements) of the array.
Word* get_words(/*in*/char* s, /*out*/int* n) {
    require_not_null(s);
    require_not_null(n);
    // todo: implement
    return NULL;
}

// Gets an array of words and the length (number of elements) of the array.
void get_words2(/*in*/char* s, /*out*/Word** words, /*out*/int* n) {
    require_not_null(s);
    require_not_null(words);
    require_not_null(n);
    // todo: implement
}

int main(void) {
    char* s = "";
    for (Word w = first_word(s); !is_empty_word(w); w = next_word(w)) {
        print_word(w);
    }
    printiln(count_words(s));

    s = "Hello, world.";
    for (Word w = first_word(s); !is_empty_word(w); w = next_word(w)) {
        print_word(w);
    }
    printiln(count_words(s));

    s = "  This is  a   small text. ";
    for (Word w = first_word(s); !is_empty_word(w); w = next_word(w)) {
        print_word(w);
    }
    printiln(count_words(s));

    s = "Lorem ipsum, dolor sit amet. Consetetur sadipscing elitr, voluptua. ";
    for (Word w = first_word(s); !is_empty_word(w); w = next_word(w)) {
        print_word(w);
    }
    printiln(count_words(s));

    int n = 0;
    Word* words = get_words(s, &n);
    for (int i = 0; i < n; i++) {
        print_word(words[i]);
    }
    // free(words);

    get_words2(s, &words, &n);
    for (int i = 0; i < n; i++) {
        print_word(words[i]);
    }
    // free(words);

    return 0;
}
