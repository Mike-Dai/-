#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Node{
char name[10];
int score;
struct Node* next;
}LinkList;

FILE *fp1, *fp2;

LinkList* InitLinkList()
{
    LinkList* head;
    head = (LinkList*)malloc(sizeof(LinkList));
    head->next = NULL;
    LinkList* p = head, *q = head;
	FILE* fp;
	fp = fopen("information.txt", "r");
	if (!fp)
    {
        printf("文件打开失败！\n");
        return;
    }
    char s[10];
    int t;
    while (fscanf(fp, "%s ,%d", s, &t)!=EOF)
    {
    	q = (LinkList*)malloc(sizeof(LinkList));
    	strcpy(q->name,s);
    	q->score = t;
    	p->next = q;
    	p = q;
	}
	p->next = NULL;
    return head;
}

LinkList* MoveToEnd(LinkList* head)
{
	LinkList* t = head;
	while (t->next != NULL)
	{
		t = t->next;
	}
	return t;
}
void GetScore(LinkList* end)
{
	puts("请输入学生姓名：");
    char name[10];
    scanf("%s", name);
    puts("请输入学生成绩：");
    int score;
    scanf("%d", &score);
    LinkList* stu;
    stu = (LinkList*)malloc(sizeof(LinkList));
    strcpy(stu->name,name);
    stu->score = score;
    end->next = stu;
    end = stu;
    puts("新增成功！"); 
    /*puts("1.继续输入");
    puts("2.返回");
    int t;
    scanf("%d", &t);
    if (t == 1)
    {
        GetScore(end);
    }
    else
    {
        return;
    }*/ 
}

void DeleteScore(LinkList* head)
{
	LinkList* p = head->next, *q = head;
	puts("请输入学生姓名：");
	char s[10];
	scanf("%s", s);
	while ( p != NULL )
	{
		if (strcmp(p->name,s)==0 )
		{
			printf("学生姓名：%s, 学生成绩：%d\n", p->name, p->score);
			q->next = p->next;
			free(p);
			puts("删除成功！");
			break;
		}
		q = p;
		p = p->next;
	}
	 
	 
}


void SearchScore(LinkList* head)
{
	LinkList* p = head->next;
	puts("请输入学生姓名：");
	char s[10];
	scanf("%s", s);
	while ( p != NULL )
	{
		if ( strcmp(p->name,s)==0 )
		{
			puts("查询成功！");
			printf("学生姓名：%s, 学生成绩：%d\n", p->name, p->score);
			return;
		}
		p = p->next;
	}
	puts("查无此人！");
}

void ModifyScore(LinkList* head)
{
	LinkList* p = head->next;
	puts("请输入学生姓名：");
	char s[10];
	scanf("%s", s);
	while ( p != NULL )
	{
		if ( strcmp(p->name,s)==0 )
		{
			printf("学生姓名：%s, 学生成绩：%d\n", p->name, p->score);
			puts("请输入更改后的成绩：");
			scanf("%d", &p->score);
			puts("修改成功！");
			return;
		}
		p = p->next;
	}
	puts("查无此人！");
}
void PrintScore(LinkList* head)
{
    int i;
    LinkList* t = head;
    //SaveInfo(head);
    for (i = 0; t->next !=NULL; i++)
    {
        t = t->next;
        printf("学生姓名：%s  学生成绩：%d\n",t->name, t->score);
    }
}
void Menu()
{
    puts("学生成绩管理系统");
    puts("1.添加成绩");
    puts("2.打印成绩");
    puts("3.删除成绩");
    puts("4.查询成绩");
    puts("5.修改成绩");
    puts("6.退出");
    puts("请选择1~6");
}

void LoadInfo(LinkList *head)
{
	
    
    
    /*LinkList *p = head, *q;
    FILE *fp = fopen("./Information.dat","rb");
    if (!fp)
    {
        printf("文件打开失败！\n");
        return;
    }
        q = (LinkList*)malloc(sizeof(LinkList));
        fread(q, sizeof(LinkList), 1, fp);
        while (!feof(fp))
        {
            p->next = q;
            p = q;
            q = (LinkList*)malloc(sizeof(LinkList));
            fread(q, sizeof(LinkList), 1, fp);
        }
        p->next = NULL;
        fclose(fp);*/
}



void SaveInfo(LinkList* head)
{
    printf("enter!\n");
    LinkList* t = head;
    FILE* fp = fopen("information.txt","w");
    if (!fp)
    {
        printf("文件打开失败\n");
        return;
    }
    int i;
    for (i = 0; t->next !=NULL; i++)
    {
        t = t->next;
        printf("学生姓名：%s  学生成绩：%d\n",t->name, t->score);
        fprintf(fp, "%s ,%d\n",t->name, t->score);
    }
    /*while (p != NULL)
    {
        fprintf(fp, "%s ,%d\n", p->name, p->score);
        p = p->next;
    }*/
    fclose(fp);
    printf("保存成功！\n");

    /*LinkList* p = head->next;
    FILE* fp = fopen("./Information.dat","ab");
    if (!fp)
    {
        printf("文件打开失败\n");
        return;
    }
    while (p != NULL)
    {
        fwrite(p, sizeof(LinkList), 1, fp);
        p = p->next;
    }
    printf("保存成功\n");
    fclose(fp);*/
}


int main()
{
    LinkList* head, *ptr;
    head = InitLinkList();
    PrintScore(head);
    LinkList* end;
    while (1)
    {
        Menu();
        int t;
        scanf("%d", &t);
        switch(t)
        {
        case 1:
        	end = MoveToEnd(head);
            GetScore(end);
            break;
        case 2:
            PrintScore(head);
            break;
        case 3:
        	DeleteScore(head);
        	break;
        case 4:
        	SearchScore(head);
        	break;
        case 5:
        	ModifyScore(head);
        	break;
        case 6:
            goto save;
        }
    }
    save:
    SaveInfo(head);
    getchar();
    return 0;
}
