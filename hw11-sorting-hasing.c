ï/*
 * hw5-sorting.c
 *
 *  Created on: May 22, 2019
 *
 *  Homework 5: Sorting & Hashing
 *  Department of Computer Science at Chungbuk National University
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ARRAY_SIZE			13	/* prime number */
#define MAX_HASH_TABLE_SIZE 	MAX_ARRAY_SIZE
/* 필요에 따라 함수 추가 가능 */
int initialize(int **a);
int freeArray(int *a);
void printArray(int *a);
int selectionSort(int *a);
int insertionSort(int *a);
int bubbleSort(int *a);
int shellSort(int *a);
/* recursive function으로 구현 */
int quickSort(int *a, int n);
/* hash code generator, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key);
/* array a에대 한 hash table을 만든다. */
int hashing(int *a, int **ht);
/* hash table에서 key를 찾아 hash table의 index return */
int search(int *ht, int key);
int main()
{	char command;
	int *array = NULL;
	int *hashtable = NULL;
	int key = -1;
	int index = -1;
	srand(time(NULL));
	do{
		printf("----------------------------------------------------------------\n");
		printf("                        Sorting & Hashing                       \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize       = z           Quit             = q\n");
		printf(" Selection Sort   = s           Insertion Sort   = i\n");
		printf(" Bubble Sort      = b           Shell Sort       = l\n");
		printf(" Quick Sort       = k           Print Array      = p\n");
		printf(" Hashing          = h           Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");
		printf("Command = ");
		scanf(" %c", &command);
		switch(command) {
		case 'z': case 'Z':
			initialize(&array);
			break;
		case 'q': case 'Q':
			freeArray(array);
			break;
		case 's': case 'S':
			selectionSort(array);
			break;
		case 'i': case 'I':
			insertionSort(array);
			break;
		case 'b': case 'B':
			bubbleSort(array);
			break;
		case 'l': case 'L':
			shellSort(array);
			break;
		case 'k': case 'K':
			printf("Quick Sort: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			quickSort(array, MAX_ARRAY_SIZE);
			printf("----------------------------------------------------------------\n");
			printArray(array);
			break;
		case 'h': case 'H':
			printf("Hashing: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			hashing(array, &hashtable);
			printArray(hashtable);
			break;
		case 'e': case 'E':
			printf("Your Key = ");
			scanf("%d", &key);
			printArray(hashtable);
			index = search(hashtable, key);
			printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]);
			break;
		case 'p': case 'P':
			printArray(array);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}
	}while(command != 'q' && command != 'Q');
	return 1;
}int initialize(int** a)
{	int *temp = NULL;
	/* array가 NULL인 경우 메모리 할당 */
	if(*a == NULL) {
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*a = temp;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	} else
		temp = *a;
	/* 랜덤값을 배열의 값으로 저장 */
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		temp[i] = rand() % MAX_ARRAY_SIZE;
	return 0;
}

int freeArray(int *a)
{	if(a != NULL)
		free(a);
	return 0;
}

