#include"alloc.h"
#include "conio.h"
#include"stdio.h"
#include"io.h"
#define LEN sizeof(struct LNode)

typedef struct LNode
{
    char data;
    struct LNode *next;
}LNode,*LinkList;

LinkList CreatList(LinkList head)
{
    char temp;
    LinkList p1,p2;   /*一行变量定义过多，提示未定义！*/
    printf("please input temp data:\n");
    fflush(stdin);
    scanf("%c",&temp);
    while(temp!='0')
    {
        p1=(LinkList)malloc(LEN);
        p1->data=temp;
        p1->next=NULL;
        if(head->next==NULL)
        head->next=p1;
        else
        p2->next=p1;
        p2=p1;
        fflush(stdin);
        printf("please input temp data:\n");
        scanf("%c",&temp);
    }
    return head;
}
/* Insert elment */
int Insert(LinkList head,int i,char e)
{
    LinkList p=head;
        LinkList s;
        int j;
        p=p->next;
        for(j=1;j<i;j++)    /*在i后面插入*/
        {
        if(p) 
            p=p->next;
        else  
            break;
        }
        if(!p||i<1)
        {
            printf("error!Please Input right i value:\n");
            return 0;
        }
        s=(LinkList)malloc(sizeof(LNode));
        s->data=e;
        s->next=p->next;
    p->next=s;
        return 1;
}
Output(LinkList head)
{
    struct LNode *p;
    p=head->next;
    while(p!=NULL)
    {
        if(p->next==NULL)
            printf("%c",p->data);/*如果是最后一个元素，就不输出-->了*/
        else
            printf("%c-->",p->data);
            p=p->next;
    }
}
int DelList(LinkList head,int i)
{
    LinkList p,tmp;
        int j;
        p=head->next;
        tmp=head;
        for(j=1;j<i;j++)
        {
        if(p)
        {
            p=p->next;
                tmp=tmp->next;
        }
        else
        break;
        }
        if(!p||i<1)
        {
        printf("error!Input right ivalue:\n");
        return 0;
        }
        tmp->next=p->next;
        free(p);
        return 1;
}
main()
{
    int i;
        char cmd,e;
        LinkList head;
        head=(LinkList)malloc(sizeof(LNode));
        head->next=NULL;
        CreatList(head);
        Output(head);
    printf("\n");
        do
        {
        printf("i insert:\n");
        printf("d delete:\n");
        printf("q quit:\n");
        do
        {
        fflush(stdin);
        scanf("%c",&cmd);
        }while((cmd!='d')&&(cmd!='i'));
        switch(cmd)
        {
            case 'i':
            printf("input inserted data:");
            fflush(stdin);
            scanf("%c",&e);
            printf("input location i:");
            scanf("%d",&i);
            Insert(head,i,e);
            printf("after insert:");
            Output(head);
            printf("\n");
            break;
                case 'd':
            printf("input location i:");
            fflush(stdin);
            scanf("%d",&i);
            DelList(head,i);
            Output(head);
            break;
        }
        }while(cmd!='q');
    getch();
}
