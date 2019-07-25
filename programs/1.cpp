#include<iostream>
#include <string>
using namespace std;
#define MAX 10
typedef struct
{
	int number;
	char name;
}student[MAX];
typedef struct snode
{
	int number;
	char name;
	struct snode *next;
}StudNode;
void DispStud(StudNode *L)
{
	StudNode *p = L->next;
	while (p != NULL)
	{
		cout << p->number <<" "<< p->name << endl;
		p = p->next;
	}
}
void CreateListR(StudNode *&L, student a, int n)
{
	StudNode *s,*r;
	int i;
	L = (StudNode *)malloc(sizeof(StudNode));
	r = L;
	cout<<"请输入每个学生的学号和姓名"<<endl;
	for (i = 0; i <n; i++)
	{
		cin>>a[i].number>>a[i].name;
		s = (StudNode *)malloc(sizeof(StudNode));
		s->number = a[i].number;
		s->name = a[i].name;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}
void ExchList(StudNode *&L)
{
	StudNode *p = L->next, *q;
	L->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}
int main()
{
	StudNode *h;
	student a ;
	CreateListR(h, a, 10);
	cout <<"按输入顺序输出："<< endl;
	DispStud(h);
	ExchList(h);
	cout <<"按输入的倒置顺序输出："<< endl;
	DispStud(h);
	return 0;
}
