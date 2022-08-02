#include<iostream.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define infeasible -1
#define OVERFLOW -2

typedef int Status;
typedef char ElemType;
typedef struct {
	EleType* elem;
	int length;
}SqList;//����˳�������

Status InitList_Sq(Sqlist& L) {		//����һ���ձ�
	L.elem = new ElemType[MAXSIZE];	//Ϊ˳������ռ�
	if (!L.elem) exit(OVERFLOW);	//�洢����ʧ��
	L.length = 0;					//�ձ���Ϊ0
	return OK;
}

void DestroyList(SqList& L) {	//�������Ա�
	if (L.elem) delete L.elem;	//�ͷŴ洢�ռ�
}

void ClearList(SqList& L) {		//������Ա�
	L.length = 0;				//�����Ա�ĳ�����Ϊ0
}

int GetLength(SqList L) {		//�����Ա�L�ĳ���
	return(L.length);
}
int IsEmpty(SqList L) {			//�ж����Ա�L�Ƿ�Ϊ��
	if (L.length == 0) return 1;
	else return 0;
}