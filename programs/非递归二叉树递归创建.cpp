#include<iostream>
using namespace std;
struct Node
{
	char data;
	struct Node *lchild;
	struct Node *rchild;
};
Node* creatTree(struct Node *head)
{
	char ch;
	scanf("%c",&ch);
	if(ch=='$') 
		head=NULL; 
	else
	{
		head=(Node*)malloc(sizeof(Node));
		head->data=ch;					             //先序输入
		head->lchild=creatTree(head->lchild);
		head->rchild=creatTree(head->rchild);
	}
	return head;
}
void preOrderUnrec(struct Node *head){
	struct Node *p;
	struct Node *stack[20];
	int top=0;
	p=head;
	while (p|| top!=0)
	{
		while (p) //遍历左子树
		{
			cout<<p->data<<" ";
			if(p->rchild)
			{
				stack[top++] = p->rchild;
			}
			p=p->lchild; 
		}//endwhile
		if (top!=0)
		{
			p = stack[--top];
		}//end of if
	}//end of while 
}//preOrderUnrec 

void inOrderUnrec(struct Node *head){
	struct Node *p;
	struct Node *stack[20];
	int top=0;
	p=head;
	while(p||top!=0){
		while (p){
			stack[top++]=p;
			p=p->lchild ;
		}
		p=stack[--top];
		cout<<p->data<<" ";
		p=p->rchild ;
	}//end of while 
}//inOrderUnrec

void postOrderUnrec(struct Node *head){
	struct Node *p;
	struct Node *stack[20];
	int status[20];
	int top = 0;
	int tempstatus;
	p = head;
	if(p){
		stack[top] = p;
		status[top] = 1;
		top ++;
	}
	while(top!=0){
		top = top -1;
		p = stack[top];
		tempstatus = status[top];
		switch(tempstatus){
			case 1: {
				stack[top] = p;
				status[top] = 2;
				top ++;
				if(p->lchild){
					stack[top] = p->lchild;
					status[top] = 1;
					top ++;
				}
				break;
			}
			case 2: {
				stack[top] = p;
				status[top] = 3;
				top ++;
				if(p->rchild != NULL){
					stack[top] = p->rchild;
					status[top] = 1;
					top ++;
				}
				break;
			}
			case 3: {
				cout<<p->data<<" ";
				break;
			}

		}//end of switch
	}//end of while
}//postOrderUnrec
void main()
{
	cout<<"请输入二叉树数据：";
	Node *head = creatTree(head);
	cout<<"先序输出：";
	preOrderUnrec(head);
	cout<<endl<<"中序输出：";
	inOrderUnrec(head);
	cout<<endl<<"后序输出：";
	postOrderUnrec(head);
	cout<<endl;
}