/*
 * hwd8.c
 *
 *  Created on: 2020. 5. 15.
 *      Author: yb
 */
#include<stdio.h>
#include<stdlib.h>
/* �ʿ��� ������� �߰� */

typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;

/* �Լ� ����Ʈ */
int initialize(listNode** h);
int freeList(listNode* h);
int insertLast(listNode* head, int k);
int deleteLast(listNode* head);
int insertFirst(listNode* head, int k);
int deleteFirst(listNode* head);
int invertList(listNode* head);

int insertNode(listNode* head, int k);
int deleteNode(listNode* head, int k);

void printList(listNode* h);



int main()
{
	char command;
	int key;
	listNode* headnode=NULL;
	printf("[---- [��������а�]----[�̿���]---- [2017017031] ----]");
	do{
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
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
			initialize(&headnode);
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


int initialize(listNode** h) {

	/* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
	if(*h != NULL)
		freeList(*h);

	/* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
	*h = (listNode*)malloc(sizeof(listNode));
	(*h)->rlink = *h;
	(*h)->llink = *h;
	(*h)->key = -9999;
	return 1;
}

/* �޸� ���� */
int freeList(listNode* h){

	listNode* p = h->rlink;
	listNode* prev = NULL;

			while(h->rlink != h) {

				prev = p;

				p = p->rlink;

				free(prev);

			}

			free(h);
	return 1;
}



void printList(listNode* h) {
	int i = 1;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->rlink;

	while( p != h->llink) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}
	printf("[ [%d]=%d ] ", i, p->key);

	printf("  items = %d\n", i);


	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);

	i = 1;
	p = h->rlink;
	while( p != h->llink) {
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		p = p->rlink;
		i++;
	}
	printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);

}



/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(listNode* head, int k) {



	listNode* newnode;
	newnode = (listNode*)malloc(sizeof(listNode));
	newnode->key = k;
    newnode->rlink=newnode;
    newnode->llink=newnode;

    if(head->rlink == head)

        {

    	head->rlink = newnode;
    	head->llink = newnode;

        }

        else

        {

        	head->llink->rlink = newnode;
        	newnode->rlink = head->rlink;
            newnode->llink = head->llink;
            head->llink = newnode;
            head->rlink->llink = head->llink;

        }

 return 0;
}
/**
 * list�� ������ ��� ����
 */
int deleteLast(listNode* head) {

	if(head->rlink == head)  return 0;

	listNode *temp = head->rlink;
	listNode *current = head->rlink;
	    while(current->rlink != head->rlink)
	    {
	        temp = current;
	        current = current->rlink;
	    }
	    temp->rlink = head->rlink; //also can write temp->next = current->next;
	    head->llink = temp;
	    head->rlink->llink = head->llink;
	    free(current);
	return 1;
}


/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(listNode* head, int k) {
	listNode* newnode;
	newnode = (listNode*)malloc(sizeof(listNode));
	newnode->key = k;
	newnode->rlink=newnode;
	newnode->llink=newnode;



	    if(head->rlink == head)

	    {

	    	head->rlink = newnode;
	    	head->llink = newnode;

	    }

	    else

	    {

	    	newnode->rlink = head->rlink;

	    	newnode->llink = head->llink;

	    	head->rlink->llink = newnode;

	    	head->llink->rlink = newnode;

	        head->rlink = newnode;

	    }



	return 1;
}

/**
 * list�� ù��° ��� ����
 */
int deleteFirst(listNode* head) {
	if(head->rlink== head)  return 0;

	    listNode *temp = head->rlink;

	    head->llink->rlink = head->rlink->rlink;

	    head->rlink = head->rlink->rlink;

	    head->rlink->llink = head->llink;

	    free(temp);

	return 1;

}


/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(listNode* head) {
	listNode* preNode, *sNode;
	preNode = head->rlink;
	sNode = head->llink;
	head->llink=preNode;
	head->rlink=sNode;
	do
	    {
	    	sNode = preNode->rlink;
	    	preNode->rlink = preNode->llink;
	    	 preNode->llink = sNode;
	    	 preNode = sNode;
	    }
	     while(preNode != head->rlink);
	              sNode = preNode->rlink;
		    	preNode->rlink = preNode->llink;
		    	 preNode->llink = sNode;
		    	 preNode = sNode;
			        printf("SUCCESSFULLY REVERSED LIST\n");







	return 0;
}



/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(listNode* head, int k) {

		listNode* s;
		listNode* newnode = (listNode*)malloc(sizeof(listNode));

			newnode->rlink = newnode;
			newnode->llink = newnode;
			newnode->key = k;



			s = head->rlink;



			if ( head->rlink == head)

			{ // ������ ��� ���� �տ� ����

				head->rlink = newnode;
			    head->llink = newnode;

			return 0;

			}



			else if(head->rlink->key >= newnode->key ){// �� �� ���� �ٱž� �� ��� ����

				newnode->rlink = head->rlink;
			 	newnode->llink = head->llink;
				head->rlink->llink = newnode;
			    head->llink->rlink = newnode;
			    head->rlink = newnode;

			    return 0;

			}

			else

			{

			while ( s!= head->llink) { // ������ 2��° ��� ���ĺ��� �Ҷ�

			if (s->rlink->key >= k)

			{

				newnode->rlink = s->rlink;

				newnode->llink = s;

				s->rlink->llink = newnode;

				s->rlink=newnode;

				return 0;

			}

			s = s->rlink;

			}
			}

			s->rlink = newnode;
			newnode->llink = s;
			head->llink->rlink = newnode;
			newnode->rlink = head->rlink;
			newnode->llink = head->llink;
			head->llink = newnode;
			head->rlink->llink = head->llink;

	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(listNode* head, int k) {
	listNode* pre = head->rlink;
	listNode* p= head->rlink;

	while (p->rlink != head->rlink) {

			  if (p->key == k)break;   //�Է��� ���� ������ �ٷ� break�Ͽ� ��ġ�� ����

			  pre = p;

			  p = p->rlink;

			 }

			 if (p == head->rlink) { //ã�� ��尡 ù ��° ����� ���


				 head->llink->rlink = head->rlink->rlink;
				 head->rlink = head->rlink->rlink;
				 head->rlink->llink = head->llink;

				 return 0;

			 }

			 if (head->rlink == head)return 0; //��尡 ������ ���

			  if ( head->rlink->rlink == head->rlink) {  //��尡 �Ѱ��� ���� ���

			  free( head->rlink);

			  head->rlink =  head;

			  return 0;

			 }

			 else if (p->rlink == head->rlink)return 0; //ã�� �� ������ �ٷ� ����

			 else {

			  pre = head->rlink;

			  while (pre->rlink != p) {

			   pre = pre->rlink;

			  }
			  }

			  pre->rlink = p->rlink;
			  p->rlink->llink = pre;

			  free(p);

	return 0;
}