void printArray(int *a)
{	if (a == NULL) {
		printf("nothing to print.\n");
		return;
	}
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("a[%02d] ", i);
	printf("\n");
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("%5d ", a[i]);
	printf("\n");
}
// 선택 정렬
int selectionSort(int *a)
{	int min;
	int minindex;
	int i, j;
	printf("Selection Sort: \n");
	printf("----------------------------------------------------------------\n");
	printArray(a);
	

    // 마지막 숫자는 자동으로 정렬되기 때문에 (숫자 개수-1) 만큼 반복한다.
    for (i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		minindex = i;
		min = a[i];
		// 최솟값을 탐색한다.
                for(j = i+1; j < MAX_ARRAY_SIZE; j++)
		{
			if (min > a[j])
			{
				min = a[j];
				minindex = j;
			}
		}
		a[minindex] = a[i];
		a[i] = min;
	}
	printf("----------------------------------------------------------------\n");
	printArray(a);
	return 0;
}
// 삽입 정렬
int insertionSort(int *a)
{	int i, j, t;
	printf("Insertion Sort: \n");
	printf("----------------------------------------------------------------\n");
	printArray(a);
// 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
for(i = 1; i < MAX_ARRAY_SIZE; i++)
	{
		t = a[i]; // 현재 삽입될 숫자인 i번째 정수를 t 변수로 복사
		j = i;
	// 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.  
        // j 값은 음수가 아니어야 한다.     	
while (a[j-1] > t && j > 0)
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = t;
	}
	printf("----------------------------------------------------------------\n");
	printArray(a);
	return 0;
}
// 버블 정렬
int bubbleSort(int *a)
{	int i, j, t;
	printf("Bubble Sort: \n");
	printf("----------------------------------------------------------------\n");
	printArray(a);
	
      for(i = 0; i < MAX_ARRAY_SIZE; i++)
	{     // 0 ~ (i-1)까지 반복
		for (j = 0; j < MAX_ARRAY_SIZE; j++)
		{     // j-1번째와 j번째의 요소가 크기 순이 아니면 교환
			if (a[j-1] > a[j])
			{
				t = a[j-1];
				a[j-1] = a[j];
				a[j] = t;
			}
		}
	}
	printf("----------------------------------------------------------------\n");
	printArray(a);
	return 0;
}
//셀 정렬
int shellSort(int *a)
{	int i, j, k, h, v;
	printf("Shell Sort: \n");
	printf("----------------------------------------------------------------\n");
	printArray(a);
	 //h을 홀수로 만든다.
     for (h = MAX_ARRAY_SIZE/2; h > 0; h /= 2)
	{      // 부분 리스트의 개수는 h와 같다.
		for (i = 0; i < h; i++)
		{      // 부분 리스트에 대한 삽입 정렬 수행
			for(j = i + h; j < MAX_ARRAY_SIZE; j += h)
			{
				v = a[j]; /* 현재 삽입될 숫자인 j번째 정수를 v 변수로복사*/
				k = j;	    
 // j 값은 v 이상이어야 한다
                             while (k > h-1 && a[k-h] > v)
				{
					a[k] = a[k-h];
					k -= h;
				}
				a[k] = v;
			}
		}
	}
	printf("----------------------------------------------------------------\n");
	printArray(a);
	return 0;
}
// 퀵 정렬
int quickSort(int *a, int n)
{	int v, t;
	int i, j;
	  // 원소가 1개이상인 경우
     if (n > 1)
	{
		v = a[n-1];
		i = -1; // 왼쪽 출발 지점 
		j = n - 1; // 오른쪽 출발 지점
		while(1)
		{
			while(a[++i] < v);
			while(a[--j] > v);
			// 포인터가 엇갈릴때까지 반복
                       if (i >= j) break;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		t = a[i];
		a[i] = a[n-1];
		a[n-1] = t;
		// 분할 계산
                quickSort(a, i);
		quickSort(a+i+1, n-i-1);
	}
	return 0;
}
int hashCode(int key) {
   return key % MAX_HASH_TABLE_SIZE;
}
int hashing(int *a, int **ht)
{	int *hashtable = NULL;
	/* hash table이 NULL인 경우 메모리 할당 */
	if(*ht == NULL) {
		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*ht = hashtable;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	} else {
		hashtable = *ht;	/* hash table이 NULL이 아닌경우, table 재활용, reset to -1 */
	}
	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		hashtable[i] = -1;
	/*
	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		printf("hashtable[%d] = %d\n", i, hashtable[i]);
	*/
	int key = -1;
	int hashcode = -1;
	int index = -1;
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		key = a[i];
		hashcode = hashCode(key);
		/*
		printf("key = %d, hashcode = %d, hashtable[%d]=%d\n", key, hashcode, hashcode, hashtable[hashcode]);
		*/
		if (hashtable[hashcode] == -1)
		{
			hashtable[hashcode] = key;
		} else 	{
			index = hashcode;
			while(hashtable[index] != -1)
			{
				index = (++index) % MAX_HASH_TABLE_SIZE;
				/*
				printf("index = %d\n", index);
				*/
			}
			hashtable[index] = key;
		}
	}
	return 0;
}

/* hash table에서 key를 찾아 hash table의 index return */
int search(int *ht, int key)
{	int index = hashCode(key);
	if(ht[index] == key)
		return index;
	
       while(ht[++index] != key)
	{
		index = index % MAX_HASH_TABLE_SIZE;
	}
	return index;
}
