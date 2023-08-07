typedef struct _Node
{
	Student Info;
	struct _Node* Next;
} Node;

typedef struct _LinkList
{
	Node* Head;
	Node* Tail;
	int NumOfNodes;
} LinkList, * PLinkList;

// 创建头结点
bool LinkList_Create(LinkList* L);

// 创建结点
Node* LinkList_CreateNode();

// 初始的插入函数
bool LinkList_Insert1(LinkList* L, Node* pNew, int Pos);

// 在第Pos个位置插入结点，并写入学生信息
bool LinkList_Insert2(LinkList* L);

// 删除第Pos个结点
bool LinkList_Delete(LinkList* L);

// 根据学号修改学生信息
bool LinkList_Rewrite(LinkList* L);

// 根据学号查找学生信息
bool LinkList_SearchById(LinkList* L);

// 打印学生信息
bool LinkList_Print(LinkList* L);

// 销毁链表
void LinkList_Destroy(LinkList* L);

// 将学生数据写入文件
bool LinkList_SaveToFile(LinkList* L, char* fn);

// 读取学生数据文件，并将学生数据写入链表
bool LinkList_LoadFromFile(LinkList* L, char* fn);