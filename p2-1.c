/*
 * p2-1.c
 *
 *  Created on: 2020. 4. 10.
 *      Author: yb
 */


#include <stdio.h>

#define MAX_SIZE 100

float sum(float[], int);
float input[MAX_SIZE], answer;
int i;
void main(void)
{

	printf("[----[정보통계학과]----[이연준]----[2017017031]----]\n");
	for(i=0; i < MAX_SIZE; i++) /**/
		input[i]= i ;

	printf("address of input= %p\n", input); /* 배열 list의 주소 */

	answer = sum(input, MAX_SIZE);
	printf("The sum is : %f/n", answer); /* */

}

float sum(float list[], int n)
{
	printf("value of list = %p\n", list); /* 배열 list의 주소 */
	printf("address of list = %p\n", &list); /* 배열 list의 주소 */

	int i ;
	float tempsum = 0;
	for (i = 0; i < n; i++)
		tempsum += list[i];
	return tempsum;

}
