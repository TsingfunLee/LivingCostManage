#pragma once

#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

enum CostTitle
{
	STUDENTCARD,      //ѧ����
	CLOTHES,          //����
	YULE,             //����
	SHENGHUOYONGPIN   //������Ʒ
};

struct Cost 
{
	int No = 0;                    //���ݱ��
	CostTitle costTitle = STUDENTCARD;       //��������
	float costNum = 0;                    //����
};

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef struct Cost ElemType;/* ElemType���͸���ʵ������������������Ϊint */

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;   /* ����LinkList */

class List
{
public:
	List();
	~List();
	/* ��ʼ��˳�����Ա� */
	Status InitList(LinkList L);
	Status VisitElem(ElemType e);     //��ӡһ����������
	/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
	Status IsEmpty(LinkList L);
	ElemType GetLastElem(LinkList L);    //������һ����������
	/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
	Status ClearList(LinkList L);
	/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
	int GetListLength(LinkList L);
	/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
	/* �����������e����L�е�i������Ԫ�ص�ֵ */
	ElemType GetElem(LinkList L,int i, ElemType e);
	void LocateElem(LinkList L,ElemType e);    //��ӡL��������e�����ϵ������Ԫ�ص�λ��  
	void QueryElem(LinkList L,ElemType e, int type);     //�ҵ�������e�����ϵ������Ԫ�أ�����ӡ
	ElemType MaxElem(LinkList L);         //�ҵ���Ŀ����Ԫ��
	ElemType MinElem(LinkList L);         //�ҵ���Ŀ��С��Ԫ��
	float TotalElem(LinkList L);         //����������Ŀ���ܺ�
	/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
	/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
	Status InsertList(LinkList L,int i, ElemType e);
	//������β��������
	Status AddList(LinkList L,ElemType e);
	Status UpdateList(LinkList L, int i,ElemType e);    //�޸�����ĵ�i�����
	/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
	/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
	Status DeleteList(LinkList L,int i, ElemType e);
	/* ��ʼ������˳�����Ա�L�Ѵ��� */
	/* ������������ζ�L��ÿ������Ԫ����� */
	Status TraverseList(LinkList L);
	Status SaveList(LinkList L);      //����
	Status ReadList(LinkList L);      //����
	Status PPList(LinkList L,int i);    //�Ե�i�����ݺ��ÿ�����ݵ�����Լ�
	Status MMList(LinkList L,int i);    //�Ե�i�����ݺ��ÿ�����ݵ�����Լ�
private:
	//LinkList L;   //ͷ�ڵ�
};

