#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"
#include "LinkList.h"
#include "Menu.h"

// ����ͷ���
bool LinkList_Create(LinkList* L)
{
	L->Head = (Node*)malloc(sizeof(Node)); // ����ڵ�ռ�
	// ����ʧ�ܣ�����
	if (L->Head == NULL) 
	{
		printf("Not enough memory!\n");
		return false;
	}
	L->Head->Next = NULL; // ͷ����ָ����ΪNULL
	L->Tail = L->Head; // ��ʼʱβ�ڵ�ָ��ͷ���
	L->NumOfNodes = 0; // ������Ϊ0
	return true;
}

// �����ڵ�
Node* LinkList_CreateNode()
{
	Node* n;
	n = (Node*)malloc(sizeof(Node));
	// n���ܴ���ʧ��
	if (n == NULL)
		return NULL;
	else
		n->Next = NULL;
	return n;
}

// ����ڵ� write in code
bool LinkList_Insert1(LinkList* L, Node* pNew, int Pos)
{
	Node* p;
	p = L->Head;
	// �����һ���������
	if (Pos == -1)
	{
		pNew->Next = NULL;
		L->Tail->Next = pNew;
		L->Tail = pNew;
		L->NumOfNodes++;
		return true;
	}
	// pָ���Pos-1�����
	for (int i = 1; i < Pos && p != NULL; i++) 
		p = p->Next;
	// �����е�Pos-1����㲻����
	if (p == NULL || Pos == 0) 
	{
		printf("the %d node not found!\n", Pos-1);
		return false;
	}
	pNew->Next = p->Next;
	p->Next = pNew;
	L->NumOfNodes++;
	return true;
}

// ������ write in terminal
bool LinkList_Insert2(LinkList* L)
{
	int Pos;
	printf("����������λ�ã�");
	scanf_s("%d", &Pos);
	Node* p = L->Head;
	Node* q = p;
	Node* pNew = LinkList_CreateNode();
	if (pNew == NULL)
	{
		printf("�������ʧ�ܣ�\n");
		return false;
	}
	else
	{
		// pָ���Pos-1�����
		for (int i = 1; i < Pos && p != NULL; i++)
			p = p->Next;
		// �����е�Pos-1����㲻����
		if (p == NULL || Pos == 0 || Pos < -1)
		{
			printf("Fail to insert,the %d node not found!\n", Pos-1);
			return false;
		}
		printf("������������");
		scanf_s("%s", pNew->Info.Name, MAXSIZE);

		printf("�������Ա�(M/W)��");
		scanf_s(" %c", &pNew->Info.Gender, 1);

		printf("���������䣺");
		scanf_s("%d", &pNew->Info.Age);

		printf("������ѧ�ţ�");
		scanf_s("%s", pNew->Info.Id, MAXSIZE);
		// ���������ѧ����ͬ��ѧ��
		for (int i = 0; i < L->NumOfNodes; i++)
		{
			q = q->Next;
			if ( strcmp(pNew->Info.Id, q->Info.Id) == 0 )
			{
				printf("����ʧ�ܣ��Ѵ���ѧ��Ϊ%s��ѧ����\n", pNew->Info.Id);
				return false;
			}
		}

		printf("������ɼ���");
		scanf_s("%lf", &pNew->Info.Score);
		printf("\n");
		// �����һ���������
		if (Pos == -1)
		{
			pNew->Next = NULL;
			L->Tail->Next = pNew;
			L->Tail = pNew;
			L->NumOfNodes++;
			printf("¼����Ϣ�ɹ���\n");
			return true;
		}
		pNew->Next = p->Next;
		p->Next = pNew;
		L->NumOfNodes++;
		// ��ֹ����1��2��3������˳�����ʱβָ��δ�ƶ�
		if (Pos == L->NumOfNodes)
			L->Tail = pNew;
		printf("¼����Ϣ�ɹ���\n");
		return true;
	}
}

// ɾ����Pos�����(����ͷ����ֱ�Ӻ��Ϊ��һ�����)
bool LinkList_Delete(LinkList* L)
{
	int Pos;
	printf("������ɾ����λ�ã�");
	scanf_s("%d", &Pos);
	Node* p, * q;
	p = L->Head;
	// ��pָ���Pos������ǰ��,Ҳ���ǵ�Pos-1�����
	for (int i = 1; i < Pos && p->Next != NULL; i++)
		p = p->Next;
	if (p->Next == NULL || Pos == 0)
	{
		printf("Fail to delete,the %d node not found!\n", Pos);
		return false;
	}
	// qָ���Pos�����
	q = p->Next;
	p->Next = q->Next;
	// ɾ��β��㣬�޸�βָ��
	if (p->Next == NULL)
		L->Tail = p;
	free(q);
	L->NumOfNodes--;
	printf("ɾ���ɹ���\n");
	return true;
}

