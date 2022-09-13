#include<stdio.h>
#include <malloc.h>

typedef int ElemType;//����ElemTypeΪint����
typedef struct{
    ElemType *elem; //�洢�ռ��ַ
    int length; //��ǰ����
    int listsize; //��ǰ����Ĵ洢����
}Sqlist;

void InitList_sq(Sqlist &A)
{
    A.elem = (ElemType *)malloc(100 * sizeof(ElemType));
    A.length = 0;
    A.listsize = 100;
}

int load_sq(Sqlist &L)
{
    int i;
    if (L.length == 0)
        printf("The List is empty!");
    else
    {
        for (i = 0; i < L.length; i++)
            printf("%d ",L.elem[i]);
    }
    printf("\n");
    return 0;
}

void merge( Sqlist A,Sqlist B, Sqlist &C)
{
    int i = 0, j = 0, k = 0;  // A B C��������ָ�� i,j,k;
    while (i < A.length&&j < B.length)  //ѭ���˳�������
    {
        if (A.elem[i]<B.elem[j])  //���A��ֵ��B��ֵС����ô��A��ֵ����C
        {
            C.elem[k] = A.elem[i];
            i++;
            k++;
        }
        else// (A.elem[i]>B.elem[j])
        {
            C.elem[k] = B.elem[j];
            j++;
            k++;
        }
    }
    while (i<A.length) // ����A����Ԫ�أ�����B�Ѿ�û��  �ͽ�Aʣ��Ԫ�ؽ���C��ı�β
    {
        C.elem[k] = A.elem[i]; 
        i++;
        k++;
    }
    while (j<B.length)
    {
        C.elem[k] = B.elem[j];
        j++;
        k++;
    }
    C.length = k;  //����A B����ȫ���꣬��C������A B��֮��

}

int main()
{
    Sqlist A;
    Sqlist B;
    Sqlist C;
    int m, n, c;
    int i = 0;
    InitList_sq(A);
    InitList_sq(B);
    InitList_sq(C);
    printf("����A�ĳ��ȣ�");
    scanf("%d",&m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &A.elem[i]);
    }
    A.length = m;
    printf("����B�ĳ��ȣ�");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &B.elem[i]);
    }
    B.length = n;
    c = m + n;//C�ı�
    printf("List A:");
    load_sq(A);
    printf("List B:");
    load_sq(B);
    merge(A,B,C);
    printf("List C:");
    load_sq(C);
    return 0;
}
