#include "stdafx.h"
#include "List.h"


List::List()
{
}


List::~List()
{
}


/* ��ʼ��˳�����Ա� */
Status List::InitList(LinkList L)
{
	//L = (LinkList)malloc(sizeof(Node)); /* ����ͷ���,��ʹLָ���ͷ��� */
	if (!(L)) /* �洢����ʧ�� */
		return ERROR;
	(L)->next = NULL; /* ָ����Ϊ�� */
	return OK;
}

Status List::VisitElem(ElemType e)
{
	printf("%2d  ", e.No);
	switch (e.costTitle)
	{
	case STUDENTCARD:
		printf("  ѧ����    ");
		break;
	case CLOTHES:
		printf("  ����      ");
		break;
	case YULE:
		printf("  ����      ");
		break;
	case SHENGHUOYONGPIN:
		printf("  ������Ʒ  ");
		break;
	default:
		printf("��������\n");
		break;
	}
	printf("%-2.2f\n", e.costNum);

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
Status List::IsEmpty(LinkList L)
{
	if ((L)->next)
		return FALSE;
	else
		return TRUE;
}

//������һ����������
ElemType List::GetLastElem(LinkList L)
{
	LinkList p=L->next;
	ElemType e;
	while (p)
	{
		e = p->data; 
		p = p->next;	
	}
	return e;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status List::ClearList(LinkList L)
{
	LinkList p, q;
	p = (L)->next;           /*  pָ���һ����� */
	while (p)                /*  û����β */
	{
		q = p->next;
		free(p);
		p = q;
	}
	(L)->next = NULL;        /* ͷ���ָ����Ϊ�� */
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int List::GetListLength(LinkList L)
{
	int i = 0;
	LinkList p = (L)->next; /* pָ���һ����� */
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ */
ElemType List::GetElem(LinkList L,int i, ElemType e)
{
	int j;
	LinkList p;		/* ����һ���p */
	p = (L)->next;		/* ��pָ������L�ĵ�һ����� */
	j = 1;		/*  jΪ������ */
	while (p && j<i)  /* p��Ϊ�ջ��߼�����j��û�е���iʱ��ѭ������ */
	{
		p = p->next;  /* ��pָ����һ����� */
		++j;
	}
	if (!p || j>i)
		printf("��i��Ԫ�ز�����\n");  /*  ��i��Ԫ�ز����� */
	e = p->data;   /*  ȡ��i��Ԫ�ص����� */
	return e;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
/* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
void List::LocateElem(LinkList L,ElemType e)
{
	/*int i = 0;*/
	LinkList p = (L)->next;
	while (p)
	{
		/*i++;*/
		if (p->data.costTitle == e.costTitle && p->data.costNum == e.costNum) /* �ҵ�����������Ԫ�� */
		{
			printf("%d\n", p->data.No);
		}
		p = p->next;
	}
}

//�ҵ�������e�����ϵ������Ԫ�أ�����ӡ
void List::QueryElem(LinkList L,ElemType e, int type)
{
	LinkList p = (L)->next;
	int i = 0;
	
	if (type==1)
	{
		while (p)
		{
			if (p->data.costTitle == e.costTitle) /* �ҵ�����������Ԫ�� */
			{
				VisitElem(p->data);
				++i;
			}
			p = p->next;
		}
		if (i==0)
		{
			printf("δ�ҵ����ϵļ�¼��\n");
		}
		else{
			printf("�ҵ�%d����¼\n", i);
		}
	}
	else if (type==2)
	{
		while (p)
		{
			if (p->data.costNum == e.costNum) /* �ҵ�����������Ԫ�� */
			{
				VisitElem(p->data);
				++i;
			}
			p = p->next;
		}
		if (i == 0)
		{
			printf("δ�ҵ����ϵļ�¼��\n");
		}
		else{
			printf("�ҵ�%d����¼\n", i);
		}
	}

}

 //�ҵ���Ŀ����Ԫ��
ElemType List::MaxElem(LinkList L)
{
	LinkList p = (L)->next;
	ElemType Max;
	Max.costNum = p->data.costNum;

	while (p)
	{
		if (p->data.costNum>=Max.costNum) /* �ҵ�����������Ԫ�� */
		{
			Max.costNum=p->data.costNum;
			Max.costTitle = p->data.costTitle;
			Max.No = p->data.No;
		}
		p = p->next;
	}
	return Max;
}

 //�ҵ���Ŀ��С��Ԫ��
ElemType List::MinElem(LinkList L)
{
	LinkList p = (L)->next;
	ElemType Min;
	Min.costNum = p->data.costNum;

	while (p)
	{
		if (p->data.costNum <= Min.costNum) /* �ҵ�����������Ԫ�� */
		{
			Min.costNum = p->data.costNum;
			Min.costTitle = p->data.costTitle;
			Min.No = p->data.No;
		}
		p = p->next;
	}
	return Min;
}

//����������Ŀ���ܺ�
float List::TotalElem(LinkList L)
{
	LinkList p = (L)->next;
	float total = 0;
	while (p)
	{
		total = total + p->data.costNum;
		p = p->next;
	}
	return total;
}
/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status List::InsertList(LinkList L,int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = L;
	j = 1;
	while (p && j < i)     /* Ѱ�ҵ�i����� */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;   /* ��i��Ԫ�ز����� */
	s = (LinkList)malloc(sizeof(Node));  /*  �����½��(C���Ա�׼����) */
	s->data = e;
	s->next = p->next;      /* ��p�ĺ�̽�㸳ֵ��s�ĺ��  */
	p->next = s;          /* ��s��ֵ��p�ĺ�� */
	return OK;
}

//������β��������
Status List::AddList(LinkList L,ElemType e)
{
	LinkList p,r;
	r = L;
	p = (LinkList)malloc(sizeof(Node));  /* �����½�� */
	if (p == NULL)
	{
		printf("No enough memory to alloc");
		exit(0);
	}
	if (L=NULL)
	{
		(L) = p;
	}
	else
	{
		while (r->next != NULL)
		{
			r = r->next;
		}
		r->next = p;
	}
	p->data = e;
	/*p->data.No = e.No;*/
	/*p->data.costTitle = e.costTitle; */   //�������һ���������
	//p->data.costNum = e.costNum;
	p->next = NULL;

	return OK;
}

//�޸�����ĵ�i�����
Status List::UpdateList(LinkList L, int i,ElemType e)
{
	LinkList p;
	int j = 1;
	p = L->next;
	while (p&&j<i)
	{
		p = p->next;
		++j;
	}
	if (!p||j>i)
	{
		return ERROR;
	}
	p->data = e;
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status List::DeleteList(LinkList L,int i, ElemType e)
{
	int j;
	LinkList p , q;
	p = L;
	j = 1;
	while (p->next && j < i)	/* ����Ѱ�ҵ�i��Ԫ�� */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;           /* ��i��Ԫ�ز����� */
	q = p->next;
	p->next = q->next;			/* ��q�ĺ�̸�ֵ��p�ĺ�� */
	e = q->data;               /* ��q����е����ݸ�e */
	free(q);                    /* ��ϵͳ���մ˽�㣬�ͷ��ڴ� */
	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
Status List::TraverseList(LinkList L)
{
	LinkList p;
    p = (L)->next;
	printf("���  ����      ��Ŀ\n");
	while (p)
	{
		VisitElem(p->data);
		p = p->next;
	}
	/*printf("\n");*/
	return OK;
}

//����
Status List::SaveList(LinkList L)
{
	FILE *fp = fopen("cost.ini", "w");
	LinkList p = (L)->next;
	int ino = 0;               //�������
	char str[10] = "";         //��������
	float fnum = 0;            //������Ŀ

	if (fp == NULL)
	{
		printf("�洢ʧ��!\n");
		return ERROR;
	}
	while (p != NULL)           //������������ݴ��������Ȼ��д���ļ�
	{
		ino = p->data.No;
		switch (p->data.costTitle)
		{
		case STUDENTCARD:
			strcpy(str,"ѧ����");
			break;
		case CLOTHES:
			strcpy(str, "����");
			break;
		case YULE:
			strcpy(str, "����");
			break;
		case SHENGHUOYONGPIN:
			strcpy(str, "������Ʒ");
		default:
			break;
		}
		fnum = p->data.costNum;
		fprintf(fp, "%d %s %f\n", ino, str, fnum);
		p = p->next;
	}
	fclose(fp);
	printf("�洢�ɹ�!\n");

	return OK;
}

//����
Status List::ReadList(LinkList L)
{
	LinkList p = NULL;
	LinkList r = L;
	int ino = 0;      //�������
	char str[10] = "";    //��������
	float fnum = 0;            //������Ŀ
	FILE *fp = fopen("cost.ini", "r");
	if (fp == NULL)
		return ERROR;
	while (fscanf(fp, "%d %s %f\n", &ino, str, &fnum) > 0)     //��ȡ�ļ���Ȼ��ֱ�ֵ
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data.No = ino;
		if (strcmp(str,"ѧ����") == 0)
		{
			p->data.costTitle = STUDENTCARD;
		}else if (strcmp(str,"����") == 0)
		{
			p->data.costTitle = CLOTHES;
		}else if (strcmp(str,"����") == 0)
		{
			p->data.costTitle = YULE;
		}else if (strcmp(str,"������Ʒ") == 0)
		{
			p->data.costTitle = SHENGHUOYONGPIN;
		}
		p->data.costNum = fnum;
		p->next = NULL;
		if (L == NULL)
		{
			L = p;
			r = p;
		}
		else
		{
			r->next = p;
			r = r->next;
		}
	}

	fclose(fp);

	return OK;
}

//�Ե�i�����ݺ��ÿ�����ݵ�����Լ�
Status List::PPList(LinkList L,int i)
{
	LinkList p = (L)->next;
	int j = 1;
	while (p && j<(i+1))
	{
		p = p->next;
		++j;
	}
	if (!p || j>(i+1))
	{
		return ERROR;
	}
	while (p)
	{
		++(p->data.No);
		p = p->next;
	}

	return OK;
}

  //�Ե�i�����ݺ��ÿ�����ݵ�����Լ�
Status List::MMList(LinkList L,int i)
{
	LinkList p = (L)->next;
	int j = 1;
	while (p && j<(i ))
	{
		p = p->next;
		++j;
	}
	if (!p || j>(i))
	{
		return ERROR;
	}
	while (p)
	{
		--(p->data.No);
		p = p->next;
	}

	return OK;
}
