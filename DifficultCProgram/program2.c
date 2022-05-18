//Accept N from user and print the summation of even number in thatr array

#include<stdio.h>
#include<stdlib.h>

void Display(int Arr[],int iLength)
{
    int iCnt=0;
    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        printf("%d\n",Arr[iCnt]);
    }
}

int main()
{
    int *ptr=NULL;
    int iSize=0;
    int iCnt=0;

    printf("Enter How many Numbers:  ");
    scanf("%d",&iSize);


    printf("Enter Elemnts in Array:\n");

    ptr=(int *) malloc(iSize*sizeof(int));

    for (iCnt=0;iCnt<iSize;iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }

    Display(ptr,iSize);
    
    return 0;
}