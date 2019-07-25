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
	cout << "请输入链表长度" << endl;
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
int deleted(node *&h, int x)
{
	node *p, *pre;
	pre = h;
	p = h->next;
	while (p->data != x&&p != NULL)
	{
		pre = p;
		p = p->next;
	}
	if (p == NULL) return 0;
	else
	{
		pre->next = p->next;
		delete p;
		return 1;
	}
}
void disp(node * h)
{
	node *p = h->next;
	cout << "\n链表中的元素为：" << endl;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
void main()
{
	node *p;
	int x;
	p = create();
	disp(p);
	cout << "请输入要删除的数据" << endl;
	cin >> x;
	if (deleted(p, x)) cout << "删除成功" << endl;
	else cout << "失败，没有此数据" << endl;
	disp(p);
}