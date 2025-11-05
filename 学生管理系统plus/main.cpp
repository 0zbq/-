#include <graphics.h>
#include<easyx.h> 
#include <stdio.h> 
#include<stdlib.h>
#include<string.h>
typedef struct stu{
	int num;
	char name[20];
	int score;
	stu *next;
}stu;
stu* menu1(stu *head);
void initmenu1();
void initmenu2();
void show(stu *head);
stu* creat(stu* head);
stu* insert(stu* head,int n);
stu* replace(stu* head,int n);
stu* delate(stu* head,int n);
void writef(stu* head);
stu* readf(stu* head);
void freeList(stu* head);
static int flag=220; 
int main()
{
	stu *head=NULL;
	initgraph(700,1200,0);// 初始化图形窗口
	initmenu1();
	ExMessage m;		// 定义消息变量
	while(true)
	{
		m = getmessage(EX_MOUSE | EX_KEY);// 获取一条鼠标或按键消息
		switch(m.message)
		{
//			case WM_MOUSEMOVE:
//				// 鼠标移动的时候画红色的小点
//				settextstyle(10,5, "幼圆");
//				outtextxy(m.x,m.y,"C");
//				break;
			case WM_LBUTTONDOWN:
				if (m.x>120&&m.x<580&&m.y<950&&m.y>350)
				{
					if(m.y<550)
					{
						 head=menu1(head);
						 initmenu1();
					}
					else if(m.y<750)
					{	
					    writef(head); 
						fillrectangle(190,275,510,200);
						settextstyle(60, 30, "幼圆");
						outtextxy(230,205, "存档成功");
					}
					else
					{
						head=readf(head);
						fillrectangle(190,275,510,200);
						settextstyle(60, 30, "幼圆");
						outtextxy(230,205, "读档成功");
					} 
				}
				else if(m.x>50&&m.x<130&&m.y<1150&&m.y>1100)
				{
					HWND hwnd = GetConsoleWindow();
					ShowWindow(hwnd, SW_SHOW);
					freeList(head); 
					return 0;
				}
				else if(m.y<150&&m.y>10);
				else if(m.x>400&&m.x<660&&m.y<1150&&m.y>1100);
				else if(m.x>190&&m.x<510&&m.y<275&&m.y>200) 
				{
				fillrectangle(190,275,510,200);
				settextstyle(60, 30, "幼圆");
				outtextxy(260,205, "状态栏");
				}
				else 
					rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);// 画一个小方块
				break;
			case WM_KEYDOWN:
				if (m.vkcode == VK_ESCAPE)
				{
					HWND hwnd = GetConsoleWindow();
					ShowWindow(hwnd, SW_SHOW);
					freeList(head); 
					return 0;// 按 ESC 键退出程序
				}	
		}
	}	
	closegraph();// 关闭图形窗口
	return 0;
}
stu* menu1(stu *head)
{
	initmenu2();
	show(head); 
	ExMessage m;		// 定义消息变量
	while(true)
	{
		m = getmessage(EX_MOUSE | EX_KEY);// 获取一条鼠标或按键消息
		switch(m.message)
		{
//			case WM_MOUSEMOVE:
//				// 鼠标移动的时候画红色的小点
//				settextstyle(10,5, "幼圆");
//				outtextxy(m.x,m.y,"C");
//				break;
			case WM_LBUTTONDOWN:		
				if (m.x>0&&m.x<700&&m.y<1005&&m.y>160)
				{
					if(m.y<220);
					else if(m.y<flag)
					{
						int x=((int)m.y-220)/40;
						if(m.ctrl)
						{
							printf("修改\n");
							head=replace(head,x);
							show(head);
							fillrectangle(190,125,510,50);
							settextstyle(60, 30, "幼圆");
							outtextxy(230,55, "修改成功");
						}
						else if(m.shift)
						{
							printf("删除\n");
							head=delate(head,x);
							flag-=40;
							show(head);
							fillrectangle(190,125,510,50);
							settextstyle(60, 30, "幼圆");
							outtextxy(230,55, "删除成功");
						}
						else
						{
							printf("插入\n");
							head=insert(head,x);
							flag+=40;
							show(head);
							fillrectangle(190,125,510,50);
							settextstyle(60, 30, "幼圆");
							outtextxy(230,55, "插入成功");
						}
					}
					else
					{
						printf("添加\n"); 
						head=creat(head);
						show(head);
						flag+=40;
						line(0,flag,700,flag);
						fillrectangle(190,125,510,50);
						settextstyle(60, 30, "幼圆");
						outtextxy(230,55, "添加成功");
					}	
				}
				else if(m.y>1025&&m.y<1075); 
				else if(m.x>400&&m.x<660&&m.y<1150&&m.y>1100);
				else if(m.x>50&&m.x<130&&m.y<1150&&m.y>1100)
				{
					HWND hwnd = GetConsoleWindow();
					ShowWindow(hwnd, SW_SHOW);
					freeList(head); 
					exit(0);	
				}
				else if(m.x>130&&m.x<210&&m.y<1150&&m.y>1100)
				{
					cleardevice();//清除当前画图窗口
					return head;
				}
				else if(m.x>190&&m.x<510&&m.y<125&&m.y>50) 
				{
						fillrectangle(190,125,510,50);
						settextstyle(60, 30, "幼圆");
						outtextxy(260,55, "状态栏");
				}
				else 
					rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);// 画一个小方块
				break;
			case WM_KEYDOWN:
				if (m.vkcode == VK_ESCAPE)
				{
					HWND hwnd = GetConsoleWindow();  //显示控制台 
					ShowWindow(hwnd, SW_SHOW);
					freeList(head); 
					exit(0);	// 按 ESC 键退出程序
				}
					
		}
	}
}
void initmenu1()
{
	//绘画主界面	 
	/**/
	setfillcolor(BLUE);//设置填充颜色（即实心的颜色） 
	fillrectangle(0,150,700,10);//表示画一个实心的矩形
	settextstyle(100, 50, "幼圆");//字体的风格
	setbkmode(TRANSPARENT);//设置背景字体背景颜色为透明，字体本身是有背景颜色的
	settextcolor(RED);//设置文本的颜色 
	outtextxy(50,30, "学生管理系统");//设置文本的位置和内容 
	/**/
	fillrectangle(190,275,510,200);
	settextstyle(60, 30, "幼圆");
	outtextxy(260,205, "状态栏");
	/**/
	fillrectangle(120,950,580,350);
	setlinecolor(WHITE);//设置实线的颜色 
	line(120,550,580,550);//画一条实线 
	line(120,750,580,750);
	settextstyle(150, 75, "幼圆");
	outtextxy(200,370, "编辑");
	outtextxy(200,570, "存档");
	outtextxy(200,770, "读档");
	/**/
	fillrectangle(50,1150,130,1100);
	settextstyle(30, 15, "幼圆");
	outtextxy(60,1110, "退出");
	/**/
	settextstyle(30, 15, "幼圆");
	outtextxy(400,1110, "张宝祺 2024204462");
}
void initmenu2()
{
		cleardevice();//清除当前画图窗口
	/**/
	fillrectangle(190,125,510,50);
	settextstyle(60, 30, "幼圆");
	outtextxy(260,55, "状态栏");
	
	/**/
	fillrectangle(0,1005,700,160);
	line(0,220,700,220);
	line(60,160,60,1005);
	line(280,160,280,1005);
	line(500,160,500,1005);
	settextstyle(50, 25, "幼圆");
	outtextxy(5,160, "序");
	outtextxy(120,160, "学号");
	outtextxy(340,160, "姓名");
	outtextxy(560,160, "成绩");
	/**/
	fillrectangle(0,1025,700,1075);
	line(195,1025,195,1075); 
	line(460,1025,460,1075); 
	settextstyle(25, 15, "幼圆");
	outtextxy(22.5,1025, "cltr+click");
	outtextxy(70,1050, "修改");
	outtextxy(245,1025, "shift+click");
	outtextxy(305,1050, "删除");
	outtextxy(542.5,1025, "click");
	outtextxy(515,1050, "添加 插入");
	/**/
	fillrectangle(50,1150,130,1100);
	settextstyle(30, 15, "幼圆");
	outtextxy(60,1110, "退出");
	/**/
	fillrectangle(130,1150,210,1100);
	settextstyle(30, 15, "幼圆");
	outtextxy(140,1110, "返回");
	/**/
	settextstyle(30, 15, "幼圆");
	outtextxy(400,1110, "张宝祺 2024204462");
}
     /*展示*/
