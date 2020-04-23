/*
 * hw5(circularQ).c
 *
 *  Created on: 2020. 4. 24.
 *      Author: yb
 */
/*
 * hw5-circularQ.c
 *
 *  Created on: 2020. 4. 24.
 *      Author: yb
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element; /* 큐 원소(element)의 자료형을 char로 정의 */
typedef struct {
	element queue[MAX_QUEUE_SIZE]; /* 1차원 배열 큐 선언 */
	int front, rear;
}QueueType;


QueueType *createQueue();
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);

element getElement();


int main(void)
{
	QueueType *cQ = createQueue();
	element data;

	char command;
	printf("[----[정보통계학과]----[이연준]----[2017017031]----]\n");

	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			data = getElement();
			enQueue(cQ, data);

			break;
		case 'd': case 'D':
			deQueue(cQ,&data);

			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');


	return 1;
}


QueueType *createQueue()
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

element getElement()
{
	element item;
	printf("Input element = ");
	scanf(" %c", &item);
	return item;
}


/*원형 큐가 공백 상태인지 검사하는 연산*/
int isEmpty(QueueType *cQ)
{
	  if (cQ->front == cQ->rear) {
	        printf(" Circular Queue is empty! ");
	        return 1;
	    }

	  else  return 0;
}

/* 원형 큐가 포화 상태인지 검사하는 연산 */
int isFull(QueueType *cQ)
{
	if (((cQ->rear + 1) %  MAX_QUEUE_SIZE) == cQ->front) {
	        printf("  Circular Queue is full! ");
	        return 1;
	    }
	    else return 0;
}


/*원형 큐의 rear에 원소를 삽입하는 연산 */
void enQueue(QueueType *cQ, element item)
{
	 if (isFull(cQ)) return;
	    else {
	        cQ->rear = (cQ->rear + 1) % MAX_QUEUE_SIZE;
	        cQ->queue[cQ->rear] = item;

	    }
}

/* 원형 큐의 front에 원소를 삭제하는 연산 */
void deQueue(QueueType *cQ, element *item)
{
	 if (isEmpty(cQ))
{
		return;
}
	    else {
	        cQ->front = (cQ->front + 1) % MAX_QUEUE_SIZE;

	    }
}


void printQ(QueueType *cQ)
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;

	printf("Circular Queue : [");

	i = first;
	while(i != last){
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}





