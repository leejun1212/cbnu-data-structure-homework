#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

/* for stack */
#define MAX_STACK_SIZE		20
Node* stack[MAX_STACK_SIZE];
int top = -1;

Node* pop();
void push(Node* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		20
Node* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

Node* deQueue();
void enQueue(Node* aNode);


int initializeBST(Node** h);

/* functions that you have to implement */
void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int deleteNode(Node* head, int key);  /* delete the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */




int main()
{
	char command;
	int key;
	Node* head = NULL;
	printf("[---- [��������а�]----[�̿���]---- [2017017031] ----]");
	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(head->left, key);
			break;

		case 'r': case 'R':
			recursiveInorder(head->left);
			break;
		case 't': case 'T':
			iterativeInorder(head->left);
			break;

		case 'l': case 'L':
			levelOrder(head->left);
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

	top = -1;

	front = rear = -1;

	return 1;
}


//����� ������ȸ
void recursiveInorder(Node* ptr)
{
	if(ptr) {
		recursiveInorder(ptr->left);
		printf(" [%d] ", ptr->key);
		recursiveInorder(ptr->right);
	}
}

/**
 * �ݺ����� ������ȸ (���� �̿�)
 */
void iterativeInorder(Node* node)
{
	Node* ptr; top = -1;

	ptr = node;

	while(1) {
		//������ �������� �ݺ�
		while(ptr != NULL)
		{
                        //���ÿ� ��� ����
                        push(ptr);
		//��忡 �������� �̵�
                        ptr = ptr->left; }
		//��� ����
                        ptr = pop();
		if(ptr == NULL)
			break;
		//��� ���
                        printf("[%d] ", ptr->key);
		//�������� �̵�
                        ptr = ptr->right; }


}

/**
 *���� ��ȸ (ť �̿�)
 */
void levelOrder(Node* head)
{
	Node* ptr;
	front = -1;
	rear = -1;
if(head == NULL)
{ return; }
enQueue(head);
/* ť���� �� ó���� �ִ� ��带 x�� �����´�.
x�� ������ ���� ����Ѵ�.
x�� ���� �ڽ��� NULL�� �ƴϸ� ť�� �����Ѵ�.
x�� ������ �ڽ��� NULL�� �ƴϸ� ť�� �����Ѵ�.*/

while(1)
{ ptr = deQueue();

if(ptr == NULL)
{ break; }
printf("[%d] ", ptr->key);
if(ptr->left != NULL)
{ enQueue(ptr->left); }
if(ptr->right != NULL)
{ enQueue(ptr->right); }
}

}


int insert(Node* head, int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;

	if (head->left == NULL) {
		head->left = newNode;
		return 1;
	}

	/* head->left is the root */
	Node* ptr = head->left;

	Node* parentNode = NULL;
	while(ptr != NULL) {

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}

	/* linking the new node to the parent */
	if(parentNode->key > key)
		parentNode->left = newNode;
	else
		parentNode->right = newNode;
	return 1;
}


// ��� ����
int deleteNode(Node* htree,int k)
{

	Node* temp =NULL;
	Node* search;
	Node* parent_node = NULL;
	search = htree; // �˻��� ���ؼ� ��Ʈ��带 ����
	int temp_val;// �����͸� �ӽ÷� ����

	while(search)// ��带 �˻�
	{
		if(search->key ==k)
		break;

		parent_node = search;// ã�� �� ����� �θ���

		if(search->key < k)
		search = search->right;
		else
		search = search->left;
	}

	if(!search)
	return 0;// Ʈ���� ���� ���� ���� ����

	if(search->left && search->right)// �ܸ� ��尡 2��
	{
		parent_node = search;
		search = search->left;//���� ����Ʈ������ ���� ū���� ã�´�.

		while(search->right)
		search = search->right;// �������� ���� ������ ã�´�.

		temp_val = search->key;// �����͸� �����Ѵ�.
		deleteNode(parent_node,search->key);//���� ����Ʈ���� ����� �������� ����
		parent_node->key = temp_val; //�����͸� �̵��Ѵ�.
	}
	else if(search->left || search->right) // �ܸ� ��尡 1��
	{
		if(search->left)// �ܸ���尡 �����
		temp = search->left;
		else
		temp = search->right;

		if(parent_node->left == search)// �θ����� �����
		parent_node->left = temp;
		else
		parent_node->right = temp;
	}
	else// �ܸ������ ���
	{
		if(parent_node->left == search)// �θ��忡�� �ܸ���尡 ���������� �������� Ž��
		parent_node->left = NULL;
		else
		parent_node->right = NULL;
	}
	free(search);// ���� ����� ����

	return 1;
}


void freeNode(Node* ptr)
{
	if(ptr) {
		freeNode(ptr->left);
		freeNode(ptr->right);
		free(ptr);
	}
}

int freeBST(Node* head)
{

	if(head->left == head)
	{
		free(head);
		return 1;
	}

	Node* p = head->left;

	freeNode(p);

	free(head);
	return 1;
}



Node* pop()
{
	Node* node = NULL;
	if(top == -1)

	{ return node; }

	node = stack[top];
	top--;
	return node;


}

void push(Node* aNode)
{
	if(top >= MAX_STACK_SIZE-1)

	{ return; }
	top++; stack[top] = aNode;


}



Node* deQueue()
{
Node* node = NULL;

if(front == rear)
{ return node; }
front++;
node = queue[front];
return node;


}

void enQueue(Node* aNode)
{
	if(rear == MAX_QUEUE_SIZE-1)
	{ return; }
	rear++;
	queue[rear] = aNode;


}

