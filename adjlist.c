/*nodirection graph Adjacency List*/
#include"stdio.h"
#define NMAX 10
typedef struct node *pointer;
struct node
{
    int vertex;
    struct node *next;
}nnode;
typedef struct
{
    int data;
    pointer first;
}headtype;
typedef struct
{
    headtype adlist[NMAX];
        int n,e;
}ikgraph;

void CreatGraph(ikgraph *ga)
{
    int i,j,e,k;
        pointer p;
        printf("Input vertex no.:\n");
        fflush(stdin);
        scanf("%d",&(ga->n));
        for(i=0;i<ga->n;i++)
        {
            fflush(stdin);/*integrant*/
            printf("input data:\n");
            scanf("%d",&(ga->adlist[i].data));
            ga->adlist[i].first=NULL;
                ga->adlist[ga->n].data='\0';
        }
        e=0;
        printf("input vertex with edges:\n");
        scanf("%d,%d\n",&i,&j);
        while(i>0)
        {
            e++;
            p=(pointer)malloc(sizeof(struct node));
            p->vertex=j;
            p->next=ga->adlist[i-65].first;
            ga->adlist[i-65].first=p;
                p=(pointer)malloc(sizeof(struct node));
            p->vertex=i;
                p->next=ga->adlist[j-65].first;
            ga->adlist[j-65].first=p;
            scanf("%d,%d\n",&i,&j);
        }
        ga->e=e;
}
void ShowAdjList(ikgraph *ga)
{
    struct node *p;
        int i;
        for(i=0;i<(ga->n);i++)
        {
                printf("%c",(char)(ga->adlist[i].data));
                p=ga->adlist[i].first;
                do
                {
                        printf("-->%c",(char)(p->vertex));
                        p=p->next;
                }while(p!=NULL);
                printf("\n\n");
        }
}
/*directed graph should be seperated from this program.*/
/*void Creat_Graph(ikgraph *ga)
{
    int i,j,e,k;
    pointer p;
    printf("Input vertex no.:\n");
    scanf("%d",&(ga->n));
    for(i=0;i<ga->n;i++)
    {
            scanf("%c",&(ga->adlist[i].data));
            ga->adlist[i].first=NULL;
    }
        e=0;
        scanf("%d,%d\n",&i,&j);
        while(i>0)
        {
           e++;
           p=(pointer)malloc(sizeof(struct node));
           p->vertex=ga->adlist[i].first;
           ga->adlist[i].first=p;
           scanf("%d,%d",&i,&j);
        }
        ga->e=e;
}*/
main()
{
    ikgraph *ga;
        clrscr();
        CreatGraph(ga);
        ShowAdjList(ga);
        getch();
}

/*this function use insert from head即头插法*/
/*void CreatGraph(ikgraph *ga)
{
    int i,j,e,k;
        pointer p;
        printf("Input vertex no.:\n");
        fflush(stdin);
        scanf("%d",&(ga->n));
        for(i=0;i<ga->n;i++)
        {
            fflush(stdin);/*integrant*/
            printf("input data:\n");
            scanf("%d",&(ga->adlist[i].data));
            ga->adlist[i].first=NULL;
                ga->adlist[ga->n].data='\0';
        }
        e=0;
        printf("input vertex with edges:\n");
        scanf("%d,%d\n",&i,&j);
        while(i>0)
        {
            /*这里的i,j既表示info又表示顺序*/
                /*输入大写字母的ASCII码还要减去65*/
                e++;
            p=(pointer)malloc(sizeof(struct node));
            p->vertex=j;
            p->next=ga->adlist[i-65].first;                     /*input capital*/
            ga->adlist[i-65].first=p;
                p=(pointer)malloc(sizeof(struct node));
            p->vertex=i;
                p->next=ga->adlist[j-65].first;
            ga->adlist[j-65].first=p;
            scanf("%d,%d\n",&i,&j);
        }
        ga->e=e;
}*/

/*directed graph should be seperated from this program.*/
/*void Creat_Graph(ikgraph *ga)
{
    int i,j,e,k;
    pointer p;
    printf("Input vertex no.:\n");
    scanf("%d",&(ga->n));
    for(i=0;i<ga->n;i++)
    {
            scanf("%c",&(ga->adlist[i].data));
            ga->adlist[i].first=NULL;
    }
        e=0;
        scanf("%d,%d\n",&i,&j);
        while(i>0)
        {
           e++;
           p=(pointer)malloc(sizeof(struct node));
           p->vertex=ga->adlist[i].first;
           ga->adlist[i].first=p;
           scanf("%d,%d",&i,&j);
        }
        ga->e=e;
}*/