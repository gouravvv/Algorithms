#include<stdio.h>
#include<stdlib.h>
static long int m;
static int count=0;

struct Stack
{
int data;
struct Stack *next;    
}*top=NULL;
typedef struct Stack stack;

int isEmpty()
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}
int isFull()
{
    if(count==m){
        
    return 1;}
    return 0;
}
void push(int data)
{
    stack *temp;
    temp=(stack*)malloc(sizeof(stack));
    temp->data=data;
    if(isFull())
    {
        printf("Stack Overflow\n");
        return -1;
    }
    if(top==NULL)
    {
        top=temp;
        temp->next=NULL;
        count++;
    }
    else
    {
        temp->next=top;
        top=temp;
        count++;
    }
}
int peek()
{
    if(isEmpty())
    return -1;
    return top->data;
}
int pop()
{
    int temp;
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else{
    temp=top->data;
    top=top->next;
    return temp;}
}

void display()
{
    stack *p;
    p=top;
    if(top==NULL)
    {
        printf("Empty Stack\n");
        return;
    }
    
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{

    scanf("%ld",&m);
    while(1)
    {
        int n,x;
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                
                scanf("%d",&x);
                push(x);
                break;
            case 3:
                display();
                break; 
            case 2:
                x=pop();
                if(x==-1)
                {
                   // printf("nothing");
                }
                else
                printf("%d\n",x);
                break;
            case 4:
                exit(0);
                break;
        }
    }
}
