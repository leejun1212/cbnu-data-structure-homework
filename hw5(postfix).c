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



/* stack 내에서 우선순위, lparen = 0 가장 낮음 */

typedef enum{
	lparen = 0,   /* ( 왼쪽 괄호 */
	rparen = 9,  /* ) 오른쪽 괄호*/
	times = 7,  /* * 곱셈 */
	divide = 7,  /* / 나눗셈 */
	plus = 4,    /* + 덧셈 */
	minus = 4,   /* - 뺄셈 */
	operand = 1 /* 피연산자 */
} precedence;


char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression을 저장하는 배열 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix로 변경된 문자열을 저장하는 배열 */
char postfixStack[MAX_STACK_SIZE];	/* postfix로 변환을 위해 필요한 스택 */
int evalStack[MAX_STACK_SIZE];		/* 계산을 위해 필요한 스택 */

int postfixStackTop = -1;  /* postfixStack용 top */
int evalStackTop = -1;	   /* evalStack용 top */

int evalResult = 0;	    /* 계산 결과를 저장 */

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
int is_operator(char op) /* 사친연산자 식별 함수 */

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
 * infix expression을 입력받는다.
 * infixExp에는 입력된 값을 저장한다.
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
  문자하나를 전달받아, postfixExp에 추가
 */
void charCat(char* c)
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}



/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.
 */
void toPostfix()
{
	/* infixExp의 문자 하나씩을 읽기위한 포인터 */
	char *exp = infixExp;
	postfixPush('(');
	strcat(infixExp,")");
	char x; /* 문자하나를 임시로 저장하기 위한 변수 */
	int j =0;
	/* exp를 증가시켜가면서, 문자를 읽고 postfix로 변경 */
	while(*exp != '\0')
	{
		if(*exp == '(') /* ( 문자 푸쉬 */

				{

			      postfixPush(*exp);

				}
				else if(isdigit(*exp) || isalpha(*exp)) /* 정수형 문자 출력 */

				{
					postfixExp[j] = *exp;
					j++;
				}

				else if(is_operator(*exp) == 1) /* 사친연산자 식별 함수 */

				{

					x = postfixPop();

					while(is_operator(x) == 1 && getPriority(x) >= getPriority(*exp)) /* 사친연산자 우선 순위 구별 */

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
/* 계산을 위해 필요한 함수 */
void evaluation()
{
	int op1, op2, value, i;
	    int len = strlen(postfixExp); /* 배열의 길이 도출 */
	    char ch;
	    for(i=0; i<len; i++)
	    {
	        ch = postfixExp[i];

	        if(ch!='*' && ch!='+' && ch!='/' && ch!='-')
	        {
	            value = ch - '0'; /* char형 변수를 정수형 변수로 변환 */
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
	printf("[----[정보통계학과]----[이연준]----[2017017031]----]\n");
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



