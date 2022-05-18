//Accept N number from user and Return elements which divisible by 5

#include<stdio.h>
#include<stdlib.h>
void Display(int Arr[],int iLength)
{
    int iCnt=0;

    for (iCnt=0;iCnt<iLength;iCnt++)
    {
        if ((Arr[iCnt]%5)==0)
        {
            printf("%d\n",Arr[iCnt]);
        }
        
    }
}
int main()
{
    int *ptr=NULL;
    int iCnt=0;
    int iSize=0;


    printf("Enter How Many Elements : \t");
    scanf("%d",&iSize);

    ptr=(int *)malloc(iSize* sizeof(int));

    if (ptr==NULL)
    {
        printf("Unable to allocate memory: ");
        return -1;
    }
    
    printf("Enter the Elements :\n");

    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }

    printf("Elements which Divisible by 5 is:\n");
    Display(ptr,iSize);

    free(ptr);

return 0;
}