// ����ѧ��ѧ���޸�ѧ����Ϣ
bool LinkList_Rewrite(LinkList* L)
{
	char Curr[MAXSIZE] = {0};
	printf("������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	scanf_s("%s", Curr, MAXSIZE);
	Node* p = L->Head->Next;

	while (p != NULL) 
	{
		if (strcmp(Curr, p->Info.Id) == 0) 
		{
			printf("��ѡ��Ҫ�޸ĵ���Ϣ��\n");
			printf("1. ����\n");
			printf("2. �Ա�\n");
			printf("3. ����\n");
			printf("4. ѧ��\n");
			printf("5. ����\n");
			printf("��ѡ�����(1-5)��");

			char Idx[MAXSIZE] = {0};
			scanf_s("%s", Idx, MAXSIZE);
			if (strcmp(Idx, "1") == 0)
			{
				printf("�������µ�������");
				scanf_s("%s", p->Info.Name, MAXSIZE);
				printf("�������޸ģ�\n");
			}
			else if (strcmp(Idx, "2") == 0)
			{
				printf("�������µ��Ա�");
				scanf_s(" %c", &p->Info.Gender, 1);
				printf("�Ա����޸ġ�\n");
			}
			else if (strcmp(Idx, "3") == 0)
			{
				printf("�������µ����䣺");
				scanf_s("%d", &p->Info.Age);
				printf("�������޸ġ�\n");
			}
			else if (strcmp(Idx, "4") == 0)
			{
				printf("�������µ�ѧ�ţ�");
				scanf_s("%s", p->Info.Id, MAXSIZE);
				// ���������ѧ����ͬ��ѧ��
				Node* q = L->Head;
				for (int i = 0; i < L->NumOfNodes; i++)
				{
					q = q->Next;
					{
						if (p != q)
							if (strcmp(p->Info.Id, q->Info.Id) == 0)
							{
								printf("�޸�ʧ�ܣ��Ѵ���ѧ��Ϊ%s��ѧ����\n", p->Info.Id);
								strcpy_s(p->Info.Id, MAXSIZE, Curr);
								return false;
							}
					}
				}
				printf("ѧ�����޸ġ�\n");
			}
			else if (strcmp(Idx, "5") == 0)
			{
				printf("�������µķ�����");
				scanf_s("%lf", &p->Info.Score);
				printf("�������޸ġ�\n");
			}
			else
			{
				printf("�޸�ʧ�ܣ���Ч��ѡ��\n");
			}
			return true;
		}
		p = p->Next;
	}
	printf("�޸�ʧ�ܣ�������ѧ��Ϊ%s��ѧ����\n", Curr);
	return false;
}

// ͨ��ѧ��������ѧ����Ϣ
bool LinkList_SearchById(LinkList* L) 
{
	Node* p;
	p = L->Head->Next;
	char Curr[MAXSIZE] = {0};
	printf("������Ҫ����ѧ����ѧ�ţ�");
	scanf_s("%s", Curr, MAXSIZE);

	for (int i=0; i<L->NumOfNodes; i++)
	{
		if (strcmp(Curr, p->Info.Id) == 0)
		{
			ListHead_Print();
			printf("\033[33m\t%-d\t%-s\t%-c\t%-d\t%-s\t%-.2lf\033[0m\n", i+1, p->Info.Name, p->Info.Gender, p->Info.Age, p->Info.Id, p->Info.Score);
			return true;
		}
		p = p->Next;
	}
	printf("����ʧ�ܣ�ѧ��Ϊ%s��ѧ�������б��У�\n", Curr);
	return false;
}

// ��ӡ����Ԫ��
bool LinkList_Print(LinkList* L)
{
	int i = 1;
	if (L == NULL)
	{
		printf("LinkList Empty!\n");
		return false;
	}
	Node* p = L->Head->Next;
	ListHead_Print();
	while (p != NULL)
	{
		printf("\033[33m\t%-d\t%-s\t%-c\t%-d\t%-s\t%-.2lf\033[0m\n", i, p->Info.Name, p->Info.Gender, p->Info.Age, p->Info.Id, p->Info.Score);
		printf("\n");
		p = p->Next;
		i++;
	}
	return true;
}

// ��������
void LinkList_Destroy(LinkList* L)
{
	Node *p, *q;
	p = L->Head;
	while (p->Next != NULL)
	{
		q = p->Next;
		p->Next = q->Next;
		free(q);
	}
	L->Head = NULL;
	L->Tail = NULL;
	L->NumOfNodes = 0;
	free(L->Head);
	printf("����ɹ���\n");
}

// ����������д���ļ�
bool LinkList_SaveToFile(LinkList* L, char* fn)
{
	if (L == NULL)
	{
		printf("LinkList Empty!\n");
		return false;
	}

	Node* p = L->Head->Next;
	// ����ָ���ļ���ָ�����fp
	FILE* fp;
	// ��д��ģʽ��һ���������ļ��������ļ�ָ��洢��fp������
	fopen_s(&fp, fn, "wb");
	// �ļ�������
	if (fp == NULL)
	{
		printf("File open failed.\n");
		return false;
	}
	// ��������д���ļ�
	fwrite(&(L->NumOfNodes), sizeof(L->NumOfNodes), 1, fp);
	// ��ÿ����������д��fp�ļ�
	while (p != NULL)
	{
		fwrite(&(p->Info), sizeof(p->Info), 1, fp);
		p = p->Next;
	}
	fclose(fp);
	printf("д��ɹ���\n");
	return true;
}

// ��ȡѧ����Ϣ�����ļ�������ѧ����Ϣд������
bool LinkList_LoadFromFile(LinkList* L, char* fn)
{
	FILE* fp;
	fopen_s(&fp, fn, "rb"); // ��ȡ�������ļ�
	if (fp == NULL)
	{
		printf("File open failed.\n");
		return false;
	}

	// ����ֲ�����NumOfNodes�洢�ļ��н��ĸ���
	int NumOfNodes;
	fread(&NumOfNodes, sizeof(int), 1, fp);
	// ��ȡ�ļ���Ϣ�������뵽������
	for (int i = 0; i < NumOfNodes; i++)
	{
		Node* n = LinkList_CreateNode();
		fread(&(n->Info), sizeof(n->Info), 1, fp);
		// β�巨
		LinkList_Insert1(L, n, -1);
	}
	fclose(fp);
	printf("��ȡ�ɹ���\n");
	return true;
}