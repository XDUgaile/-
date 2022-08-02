#include<stdio.h>
#include<math.h>

typedef struct Complex{
	float realpart;			//ʵ��
	float imagpart;			//�鲿
}Complex;					//���帴����������

void assign(Complex* A, float real, float imag);		//��ֵ
void add(Complex* A, Complex real, Complex imag);			//A + B
void minus(Complex* A, Complex real, Complex imag);			//A - B
void multiply(Complex* A, Complex real, Complex imag);		//A * B
void divide(Complex* A, Complex real, Complex imag);		//A / B

int main() {
	printf("helloworld\n");
	Complex z1, z2, z3, z4, z;
	assign(&z1, 8, 6);
	assign(&z2, 4, 3);
	add(&z3, z1, z2);
	multiply(&z4, z1, z2);
	printf("z1 + z2 = %.3lf+%.3lfi\n", z3.realpart, z3.imagpart);
	printf("z1 * z2 = %.2lf+%.2lfi\n", z4.realpart, z4.imagpart);

	return 0;
}
void assign(Complex* A, float real, float imag)
{
	A->realpart = real;			//ʵ����ֵ
	A->imagpart = imag;			//�鲿��ֵ
}

void add(Complex* c, Complex A, Complex B)			//c = A + B
{
	c->realpart = A.realpart + B.realpart;			//ʵ�����
	c->imagpart = A.imagpart + B.imagpart;			//�鲿���
	//��*��ָ�����������һ��ָ��ṹ���ָ�룬��Ҫ��ָ��ȡ���ṹ���е����ݣ���Ҫ�õ���->��
	//����*��Complex���͵���ͨ����������.ȡ����
}

void minus(Complex* c, Complex A, Complex B)			//c = A - B
{
	c->realpart = A.realpart - B.realpart;			//ʵ�����
	c->imagpart = A.imagpart - B.imagpart;			//�鲿���
}

void multiply(Complex* c, Complex A, Complex B)			//c = A * B
{
	c->realpart = A.realpart * B.realpart - A.imagpart * B.imagpart;	
	c->imagpart = A.realpart * B.imagpart + A.imagpart * B.realpart;
}

void divide(Complex* c, Complex A, Complex B)			//c = A / B
{
	c->realpart = (A.realpart * B.realpart + A.imagpart * B.imagpart) / (pow(B.realpart, 2) + pow(B.imagpart, 2));
	c->imagpart = (A.imagpart*B.realpart-A.realpart*B.imagpart)/ (pow(B.realpart, 2) + pow(B.imagpart, 2));
}

