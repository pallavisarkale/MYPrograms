//Accept N number from user and Return difference bet summation of even elements and odd elements

#include<stdio.h>
#include<stdlib.h>
int DiffBetEvenOdd(int Arr[],int iLength)
{
    int iCnt=0;
    int iSumEven=0,iSumOdd=0;

    for (iCnt=0;iCnt<iLength;iCnt++)
    {
        if ((Arr[iCnt]%2)==0)
        {
            iSumEven=iSumEven+Arr[iCnt];
        }
        else
        {
            iSumOdd=iSumOdd+Arr[iCnt];
        }
        
    }
    if (iSumEven>iSumOdd)
    {
        return iSumEven-iSumOdd;
    }
    else
    {
        return iSumOdd-iSumEven;
    }
    
    
    
}
int main()
{
    int *ptr=NULL;
    int iCnt=0;
    int iSize=0;
    int iRet=0;


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

    iRet=DiffBetEvenOdd(ptr,iSize);
    printf("Difference is: %d",iRet);

        free(ptr);


return 0;

}
