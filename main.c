#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
} list;

void creatlist(list *l,int c)
{
    while(c--)
    {
        scanf("%d",&(l->data));
        if(c!=0)
        {
            l->next=(list *)malloc(sizeof(list));
            l=l->next;
        }
        else
        {
            l->next=NULL;
        }
    }
}

void inlist(list *l,int num,int loc)
{
    list *newlist=(list *)malloc(sizeof(list));
    newlist->data=num;
    if(loc==1)
    {
        newlist->next=l;
    }
    else
    {
        while(--loc-1)
        {
            l=l->next;
        }

        newlist->next=l->next;
        l->next=newlist;
    }
}
list *  dellist(list *l,int loc)
{
    list *q=l,*p=l->next;

    if(loc==1)
    {
        return l=l->next;
    }
    else
    {
        while(loc--)
        {
            if(loc-1==0)
            {
                q->next=p->next;
                free(p);
                break;
            }
            q=q->next;
            p=p->next;
        }
        return l;
    }


}
int lenlist(list *l)
{
    int count=0;
    while(l)
    {
        count++;
        l=l->next;
    }
    return count;
}

void find(list *l,int loc)
{
    int post=loc;
    while(loc--)
    {
        if(loc==0)
            printf("单链表第%d个位置的元素数为:%d\n",post,l->data);
        l=l->next;
    }
}

void print(list *l)
{
    while(l->next)
    {
        printf("%d ",l->data);
        l=l->next;
    }
    printf("%d\n",l->data);
}

int main()
{
    list *head=(list *)malloc(sizeof(list));
    int c,num,loc;
    scanf("%d",&c);
    creatlist(head,c);
    printf("单链表为:");
    print(head);
    printf("单链表的长度为:%d\n",lenlist(head));
    scanf("%d",&loc);
    find(head,loc);
    scanf("%d%d",&loc,&num);
    inlist(head,num,loc);
    printf("插入数据后的单链表为:");
    print(head);
    scanf("%d",&loc);
    head=dellist(head,loc);
    printf("删除数据后的单链表为:");
    print(head);
}

