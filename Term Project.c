#include <stdio.h>
#include <stdlib.h>
enum color{White, Gray, Black}; // ����� ������ �����ϱ����� �� ����

#define SIZE 40
#define MAX_VERTEX 20 /* you can change value 20 */
typedef struct Vertex {

	int num; /* vertex number */
    struct Vertex* link; /* link to a next adjacent vertext */

} Vertex;

typedef struct VertexHead {


	int data;
	enum color colr;
	Vertex* head; /* linked list of all adjacent vertices */

} VertexHead;


typedef struct Graph {
  int numVertices;
  VertexHead* vlist; /* list of all vertices: vlist[MAX_VERTEX] */
} Graph;

typedef struct queue_node {
  	 VertexHead* n;
       struct queue_node *next;
  }queue_node;

  struct queue
  {
      int count;
      queue_node *front;
      queue_node *rear;
  };

 typedef struct queue queue;

int initializeGraph(Graph** h, int num); /* initializing Graph */
void destroyGraph(Graph* head); /* deallocating all allocated memory */
void insertVertex(Graph* head,int num); /* vertex insertion */
void deleteVertex(Graph* head,int num); /* vertex deletion */
void insertEdge(Graph* head, int s, int d); /* new edge creation between two vertices */
int deleteEdge(Graph* head,int s, int d); /* edge removal */
void depthFS(Graph* head); /* depth firt search using stack */
void breadthFS(Graph* head); /* breadth first search using queue */
void printGraph(Graph* head); /* printing graph with vertices and edges */
Vertex* CreateVertex(int num); /* ���� ����� */
void enqueue(queue *q, VertexHead *n);
void print_queue(queue *q);


