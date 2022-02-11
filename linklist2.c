#include"alloc.h"
#define LEN sizeof(struct node)
#include "conio.h"
#include"stdio.h"
struct head
{
    char data;
 struct node *first;
}*head;
struct node
{
    char data;
 struct node *next;
}node;
typedef struct node *pointer;
CreatLinkList()
{
    char temp='B';
    struct node *p1,*p2;
    head->data='A';
    head->first=NULL;
    p1=(pointer *)malloc(LEN);
    p1->data=temp;
    p1->next=NULL;
    head->first=p1;
    p2=p1;
    printf("please input temp data:\n");
/*创建单链表(很罗嗦)第一第二个节点都初始化了*/
/*scanf("%c\n",&temp);*/
/*%c 后面加\n是天大的错误！切记切记！*/
    scanf("%c",&temp);
    while(temp!='0')
    {
     p1=(pointer)malloc(LEN);
     p1->data=temp;
     p1->next=NULL;
     p2->next=p1;
     p2=p1;
     fflush(stdin);
     printf("please input temp data:\n");
     scanf("%c",&temp);
    }
}
Output(struct node *p)
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
    CreatLinkList();
    Output(p);
    getch();
}