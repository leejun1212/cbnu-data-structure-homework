/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node** head, int key);  /* insert a node to the tree */
Node* deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* find_minimum(Node* root);
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
void freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */
	printf("[---- [정보통계학과]----[이연준]---- [2017017031] ----]");
	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head->left);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(&(head->left), key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head->left, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}

 Node* new_node(int x) //새로운 노드 생성
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->key = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}


void inorderTraversal(Node* ptr) // 이진트리노드 중위순회
{
	if (ptr)
	    {
		inorderTraversal(ptr->left);
	        printf("%d ", ptr->key);
	        inorderTraversal(ptr->right);
	    }
}

void preorderTraversal(Node* ptr) //이진트리노드 전위순회
{
	 if (ptr == NULL)
		 return;
	 else{
	 printf("%d ", ptr->key);
	 preorderTraversal(ptr->left);
	 preorderTraversal(ptr->right);
	 }
}

void postorderTraversal(Node* ptr) //이진트리노드 후위순회
{
	if ( ptr == NULL)
		return;
	else{
		postorderTraversal( ptr->left);
	    postorderTraversal( ptr->right);
	    printf("%d ",  ptr->key);
	}
}


int insert(Node** head, int k)
{
	Node *seek = *head;
	    int gap = 0;
	    if (seek == NULL)
	    {
	    	(*head) = new_node(k);
	        return 1;//보관 성공 반환
	    }
	    while (1)
	    {
	        gap = seek->key - k;
	        if (gap == 0)//이미 같은 값의 데이터를 보관했음
	        {
	            return 0;//보관 실패 반환
	        }
	        if (gap>0)//기존 데이터가 클 때(들어갈 데이터가 작을 때)
	        {
	            if (seek->left)//왼쪽에 자식이 이미 있으면
	            {
	                seek = seek->left;//seek를 왼쪽 자식으로 설정
	            }
	            else
	            {
	                seek->left = new_node(k);//왼쪽 자식으로 새로운 노드를 설정
	                return 1;//보관 성공 반환
	            }
	        }
	        else//기존 데이터가 작을 때(들어갈 데이터가 클 때)
	        {
	            if (seek->right)//오른쪽에 자식이 이미 있으면
	            {
	                seek = seek->right;//seek를 오른쪽 자식으로 설정
	            }
	            else
	            {
	                seek->right = new_node(k);//오른쪽 자식으로 새로운 노드를 설정
	                return 1;//보관 성공 반환
	            }
	        }

	    }
	    return 1;

}

Node* deleteLeafNode(Node* head, int k)
{
	if(head==NULL)
	        return NULL;
	    if (k>head->key)
	    	head->right = deleteLeafNode(head->right, k);
	    else if(k<head->key)
	    	head->left = deleteLeafNode(head->left, k);
	    else
	    {
	        //자식이 없는 경우
	        if(head->left==NULL && head->right==NULL)
	        {
	            free(head);
	            return NULL;
	        }

	        //자식이 하나인 경우
	        else if(head->left==NULL || head->right==NULL)
	        {
	             Node* temp;
	            if(head->left==NULL)
	                temp = head->right;
	            else
	                temp = head->left;
	            free(head);
	            return temp;
	        }

	        //자식이 두개인 경우
	        else
	        {
	            Node *temp = find_minimum(head->right);
	            head->key = temp->key;
	            head->right = deleteLeafNode(head->right, temp->key);
	        }
	    }
	    return  head;

}

Node* find_minimum(Node* root)
{
    if(root== NULL)
        return NULL;
    else if(root->left != NULL) // 제일 작은 값을 가진 노드는 left포인터의 값이 NULL일 것이다
        return find_minimum(root->left); // 제일 좌측의 노드의 값이 미니멈일 것이다
    return root;
}

Node* searchRecursive(Node* ptr, int k) // 재귀적 방법으로 이진 탐색 트리의 k를 찾는 함수
{
	if(ptr){
	if(ptr->key==k)
	        return ptr;

	    	else if(ptr->key>k){
	        	return searchRecursive(ptr->left,k);
	    	}
	    	else{
	        	return searchRecursive(ptr->right,k);
	    	}

	}
	return NULL;
}

Node* searchIterative(Node* head, int k) //순환적 방법으로 이진 탐색 트리의 k를 찾는 함수
{
	while(head->left!=NULL)
	   {
	      if(k == head->left->key) return(head->left);
	      else if(k < head->left->key)
	      head->left = head->left->left;
	      else
	    	  head->left = head->left->right;
	   }
	   return NULL;
}


void freeBST(Node* head) // 이진트리 함수 초기화
{
	while(1){
	        if(head == NULL){
	            break;
	        }
	        else if(head != NULL && head->left != NULL){
	        	freeBST(head->left);
	        }
	        else if(head != NULL && head->right != NULL){
	        	freeBST(head->right);
	        }
	        else{
	                        free(head);
	            return ;
	        }
	    }
}
