#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name;
    int size,start;
}continuous;

struct node
{
    int data;
    struct node* next;
};

typedef struct
{
    char name;
    int size;
    struct node *start;
    struct node *end;
}linked;

typedef struct
{
    int* addr;
    char name;
    int size;
}index;


int main()
{
    int i,j,total_size=0,lim=0,ds,temp,query,choice,ask;char ch;
    printf("Hello world!\n");

    printf("input the number of data segments:\n");
    scanf("%d",&ds);
    printf("input 1 for continuous allocation 2 for linked allocation 3 for indexed allocation:\n");
    scanf("%d",&ask);
    if(ask==1)
    {
    continuous *cont;
    cont=(continuous*)malloc(sizeof(continuous)*ds);
    for(i=0;i<ds;i++)
    {
        printf("enter the name of data segment %d:\n",i);
        scanf(" %c",&ch);
        (cont+i)->name=ch;
        printf("enter the number of blocks in data segment\n");
        scanf("%d",&(cont+i)->size);
        total_size+=(cont+i)->size;

    }
    int *c;
    c=(int*)malloc(sizeof(int)*total_size);
    int count=0;
    for(i=0;i<ds;i++)
    {
        (cont+i)->start=lim;
        j=lim;
        lim=lim+(cont+i)->size;
        for(;j<lim;j++)
        {
            printf("enter the data in block %d in data segment %d:\n",j,i);
            scanf("%d",&temp);
            *(c+count)=temp;
            count++;
        }

    }

    printf("continuous allocation table:\n");
    printf("Name\tSize\tStart\n");
    for(i=0;i<ds;i++)
    {
        printf("%c\t%d\t%d\n",(cont+i)->name,(cont+i)->size,(cont+i)->start);
    }
    printf("enter 0 to end or 1 to make query:\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 0:
        return 0;
    case 1:
        printf("enter the name of data which you want to search:\n");
        scanf("%d",&query);
        for(i=0;i<total_size;i++)
        {
            if(*(c+i)==query)
            {
                printf("found\n");
                for(j=0;j<ds;j++)
                {
                    if(i>=(cont+j)->start && i<((cont+j)->start + (cont->size)))
                        printf("data is present in data segment %c\n",(cont+j)->name);
                }
            }

        }
    }
    }


    if(ask==2)
    {
        linked *li;
        struct node *new_node;
        struct node *prev;
        struct node *search;
        li=(linked*)(malloc(sizeof(linked)*ds));
        for(i=0;i<ds;i++)
        {
            printf("enter the name of data segment %d:\n",i);
            scanf(" %c",&ch);
            (li+i)->name=ch;
            printf("enter the number of blocks in data segment\n");
            scanf("%d",&(li+i)->size);
            total_size+=(li+i)->size;
            for(j=0;j<(li+i)->size;j++)
            {
                new_node=(struct node*)malloc(sizeof(struct node));
                if(j==0)
                    (li+i)->start=new_node;
                if(j==(li+i)->size-1)
                    (li+i)->end=new_node;
                printf("enter the valuve in block %d in data segment %d:\n",j,i);
                scanf("%d",&(new_node->data));
                if(j!=0)
                prev->next=new_node;
                prev=new_node;
            }


        }
        printf("File\tStart\t\tEnd\n");
        for(i=0;i<ds;i++)
        {
            printf("%c\t%p\t%p\n",(li+i)->name,(li+i)->start,(li+i)->end);
        }

        printf("enter 0 to end or 1 to make query:\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            return 0;
        case 1:
            printf("enter the name of data which you want to search:\n");
            scanf("%d",&query);
            for(i=0;i<ds;i++)
            {
                search=(li+i)->start;
                for(j=0;j<(li+i)->size;j++)
                {

                    if(search->data==query)
                    {
                        printf("found\n");
                        printf("data is present in data segment %c\n",(li+i)->name);
                    }
                    search=search->next;
                }
            }
        }
    }


    if(ask==3)
    {
        index *ind;
        ind=(index*)malloc(sizeof(index)*ds);
        for(i=0;i<ds;i++)
        {
            printf("enter name of data segment %d:\n",i);
            scanf(" %c",&(ind+i)->name);
            printf("enter the number of blocks in data segment %d:\n",i);
            scanf("%d",&(ind+i)->size);
            (ind+i)->addr=(int*)malloc(sizeof(int)*(ind+i)->size);
            for(j=0;j<(ind+i)->size;j++)
            {
                printf("enter the block no %d:\n",j);
                scanf("%d",&temp);
                ((ind+i)->addr)[j]=temp;
            }
        }
        printf("File\tIndex\n");
        for(i=0;i<ds;i++)
        {
            printf("%c\t%p\n",(ind+i)->name,(ind+i)->addr);
        }
        printf("enter 0 to end or 1 to make query:\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            return 0;
        case 1:
            printf("enter the name of data which you want to search:\n");
            scanf("%d",&query);
            for(i=0;i<ds;i++)
            {
                for(j=0;j<(ind+i)->size;j++)
                {
                    if(query==((ind+i)->addr)[j])
                    {
                        printf("Query found in data segment %c\n",(ind+i)->name);
                    }
                }
            }
        }
    }
    return 0;
}
