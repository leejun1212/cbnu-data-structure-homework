/*
 * hw5.c
 *
 *  Created on: 2020. 4. 24.
 *      Author: yb
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20



/* stack ������ �켱����, lparen = 0 ���� ���� */

typedef enum{
	lparen = 0,   /* ( ���� ��ȣ */
	rparen = 9,  /* ) ������ ��ȣ*/
	times = 7,  /* * ���� */
	divide = 7,  /* / ������ */
	plus = 4,    /* + ���� */
	minus = 4,   /* - ���� */
	operand = 1 /* �ǿ����� */
} precedence;


char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression�� �����ϴ� �迭 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix�� ����� ���ڿ��� �����ϴ� �迭 */
char postfixStack[MAX_STACK_SIZE];	/* postfix�� ��ȯ�� ���� �ʿ��� ���� */
int evalStack[MAX_STACK_SIZE];		/* ����� ���� �ʿ��� ���� */

int postfixStackTop = -1;  /* postfixStack�� top */
int evalStackTop = -1;	   /* evalStack�� top */

int evalResult = 0;	    /* ��� ����� ���� */

void postfixPush(char x)
{
    postfixStack[++postfixStackTop] = x;
}

char postfixPop()
{
    char x;
    if(postfixStackTop == -1)
        return '\0';
    else {
    	x = postfixStack[postfixStackTop--];
    }
    return x;
}
int is_operator(char op) /* ��ģ������ �ĺ� �Լ� */

{
	if( op == '*' ||  op == '/' || op == '+' || op == '-')
	{
	  return 1;
	}
	else
	{
		return 0;
	}
}

void evalPush(int x)
{
    evalStack[++evalStackTop] = x;
}

int evalPop()
{
    if(evalStackTop == -1)
        return -1;
    else
        return evalStack[evalStackTop--];
}





/*
 * infix expression�� �Է¹޴´�.
 * infixExp���� �Էµ� ���� �����Ѵ�.
 */
void getInfix()
{
    printf("Type the expression >>> ");
    scanf("%s",infixExp);
}

precedence getToken(char symbol)
{
	switch(symbol) {
	case '(' : return lparen;
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	default : return operand;
	}

}

precedence getPriority(char x)
{
	return getToken(x);
}



/*
  �����ϳ��� ���޹޾�, postfixExp�� �߰�
 */
void charCat(char* c)
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}



/**
 * infixExp�� ���ڸ� �ϳ��� �о�鼭 stack�� �̿��Ͽ� postfix�� �����Ѵ�.
 * ����� postfix�� postFixExp�� ����ȴ�.
 */
void toPostfix()
{
	/* infixExp�� ���� �ϳ����� �б����� ������ */
	char *exp = infixExp;
	postfixPush('(');
	strcat(infixExp,")");
	char x; /* �����ϳ��� �ӽ÷� �����ϱ� ���� ���� */
	int j =0;
	/* exp�� �������Ѱ��鼭, ���ڸ� �а� postfix�� ���� */
	while(*exp != '\0')
	{
		if(*exp == '(') /* ( ���� Ǫ�� */

				{

			      postfixPush(*exp);

				}
				else if(isdigit(*exp) || isalpha(*exp)) /* ������ ���� ��� */

				{
					postfixExp[j] = *exp;
					j++;
				}

				else if(is_operator(*exp) == 1) /* ��ģ������ �ĺ� �Լ� */

				{

					x = postfixPop();

					while(is_operator(x) == 1 && getPriority(x) >= getPriority(*exp)) /* ��ģ������ �켱 ���� ���� */

					{

						postfixExp[j] = x;
								j++;
						x = postfixPop();
					}

					 postfixPush(x);
					 postfixPush(*exp);

				}

				else if(*exp == ')')

				{

					x =postfixPop();

					while(x != '(')

					{

						postfixExp[j] = x;
										j++;
						x = postfixPop();
					}

				}

				else

				{

					printf("\nInvalid expression!");

					exit(1);

				}
		      exp++;

			}

	if(postfixStackTop>0)
		{
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}



		postfixExp[j] = '\0';

	}




void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp =  (%s\n", infixExp);
	printf("postExp =  %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for(int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");

}

void reset()
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	for(int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';

	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}
/* ����� ���� �ʿ��� �Լ� */
void evaluation()
{
	int op1, op2, value, i;
	    int len = strlen(postfixExp); /* �迭�� ���� ���� */
	    char ch;
	    for(i=0; i<len; i++)
	    {
	        ch = postfixExp[i];

	        if(ch!='*' && ch!='+' && ch!='/' && ch!='-')
	        {
	            value = ch - '0'; /* char�� ������ ������ ������ ��ȯ */
	            evalPush(value);
	            continue;
	        }

	        op2 = evalPop();
	        op1 = evalPop();

	        switch(ch){
	            case '*': value = op1*op2; break;
	            case '+': value = op1+op2; break;
	            case '/': value = op1/op2; break;
	            case '-': value = op1-op2; break;
	            default : exit(1); break;
	        }

	        evalPush( value);
	    }

	    evalResult=(*evalStack);
}


int main()
{
	char command;
	printf("[----[��������а�]----[�̿���]----[2017017031]----]\n");
	do{
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			getInfix();
			break;
		case 'p': case 'P':
			toPostfix();
			break;
		case 'e': case 'E':
			evaluation();
			break;
		case 'd': case 'D':
			debug();
			break;
		case 'r': case 'R':
			reset();
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 0;


}



