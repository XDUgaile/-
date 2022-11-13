#include<stdio.h>
#include<malloc.h>

typedef struct node {
	int data;	//������
	struct node* lchild, * rchild, * parent;	//������������˫�׽��ָ��
}Bstnode;

Bstnode* InsertBst(Bstnode* t, Bstnode* s);
Bstnode* CreateBst(int num);
void InOrder(Bstnode*p);
void Search(Bstnode*p, int data);

/*�˴��趨ȫ�ֱ�����ԭ������Ҫ��������������˳���¼���������Դ������ǰ������̽��
  PS��ȫ�ֱ����Զ���ʼ��Ϊ0*/

int sort[1000];
int g;

int main(){
	int N, M;
	int i, j;
	scanf("%d", &N);		//��������
	Bstnode *tree = CreateBst(N);		//��������
	InOrder(tree);		//��˳���������
//	for(i=0;i<N;i++){
//		printf("%d ",sort[i]);
//	}
	scanf("%d", &M);	//�����ѯ�ĸ���
	int a[M];	
	for(i=0;i<M;i++){
		scanf("%d", &a[i]);		//�����ѯ������ 
	}
	for(i=0;i<M;i++){
		Search(tree, a[i]);		
		for(j=0;j<N;j++){
			if(sort[j+1]==a[i]){	//���������һ����Ҫ��ѯ�����ݣ����������ǰ�����
				printf("%d ", sort[j]);
			}
			else if(sort[j]==a[i]&&j==0){	//�����һ������Ҫ��ѯ�ľ���û��ǰ�����
				printf("NIL ");
			}
			if(sort[j]==a[i]&&sort[j+1]!=0){	//�����������Ҫ��ѯ�ģ��Һ�̽ڵ㲻Ϊ0����ô�����к�̽�㣬���
				printf("%d ",sort[j+1]);
			}
			else if(sort[j]==a[i]&&sort[j+1]==0){		//�����̽��Ϊ0����ô����û�к��
				printf("NIL ");				
			}
		} 
		printf("\n");
	}
	return 0;
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
	if (t == NULL){		//ԭ��Ϊ�գ�����s��Ϊ�����
		s->parent = NULL; 
		return s;
	}
	if (s->data < f->data){		//����������ֵ���ڲ����㣬�ͷ����������������������
		f->lchild = s;
		s->parent = f;
	}
	else
		f->rchild = s;
		s->parent = f;
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
		s->lchild = s->rchild = s->parent = NULL;	//����������˫�׽���ʼ��
		s->data = data;
		t = InsertBst(t, s);		//�����½ڵ�
	}
	return t;
}

void InOrder(Bstnode*p){
	if(p!=NULL){
		InOrder(p->lchild);		//����������	 
		sort[g]=p->data;		//��������ݴ������� 
		g++;					//ÿ�δ�һ����g++
		InOrder(p->rchild);		//���������� 
	}
}

void Search(Bstnode*p, int data){
	if(p!=NULL){
		Search(p->lchild, data);		//�������������������ݲ���	 	
		if(p->data==data){		//����ҵ��˾ͽ������ 
			if(p->parent!=NULL){//���˫��
				printf("%d ",p->parent->data);
			}
			else{
				printf("NIL ");		//���ΪNULL�����NIL
			}
			if((p->lchild!=NULL)){//�������
				printf("%d ",p->lchild->data);
			}
			else{
				printf("NIL ");
			}
			if((p->rchild!=NULL)){//����Һ���
				printf("%d ",p->rchild->data);
			}
			else{	
				printf("NIL ");
			}			
		}
		Search(p->rchild, data);		//�������������������ݲ���
	}
}

