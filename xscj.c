#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <process.h>

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
        printf("�ļ���ʧ�ܣ�\n");
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
	puts("������ѧ��������");
    char name[10];
    scanf("%s", name);
    puts("������ѧ���ɼ���");
    int score;
    scanf("%d", &score);
    LinkList* stu;
    stu = (LinkList*)malloc(sizeof(LinkList));
    strcpy(stu->name,name);
    stu->score = score;
    end->next = stu;
    end = stu;
    puts("1.��������");
    puts("2.����");
    int t;
    scanf("%d", &t);
    if (t == 1)
    {
        GetScore(end);
    }
    else
    {
        return;
    }
}

void PrintScore(LinkList* head)
{
    int i;
    LinkList* t = head;
    //SaveInfo(head);
    for (i = 0; t->next !=NULL; i++)
    {
        t = t->next;
        printf("ѧ��������%s  ѧ���ɼ���%d\n",t->name, t->score);
    }
}
void Menu()
{
    puts("ѧ���ɼ�����ϵͳ");
    puts("1.��ӳɼ�");
    puts("2.��ӡ�ɼ�");
    puts("3.ɾ���ɼ�");
    puts("4.�˳�");
    puts("��ѡ��1~4");
}

void LoadInfo(LinkList *head)
{
	
    
    
    /*LinkList *p = head, *q;
    FILE *fp = fopen("./Information.dat","rb");
    if (!fp)
    {
        printf("�ļ���ʧ�ܣ�\n");
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
    FILE* fp = fopen("information.txt","a");
    if (!fp)
    {
        printf("�ļ���ʧ��\n");
        return;
    }
    int i;
    for (i = 0; t->next !=NULL; i++)
    {
        t = t->next;
        printf("ѧ��������%s  ѧ���ɼ���%d\n",t->name, t->score);
        //fprintf(fp, "hello\n");
        fprintf(fp, "%s ,%d\n",t->name, t->score);
    }
    /*while (p != NULL)
    {
        fprintf(fp, "%s ,%d\n", p->name, p->score);
        p = p->next;
    }*/
    fclose(fp);
    //system("type fprintf.fp");
    printf("����ɹ���\n");

    /*LinkList* p = head->next;
    FILE* fp = fopen("./Information.dat","ab");
    if (!fp)
    {
        printf("�ļ���ʧ��\n");
        return;
    }
    while (p != NULL)
    {
        fwrite(p, sizeof(LinkList), 1, fp);
        p = p->next;
    }
    printf("����ɹ�\n");
    fclose(fp);*/
}


int main()
{
    LinkList* head, *ptr;
    head = InitLinkList();
    PrintScore(head);
    //LoadInfo(head);
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
        	//DeleteScore();
        	break;
        case 4:
            goto save;
        }
    }
    save:
    SaveInfo(head);
    getchar();
    return 0;
}

