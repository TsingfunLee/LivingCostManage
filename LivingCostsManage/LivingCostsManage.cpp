// LivingCostsManage.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "List.h"


void help();

int _tmain(int argc, _TCHAR* argv[])
{
	char command[10] = "";    //操作指令
	char input[10] = "";     //用户输入 
	int  i = 0;      //标记数据条数
	bool IsStored = FALSE;      //标记是否存盘
	LinkList L;
	ElemType e;    //链表数据元素
	List costs;    //链表对象

	L = (LinkList)malloc(sizeof(Node));

	costs.InitList(L);
	help();
	
	while (command)
	{
		printf("请输入指令：\n");
		scanf("%s", command);
		switch (command[0])
		{
		case '?':     //帮助
			help();
			break;
		case 'a':     //添加
			e=costs.GetLastElem(L);
			++e.No;

			printf("请输入类型：0学生卡 1服饰 2娱乐 3生活用品\n");
			scanf("%s", input);
			if (input[0] == '0')
			{
				e.costTitle = STUDENTCARD;
			}
			else if(input[0] == '1'){
				e.costTitle = CLOTHES;
			}
			else if (input[0] == '2')
			{
				e.costTitle = YULE;
			}
			else if (input[0]=='3')
			{
				e.costTitle = SHENGHUOYONGPIN;
			}

			printf("请输入数目：\n");
			scanf("%f", &e.costNum);

			if (costs.AddList(L,e))
			{
				printf("添加记录成功！\n");
				IsStored = FALSE;
			}
			else{
				printf("添加记录失败！\n");
			}

			costs.TraverseList(L);
			
			break;
		case 'i':      //插入
			printf("请输入要在第几条数据前插入：\n");
			scanf("%d", &i);

			e.No = i;

			printf("请输入类型：0学生卡 1服饰 2娱乐 3生活用品\n");
			scanf("%s", input);

			if (input[0] == '0')
			{
				e.costTitle = STUDENTCARD;
			}
			else if (input[0] == '1'){
				e.costTitle = CLOTHES;
			}
			else if (input[0] == '2')
			{
				e.costTitle = YULE;
			}
			else if (input[0] == '3')
			{
				e.costTitle = SHENGHUOYONGPIN;
			}

			printf("请输入数目：\n");
			scanf("%f", &e.costNum);

			if (costs.InsertList(L,i,e))
			{
				printf("插入记录成功！\n");
				IsStored = FALSE;
				costs.PPList(L,i);
			} 
			else
			{
				printf("插入记录失败！\n");
			}

			costs.TraverseList(L);

			break;
		case 'm':    //修改
			printf("请输入要修改的数据序号：\n");
			scanf("%d", &i);
			e.No = i;

			printf("请输入类型：0学生卡 1服饰 2娱乐 3生活用品\n");
			scanf("%s", input);

			if (input[0] == '0')
			{
				e.costTitle = STUDENTCARD;
			}
			else if (input[0] == '1'){
				e.costTitle = CLOTHES;
			}
			else if (input[0] == '2')
			{
				e.costTitle = YULE;
			}
			else if (input[0] == '3')
			{
				e.costTitle = SHENGHUOYONGPIN;
			}

			printf("请输入数目：\n");
			scanf("%f", &e.costNum);

			costs.UpdateList(L, i, e);
			costs.TraverseList(L);
			break;
		case 'd':      //删除
			printf("请输入要删除的数据序号：\n");
			scanf("%d", &i);
			if (costs.DeleteList(L,i, e))
			{
				printf("删除成功！\n");
				IsStored = FALSE;
				costs.MMList(L,i);
				costs.TraverseList(L);
			}
			else{
				printf("删除失败！\n");
			}
			break;
		case 'c':
			printf("确定要清空所有数据？ 是y 否n\n");
			scanf("%s", input);
			if (input[0]=='y')
			{
				costs.ClearList(L);
				printf("数据已清空！\n");
			} 
			break;
		case 'f':      //查找
			printf("请输入要查找的数据序号：\n");
			scanf("%d", &i);
			e = costs.GetElem(L,i, e);
			printf("序号  类型      数目\n");
			costs.VisitElem(e);
			break;
		case 'g':     //定位
			printf("请输入要定位的记录的类型：0学生卡 1服饰 2娱乐 3生活用品\n");
			scanf("%s", input);

			if (input[0] == '0')
			{
				e.costTitle = STUDENTCARD;
			}
			else if (input[0] == '1'){
				e.costTitle = CLOTHES;
			}
			else if (input[0] == '2')
			{
				e.costTitle = YULE;
			}
			else if (input[0] == '3')
			{
				e.costTitle = SHENGHUOYONGPIN;
			}

			printf("请输入要定位的记录的数目：\n");
			scanf("%f", &e.costNum);
			printf("该记录位于：\n");
			costs.LocateElem(L,e);
			break;
		case 'h':     //按条件查询
			printf("条件查询1 查询最大数目2 查询最小数目3\n");
			scanf("%s", input);
			if (input[0]=='1')       //条件查询
			{
				int type = 0;
				printf("按类型查询 1  按数目查询 2\n");
				scanf("%d", &type);
				printf("请输入要查询的值：\n");
				if (type==1)
				{
					printf("0学生卡 1服饰 2娱乐 3生活用品\n");
					scanf("%s", input);

					if (input[0] == '0')
					{
						e.costTitle = STUDENTCARD;
					}
					else if (input[0] == '1'){
						e.costTitle = CLOTHES;
					}
					else if (input[0] == '2')
					{
						e.costTitle = YULE;
					}
					else if (input[0] == '3')
					{
						e.costTitle = SHENGHUOYONGPIN;
					}
				} 
				else if (type == 2)
				{
					scanf("%f", &e.costNum);
				}
				printf("序号  类型      数目\n");
				costs.QueryElem(L,e, type);
			} 
			else if (input[0] == '2')    //查询最大数目
			{
				e=costs.MaxElem(L);
				printf("最大数目为：\n");
				printf("序号  类型      数目\n");
				costs.VisitElem(e);
			}
			else if (input[0]=='3')     //查询最小数目
			{
				e = costs.MinElem(L); 
				printf("最小数目为：\n");
				printf("序号  类型      数目\n");
				costs.VisitElem(e);
			}
			break;
		case 't':     //统计
			printf("数目总和为：%.2f元\n", costs.TotalElem(L));
			break;
		case 'p':      //显示所有数据
			if (costs.IsEmpty(L))
			{
				printf("记录为空！\n");
			}
			else{
				costs.TraverseList(L);
				printf("共有%d条记录\n", costs.GetListLength(L));
			}
			break;
		case 'l':      //读取文件
			costs.ReadList(L);
			costs.TraverseList(L);
			break;
		case 's':      //保存文件
			costs.SaveList(L);
			break;
		case 'q':      //退出
			if (IsStored == FALSE)
			{
				printf("是否要存盘？ 是y 否n\n");
				scanf("%s", input);
				if (input[0] == 'y')
				{
					costs.SaveList(L);
				}
				else if (input[0] == 'n')
				{
					return -1;
				}
			} 
			
			return -1;
			break;
		default:
			printf("请输入正确的指令\n");
			break;
		}
	}
	return 0;
}

void help()       //帮助模块
{
	printf("/---------------程序使用说明---------------\\\n");
	printf("|------------------------------------------|\n");
	printf("|指令|   功能   |           说明           |\n");
	printf("| ?  | 取得帮助 |显示本帮助信息            |\n");
	printf("| a  | 添加     |向链表中末尾添加记录      |\n");
	printf("| i  | 插入     |向链表中插入记录          |\n");
	printf("| m  | 修改     |修改某个节点的记录        |\n");
	printf("| d  | 删除     |删除链表中的记录          |\n");
	printf("| c  | 清空     |清空链表中的所有记录      |\n");
	printf("| f  | 查找记录 |查找链表中的记录          |\n");
	printf("| g  | 定位记录 |定位记录所在结点          |\n");
	printf("| h  | 条件查询 |按条件查找链表中的记录    |\n");
	printf("| t  | 统计     |统计金额总数              |\n");
	printf("| p  | 显示记录 |显示链表中全部记录        |\n");
	printf("| l  | 读取文件 |读入磁盘文件              |\n");
	printf("| s  | 存为文件 |将当前工作保存为文件      |\n");
	printf("| q  | 退出程序 |退出本系统                |\n");
	printf("\\------------------------------------------/\n");
}

