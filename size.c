/*
 * size.c
 *
 *  Created on: 2020. 4. 10.
 *      Author: yb
 */

#include <stdio.h>
#include <stdio.h>

void main()
{
	int **x;

	printf("[----[정보통계학과]----[이연준]----[2017017031]----]\n");
	printf("sizeof(x) = %lu\n", sizeof(x)); /*더블포인터 배열 x의 첫배열 크기*/
	printf("sizeof(*x) = %lu\n", sizeof(*x)); /*x가 가르키는 포인터 배열의 크기*/
	printf("sizeof(**x) = %lu\n", sizeof(**x)); /* x가 가르키는 포인터 배열이 가르키는 곳의 크기*/


}




