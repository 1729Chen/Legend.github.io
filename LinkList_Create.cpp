#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"
#include "LinkList.h"
#include "Menu.h"

// 创建头结点
bool LinkList_Create(LinkList* L)
{
	L->Head = (Node*)malloc(sizeof(Node)); // 申请节点空间
	// 创建失败，返回
	if (L->Head == NULL) 
	{
		printf("Not enough memory!\n");
		return false;
	}
	L->Head->Next = NULL; // 头结点的指针域为NULL
	L->Tail = L->Head; // 开始时尾节点指向头结点
	L->NumOfNodes = 0; // 结点个数为0
	return true;
}

// 创建节点
Node* LinkList_CreateNode()
{
	Node* n;
	n = (Node*)malloc(sizeof(Node));
	// n可能创建失败
	if (n == NULL)
		return NULL;
	else
		n->Next = NULL;
	return n;
}

// 插入节点 write in code
bool LinkList_Insert1(LinkList* L, Node* pNew, int Pos)
{
	Node* p;
	p = L->Head;
	// 在最后一个结点后插入
	if (Pos == -1)
	{
		pNew->Next = NULL;
		L->Tail->Next = pNew;
		L->Tail = pNew;
		L->NumOfNodes++;
		return true;
	}
	// p指向第Pos-1个结点
	for (int i = 1; i < Pos && p != NULL; i++) 
		p = p->Next;
	// 链表中第Pos-1个结点不存在
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

// 插入结点 write in terminal
bool LinkList_Insert2(LinkList* L)
{
	int Pos;
	printf("请输入插入的位置：");
	scanf_s("%d", &Pos);
	Node* p = L->Head;
	Node* q = p;
	Node* pNew = LinkList_CreateNode();
	if (pNew == NULL)
	{
		printf("创建结点失败！\n");
		return false;
	}
	else
	{
		// p指向第Pos-1个结点
		for (int i = 1; i < Pos && p != NULL; i++)
			p = p->Next;
		// 链表中第Pos-1个结点不存在
		if (p == NULL || Pos == 0 || Pos < -1)
		{
			printf("Fail to insert,the %d node not found!\n", Pos-1);
			return false;
		}
		printf("请输入姓名：");
		scanf_s("%s", pNew->Info.Name, MAXSIZE);

		printf("请输入性别(M/W)：");
		scanf_s(" %c", &pNew->Info.Gender, 1);

		printf("请输入年龄：");
		scanf_s("%d", &pNew->Info.Age);

		printf("请输入学号：");
		scanf_s("%s", pNew->Info.Id, MAXSIZE);
		// 不允许存在学号相同的学生
		for (int i = 0; i < L->NumOfNodes; i++)
		{
			q = q->Next;
			if ( strcmp(pNew->Info.Id, q->Info.Id) == 0 )
			{
				printf("插入失败，已存在学号为%s的学生！\n", pNew->Info.Id);
				return false;
			}
		}

		printf("请输入成绩：");
		scanf_s("%lf", &pNew->Info.Score);
		printf("\n");
		// 在最后一个结点后插入
		if (Pos == -1)
		{
			pNew->Next = NULL;
			L->Tail->Next = pNew;
			L->Tail = pNew;
			L->NumOfNodes++;
			printf("录入信息成功！\n");
			return true;
		}
		pNew->Next = p->Next;
		p->Next = pNew;
		L->NumOfNodes++;
		// 防止按照1，2，3这样的顺序插入时尾指针未移动
		if (Pos == L->NumOfNodes)
			L->Tail = pNew;
		printf("录入信息成功！\n");
		return true;
	}
}

// 删除第Pos个结点(定义头结点的直接后继为第一个结点)
bool LinkList_Delete(LinkList* L)
{
	int Pos;
	printf("请输入删除的位置：");
	scanf_s("%d", &Pos);
	Node* p, * q;
	p = L->Head;
	// 将p指向第Pos个结点的前驱,也就是第Pos-1个结点
	for (int i = 1; i < Pos && p->Next != NULL; i++)
		p = p->Next;
	if (p->Next == NULL || Pos == 0)
	{
		printf("Fail to delete,the %d node not found!\n", Pos);
		return false;
	}
	// q指向第Pos个结点
	q = p->Next;
	p->Next = q->Next;
	// 删除尾结点，修改尾指针
	if (p->Next == NULL)
		L->Tail = p;
	free(q);
	L->NumOfNodes--;
	printf("删除成功！\n");
	return true;
}

// 根据学生学号修改学生信息
bool LinkList_Rewrite(LinkList* L)
{
	char Curr[MAXSIZE] = {0};
	printf("请输入要修改的学生学号：");
	scanf_s("%s", Curr, MAXSIZE);
	Node* p = L->Head->Next;

	while (p != NULL) 
	{
		if (strcmp(Curr, p->Info.Id) == 0) 
		{
			printf("请选择要修改的信息：\n");
			printf("1. 姓名\n");
			printf("2. 性别\n");
			printf("3. 年龄\n");
			printf("4. 学号\n");
			printf("5. 分数\n");
			printf("请选择操作(1-5)：");

			char Idx[MAXSIZE] = {0};
			scanf_s("%s", Idx, MAXSIZE);
			if (strcmp(Idx, "1") == 0)
			{
				printf("请输入新的姓名：");
				scanf_s("%s", p->Info.Name, MAXSIZE);
				printf("姓名已修改！\n");
			}
			else if (strcmp(Idx, "2") == 0)
			{
				printf("请输入新的性别：");
				scanf_s(" %c", &p->Info.Gender, 1);
				printf("性别已修改。\n");
			}
			else if (strcmp(Idx, "3") == 0)
			{
				printf("请输入新的年龄：");
				scanf_s("%d", &p->Info.Age);
				printf("年龄已修改。\n");
			}
			else if (strcmp(Idx, "4") == 0)
			{
				printf("请输入新的学号：");
				scanf_s("%s", p->Info.Id, MAXSIZE);
				// 不允许存在学号相同的学生
				Node* q = L->Head;
				for (int i = 0; i < L->NumOfNodes; i++)
				{
					q = q->Next;
					{
						if (p != q)
							if (strcmp(p->Info.Id, q->Info.Id) == 0)
							{
								printf("修改失败，已存在学号为%s的学生！\n", p->Info.Id);
								strcpy_s(p->Info.Id, MAXSIZE, Curr);
								return false;
							}
					}
				}
				printf("学号已修改。\n");
			}
			else if (strcmp(Idx, "5") == 0)
			{
				printf("请输入新的分数：");
				scanf_s("%lf", &p->Info.Score);
				printf("分数已修改。\n");
			}
			else
			{
				printf("修改失败，无效的选择！\n");
			}
			return true;
		}
		p = p->Next;
	}
	printf("修改失败，不存在学号为%s的学生！\n", Curr);
	return false;
}

// 通过学号来检索学生信息
bool LinkList_SearchById(LinkList* L) 
{
	Node* p;
	p = L->Head->Next;
	char Curr[MAXSIZE] = {0};
	printf("请输入要查找学生的学号：");
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
	printf("查找失败，学号为%s的学生不在列表中！\n", Curr);
	return false;
}

// 打印链表元素
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

// 销毁链表
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
	printf("清除成功！\n");
}

