//�����ַ������ж��Ƿ���ġ�
//������ʹ�õ��Ӻ������书�ܵ�˵����
//����������ݽṹ��main�����Ŀ��(�Լ���ʾ)��ʵ���Ӻ����������������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
//ʹ��˳��ջ
typedef struct node
{
	char elements[MAXSIZE];
	int Top;
} stack;
stack *S;

stack* setnull(stack* S); //��ʼ��ջ
char pop(stack* S); //��ջ����
stack* push(stack* S, char e); //��ջ����
int correct(char String[], int len); //��������ַ������ж��Ƿ�Ϊ���ģ���Ҫ����pop��push����

int main()
{
	int sign; //signΪ��־��sign=1�ǻ��ģ�sign=0���ǻ��� 
	int len;
	char str[100];
 //����˳��ջ
	S = (stack*)malloc(sizeof(stack));
 //����setnull������ʼ��ջ
	gets(str);//�����ַ��� 
	len = strlen(str);
	sign = correct(str, len);
	if (sign)
		printf("right\n");
	else
		printf("wrong\n");
	return 0;
}

stack* setnull(stack* S) {
	S->Top= -1;		//��ʼ��ջ��Ϊ-1 
	return S;
}

stack* push(stack* S, char e) {
	S->Top++;		//ÿ��ѹ��ջһ��Ԫ�ؾͽ�ջ����һ 
	S->elements[S->Top] = e;	
	return S;
}

char pop(stack* S) {
	char e=NULL;
	e = S->elements[S->Top];		 
	S->Top--;		//��ջһ��Ԫ�ؾͽ�ջ��������һλ 
	return e;
}

int correct(char String[], int len) {
	int i, sign=1;
	setnull(S);		//��ʼ��ջ 
	for (i = 0; i < len / 2; i++) {
		push(S, String[i]);			//ͨ��ѭ��������Ԫ�ص�һ��ѹ��ջ�������Ļ���������ѹ��ջ�� 
	}
	for (i = len/2; i > 0; i--) {
//		printf("%c==%c",pop(S), String[len-i]); 	//���������֮���Ҫע�͵�������ᵼ��ջ��Ԫ�س�ջ 
		if(pop(S)==String[len-i]){		//Ҫ��ÿ�γ�ջ��Ԫ�غ��ַ��������Ԫ��һ�����ǻ��� 
		}
		else {
			sign = 0;		//����ֻҪ��һ����һ����Ϊ�ǻ��ģ�����ѭ�� 
			break;
		}
	}
	return sign;		//���ر�־ 
}
