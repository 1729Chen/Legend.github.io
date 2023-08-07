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

// ����ͷ���
bool LinkList_Create(LinkList* L);

// �������
Node* LinkList_CreateNode();

// ��ʼ�Ĳ��뺯��
bool LinkList_Insert1(LinkList* L, Node* pNew, int Pos);

// �ڵ�Pos��λ�ò����㣬��д��ѧ����Ϣ
bool LinkList_Insert2(LinkList* L);

// ɾ����Pos�����
bool LinkList_Delete(LinkList* L);

// ����ѧ���޸�ѧ����Ϣ
bool LinkList_Rewrite(LinkList* L);

// ����ѧ�Ų���ѧ����Ϣ
bool LinkList_SearchById(LinkList* L);

// ��ӡѧ����Ϣ
bool LinkList_Print(LinkList* L);

// ��������
void LinkList_Destroy(LinkList* L);

// ��ѧ������д���ļ�
bool LinkList_SaveToFile(LinkList* L, char* fn);

// ��ȡѧ�������ļ�������ѧ������д������
bool LinkList_LoadFromFile(LinkList* L, char* fn);