#define MAXSIZE 100
typedef struct _Student
{
	char Name[MAXSIZE]; // 姓名
	char Gender; // 性别
	int Age; // 年龄
	char Id[MAXSIZE]; // 学号
	double Score; // 分数
} Student, * PStudent;