/* 2019年10月29日 14:52:23 */
#include<stdio.h>
#include<math.h>

/* 利用堆栈求解表达式计算 */

typedef int ElemType; // 将int自定义为ElemType

// 获取堆栈里面的两个操作数
bool getOperands(Stack *S, double *op1, double *op2)
{
	if (!Top(S, op1)) {  
		printf("missing operand!")
		return fasle;		
	}
	Pop(S);  // 弹出操作数
	if(!Top(S, op2)) { 
		printf("missing operand!")
		return fasle;	
	}
	Pop(S); // 弹出操作数
	return true;
}

// 执行表达式计算
void doOperator(Stack *S, char oper)
{
	bool result;
	double oper1,oper2;
	result = getOperands(S, &oper1, &oper2);  // 从栈中弹出两个数
	if (!result) {
		Clear(S);
	}
	else
	{
		switch(oper) {
		case '+': push(S, oper2 + oper1); break;
		case '-': push(S, oper2 - oper1); break;
		case '*': push(S, oper2 * oper1); break;
		case '/':
			if (fabs(oper2) < 1e-6)  // 如果除数为0
			{
				printf("Divide by zero!\n");
				Clear(S);
			}
			else
			{
			push(S, oper1 / oper2); break;
			}
		case '^': pow(oper1, oper2); break;			
		}
	}
}

#define SIZE=20 // 堆栈容量

void main(Stack *S) {
	Stack *S;
	char c;
	double newop;

	Create(S, SIZE);
	c = getchar();
	while(c!='#') { // 不等于终止符
		switch(c) {
		case '+':
		case '-':
		case '/':
		case '*':
		case '^':
			doOperator(S, c);   // 是操作符则进行相应的运算
			break;  
		}
		default:
			ungetc(c, stdin);  // 非运算符则将字符放回输入流
			scanf("%f", &newop);
			Push(S, newop);  // 操作数入栈
	}
	c = getchar();
	if (Top(S, &newop)) {
		printf("%f", newop)  // 取出栈顶元素
	}
	Destroy(S);
}
