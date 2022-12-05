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
	i++;
	
	// TODO
	int start = i;
	int end = 0;
	String content = "";
	int diverse = 0;
	int female = 0;
	int male = 0;
	int counter = 1;
	int year_counter = 0;
	int year_total = 0;
	double male_height = 0;
	double female_height = 0;
	double diverse_height = 0;
	String last = "male";
	while (i < n) {
		if (s_get(table, i) == '\t' || s_get(table, i) == '\n') {
			end = i;
			content = s_sub(table, start, end);			
			if (counter % 3 == 1) {
				year_counter++;
				year_total += i_of_s(content);
				printf("Year total: %d, Year: %d \n", year_total, i_of_s(content));
			} else if (counter % 3 == 2) {
				if (s_compare(content, "f") == EQ) {
					last = "female";
					female++;
				} else if (s_compare(content, "m") == EQ) {
					male++;
					last = "male";
				} else {
					diverse++;
					last = "diverse";
				}
			} else {
				if (s_compare(last, "male") == EQ) {
					male_height += d_of_s(content);
				} else if (s_compare(last, "female") == EQ) {
					female_height += d_of_s(content);
				} else {
					diverse_height += d_of_s(content);
				}
			}
			start = end + 1;
			counter++;
		}
		i++;
	}
	ps.mean_height_diverse = diverse_height / diverse;
	ps.mean_height_females = female_height / female;
	ps.mean_height_males = male_height / male;
	ps.mean_year = year_total / year_counter;
	ps.number_diverse = diverse;
	ps.number_females = female;
	ps.number_males = male;
	return ps;
}


int main(void) {
	String table = s_read_file("people.txt");
	Statistics s = compute_statistics(table);
	print_statistics(s);
	
	/*
	Erwartete Ausgabe:
	
	mean year: 1974
	number males: 488
	number females: 501
	number diverse: 11
	mean height males: 1.79
	mean height females: 1.64
	mean height diverse: 1.69
	*/
	
	return 0;
}
