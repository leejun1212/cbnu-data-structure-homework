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

	printf("[----[��������а�]----[�̿���]----[2017017031]----]\n");
	for(i=0; i < MAX_SIZE; i++) /**/
		input[i]= i ;

	printf("address of input= %p\n", input); /* �迭 list�� �ּ� */

	answer = sum(input, MAX_SIZE);
	printf("The sum is : %f/n", answer); /* */

}

float sum(float list[], int n)
{
	printf("value of list = %p\n", list); /* �迭 list�� �ּ� */
	printf("address of list = %p\n", &list); /* �迭 list�� �ּ� */

	int i ;
	float tempsum = 0;
	for (i = 0; i < n; i++)
		tempsum += list[i];
	return tempsum;

}
