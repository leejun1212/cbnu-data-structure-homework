/*
 * ap2.c
 *
 *  Created on: 2020. 4. 10.
 *      Author: yb
 */


#include <stdio.h>
#include <stdio.h>

void main()
{
	int list[5];
	int *plist[5];

	list[0] = 10;
	list[1] = 11;

	plist[0] = (int*)malloc(sizeof(int));

            printf("[----[��������а�]----[�̿���]----[2017017031]----]\n");
	printf("list[0] \t = %d\n", list[0] ); /* list[0]�� ����� �� */
	printf("address of list \t= %p\n", list); /* �迭 list�� �ּ� */
	printf("address of list[0] \t = %p\n", &list[0]); /* list[0]�� �ּ� */
	printf("address of list + 0 \t= %p\n", list + 0); /* �迭 list�� �ּҿ� 0ũ�⸦ ���� ���� �ּ� */
	printf("address of list + 1 \t= %p\n", list + 1); /* �迭 list�� �ּҿ� 1ũ�⸦ ���� ���� �ּ� */
	printf("address of list + 2 \t= %p\n",  list + 2);/* �迭 list�� �ּҿ� 2ũ�⸦ ���� ���� �ּ� */
	printf("address of list + 3 \t= %p\n",list + 3);/* �迭 list�� �ּҿ� 3ũ�⸦ ���� ���� �ּ� */
	printf("address of list + 4 \t= %p\n", list + 4); /* �迭 list�� �ּҿ� 4ũ�⸦ ���� ���� �ּ� */
	printf("address of list[4] \t= %p\n", &list[4]); /* list[4]�� �ּ� */

	free(plist[0]);

}
