


#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 if necessary */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* 함수 리스트 */

/* 이중포인터 h를 받으므로써 함수 initialize를 벗어나도 주소값을
  받으므로써 함수내에 매개변수를 통해 저장된 값이 누수되지 않음  */
int initialize(headNode** h);

/* freeList는 이미 저장된 포인터의 이름을 알기 때문에 굳이
  이중포인터를 이용할 필요 없음
  필요시 이중포인터가 가르키는 포인터 값을 대입하면 이중포인터도
  매개변수로 이용가능*/
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
	printf("[---- [정보통계학과]----[이연준]---- [2017017031] ----]");

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

		/* headNode에 대한 메모리를 할당하여 리턴 */
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
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int k) {
	listNode* newnode;
		listNode* temp;
		newnode = (listNode*)malloc(sizeof(listNode));
		newnode->key = k;
		newnode->rlink=NULL;
		newnode->llink=NULL;
		if(h->first == NULL){ // 노드가 하나도 없을 경우의 삽입
			h->first=newnode;
			return 0;
		}
		temp = h->first;
		while(temp->rlink != NULL)
		{
		 temp= temp->rlink;// temp가 맨 마지막 노드의 포인터가 됨
		}
		temp->rlink =newnode;// 맨 뒤에 새로운 노드를 연결

	return 0;
}



/**
 * list의 마지막 노드 삭제
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

		        /* 마지막 노드 탐색 */
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
		            /* 마지막노드 앞 노드와 마지막 노드의 연결 해제  */
		            secondLastNode->rlink = NULL;

		       }

		        /*마지막 노드 해제 */
		        free(toDelete);

		        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
		    }



	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
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
 * list의 첫번째 노드 삭제
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

		        /*삭제 노드 포인터 초기화*/
		        free(toDelete);

		        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
		    }


	return 0;
}



/**
 * 리스트의 링크를 역순으로 재 배치
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
		        preNode->rlink = NULL; // 첫번째 노드를 마지막 노드로 전환

		        while(h->first != NULL)
		        {
		        	h->first = h->first->rlink;


		        	sNode->rlink = preNode;
		        	preNode->llink=sNode;
		            preNode =sNode;
		            sNode = h->first;
		        }

		        h->first = preNode; // 마지막 노드를 첫번째 노드로 전환

		        printf("SUCCESSFULLY REVERSED LIST\n");
		    }


	return 0;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int k) {
	listNode* f = h->first;
	listNode* s;
	listNode* newnode = (listNode*)malloc(sizeof(listNode));
		newnode->rlink = NULL;
		newnode->llink = NULL;
		newnode->key = k;

		s = h->first;

		if ( h->first == NULL)
		{ // 빈노드일 경우 제일 앞에 삽입
		h->first=newnode;
		newnode->llink = f;
		return 0;
		}

		else if(h->first->key >= newnode->key ){// 맨 앞 노드와 바궈야 할 경우 삽입
			newnode->rlink = h->first;
			newnode->llink = f;
			h->first->llink= newnode;
			h->first = newnode;

		    return 0;
		}
		else
		{
		while ( s->rlink != NULL) { // 삽입을 2번째 노드 이후부터 할때
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
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int k)
{
	listNode* pre = h->first;
		listNode* p= h->first;
		 while (p != NULL) {
		  if (p->key == k)break;   //입력한 값을 만나면 바로 break하여 위치를 보존
		  pre = p;
		  p = p->rlink;
		 }
		 if (p == h->first) { //찾는 노드가 첫 번째 노드일 경우
			 h->first->rlink->llink=h->first;
			 h->first =  h->first->rlink;
			 return 0;
		 }
		 if (h->first == NULL)return 0; //노드가 공백일 경우
		  if ( h->first->rlink == NULL) {  //노드가 한개만 있을 경우
		  free( h->first);
		  h->first = NULL;
		  return 0;
		 }
		 else if (p == NULL)return 0; //찾을 수 없으면 바로 복귀
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




