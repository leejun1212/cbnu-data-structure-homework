/*
 * p2-2.c
 *
 *  Created on: 2020. 4. 10.
 *      Author: yb
 */
#include <stdio.h>

void print1 (int *ptr, int rows);

int main()
{
	int one[] = {0, 1, 2, 3, 4};
	printf("[----[��������а�]----[�̿���]----[2017017031]----]\n");
	printf("one  = %p\n", one); /*�迭 one�� �� */
	printf("&one  = %p\n", &one); /*�迭 one�� �ּ� */
	printf("&one[0]  = %p\n", &one[0]); /* one[0]�� �ּ� */
	printf("\n" );

	print1(&one[0], 5); /* �Լ� print1�� �����͹迭 �Է� �ڸ��� one[0]�� �ּ� �� ����, ���� �������� 5���� */

	return 0;

}

void print1 (int *ptr, int rows)
{
	int i;
	printf("address \t contents\n");
	for ( i= 0; i < rows; i++)
		printf("%p \t %5d\n", ptr + i, *(ptr + i));/* ������ �迭 ptr�� i��ŭ�� ũ�⸦ ���� ���� ��, ������ �迭 ptr�� i��ŭ�� ũ�⸦ ���� ���� ����Ű�� �� */
	printf("\n" );
}
