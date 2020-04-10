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

            printf("[----[정보통계학과]----[이연준]----[2017017031]----]\n");
	printf("list[0] \t = %d\n", list[0] ); /* list[0]에 저장된 값 */
	printf("address of list \t= %p\n", list); /* 배열 list의 주소 */
	printf("address of list[0] \t = %p\n", &list[0]); /* list[0]에 주소 */
	printf("address of list + 0 \t= %p\n", list + 0); /* 배열 list에 주소에 0크기를 더한 곳에 주소 */
	printf("address of list + 1 \t= %p\n", list + 1); /* 배열 list에 주소에 1크기를 더한 곳에 주소 */
	printf("address of list + 2 \t= %p\n",  list + 2);/* 배열 list에 주소에 2크기를 더한 곳에 주소 */
	printf("address of list + 3 \t= %p\n",list + 3);/* 배열 list에 주소에 3크기를 더한 곳에 주소 */
	printf("address of list + 4 \t= %p\n", list + 4); /* 배열 list에 주소에 4크기를 더한 곳에 주소 */
	printf("address of list[4] \t= %p\n", &list[4]); /* list[4]에 주소 */

	free(plist[0]);

}
