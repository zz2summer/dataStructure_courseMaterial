#include <iostream>
using namespace std;
typedef struct
{
	double coef;
	int exp;
}PolyArray[];
typedef struct pnode
{
	double coef;
	int exp;
	struct pnode * next;
}PolyNode;
void DispPoly(PolyNode *L)
{
	PolyNode *p=L->next;
	while (p!=NULL)
	{
		cout<<p->coef<<"x^"<<p->exp<<" ";
		p=p->next;
	}
	cout<<endl;
}
void CreateListR(PolyNode *&L,PolyArray a, int n)
{
	PolyNode * s,* r;
	int i;
	L=new PolyNode;
	L->next=NULL;
	r=L;
	cout<<"请输入多项式的个数："<<endl;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cout<<"请输入多项式的系数和指数"<<endl;
		cin>>a[i].coef>>a[i].exp;
		s=new PolyNode;
		s->coef=a[i].coef;
		s->exp=a[i].exp;
		r->next=s;
		r=s;
	}
	r->next=NULL;
}
void Sort(PolyNode *&head)
{
	PolyNode *p=head->next,*q,*r;
	if (p!=NULL)
	{
		r=p->next;
		p->next=NULL;
		p=r;
		while(p!=NULL)
		{
			r=p->next;
			q=head;
			while(q->next!=NULL&&q->next->exp>p->exp)
				q=q->next;
			p->next=q->next;
			q->next=p;
			p=r;
		}
	}
}
void Add(PolyNode *ha,PolyNode *hb,PolyNode *&hc)
{
	PolyNode *pa=ha->next,*pb=hb->next,*s,*tc;
	double c;
	hc=new PolyNode;
	tc=hc;
	while(pa!=NULL&&pb!=NULL)
	{
		if (pa->exp>pb->exp)
		{
			s=new PolyNode;
			s->exp=pa->exp;
			s->coef=pa->coef;
			tc->next=s;
			tc=s;
			pa=pa->next;
		}
		else if (pa->exp<pb->exp)
		{
			s=new PolyNode;
			s->coef=pb->coef;
			s->exp=pb->exp;
			tc->next=s;
			tc=s;
			pb=pb->next;
		}
		else
		{
			c=pa->coef+pb->coef;
			if (c!=0)
			{
				s=new PolyNode;
				s->exp=pa->exp;
				s->coef=c;
				tc->next=s;
				tc=s;
			}
			pa=pa->next;
			pb=pb->next;
		}
	}
	if (pb!=NULL)pa=pb;
	while(pa!=NULL)
	{
		s=new PolyNode;
		s->exp=pa->exp;
		s->coef=pa->coef;
		tc->next=s;
		tc=s;
	}
	tc->next=NULL;
}
void Del1(PolyNode *ha,PolyNode *hb,PolyNode *&hc)
{
	PolyNode *pa=ha->next,*pb=hb->next,*s,*tc;
	double c;
	hc=new PolyNode;
	tc=hc;
	while(pa!=NULL&&pb!=NULL)
	{
		if (pa->exp>pb->exp)
		{
			s=new PolyNode;
			s->exp=pa->exp;
			s->coef=pa->coef;
			tc->next=s;
			tc=s;
			pa=pa->next;
		}
		else if (pa->exp<pb->exp)
		{
			s=new PolyNode;
			s->coef=-pb->coef;
			s->exp=pb->exp;
			tc->next=s;
			tc=s;
			pb=pb->next;
		}
		else
		{
			c=pa->coef-pb->coef;
			if (c!=0)
			{
				s=new PolyNode;
				s->exp=pa->exp;
				s->coef=c;
				tc->next=s;
				tc=s;
			}
			pa=pa->next;
			pb=pb->next;
		}
	}
	if (pb!=NULL)pa=pb;
	while(pa!=NULL)
	{
		s=new PolyNode;
		s->exp=pa->exp;
		s->coef=pa->coef;
		tc->next=s;
		tc=s;
	}
	tc->next=NULL;
}
void Del2(PolyNode *ha,PolyNode *hb,PolyNode *&hc)
{
	PolyNode *pa=ha->next,*pb=hb->next,*s,*tc;
	double c;
	hc=new PolyNode;
	tc=hc;
	while(pa!=NULL&&pb!=NULL)
	{
		if (pa->exp>pb->exp)
		{
			s=new PolyNode;
			s->exp=pa->exp;
			s->coef=-pa->coef;
			tc->next=s;
			tc=s;
			pa=pa->next;
		}
		else if (pa->exp<pb->exp)
		{
			s=new PolyNode;
			s->coef=pb->coef;
			s->exp=pb->exp;
			tc->next=s;
			tc=s;
			pb=pb->next;
		}
		else
		{
			c=pb->coef-pa->coef;
			if (c!=0)
			{
				s=new PolyNode;
				s->exp=pa->exp;
				s->coef=c;
				tc->next=s;
				tc=s;
			}
			pa=pa->next;
			pb=pb->next;
		}
	}
	if (pb!=NULL)pa=pb;
	while(pa!=NULL)
	{
		s=new PolyNode;
		s->exp=pa->exp;
		s->coef=pa->coef;
		tc->next=s;
		tc=s;
	}
	tc->next=NULL;
}
void main()
{
	PolyNode *ha,*hb,*hc;
	int n,m;
	PolyArray a;//={{1.2,0},{2.5,1},{3.2,3},{-2.5,5}};
	PolyArray b;//={{-1.2,0},{2.5,1},{3.2,3},{2.5,5},{5.4,10}};
	CreateListR(ha,a,n);
	CreateListR(hb,b,m);
	cout<<"原多项式A："<<endl;
	DispPoly(ha);
	cout<<"原多项式B："<<endl;
	DispPoly(hb);
	Sort(ha);
	Sort(hb);
	cout<<"有序多项式A："<<endl;
	DispPoly(ha);
	cout<<"有序多项式B："<<endl;
	DispPoly(hb);
	Add(ha,hb,hc);
	cout<<"多项式相加："<<endl;
	DispPoly(hc);
	Del1(ha,hb,hc);
	cout<<"多项式A减B："<<endl;
	DispPoly(hc);
	Del2(ha,hb,hc);
	cout<<"多项式B减A："<<endl;
	DispPoly(hc);
	
}

