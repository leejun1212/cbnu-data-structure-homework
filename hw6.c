/*
 * hw6.c
 *
 *  Created on: 2020. 5. 1.
 *      Author: yb
 */
/*
 * dfs.c
 *
 *  Created on: 2020. 4. 30.
 *      Author: yb
 */
#include<stdio.h>
#include<stdlib.h>

/* �ʿ��� ������� �߰� */

typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* first;
}headNode;


/* �Լ� ����Ʈ */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode=NULL;
	printf("[---- [��������а�]----[�̿���]---- [2017017031] ----]");

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

headNode* initialize(headNode* h) {

	/* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
	if(h != NULL)
		freeList(h);

	/* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h){
	/* h�� ����� listNode �޸� ����
	 * headNode�� �����Ǿ�� ��.
	 */
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}



/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}


/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int k) {
	listNode* s;
	listNode* newnode = (listNode*)malloc(sizeof(listNode));
	newnode->link = NULL;
	newnode->key = k;

	s = h->first;

	if ( h->first == NULL)
	{ // ������ ��� ���� �տ� ����
	h->first=newnode;
	return 0;
	}

	else if(h->first->key >= newnode->key ){// �� �� ���� �ٱž� �� ��� ����
		newnode->link = h->first;
	    h->first = newnode;
	    return 0;
	}
	else
	{
	while ( s->link != NULL) { // ������ 2��° ��� ���ĺ��� �Ҷ�
	if (s->link->key >= k)
	{
		newnode->link = s->link;
		s->link = newnode;
	}
	s = s->link;
	}
	}
	s->link = newnode;
	return 0;
}

/**
 * list�� �������� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int k) {
	listNode* newnode;
	listNode* temp;
	newnode = (listNode*)malloc(sizeof(listNode));
	newnode->key = k;
	newnode->link=NULL;
	if(h->first == NULL){ // ��尡 �ϳ��� ���� ����� ����
		h->first=newnode;
		return 0;
	}
	temp = h->first;
	while(temp->link != NULL)
	{
	 temp= temp->link;// temp�� �� ������ ����� �����Ͱ� ��
	}
	temp->link =newnode;// �� �ڿ� ���ο� ��带 ����
	return 0;
}


/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {
	listNode* toDelete;

	    if( h->first == NULL)
	    {
	        printf("List is already empty.");
	    }
	    else
	    {
	        toDelete = h->first;
	        h->first = h->first->link;

	        printf("\nData deleted = %d\n", toDelete->key);

	        /*���� ��� ������ �ʱ�ȭ*/
	        free(toDelete);

	        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
	    }


	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int k) {
	listNode* pre = h->first;
	listNode* p= h->first;
	 while (p != NULL) {
	  if (p->key == k)break;   //�Է��� ���� ������ �ٷ� break�Ͽ� ��ġ�� ����
	  pre = p;
	  p = p->link;
	 }
	 if (p == h->first) { //ã�� ��尡 ù ��° ����� ���
		 h->first =  h->first->link;
	  return 0;
	 }
	 if (h->first == NULL)return 0; //��尡 ������ ���
	 if ( h->first->link == NULL) {  //��尡 �Ѱ��� ���� ���
	  free( h->first);
	  h->first = NULL;
	  return 0;
	 }
	 else if (p == NULL)return 0; //ã�� �� ������ �ٷ� ����
	 else {
	  pre =  h->first;
	  while (pre->link != p) {
	   pre = pre->link;
	  }
	  pre->link = p->link;
	  free(p);

	 }
	return 0;
}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {
	listNode* toDelete;
	listNode* secondLastNode;

	    if( h->first == NULL)
	    {
	        printf("List is already empty.");
	    }
	    else
	    {
	        toDelete =  h->first;
	        secondLastNode =  h->first;

	        /* ������ ��� Ž�� */
	        while(toDelete->link != NULL)
	        {
	            secondLastNode = toDelete;
	            toDelete = toDelete->link;
	        }

	        if(toDelete == h->first)
	        {
	        	h->first = NULL;
	        }
	        else
	        {
	            /* ��������� �� ���� ������ ����� ���� ����  */
	            secondLastNode->link = NULL;
	        }

	        /*������ ��� ���� */
	        free(toDelete);

	        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
	    }

	return 0;
}


/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode* h) {
	listNode* preNode, *sNode;

	    if( h->first != NULL)
	    {
	        preNode = h->first;
	        sNode =h->first->link;
	        h->first= h->first->link;

	        preNode->link = NULL; // ù��° ��带 ������ ���� ��ȯ

	        while(h->first != NULL)
	        {
	        	h->first = h->first->link;
	            sNode->link = preNode;

	            preNode =sNode;
	            sNode = h->first;
	        }

	        h->first = preNode; // ������ ��带 ù��° ���� ��ȯ

	        printf("SUCCESSFULLY REVERSED LIST\n");
	    }

	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}

