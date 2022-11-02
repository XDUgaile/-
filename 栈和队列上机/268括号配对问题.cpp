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
int correct(char String[], int len); //����������ţ��ж��ܷ�ƥ�䣬��Ҫ����pop��push����

int main()
{
	int len;
	char str[100];
	int n, i; 
	scanf("%d",&n);
	int a[n];	//����������¼ÿһ�������Ƿ�ƥ��
	for(i = 0;i < n;i++){
	 //����˳��ջ
		S = (stack*)malloc(sizeof(stack));
	 //����setnull������ʼ��ջ
		scanf("%s", &str);//�����ַ��� 
		len = strlen(str);
		a[i] = correct(str, len);
	}
	for(i=0;i<n;i++){
		if (a[i])		//��Ϊ1�����ƥ�䣬����Ͳ���
			printf("yes\n");
		else
			printf("no\n");
	}		
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
	int i;
	char temp = NULL;
	setnull(S);		//��ʼ��ջ 
	for (i = 0; i < len; i++) {
		if (String[i] == '(' || String[i] == '[') {		//�����������Ϊ������ʱ����ѹ��ջ
			push(S, String[i]);
		}
		else {
			if (S->Top == -1) {			//����������ţ�����֮ǰû����ջԪ��ʱ���ͷ���0��ʾ��ƥ��
				return 0;
			}
			temp = pop(S);		//��ջһ��Ԫ�أ����ַ��������Ž���ƥ�䣬ֻ���������Ϊƥ��ʧ�ܡ�
			if (String[i] == ')' && temp != '(') {		
				return 0;
			}
			if (String[i] == ']' && temp != '[') {
				return 0;
			}
		}
	}
	if (S->Top == -1) {		//��S->TopΪ-1����֤����ȫƥ��
		return 1;		//���ر�־ 
	}
	else {			//����Ϊδ��ȫƥ��
		return 0;
	}
}