int main()
{
	char command;
	int num;
	int s;
	int d;
	Graph* head = NULL;
	printf("[---- [��������а�]----[�̿���]---- [2017017031] ----]");
	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                     graph using  AdjacncyList                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initializegraph        = z                                       \n");
		printf(" Insert Vertex    = i          insert edge   = n \n");
		printf(" delete vertex  = d           delete edge                      = l \n");
		printf(" depthFS  = e              breadthFS  = b  \n");
		printf(" print graph  = p         destroy graph                  = o \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			printf("how many vertices do you want to make in the graph = ");
			scanf("%d", &num);
	        initializeGraph(&head, num);
			break;
		case 'i': case 'I':
			printf("Your num = ");
			scanf("%d", &num);
			insertVertex(head, num);
			break;
		case 'n': case 'N':
			printf("Insert two vertices :  ");
			scanf("%d %d", &s, &d);
			insertEdge(head, s, d);
			break;

		case 'd': case 'D':
			printf("Your num = ");
			scanf("%d", &num);
			deleteVertex( head,num);
			break;

		case 'l': case 'L':
			printf("Insert two vertices  :  ");
			scanf("%d %d", &s, &d);
			deleteEdge( head, s, d);
			break;

		case 'e': case 'E':
					depthFS(head);
					break;

		case 'b': case 'B':
					breadthFS(head);
					break;


		case 'p': case 'P':

			printGraph(head);

			break;

		case 'q': case 'Q':

			destroyGraph(head);

			break;


		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}
// make a Vertex
Vertex* CreateVertex(int num) {

 Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
 vertex->num = num;
 vertex->link = NULL;
 return vertex;
}
//// make a VertexHead
VertexHead* new_VertexHead(int data) {
	VertexHead *z;
  z = malloc(sizeof(VertexHead));
  z->data = data;
  z->head = NULL;
  z->colr = White;

  return z;
}

/* initializing Graph */
int initializeGraph(Graph** h, int num)
{
	/* if the graph is not empty, then remove all allocated the graph*/
		if(*h != NULL)
			{
			destroyGraph(*h);
			}
		/* create a head graph pointer */
		*h = (Graph*)malloc(sizeof(Graph)+num*sizeof(struct VertexHead*));
		(*h)->numVertices = num;
		(*h)-> vlist = malloc(num * sizeof(struct VertexHead*));
		int i;
		  for (i = 0; i < num; i++)
		  {
			  VertexHead* z = new_VertexHead(-1); //*z is pointer of node. z stores address of node

			  (*h)-> vlist[i] = *z; //*z is the value at the address z
		     }
		return 1;
}


// creates a new vertex
void insertVertex(Graph* head, int num)
{   // creating a new node;
	VertexHead*z = new_VertexHead(num);
	  //this node will be added into the heads array of the graph g
	  int i;
	  for(i=0; i< head->numVertices; i++) {
	    // we will add node when the data in the node is -1
	    if (head-> vlist[i].data < 0) {
	    	head-> vlist[i] = *z; //*z is the value at the address z
	      break; //node is added
	    }
	  }

}
// function to check of the node is in the head array of graph or not
int in_graph_head_list(Graph* head, int num) {
  int i;
  for(i=0; i<head->numVertices; i++) {
    if(head-> vlist[i].data == num)
      return 1;
  }
  return 0;
}

// ���� s�� ���� �������� ���� d�� ���� �������� ���⼺ ���� �߰�
void insertEdge(Graph* head, int s, int d) {

	// �׷����� ���� s�� d�� ���� �� ���� �߰�
	  if(!in_graph_head_list(head, s)) {
		  insertVertex(head, s);
	  }
	  if(!in_graph_head_list(head,  d)) {
		  insertVertex(head,  d);
	  }

	  int i,j;
	  // ���� s�� ���� ���� i�� ã������ �ݺ� ����
	  for(i=0; i<head->numVertices; i++) {
	    if(head->vlist[i].data == s) { //source node found

	      int dest_index; //index of destination element in array heads
	      // iterating over heads array to find node containg destination element
	      for(j=0; j<head->numVertices; j++) {
	        if(head->vlist[j].data == d) { //destination found
	          dest_index = j;
	          break;
	        }
	      }

	      Vertex *n = CreateVertex(dest_index); // new adjacency list node with destination index
	      if (head->vlist[i].head == NULL) { // no head, first element in adjaceny list
	    	  head->vlist[i].head = n;
	      }
	      else { // there is head which is pointer by the node in the head array
	    	  Vertex *temp;
	        temp =  head->vlist[i].head;

	        // iterating over adjaceny list to insert new list_node at last
	        while(temp->link != NULL) {
	          temp = temp->link;
	        }
	        temp->link = n;
	      }
	      break;
	    }
	  }

}
/* printing graph with vertices and edges */
void printGraph(Graph* head) {
  int i;
  for(i=0; i<head->numVertices; i++) {
	  Vertex *temp;
    temp = head->vlist[i].head;
    printf("%d\t",head->vlist[i].data);
    while(temp != NULL) {
      printf("%d\t",head->vlist[temp->num].data);
      temp = temp->link;
    }
    printf("\n");
  }
}
// ���� �켱 Ž�� ����
void dfs_visit(Graph* head, VertexHead* i) {

i->colr = Gray;

Vertex *temp;
  temp = i->head;
  while(temp != NULL) {
    if (head->vlist[temp->num].colr == White) {
      dfs_visit(head, &head->vlist[temp->num]);
    }
    temp = temp->link;
  }
  i->colr = Black;
  printf("%d\n",i->data);
}
// ���� �켱 Ž�� ����
void depthFS(Graph* head) {
  int i;
  for(i=0; i<head->numVertices; i++) {
	  head->vlist[i].colr = White;
  }

  for(i=0; i<head->numVertices; i++) {
    if (head->vlist[i].colr == White) {
      dfs_visit(head, &head->vlist[i]);
    }
  }
}


// �׷������� ���� s�� ���� ���� �κ��� ���� d�� ���� ������ ����
int deleteEdge(Graph* head,int s, int d)
{
	int i,j;
		  // ���� s�� ���� ���� i�� ã������ �ݺ� ����
		  for(i=0; i<head->numVertices; i++) {

			  if(head->vlist[i].data == s) { //source node found

		      int dest_index; //index of destination element in array heads
		      // iterating over heads array to find node containg destination element
		      for(j=0; j<head->numVertices; j++) {
		        if(head->vlist[j].data == d) { //destination found
		          dest_index = j;
		          break;
		        }
		      }

		     // ���� s�� ����Ʈ�κ��� ���� d�� ã�Ƴ��� ���� ����
		      if (head->vlist[i].head == NULL) { // no head, first element in adjaceny list
		    	 return 0;
		      }
		      else {
		    	  Vertex *temp;
		    	  Vertex *temp2;
		        temp =  head->vlist[i].head;
		        while(temp!= NULL) {
		          if(temp->num==dest_index) break;// ���� d ����Ʈ�� ã�� �� �ݺ��� Ż��
		          temp2= temp;
		          temp=temp->link;
		        }
		        if (temp ==  head->vlist[i].head ){ //�� �� ����� ���
		        	head->vlist[i].head= head->vlist[i].head ->link;
		         return 0;
		        }

		        if (  head->vlist[i].head->link == NULL) {  //��尡 �Ѱ��� ���� ���
		       	  free(head->vlist[i].head);
		       	   head->vlist[i].head = NULL;
		       	  return 0;
		       	 }
		        else if (temp == NULL)return 0; //ã�� �� ������ �ٷ� ����
		       	 else {
		       	  temp2 = head->vlist[i].head;
		       	  while (temp2->link != temp) {
		       		temp2 =temp2->link;
		       	  }
		       	temp2->link = temp->link;
		       	  free(temp);
		       	return 0;
		       	 }

		      }
		      }
		  }
  return 0;
}
 // ���� num�� ���� ������ ���� �ϰ� ��������Ʈ����� ������ ����
	void deleteVertex(Graph* head, int num)
	{
		int i,j;
		int dest_index;
		for(j=0; j<head->numVertices; j++) {
						        if(head->vlist[j].data == num) { //���� num�� ���� ���� �߰�
						          dest_index = j; // ������ ��ġ ����
						          break;
						        }
						      }
				// �׷����� ������κ��� ���� num�� ���� �������� ���� ����
		     for(i=0; i<head->numVertices; i++) {
					  if (head->vlist[i].head != NULL)
					  {
					  		     Vertex *temp;
					  		     Vertex *temp2;
					  		        temp =  head->vlist[i].head;
					  		        while(temp!= NULL) {
					  		          if(temp->num==dest_index) break;
					  		          temp2= temp;
					  		          temp=temp->link;
					  		        }
					  		        if (temp ==  head->vlist[i].head ){ // �� �� ����� ���
					  		        	head->vlist[i].head= head->vlist[i].head ->link;
					  		        continue;
					  		        }

					  		        if (  head->vlist[i].head->link == NULL) {  //��尡 �Ѱ��� ���� ���
					  		       	  free(head->vlist[i].head);
					  		       	   head->vlist[i].head = NULL;
					  		       	continue;;
					  		       	 }
					  		        else if (temp == NULL)continue; //ã�� �� ������ �ٷ� ����
					  		       	 else {
					  		       	  temp2 = head->vlist[i].head;
					  		       	  while (temp2->link != temp) {
					  		       		temp2 =temp2->link;
					  		       	  }
					  		       	temp2->link = temp->link;
					  		       	  free(temp);
					  		       	continue;;
					  		       	 }

					  		      }
				     	 }

				  VertexHead* z = new_VertexHead(-1); //*z is pointer of node. z stores address of node
				  head-> vlist[dest_index] = *z; //*z is the value at the address z
}
    // �׷��� �ʱ�ȭ
	void destroyGraph(Graph *head)
{
    if(head != NULL)
    {
        if(head->vlist != NULL)
        {
            int vertex;

            for(vertex = 0; vertex < head->numVertices; vertex++)
            {
                Vertex* listIterator =  head->vlist[vertex].head;

                while(listIterator != NULL)
                {
                	Vertex* temp = listIterator;
                    listIterator = listIterator->link;
                    free(temp);
                }
            }

            free(head->vlist);
        }

        free(head);
    }
}


  int is_empty_queue(queue *q)
  {
    return !(q->count);
  }



void enqueue(queue *q, VertexHead *n)
{
  queue_node *new_queue_node;
  new_queue_node = malloc(sizeof(queue_node));
  new_queue_node->n = n;
  new_queue_node->next = NULL;
  if(!is_empty_queue(q))
  {
    q->rear->next = new_queue_node;
    q->rear = new_queue_node;
  }
  else
  {
    q->front = q->rear = new_queue_node;
  }
  q->count++;
}

queue_node* dequeue(queue *q)
{
  queue_node *tmp;
  tmp = q->front;
  q->front = q->front->next;
  q->count--;
  return tmp;
}

queue* make_queue()
{
  queue *q;
  q = malloc(sizeof(queue));
  q->count = 0;
  q->front = NULL;
  q->rear = NULL;
  return q;
}

void print_queue(queue *q) {
  queue_node *tmp;
  tmp = q->front;
  while(tmp != NULL) {
    printf("%d\t",tmp->n->data);
    tmp = tmp->next;
  }
  printf("\n");
}

void breadthFS(Graph* head){
  // ù��° ��带 ���
 VertexHead s = head->vlist[0];
  int i;
  for(i=0; i<head->numVertices; i++) {
	  head->vlist[i].colr = White;
  }

  s.colr = Gray;

  queue* q = make_queue();
  enqueue(q, &s);

  while(!is_empty_queue(q)) {
    // print_queue(q);
    queue_node *u = dequeue(q);
   Vertex *temp;
    temp = u->n->head;
    while(temp != NULL) {
      if (head->vlist[temp->num].colr == White) {
    	  head->vlist[temp->num].colr = Gray;
        enqueue(q, &head->vlist[temp->num]);
      }
      temp = temp->link;
    }
    u->n->colr = Black;
    printf("%d\n",u->n->data);
  }
}
/*
   �� ���α׷����� �׷����� ������ �����Ҷ� ��� �ִ� �迭���� ������ �Է��� ���ڰ� ������ ���Եǵ���
   ������ ���ҽ��ϴ�. ������ �߰��ϴ� �Լ����� ���ϴ� ���ڸ� ���� ������ ���ϴ� ������ ������ ������ ���⼺��
   �����ϰ� �߰��� �� �ְ� �����Ͽ����ϴ�. ������ ������ �����ϴ� �Լ��� �����Կ� �־� ������ ������ ��쿡��
  �׷����� ���Ե� ������ ������ ���ÿ� �� ������ ����� �ٸ� ������ �������� �����ǰ� �����Ͽ���
  ������ ������ ��쿡�� ���ϴ� ������ ������ ���⼺�� �����ϸ� ����� ���� ��������Ʈ���� ������ �����ǰ� �����Ͽ����ϴ�
    dfs�� ���ð� ����Լ��� ��� bfs�� ť�� �̿��Ͽ� ������ ���ҽ��ϴ�.
 */




