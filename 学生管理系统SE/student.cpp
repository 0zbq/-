#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stu{
	int num;
	char name[20];
	int score;
	stu *next;
}stu;
stu* menu1(int i,stu *head);
stu* menu2();
stu* head_creat();
stu* tail_creat();
void seek(stu *head);
stu* insert(stu* head,int n);
stu* delate(stu* head,int n);
int main()
{
	stu *head=NULL;
    printf("[1]新建\n[2]插入\n[3]删除\n[4]查找\n[5]退出\n");
    printf("**************\n");
	printf("请输入你的选项:\n");
	int i;
	scanf("%d",&i);
	while(i!=5)
	{	
		head=menu1(i,head);
		scanf("%d",&i);
		
	}
    system("cls"); 
	printf("******感谢使用，再见******\n");
	printf("******制作者：张宝祺******\n");
	getchar();
	getchar(); 
	return 0;
}

       /*新建*/ 
stu* menu1(int i,stu *head)
{
	system("cls");
	int n;
	switch(i)
	{
		case 1:
		    head=menu2();
		    break;
		case 2:
		    printf("请输入你要插入的位置:\n");
		    scanf("%d",&n);
		    head=insert(head,n);
		    break;
		case 3:
			printf("请输入你要删除的位置:\n");
			scanf("%d",&n);
			head=delate(head,n);
			break;
		case 4:
			seek(head);
			break;
	}
	system("cls");
	printf("[1]新建\n[2]插入\n[3]删除\n[4]查找\n[5]退出\n");
	printf("**************\n");
    printf("请输入你的选项:\n");
	return head;
}

         /*新建方式*/ 
stu* menu2()
{
	stu* head=NULL;
	system("cls");
	printf("[1]头插法\n[2]尾插法\n[3]返回上一级\n");
	printf("**************\n");
	printf("请输入你的选项:\n");
	int j;
	scanf("%d",&j);
	do
	{
		switch(j)
		{
			case 1:
				head=head_creat();
				return head;
				break;
			case 2:
		    	head=tail_creat();
                return head;
			    break;
	    	case 3:
	    		return head;
	    		break;
	    	default:
	    		break;
	    }
	    system("cls");
	   	printf("[1]头插法\n[2]尾插法\n[3]返回上一级\n");
	   	printf("**************\n");
	    printf("请输入你的选项:\n");
	   	scanf("%d",&j);
	}while(j!=3);
	
	return head;
}

         /*头插法新建*/ 
stu* head_creat()
{
    stu* head=NULL;
	system("cls");
	printf("请依次输入序号,姓名,分数:\n");
	int num;
	char name[20];
	int score;
	stu* p;
	scanf("%d%s%d",&num,name,&score);
	while(num!=0)
	{
		p=(stu*)malloc(sizeof(stu));
		p->num=num;
		strcpy(p->name,name);
		p->score=score;
		p->next=head;
		head=p;
		scanf("%d%s%d",&num,name,&score);
	}
	return head;
} 

        /*尾插法创建*/
stu *tail_creat()
{
	system("cls");
	stu* head=NULL;
	stu *p,*q;
	int num;
	char name[20];
	int score;
	printf("请依次输入序号,姓名,成绩\n");
	scanf("%d%s%d",&num,name,&score);
	while(num!=0)
	{
		p=(stu*)malloc(sizeof(stu));
		p->num=num;
		strcpy(p->name,name);
		p->score=score;
		if(head==NULL)
		{
			p->next=head;
			head=p;
		}
		else
		{
			p->next=q->next;
			q->next=p;
		}
		q=p;
		scanf("%d%s%d",&num,name,&score);
	}
	return head;
} 

        /*搜索*/
void seek(stu *head)
{
	system("cls");
	stu *p;
	printf("序号\t姓名\t成绩\n");
	for(p=head;p!=NULL;p=p->next)
	{
		printf(" %d\t%s\t%d\n",p->num,p->name,p->score);
	}
	getchar();
	getchar();
}

        /*插入*/
stu* insert(stu* head,int n)
{
	system("cls");
	if(n<1)
	{
		printf("*****位置不对*****\n");
		getchar();
		getchar();
		return head;
	}
	printf("请依次输入序号,姓名,成绩:\n");
	stu *p,*q;
	int i,num,score;
	char name[20];
	scanf("%d%s%d",&num,name,&score);
	p=(stu*)malloc(sizeof(stu));
	p->num=num;
	strcpy(p->name,name);
	p->score=score;
	if(n==1)
	{
		p->next=head;
		head=p;
	}
	else
	{
		for(q=head,i=1;i<n-1;i++)
		{
			q=q->next;
		}
		p->next=q->next;
		q->next=p;
	}
	return head;
} 

        /*删除*/
stu* delate(stu* head,int n)
{
	stu *p=head,*q;
	int m=0;
	for(q=head;q!=NULL;q=q->next)
	{
		m++;
	}
	if(n<1||n>m)
	{
		system("cls");
		printf("*****位置错误******\n");
		getchar();
		getchar();
		return head;
	}
	else if(n==1)
	{
		q=head;
		head=head->next;
		free(q);
	}
	else
	{
		for(int i=1;i<n-1;i++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=p->next->next;
		free(q);
	}
	return head;
} 
