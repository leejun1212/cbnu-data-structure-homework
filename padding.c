/*
 * padding.c
 *
 *  Created on: 2020. 4. 10.
 *      Author: yb
 */

#include <stdio.h>

struct student {
	char lastname[13]; /* 13  bytes */
	int studentid; /* 4  bytes */
	char grade; /* 2  bytes */
};
int main()
{
	struct student pst;
	printf("[----[��������а�]----[�̿���]----[2017017031]----]\n");

    printf("size of student = %ld\n", sizeof(struct student));/*����ü struct student�� ũ�� */
    printf("size of int = %ld\n", sizeof(int));/*�ڷ��� int�� ũ�� */
    printf("size of short = %ld\n", sizeof(short));/*�ڷ��� short�� ũ�� */

    return 0;
}
