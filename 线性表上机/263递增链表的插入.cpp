#include<iostream>
#include<cstdio>
#include<malloc.h>
using namespace std;

typedef struct LinkList{
	int height;
	LinkList *next;
}LinkList;

LinkList* creatList(int num){
	LinkList* head, * s, *r;
	head=(LinkList*)malloc(sizeof(LinkList));		//����ͷ�ڵ�head 
    r = head;	//βָ��ָ��ͷ�ڵ� 
    for(int i=0; i<num;i++){	
    	s=(LinkList*)malloc(sizeof(LinkList));		//�����½ڵ�*s 
		cin>>s->height;
    	r->next = s;	//�½ڵ�����β 
    	r = s;			//βָ��ָ���±�β 
	}
	r->next = NULL;
	return head;		//���ر�ͷָ�� 
} 

int main(){
	int num = 0, h;
	cin>>num>>h;
	if(num==0){		//��������£�û��С���ѣ���������ֱ��������� 
		printf("%d", h);
	}
	else{			//һ������£��Ѿ��źö��� 
		LinkList *L = creatList(num);
		LinkList *p, *r;
		p=(LinkList*)malloc(sizeof(LinkList));
		p->height = h;
		r = L->next;
		for(int i=0;i<num;i++){		//������� 
			if(h<r->height){		//������ıȵ�һ��Сʱ���嵽�����һ�� 
				p->next = r;
				L->next = p;
				break;
			}else if((h>r->height)&&(r->next==NULL)) {		//������ı����һ����ʱ���嵽����β 
				r->next = p;
				break; 
			}else if((h>=r->height)&&(h<r->next->height)&&(r->next!=NULL)){		//һ������£�������� 
				p->next = r->next;
				r->next = p;
				break;
			}
			else{
				r = r->next;
			}
		} 
		LinkList *q = L->next;
		for(int j = 0;j<=num;j++){
//			cout<<q->height<<' ';
			printf("%d ",q->height);
			q = q->next;
		} 
	}
	return 0;
} 
