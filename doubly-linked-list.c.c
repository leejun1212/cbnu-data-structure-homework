


#include<stdio.h>
#include<stdlib.h>
/* �ʿ��� ������� �߰� if necessary */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* �Լ� ����Ʈ */

/* ���������� h�� �����Ƿν� �Լ� initialize�� ����� �ּҰ���
  �����Ƿν� �Լ����� �Ű������� ���� ����� ���� �������� ����  */
int initialize(headNode** h);

/* freeList�� �̹� ����� �������� �̸��� �˱� ������ ����
  ���������͸� �̿��� �ʿ� ����
  �ʿ�� ���������Ͱ� ����Ű�� ������ ���� �����ϸ� ���������͵�
  �Ű������� �̿밡��*/
int freeList(headNode* h);

int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
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
		printf("                     Doubly Linked  List                        \n");
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


int initialize(headNode** h) {
	if(*h != NULL)
			freeList(*h);

		/* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
	*h = (headNode*)malloc(sizeof(headNode));
	(*h)-> first = NULL;
return 1;
}

int freeList(headNode* h){
	listNode* p = h->first;

		listNode* prev = NULL;
		while(p != NULL) {
			prev = p;
			p = p->rlink;
			free(prev);
		}
		free(h);

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
		p = p->rlink;
		i++;
	}

	printf("  items = %d\n", i);
}




/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int k) {
	listNode* newnode;
		listNode* temp;
		newnode = (listNode*)malloc(sizeof(listNode));
		newnode->key = k;
		newnode->rlink=NULL;
		newnode->llink=NULL;
		if(h->first == NULL){ // ��尡 �ϳ��� ���� ����� ����
			h->first=newnode;
			return 0;
		}
		temp = h->first;
		while(temp->rlink != NULL)
		{
		 temp= temp->rlink;// temp�� �� ������ ����� �����Ͱ� ��
		}
		temp->rlink =newnode;// �� �ڿ� ���ο� ��带 ����

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
		        while(toDelete->rlink != NULL)
		        {
		            secondLastNode = toDelete;
		            toDelete = toDelete->rlink;
		        }

		        if(toDelete == h->first)
		        {
		        	h->first = NULL;
		        }
		        else
		        {
		            /* ��������� �� ���� ������ ����� ���� ����  */
		            secondLastNode->rlink = NULL;

		       }

		        /*������ ��� ���� */
		        free(toDelete);

		        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
		    }



	return 0;
}



/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {
	listNode* f = h->first;
	listNode* node = (listNode*)malloc(sizeof(listNode));
		node->key = key;

		if ( h->first == NULL) {
		 h->first = node;

		}
		else {
			node->llink = f;
			node->rlink =  h->first;
			h->first->llink = node;
			h->first=node;
		}

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
		        h->first = h->first->rlink;

		        printf("\nData deleted = %d\n", toDelete->key);

		        /*���� ��� ������ �ʱ�ȭ*/
		        free(toDelete);

		        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
		    }


	return 0;
}



/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode* h) {
	listNode* preNode, *sNode;
	listNode* f = h->first;
		    if( h->first != NULL)
		    {
		        preNode = h->first;

		        sNode =h->first->rlink;
		        h->first= h->first->rlink;
		        sNode->llink =  f;
		        preNode->llink=NULL;
		        preNode->rlink = NULL; // ù��° ��带 ������ ���� ��ȯ

		        while(h->first != NULL)
		        {
		        	h->first = h->first->rlink;


		        	sNode->rlink = preNode;
		        	preNode->llink=sNode;
		            preNode =sNode;
		            sNode = h->first;
		        }

		        h->first = preNode; // ������ ��带 ù��° ���� ��ȯ

		        printf("SUCCESSFULLY REVERSED LIST\n");
		    }


	return 0;
}



/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int k) {
	listNode* f = h->first;
	listNode* s;
	listNode* newnode = (listNode*)malloc(sizeof(listNode));
		newnode->rlink = NULL;
		newnode->llink = NULL;
		newnode->key = k;

		s = h->first;

		if ( h->first == NULL)
		{ // ������ ��� ���� �տ� ����
		h->first=newnode;
		newnode->llink = f;
		return 0;
		}

		else if(h->first->key >= newnode->key ){// �� �� ���� �ٱž� �� ��� ����
			newnode->rlink = h->first;
			newnode->llink = f;
			h->first->llink= newnode;
			h->first = newnode;

		    return 0;
		}
		else
		{
		while ( s->rlink != NULL) { // ������ 2��° ��� ���ĺ��� �Ҷ�
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
	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int k)
{
	listNode* pre = h->first;
		listNode* p= h->first;
		 while (p != NULL) {
		  if (p->key == k)break;   //�Է��� ���� ������ �ٷ� break�Ͽ� ��ġ�� ����
		  pre = p;
		  p = p->rlink;
		 }
		 if (p == h->first) { //ã�� ��尡 ù ��° ����� ���
			 h->first->rlink->llink=h->first;
			 h->first =  h->first->rlink;
			 return 0;
		 }
		 if (h->first == NULL)return 0; //��尡 ������ ���
		  if ( h->first->rlink == NULL) {  //��尡 �Ѱ��� ���� ���
		  free( h->first);
		  h->first = NULL;
		  return 0;
		 }
		 else if (p == NULL)return 0; //ã�� �� ������ �ٷ� ����
		 else {
		  pre =  h->first;
		  while (pre->rlink != p) {
		   pre = pre->rlink;
		  }
		  p->llink = pre;
		  pre->rlink = p->rlink;

		  free(p);

		 }
		  return 1;

}




