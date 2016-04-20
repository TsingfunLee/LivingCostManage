// LivingCostsManage.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "List.h"


void help();

int _tmain(int argc, _TCHAR* argv[])
{
	char command[10] = "";    //����ָ��
	char input[10] = "";     //�û����� 
	int  i = 0;      //�����������
	bool IsStored = FALSE;      //����Ƿ����
	LinkList L;
	ElemType e;    //��������Ԫ��
	List costs;    //�������

	L = (LinkList)malloc(sizeof(Node));

	costs.InitList(L);
	help();
	
	while (command)
	{
		printf("������ָ�\n");
		scanf("%s", command);
		switch (command[0])
		{
		case '?':     //����
			help();
			break;
		case 'a':     //���
			e=costs.GetLastElem(L);
			++e.No;

			printf("���������ͣ�0ѧ���� 1���� 2���� 3������Ʒ\n");
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

			printf("��������Ŀ��\n");
			scanf("%f", &e.costNum);

			if (costs.AddList(L,e))
			{
				printf("��Ӽ�¼�ɹ���\n");
				IsStored = FALSE;
			}
			else{
				printf("��Ӽ�¼ʧ�ܣ�\n");
			}

			costs.TraverseList(L);
			
			break;
		case 'i':      //����
			printf("������Ҫ�ڵڼ�������ǰ���룺\n");
			scanf("%d", &i);

			e.No = i;

			printf("���������ͣ�0ѧ���� 1���� 2���� 3������Ʒ\n");
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

			printf("��������Ŀ��\n");
			scanf("%f", &e.costNum);

			if (costs.InsertList(L,i,e))
			{
				printf("�����¼�ɹ���\n");
				IsStored = FALSE;
				costs.PPList(L,i);
			} 
			else
			{
				printf("�����¼ʧ�ܣ�\n");
			}

			costs.TraverseList(L);

			break;
		case 'm':    //�޸�
			printf("������Ҫ�޸ĵ�������ţ�\n");
			scanf("%d", &i);
			e.No = i;

			printf("���������ͣ�0ѧ���� 1���� 2���� 3������Ʒ\n");
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

			printf("��������Ŀ��\n");
			scanf("%f", &e.costNum);

			costs.UpdateList(L, i, e);
			costs.TraverseList(L);
			break;
		case 'd':      //ɾ��
			printf("������Ҫɾ����������ţ�\n");
			scanf("%d", &i);
			if (costs.DeleteList(L,i, e))
			{
				printf("ɾ���ɹ���\n");
				IsStored = FALSE;
				costs.MMList(L,i);
				costs.TraverseList(L);
			}
			else{
				printf("ɾ��ʧ�ܣ�\n");
			}
			break;
		case 'c':
			printf("ȷ��Ҫ����������ݣ� ��y ��n\n");
			scanf("%s", input);
			if (input[0]=='y')
			{
				costs.ClearList(L);
				printf("��������գ�\n");
			} 
			break;
		case 'f':      //����
			printf("������Ҫ���ҵ�������ţ�\n");
			scanf("%d", &i);
			e = costs.GetElem(L,i, e);
			printf("���  ����      ��Ŀ\n");
			costs.VisitElem(e);
			break;
		case 'g':     //��λ
			printf("������Ҫ��λ�ļ�¼�����ͣ�0ѧ���� 1���� 2���� 3������Ʒ\n");
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

			printf("������Ҫ��λ�ļ�¼����Ŀ��\n");
			scanf("%f", &e.costNum);
			printf("�ü�¼λ�ڣ�\n");
			costs.LocateElem(L,e);
			break;
		case 'h':     //��������ѯ
			printf("������ѯ1 ��ѯ�����Ŀ2 ��ѯ��С��Ŀ3\n");
			scanf("%s", input);
			if (input[0]=='1')       //������ѯ
			{
				int type = 0;
				printf("�����Ͳ�ѯ 1  ����Ŀ��ѯ 2\n");
				scanf("%d", &type);
				printf("������Ҫ��ѯ��ֵ��\n");
				if (type==1)
				{
					printf("0ѧ���� 1���� 2���� 3������Ʒ\n");
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
				printf("���  ����      ��Ŀ\n");
				costs.QueryElem(L,e, type);
			} 
			else if (input[0] == '2')    //��ѯ�����Ŀ
			{
				e=costs.MaxElem(L);
				printf("�����ĿΪ��\n");
				printf("���  ����      ��Ŀ\n");
				costs.VisitElem(e);
			}
			else if (input[0]=='3')     //��ѯ��С��Ŀ
			{
				e = costs.MinElem(L); 
				printf("��С��ĿΪ��\n");
				printf("���  ����      ��Ŀ\n");
				costs.VisitElem(e);
			}
			break;
		case 't':     //ͳ��
			printf("��Ŀ�ܺ�Ϊ��%.2fԪ\n", costs.TotalElem(L));
			break;
		case 'p':      //��ʾ��������
			if (costs.IsEmpty(L))
			{
				printf("��¼Ϊ�գ�\n");
			}
			else{
				costs.TraverseList(L);
				printf("����%d����¼\n", costs.GetListLength(L));
			}
			break;
		case 'l':      //��ȡ�ļ�
			costs.ReadList(L);
			costs.TraverseList(L);
			break;
		case 's':      //�����ļ�
			costs.SaveList(L);
			break;
		case 'q':      //�˳�
			if (IsStored == FALSE)
			{
				printf("�Ƿ�Ҫ���̣� ��y ��n\n");
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
			printf("��������ȷ��ָ��\n");
			break;
		}
	}
	return 0;
}

void help()       //����ģ��
{
	printf("/---------------����ʹ��˵��---------------\\\n");
	printf("|------------------------------------------|\n");
	printf("|ָ��|   ����   |           ˵��           |\n");
	printf("| ?  | ȡ�ð��� |��ʾ��������Ϣ            |\n");
	printf("| a  | ���     |��������ĩβ��Ӽ�¼      |\n");
	printf("| i  | ����     |�������в����¼          |\n");
	printf("| m  | �޸�     |�޸�ĳ���ڵ�ļ�¼        |\n");
	printf("| d  | ɾ��     |ɾ�������еļ�¼          |\n");
	printf("| c  | ���     |��������е����м�¼      |\n");
	printf("| f  | ���Ҽ�¼ |���������еļ�¼          |\n");
	printf("| g  | ��λ��¼ |��λ��¼���ڽ��          |\n");
	printf("| h  | ������ѯ |���������������еļ�¼    |\n");
	printf("| t  | ͳ��     |ͳ�ƽ������              |\n");
	printf("| p  | ��ʾ��¼ |��ʾ������ȫ����¼        |\n");
	printf("| l  | ��ȡ�ļ� |��������ļ�              |\n");
	printf("| s  | ��Ϊ�ļ� |����ǰ��������Ϊ�ļ�      |\n");
	printf("| q  | �˳����� |�˳���ϵͳ                |\n");
	printf("\\------------------------------------------/\n");
}

