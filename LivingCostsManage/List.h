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

#define MAXSIZE 20 /* 存储空间初始分配量 */

enum CostTitle
{
	STUDENTCARD,      //学生卡
	CLOTHES,          //服饰
	YULE,             //娱乐
	SHENGHUOYONGPIN   //生活用品
};

struct Cost 
{
	int No = 0;                    //数据编号
	CostTitle costTitle = STUDENTCARD;       //费用类型
	float costNum = 0;                    //费用
};

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef struct Cost ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;   /* 定义LinkList */

class List
{
public:
	List();
	~List();
	/* 初始化顺序线性表 */
	Status InitList(LinkList L);
	Status VisitElem(ElemType e);     //打印一个结点的数据
	/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
	Status IsEmpty(LinkList L);
	ElemType GetLastElem(LinkList L);    //获得最后一个结点的数据
	/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
	Status ClearList(LinkList L);
	/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
	int GetListLength(LinkList L);
	/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
	/* 操作结果：用e返回L中第i个数据元素的值 */
	ElemType GetElem(LinkList L,int i, ElemType e);
	void LocateElem(LinkList L,ElemType e);    //打印L中所有与e满足关系的数据元素的位序  
	void QueryElem(LinkList L,ElemType e, int type);     //找到所有与e满足关系的数据元素，并打印
	ElemType MaxElem(LinkList L);         //找到数目最大的元素
	ElemType MinElem(LinkList L);         //找到数目最小的元素
	float TotalElem(LinkList L);         //计算所有数目的总和
	/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
	/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
	Status InsertList(LinkList L,int i, ElemType e);
	//在链表尾部插入结点
	Status AddList(LinkList L,ElemType e);
	Status UpdateList(LinkList L, int i,ElemType e);    //修改链表的第i个结点
	/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
	/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
	Status DeleteList(LinkList L,int i, ElemType e);
	/* 初始条件：顺序线性表L已存在 */
	/* 操作结果：依次对L的每个数据元素输出 */
	Status TraverseList(LinkList L);
	Status SaveList(LinkList L);      //存盘
	Status ReadList(LinkList L);      //读盘
	Status PPList(LinkList L,int i);    //对第i条数据后的每条数据的序号自加
	Status MMList(LinkList L,int i);    //对第i条数据后的每条数据的序号自减
private:
	//LinkList L;   //头节点
};

