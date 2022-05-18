#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;

};


typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head,int iNo)
{
    PNODE newn =NULL;

    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=iNo;
    newn->next=NULL;


    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
        newn->next=*Head;
        *Head=newn;
    }
}



void InsertLast(PPNODE Head,int iNo)
{
    PNODE newn=NULL;
    PNODE Temp=NULL;

    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=iNo;
    newn->next=NULL;

    if (*Head==NULL)
    {
       *Head=newn;
    }
    else
    {
        Temp=*Head;

        while (Temp->next!=NULL)
        {
           Temp=Temp->next;
        }
        Temp->next=newn;
        
    }
}
void DeleteFirst(PPNODE Head)
{
    PNODE Temp=NULL;

    if (*Head==NULL)
    {
       return;
    }
    else if((*Head)->next==NULL)
    {
        free(*Head);
        *Head=NULL;
    }
    else
    {
        Temp=*Head;
        *Head=Temp->next;
        free(Temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE Temp=NULL;

    if (*Head==NULL)
    {
       return;
    }
    else if((*Head)->next==NULL)
    {
        free(*Head);
        *Head=NULL;
    }
    else
    {
        Temp=*Head;
        while (Temp->next->next!=NULL)
        {
           Temp=Temp->next;
        }
        free(Temp->next);
        Temp->next=NULL;
    }
}

void Display(PNODE Head)
{
    printf("Linked List Are: \n");
    while (Head!=NULL)
    {
        printf("| %d |->",Head->data);
        Head=Head->next;

    }
    printf("NULL \n");
}

int  Count(PNODE Head)
{
    int iCount=0;
    printf("Linked List Count Are: \n");
    while (Head!=NULL)
    {
        iCount++;
        Head=Head->next;

    }
    return iCount;
}

void InsertAtPos(PPNODE Head,int iNo,int iPos)
{
    PNODE newn=NULL;
    PNODE Temp=NULL;

    int iSize=0,iCnt=0;

    iSize=Count(*Head);

    if (iPos==1)
    {
        InsertFirst(Head,iNo);
    }
    else if ((iPos<1) || (iPos>(iSize+1)))
    {
        return;
    }
    else if (iPos==(iSize+1))
    {
        InsertLast(Head,iNo);
    } 
    else
    {
        newn=(PNODE)malloc(sizeof(NODE));//allocate 12 byte memory to newn
        //initialize 
        newn->data=iNo;
        newn->next=NULL;

        Temp=*Head;
        for (iCnt=1;iCnt<(iPos-1);iCnt++)
        {
            Temp=Temp->next;
        }
        newn->next=Temp->next;
        Temp->next=newn;
        
    } 
}

void DeleteAtPos(PPNODE Head,int iPos)
{
    PNODE Temp=NULL;
    PNODE TempDel=NULL;

    int iSize=0,iCnt=0;

    iSize=Count(*Head);

    if (iPos==1)
    {
        DeleteFirst(Head);
    }
    else if ((iPos<1) || (iPos>iSize))
    {
        return;
    }
    else if (iPos==iSize)
    {
        DeleteLast(Head);
    } 
    else
    {
        Temp=*Head;
        for (iCnt=1;iCnt<(iPos-1);iCnt++)
        {
            Temp=Temp->next;
        }
        TempDel=Temp->next;
        Temp->next=Temp->next->next;
        free(TempDel);        
    } 
}



int main()
{
    PNODE  First=NULL;
    int iRet=0;


    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertLast(&First,21);

    InsertAtPos(&First,23,2);
    Display(First);
    iRet=Count(First);
    printf("%d",iRet);

    DeleteAtPos(&First,1);
    Display(First);
    iRet=Count(First);
    printf("After DeleteAtPos %d",iRet);

    

    DeleteLast(&First);
    Display(First);
    iRet=Count(First);
    printf("%d",iRet);


    DeleteFirst(&First);
    Display(First);
    iRet=Count(First);
    printf("%d",iRet);


    

    return 0;
}