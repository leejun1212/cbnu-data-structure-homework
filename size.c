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

	printf("[----[��������а�]----[�̿���]----[2017017031]----]\n");
	printf("sizeof(x) = %lu\n", sizeof(x)); /*���������� �迭 x�� ù�迭 ũ��*/
	printf("sizeof(*x) = %lu\n", sizeof(*x)); /*x�� ����Ű�� ������ �迭�� ũ��*/
	printf("sizeof(**x) = %lu\n", sizeof(**x)); /* x�� ����Ű�� ������ �迭�� ����Ű�� ���� ũ��*/


}




