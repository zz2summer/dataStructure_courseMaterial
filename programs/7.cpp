#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node * next;
}node;
node * create()
{
	node *p, *s, *h;
	int j = 1, x, n;
	p = h = new node;
	h->next = NULL;
	cout << "请输入链表长度：" << endl;
	cin >> n;
	cout << "请输入" << n << "个链表节点的值：" << endl;
	while (j <= n)
	{
		cin >> x;
		s = new node;
		s->data = x;
		p->next = s;
		p = s;
		j++;
	}
	p->next = NULL;
	return h;
}
void disp(node *h)
{
	node * p = h->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void combined1(node *&L,node *L1,node *L2)
{
	node *p = L1->next,*q = L2->next;
	L = new node;
	L->next = NULL;
	while (p!=NULL)
	{
		L->next = p;
		L = p;
		p = p->next;
	}
	while (q != NULL)
	{
		L->next = q;
		L = q;
		q = q->next;
	}
}
void main()
{
	node *L1, *L2, *L;
	L1 = create();
	L2 = create();
	cout << "L1的数据为：" << endl;
	disp(L1);
	cout << "L2的数据为：" << endl;
	disp(L2);
	combined1(L, L1, L2);
	disp(L);
}