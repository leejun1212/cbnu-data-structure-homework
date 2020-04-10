/*
 * padding.c
 *
 *  Created on: 2020. 4. 10.
 *      Author: yb
 */

#include <stdio.h>

struct student {
	char lastname[13]; /* 13  bytes */
	int studentid; /* 4  bytes */
	char grade; /* 2  bytes */
};
int main()
{
	struct student pst;
	printf("[----[정보통계학과]----[이연준]----[2017017031]----]\n");

    printf("size of student = %ld\n", sizeof(struct student));/*구조체 struct student의 크기 */
    printf("size of int = %ld\n", sizeof(int));/*자료형 int의 크기 */
    printf("size of short = %ld\n", sizeof(short));/*자료형 short의 크기 */

    return 0;
}
