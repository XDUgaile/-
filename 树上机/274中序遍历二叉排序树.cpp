#include<stdio.h>
#include<malloc.h>

typedef struct node {
	int data;	//������
	struct node* lchild, * rchild;	//��������ָ��
}Bstnode;

void InOrder(Bstnode*p);
Bstnode* InsertBst(Bstnode* t, Bstnode* s);
Bstnode* CreateBst(int num);

int main(){
	int num;
	scanf("%d", &num);
	Bstnode *tree = CreateBst(num);
	InOrder(tree);
	return 0;
} 

void InOrder(Bstnode*p){
	if(p!=NULL){
		InOrder(p->lchild);		//����������	 
		printf("%d ", p->data);	//���ʸ���� 
		InOrder(p->rchild);		//���������� 
	}
}

Bstnode* InsertBst(Bstnode* t, Bstnode* s) {
	Bstnode* p, * f;
	p = t;
	while (p != NULL) {		//Ŀ����Ϊ���ҵ��������λ�� 
		f = p;		//��f��¼��Ҫ�ŵ���λ�� 
		if (s->data == p->data)	return t;	//�������иýڵ㣬�������
		if (s->data < p->data)	p = p->lchild;	//���������ϲ��Ҳ���λ�ã�����������ֵ���ڲ����㣬�ͷ����������������������
		else
			p = p->rchild;
	}
	if (t == NULL)		//ԭ��Ϊ�գ�����s��Ϊ�����
		return s;
	if (s->data < f->data)		//����������ֵ���ڲ����㣬�ͷ����������������������
		f->lchild = s;
	else
		f->rchild = s;
	return t;
}

Bstnode* CreateBst(int num) {
	Bstnode* t, * s;
	int data;
	t = NULL;		//���ö���������Ϊ��
	int i = 0;
	for (i; i < num; i++) {
		scanf("%d", &data);
		s = (Bstnode*)malloc(sizeof(Bstnode));	//�����½ڵ�
		s->lchild = s->rchild = NULL;	//����������ʼ��
		s->data = data;
		t = InsertBst(t, s);		//�����½ڵ�
	}
	return t;
}
