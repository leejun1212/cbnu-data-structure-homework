/*
 * ap1.c
 *
 *  Created on: 2020. 4. 10.
 *      Author: yb
 */
#include <stdio.h>
#include <stdio.h>

void main()
{
	int list[5];
	int *plist[5] = {NULL,};

	plist[0] = (int*)malloc(sizeof(int));

	list[0] = 1;
	list[1] = 100;

	*plist[0] = 200;

	printf("[----[��������а�]----[�̿���]----[2017017031]----]\n");

	printf("value of list[0]= %d\n", list[0]); /* list[0]�� ����� �� */
	printf("address of list[0]= %p\n", &list[0]); /* list[0]�� �ּ� */
	printf("value of list= %p\n", list); /* �迭 list�� �� */
	printf("address of list(&list)= %p\n", &list); /* �迭 list�� �ּ� */

	printf("-----------------------\n\n");
	printf("value of list[1]= %d\n", list[1]); /* list[1]�� ����� �� */
	printf("address of list[1]= %p\n", &list[1]); /* list[0]�� ����� �ּ� */
	printf("value of *(list+1)= %d\n", *(list + 1));/* �迭 list�� ���� 1��ŭ ���� �迭�� ����� �� */
	printf("address of list+1 = %p\n", list+1); /* �迭 list�� ���� 1��ŭ ���� �迭�� �ּ� */

	printf("-----------------------\n\n");

	printf("value of *plist[0]= %d\n", *plist[0]); /*  plist[0]�� ����Ű�� �� */
	printf("&plist[0]         = %p\n", &plist[0] ); /* plist[0]�� �ּ� */
	printf("&plist            = %p\n", &plist); /* �����͹迭 plist�� �ּ� */
	printf("plist             = %p\n",  plist); /* �����͹迭 plist�� �� */
	printf("plist[0]          =  %p\n", plist[0]); /* plist[0]�� �� */
	printf("plist[1]          = %p\n",  plist[1]); /* plist[1]�� �� */
	printf("plist[2]          = %p\n",  plist[2]); /* plist[2]�� �� */
	printf("plist[3]          = %p\n",  plist[3]); /* plist[3]�� �� */
	printf("plist[3]          = %p\n",  plist[4]); /* plist[4]�� �� */

	free(plist[0]);

}
