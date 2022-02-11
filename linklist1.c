#include"alloc.h"
#define LEN sizeof(struct node)
#include "conio.h"
#include"stdio.h"
struct head
{
    char data;
    struct node *first;
}*head;
typedef struct node
{
    char data;
    struct node *next;
}node;
typedef struct node * pointer;
struct head *CreatLinkList()
{
    char temp;
    struct node *p1,*p2;
    head->data='A';
    head->first=NULL;
    printf("please input temp data:\n");
 /*scanf("%c\n",&temp);*/
 /*%c 后面加\n是天大的错误！切记切记！*/
    scanf("%c",&temp);
    while(temp!='0')
    {
        p1=(pointer *)malloc(LEN);
        p1->data=temp;
        p1->next=NULL;
        if(head->first==NULL)
        head->first=p1;
        else
        p2->next=p1;
        p2=p1;
        fflush(stdin);
        printf("please input temp data:\n");
        scanf("%c",&temp);
    }
    return head;
}
Output(struct head *head,struct node *p)
{
    printf("%c",head->data);
    p=head->first;
    while(p!=NULL)
    {
    printf("-->%c",p->data);
    p=p->next;
    }
}
main()
{
    struct node *p;
    struct head *head;
    head=CreatLinkList();
    Output(head,p);
    getch();
}
/*运行如下*/
please input temp data:
B
please input temp data:
C
please input temp data:
D
please input temp data:
0
A-->B-->C-->DNull pointer assignment
/*空指针，有错误啊*/