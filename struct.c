/*
 * struct.c
 *
 *  Created on: 2020. 4. 10.
 *      Author: yb
 */

#include <stdio.h>

struct student1 {
	char lastname;
	int studentid;
	char grade;
};

typedef struct {
	char lastname;
	int studentid;
    char grade;
} student2;


int main() {

	printf("[----[정보통계학과]----[이연준]----[2017017031]----]\n");

	struct student1 st1 = {'A' , 100, 'A'};

	printf("st1.lastname = %c\n ", st1.lastname);
	printf("st1.studentid = %d\n ", st1.studentid);
	printf("st1.grade = %c\n ", st1.grade);

	student2 st2 = {'B' , 200, 'B'};

	printf("\nst2.lastname = %c\n ", st2.lastname);
	printf("st2.studentid = %d\n ", st2.studentid);
	printf("st2.grade = %c\n ", st2.grade);

	student2 st3;

	st3 = st2;

	printf("\nst3.lastname = %c\n ", st3.lastname);
	printf("st3.studentid = %d\n ", st3.studentid);
	printf("st3.grade = %c\n ", st3.grade);
	/*
   if(st3 == st2)
	    printf("equal\n");
	else
	    printf("not equal\n");
*/
    return 0;
}

