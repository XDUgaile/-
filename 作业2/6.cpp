#include <stdio.h>
#include <math.h> 
#include <string.h>
#include <stdlib.h> 

int main()
{
	int n;
	char name[20];
	node student;
	sqlist *L;
	scanf("%d%s%c%s",&student.number, &student.name, &student.sex, &student.addr);
	L = Creat();
	Insert(L, student);
	printf("\n������Ҫɾ����ѧ��ѧ�ţ�")��
	scanf("%d", &n);
	int flag;
	flag = Delete(L,n);
	if(flag) Output(L);
	printf("������Ҫ��ѯ��ѧ��������")��
	scanf("%s", name);
	Locate(L, name); 
	return 0;
}
