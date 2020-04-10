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

	printf("[----[정보통계학과]----[이연준]----[2017017031]----]\n");

	printf("value of list[0]= %d\n", list[0]); /* list[0]에 저장된 값 */
	printf("address of list[0]= %p\n", &list[0]); /* list[0]에 주소 */
	printf("value of list= %p\n", list); /* 배열 list의 값 */
	printf("address of list(&list)= %p\n", &list); /* 배열 list의 주소 */

	printf("-----------------------\n\n");
	printf("value of list[1]= %d\n", list[1]); /* list[1]에 저장된 값 */
	printf("address of list[1]= %p\n", &list[1]); /* list[0]에 저장된 주소 */
	printf("value of *(list+1)= %d\n", *(list + 1));/* 배열 list의 값에 1만큼 더한 배열에 저장된 값 */
	printf("address of list+1 = %p\n", list+1); /* 배열 list의 값에 1만큼 더한 배열의 주소 */

	printf("-----------------------\n\n");

	printf("value of *plist[0]= %d\n", *plist[0]); /*  plist[0]가 가르키는 값 */
	printf("&plist[0]         = %p\n", &plist[0] ); /* plist[0]의 주소 */
	printf("&plist            = %p\n", &plist); /* 포인터배열 plist의 주소 */
	printf("plist             = %p\n",  plist); /* 포인터배열 plist의 값 */
	printf("plist[0]          =  %p\n", plist[0]); /* plist[0]의 값 */
	printf("plist[1]          = %p\n",  plist[1]); /* plist[1]의 값 */
	printf("plist[2]          = %p\n",  plist[2]); /* plist[2]의 값 */
	printf("plist[3]          = %p\n",  plist[3]); /* plist[3]의 값 */
	printf("plist[3]          = %p\n",  plist[4]); /* plist[4]의 값 */

	free(plist[0]);

}
