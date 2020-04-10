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
	printf("[----[정보통계학과]----[이연준]----[2017017031]----]\n");
	printf("one  = %p\n", one); /*배열 one의 값 */
	printf("&one  = %p\n", &one); /*배열 one의 주소 */
	printf("&one[0]  = %p\n", &one[0]); /* one[0]의 주소 */
	printf("\n" );

	print1(&one[0], 5); /* 함수 print1에 포인터배열 입력 자리에 one[0]의 주소 값 대입, 열의 개수에는 5대입 */

	return 0;

}

void print1 (int *ptr, int rows)
{
	int i;
	printf("address \t contents\n");
	for ( i= 0; i < rows; i++)
		printf("%p \t %5d\n", ptr + i, *(ptr + i));/* 포인터 배열 ptr에 i만큼의 크기를 더한 곳에 값, 포인터 배열 ptr에 i만큼의 크기를 더한 곳이 가르키는 값 */
	printf("\n" );
}
