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
	cout << "������������" << endl;
	cin >> n;
	cout << "������" << n << "������ڵ��ֵ��" << endl;
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
	cout << "\n�����е�Ԫ��Ϊ��" << endl;
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
	cout << "������Ҫɾ��������" << endl;
	cin >> x;
	if (deleted(p, x)) cout << "ɾ���ɹ�" << endl;
	else cout << "ʧ�ܣ�û�д�����" << endl;
	disp(p);
}