// 将链表数据写入文件
bool LinkList_SaveToFile(LinkList* L, char* fn)
{
	if (L == NULL)
	{
		printf("LinkList Empty!\n");
		return false;
	}

	Node* p = L->Head->Next;
	// 声明指向文件的指针变量fp
	FILE* fp;
	// 以写入模式打开一个二进制文件，并将文件指针存储在fp变量中
	fopen_s(&fp, fn, "wb");
	// 文件不存在
	if (fp == NULL)
	{
		printf("File open failed.\n");
		return false;
	}
	// 将结点个数写入文件
	fwrite(&(L->NumOfNodes), sizeof(L->NumOfNodes), 1, fp);
	// 将每个结点的数据写入fp文件
	while (p != NULL)
	{
		fwrite(&(p->Info), sizeof(p->Info), 1, fp);
		p = p->Next;
	}
	fclose(fp);
	printf("写入成功！\n");
	return true;
}

// 读取学生信息数据文件，并将学生信息写入链表
bool LinkList_LoadFromFile(LinkList* L, char* fn)
{
	FILE* fp;
	fopen_s(&fp, fn, "rb"); // 读取二进制文件
	if (fp == NULL)
	{
		printf("File open failed.\n");
		return false;
	}

	// 定义局部变量NumOfNodes存储文件中结点的个数
	int NumOfNodes;
	fread(&NumOfNodes, sizeof(int), 1, fp);
	// 读取文件信息，并插入到链表中
	for (int i = 0; i < NumOfNodes; i++)
	{
		Node* n = LinkList_CreateNode();
		fread(&(n->Info), sizeof(n->Info), 1, fp);
		// 尾插法
		LinkList_Insert1(L, n, -1);
	}
	fclose(fp);
	printf("读取成功！\n");
	return true;
}