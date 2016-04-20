#include "stdafx.h"
#include "List.h"


List::List()
{
}


List::~List()
{
}


/* 初始化顺序线性表 */
Status List::InitList(LinkList L)
{
	//L = (LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
	if (!(L)) /* 存储分配失败 */
		return ERROR;
	(L)->next = NULL; /* 指针域为空 */
	return OK;
}

Status List::VisitElem(ElemType e)
{
	printf("%2d  ", e.No);
	switch (e.costTitle)
	{
	case STUDENTCARD:
		printf("  学生卡    ");
		break;
	case CLOTHES:
		printf("  服饰      ");
		break;
	case YULE:
		printf("  娱乐      ");
		break;
	case SHENGHUOYONGPIN:
		printf("  生活用品  ");
		break;
	default:
		printf("操作错误！\n");
		break;
	}
	printf("%-2.2f\n", e.costNum);

	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status List::IsEmpty(LinkList L)
{
	if ((L)->next)
		return FALSE;
	else
		return TRUE;
}

//获得最后一个结点的数据
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

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status List::ClearList(LinkList L)
{
	LinkList p, q;
	p = (L)->next;           /*  p指向第一个结点 */
	while (p)                /*  没到表尾 */
	{
		q = p->next;
		free(p);
		p = q;
	}
	(L)->next = NULL;        /* 头结点指针域为空 */
	return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int List::GetListLength(LinkList L)
{
	int i = 0;
	LinkList p = (L)->next; /* p指向第一个结点 */
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
ElemType List::GetElem(LinkList L,int i, ElemType e)
{
	int j;
	LinkList p;		/* 声明一结点p */
	p = (L)->next;		/* 让p指向链表L的第一个结点 */
	j = 1;		/*  j为计数器 */
	while (p && j<i)  /* p不为空或者计数器j还没有等于i时，循环继续 */
	{
		p = p->next;  /* 让p指向下一个结点 */
		++j;
	}
	if (!p || j>i)
		printf("第i个元素不存在\n");  /*  第i个元素不存在 */
	e = p->data;   /*  取第i个元素的数据 */
	return e;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
void List::LocateElem(LinkList L,ElemType e)
{
	/*int i = 0;*/
	LinkList p = (L)->next;
	while (p)
	{
		/*i++;*/
		if (p->data.costTitle == e.costTitle && p->data.costNum == e.costNum) /* 找到这样的数据元素 */
		{
			printf("%d\n", p->data.No);
		}
		p = p->next;
	}
}

//找到所有与e满足关系的数据元素，并打印
void List::QueryElem(LinkList L,ElemType e, int type)
{
	LinkList p = (L)->next;
	int i = 0;
	
	if (type==1)
	{
		while (p)
		{
			if (p->data.costTitle == e.costTitle) /* 找到这样的数据元素 */
			{
				VisitElem(p->data);
				++i;
			}
			p = p->next;
		}
		if (i==0)
		{
			printf("未找到符合的记录。\n");
		}
		else{
			printf("找到%d条记录\n", i);
		}
	}
	else if (type==2)
	{
		while (p)
		{
			if (p->data.costNum == e.costNum) /* 找到这样的数据元素 */
			{
				VisitElem(p->data);
				++i;
			}
			p = p->next;
		}
		if (i == 0)
		{
			printf("未找到符合的记录。\n");
		}
		else{
			printf("找到%d条记录\n", i);
		}
	}

}

 //找到数目最大的元素
ElemType List::MaxElem(LinkList L)
{
	LinkList p = (L)->next;
	ElemType Max;
	Max.costNum = p->data.costNum;

	while (p)
	{
		if (p->data.costNum>=Max.costNum) /* 找到这样的数据元素 */
		{
			Max.costNum=p->data.costNum;
			Max.costTitle = p->data.costTitle;
			Max.No = p->data.No;
		}
		p = p->next;
	}
	return Max;
}

 //找到数目最小的元素
ElemType List::MinElem(LinkList L)
{
	LinkList p = (L)->next;
	ElemType Min;
	Min.costNum = p->data.costNum;

	while (p)
	{
		if (p->data.costNum <= Min.costNum) /* 找到这样的数据元素 */
		{
			Min.costNum = p->data.costNum;
			Min.costTitle = p->data.costTitle;
			Min.No = p->data.No;
		}
		p = p->next;
	}
	return Min;
}

//计算所有数目的总和
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
/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status List::InsertList(LinkList L,int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = L;
	j = 1;
	while (p && j < i)     /* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;   /* 第i个元素不存在 */
	s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
	s->data = e;
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;          /* 将s赋值给p的后继 */
	return OK;
}

//在链表尾部插入结点
Status List::AddList(LinkList L,ElemType e)
{
	LinkList p,r;
	r = L;
	p = (LinkList)malloc(sizeof(Node));  /* 生成新结点 */
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
	/*p->data.costTitle = e.costTitle; */   //赋予最后一个结点数据
	//p->data.costNum = e.costNum;
	p->next = NULL;

	return OK;
}

//修改链表的第i个结点
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

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status List::DeleteList(LinkList L,int i, ElemType e)
{
	int j;
	LinkList p , q;
	p = L;
	j = 1;
	while (p->next && j < i)	/* 遍历寻找第i个元素 */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;           /* 第i个元素不存在 */
	q = p->next;
	p->next = q->next;			/* 将q的后继赋值给p的后继 */
	e = q->data;               /* 将q结点中的数据给e */
	free(q);                    /* 让系统回收此结点，释放内存 */
	return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status List::TraverseList(LinkList L)
{
	LinkList p;
    p = (L)->next;
	printf("序号  类型      数目\n");
	while (p)
	{
		VisitElem(p->data);
		p = p->next;
	}
	/*printf("\n");*/
	return OK;
}

//存盘
Status List::SaveList(LinkList L)
{
	FILE *fp = fopen("cost.ini", "w");
	LinkList p = (L)->next;
	int ino = 0;               //数据序号
	char str[10] = "";         //数据类型
	float fnum = 0;            //数据数目

	if (fp == NULL)
	{
		printf("存储失败!\n");
		return ERROR;
	}
	while (p != NULL)           //将链表里的数据存进变量，然后写进文件
	{
		ino = p->data.No;
		switch (p->data.costTitle)
		{
		case STUDENTCARD:
			strcpy(str,"学生卡");
			break;
		case CLOTHES:
			strcpy(str, "服饰");
			break;
		case YULE:
			strcpy(str, "娱乐");
			break;
		case SHENGHUOYONGPIN:
			strcpy(str, "生活用品");
		default:
			break;
		}
		fnum = p->data.costNum;
		fprintf(fp, "%d %s %f\n", ino, str, fnum);
		p = p->next;
	}
	fclose(fp);
	printf("存储成功!\n");

	return OK;
}

//读盘
Status List::ReadList(LinkList L)
{
	LinkList p = NULL;
	LinkList r = L;
	int ino = 0;      //数据序号
	char str[10] = "";    //数据类型
	float fnum = 0;            //数据数目
	FILE *fp = fopen("cost.ini", "r");
	if (fp == NULL)
		return ERROR;
	while (fscanf(fp, "%d %s %f\n", &ino, str, &fnum) > 0)     //读取文件，然后分别赋值
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data.No = ino;
		if (strcmp(str,"学生卡") == 0)
		{
			p->data.costTitle = STUDENTCARD;
		}else if (strcmp(str,"服饰") == 0)
		{
			p->data.costTitle = CLOTHES;
		}else if (strcmp(str,"娱乐") == 0)
		{
			p->data.costTitle = YULE;
		}else if (strcmp(str,"生活用品") == 0)
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

//对第i条数据后的每条数据的序号自加
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

  //对第i条数据后的每条数据的序号自减
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
