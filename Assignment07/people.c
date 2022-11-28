/*
Compile: make people
Run: ./people
*/

#include "base.h"

// Represents statistics of a people table.
struct Statistics {
	int mean_year;
	int number_males;
	int number_females;
	int number_diverse;
	double mean_height_males; // in m
	double mean_height_females; // in m
	double mean_height_diverse; // in m
};

typedef struct Statistics Statistics;


Statistics make_statistics(void) {
	Statistics ps = { 0, 0, 0, 0, 0.0, 0.0, 0.0 };
	return ps;
}

void print_statistics(Statistics s) {
	printf("mean year: %d\n", s.mean_year);
	printf("number males: %d\n", s.number_males);
	printf("number females: %d\n", s.number_females);
	printf("number diverse: %d\n", s.number_diverse);
	printf("mean height males: %.2f\n", s.mean_height_males);
	printf("mean height females: %.2f\n", s.mean_height_females);
	printf("mean height diverse: %.2f\n", s.mean_height_diverse);

}

Statistics compute_statistics(String table) {
	Statistics ps = make_statistics();
	int n = s_length(table);
	int i = 0; //aktuelle Position im String
	
	while (s_get(table, i) != '\n') i++; // skip first row
	
	// TODO
	int start = i;
	int end = 0;
	int counter = 1;
	while (i < 100) {
		if (s_get(table, i) == '\t') {
			end = i;
			printf("%s \n", s_sub(table, start, end));
			start = end + 1;
			if (counter % 3 == 1) {
				printf("");
			}
			counter++;
		}
		i++;
	}
	
	return ps;
}


int main(void) {
	String table = s_read_file("people.txt");
	Statistics s = compute_statistics(table);
	print_statistics(s);
	
	/*
	Erwartete Ausgabe:
	
	mean year: 1996
	number males: 488
	number females: 501
	number diverse: 11
	mean height males: 1.79
	mean height females: 1.64
	mean height diverse: 1.69
	*/
	
	return 0;
}