void show(stu* head)
{
	char num[15];
	int i=0;
	stu* p=head;
	int x=220;
	initmenu2();
	while(p!=NULL)
	{
		sprintf(num,"%d",i);
		outtextxy(20,x+5,num);
		sprintf(num,"%d",p->num);
		outtextxy(90,x+5,num);
		outtextxy(340,x+5,p->name);
		sprintf(num,"%d",p->score);
		outtextxy(595,x+5,num);
		x+=40;
		line(0,x,700,x);
		i++;
		p=p->next;
	}
}
     /*添加*/ 
stu* creat(stu* head)
{
    // 显示控制台窗口
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOW);
    
	fillrectangle(190,125,510,50);
	settextstyle(60, 30, "幼圆");
	outtextxy(260,55, "添加中");
	printf("请依次输入学号,姓名,成绩:\n");
	stu *p,*q;
	int i,num,score;
	char name[20];
	scanf("%d%s%d",&num,name,&score);
	p=(stu*)malloc(sizeof(stu));
	p->num=num;
	strcpy(p->name,name);
	p->score=score;
	int n;
	n=(flag-220)/40;
	if(n==0)
	{
		head=p;
	}
	else
	{
		for(q=head,i=0;i<n-1;i++)
		{
			q=q->next;
		}
		q->next=p;
	}
	p->next=NULL;
	    
    ShowWindow(hwnd, SW_HIDE);// 隐藏控制台窗口
	return head;
} 
        /*插入*/
