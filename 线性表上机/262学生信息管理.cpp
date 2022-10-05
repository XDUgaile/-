#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct student {
    char name[20];
	int number;
	char gender;
}student;

typedef struct LinkList {
	student* data;
	LinkList* next;
}LinkList;

LinkList* creatList() {
    char ch[20];
    LinkList* head, * r, * s;
    head=(LinkList*)malloc(sizeof(LinkList));   //����ͷ�ڵ�head
    r = head; //βָ��ָ��ͷ���
    scanf("%s",ch);
    while (ch[0] != '#') {		//���벻��#�ͽ���ѭ�� 
//    	cout<<"�������ѧ����ѧ�š��������Ա�\n";
        s = (LinkList*)malloc(sizeof(LinkList));		//��̬����ռ��С 
        s->data=(student*)malloc(sizeof(student));		//ע�⣬���������������s�Ŀռ䣬���ǲ�û�з���data�Ŀռ䣬���ֱ�Ӹ�ֵ�ͻ�Խ�� 
        strcpy(s->data->name,ch);		//��ch��ֵ��ֵ��s->data 
//		cin>>s->data->name>>s->data->gender;
        scanf("%d %c",&s->data->number,&s->data->gender);	
		r->next = s;		//βָ�����һ��ָ��s 
        r = s;				//βָ���ֵ��Ϊs 
        scanf("%s",ch);		//������һ���ַ��� 
    }
    r->next = NULL;//��������ָ��һ���µ�ַ
    return head;
}

int delete_point(LinkList* list, int n)
{
    LinkList* p;
    LinkList* q;
    int flag = 0;		//��־�����û�и�ѧ�������0 
    p = list;
    q = list->next;
    while (true)
    {
    	if(q==NULL){		//���qָ��Ϊ�վ�����ѭ�������������Խ�� 
    		break;
		}
    	if(q->data->number==n){
    		flag = 1;		//����ҵ��˶�Ӧ���־ͽ�flag��Ϊ1 
    		p->next = q->next;		//��ָ��p��һ����ָ��ָ��q����һ�� 
    		free(q);		//��qָ��Ŀռ��ͷ� 
			break;
		}
		p=q;		
		q=q->next;		
    }
    return flag;
}

//LinkList* search_point(LinkList* list, int n)
//{
//    LinkList* p;
//    p = list;
//    for (int i = 0; i < n; i++)
//    {
//        p = p->next;
//    }
//    return p;
//}

void output_list(LinkList* point)
{
    LinkList* p;
    p = point;
//    cout << endl << endl << endl;
    while ((p = p->next) != NULL)		//���p����һ����Ϊ�վͽ���ѭ�� 
    {
        printf("%s %d %c\n",p->data->name,p->data->number,p->data->gender);		//��ӡ��� 
    }
}

int main() 
{
    LinkList* head;		
//    output_list(head);			
    head =  creatList();		//����һ������ 
    int num;
    scanf("%d", &num);
    int flag = delete_point(head, num);
    if(flag ==1){		//����ҵ��˾����ɾ������б� 
    	output_list(head);
	}
	else{
		printf("No"); 		//û���ҵ������NO 
	}
    return 0;
}
