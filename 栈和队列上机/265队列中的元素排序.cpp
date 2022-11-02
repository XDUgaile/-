#include<iostream>
#include<cstdio>
#include<malloc.h>
#define MAXQSIZE 1000
#define INF 99999999
using namespace std;

typedef struct {
	int data[1000];	
	int front;		//ͷָ��
	int rear;		//βָ��
}SqQueue;

void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;		//ͷָ��βָ�����㣬����Ϊ��
}

int EnQueue(SqQueue& Q, int e) {		//����
	if ((Q.rear + 1) % MAXQSIZE == Q.front) return 0;	//����
	Q.data[Q.rear] = e;		//��Ԫ�ؼ����β
	Q.rear = (Q.rear + 1) % MAXQSIZE;	//��βָ��+1
	return 1;
}

int DeQueue(SqQueue& Q) {		//����
	if (Q.front == Q.rear) return 0;	//�ӿ�
	int e = Q.data[Q.front];		//�����ͷԪ��
	Q.front = (Q.front + 1) % MAXQSIZE;	//��ͷָ��+1
	return e;
}

int main(){
	SqQueue *Q1, *Q2;
	int n = 0, i, j, temp, min;
	cin >> n;			//�����ж��ٸ�
	Q1 = (SqQueue*)malloc(sizeof(SqQueue));
	Q2 = (SqQueue*)malloc(sizeof(SqQueue));
	for (i = 0; i < n; i++) {
		cin >> temp;
		EnQueue(*Q1, temp);		//���������
	}
//	for(i=0;i<n;i++){
//		printf("%d",Q1->data[i]);
//	}
	for (i = 0; i < n; i++)
	{
		min = INF;	//ʹmin��� 

		for (j = i; j < n; j++)//��ʼһ��ѭ����ɸѡ��ԭ�����е���СԪ�أ�������ȡ�������¶��еĶ�β
		{

			int m = DeQueue(*Q1);//mΪԭ���еĶ�ͷԪ��
			if (m < min)
			{//ȡ��ͷԪ�أ�����Сֵ�Ƚ�
				if (min != INF) EnQueue(*Q1, min);	//�������СֵС���������Ԫ��ȡ����Сֵ����ԭ������Сֵ���
				min = m;
			}
			else
			{
				EnQueue(*Q1, m);	//�������Сֵ����ȡ������Ԫ�طŵ�ԭ���еĶ�β
			}
		}//����һ��ѭ���󣬵õ�����СֵΪ�����е���Сֵ
		EnQueue(*Q2, min);//�������Сֵ��ӵ��������еĶ�β

	}//����N��ѭ�����¶��е�Ԫ�ذ���������
	printf("%d", DeQueue(*Q2));
	for (i = 0; i < n-1; i++)	
	{
		printf(" %d", DeQueue(*Q2));
	}
	printf("\n");
	return 0;
}