stu* insert(stu* head,int n)
{
    // 显示控制台窗口
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOW);
    
	fillrectangle(190,125,510,50);
	settextstyle(60, 30, "幼圆");
	outtextxy(260,55, "插入中");
	printf("请依次输入学号,姓名,成绩:\n");
	stu *p,*q;
	int i,num,score;
	char name[20];
	scanf("%d%s%d",&num,name,&score);
	p=(stu*)malloc(sizeof(stu));
	p->num=num;
	strcpy(p->name,name);
	p->score=score;
	if(n==0)
	{
		p->next=head;
		head=p;
	}
	else
	{
		for(q=head,i=0;i<n-1;i++)
		{
			q=q->next;
		}
		p->next=q->next;
		q->next=p;
	}
	ShowWindow(hwnd, SW_HIDE);// 隐藏控制台窗口
	return head;
} 
         /*修改*/
stu* replace(stu* head,int n)
{
    // 显示控制台窗口
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOW);
    
	fillrectangle(190,125,510,50);
	settextstyle(60, 30, "幼圆");
	outtextxy(260,55, "修改中");
	stu* p=head;
	printf("请依次输入学号,姓名,成绩:\n");
	for(int i=0;i<=n;i++)
	{
		scanf("%d%s%d",&p->num,p->name,&p->score);
		p=p->next;
	}
	ShowWindow(hwnd, SW_HIDE);// 隐藏控制台窗口
	return head;
}
        /*删除*/
stu* delate(stu* head,int n)
{
	stu *p=head,*q;
      if(n==0)
	{
		q=head;
		head=head->next;
		free(q);
	}
	else
	{
		for(int i=0;i<n-1;i++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		free(q);
	}
	return head;
}
/*存档*/
void writef(stu* head)
{
	FILE* fp;
	if((fp=fopen("date.txt","w"))==NULL)
	{
		printf("文件打开失败\n");
		exit(1);
	}
	stu* p=head;
	while(p!=NULL)
	{
		fprintf(fp,"%d %s %d\n",p->num,p->name,p->score);
		p=p->next;
	}
	if(fclose(fp))
	{
		printf("文件关闭失败\n");
		exit(2);
	}
}
/*读档*/
stu* readf(stu* head)
{	
    FILE* fp;
	if((fp=fopen("date.txt","r"))==NULL)
	{
		printf("文件打开失败\n");
		exit(1);
	}
	
	freeList(head); 
	head=NULL;
	flag=220;
	stu *p,*q;
	int num,score;
	char name[20];

	
	while(fscanf(fp,"%d%s%d",&num,name,&score)==3)//fscanf的返回值是实际成功赋值的参数个数
	{
		p=(stu*)malloc(sizeof(stu));
		p->num=num;
	    strcpy(p->name,name);
	    p->score=score;
		p->next=NULL;
		if(head==NULL)
		{
			head=p;
		}
		else
		{
			q->next=p;
		}
		q=p;
		flag+=40;
	}
		if(fclose(fp))
	{
		printf("文件关闭失败\n");
		exit(2);
	}
	return head;
} 

// 释放链表内存
void freeList(stu* head) {
    stu* p = head;
    while(p != NULL) {
        stu* temp = p;
        p = p->next;
        free(temp);
    }
}
