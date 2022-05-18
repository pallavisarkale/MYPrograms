//Accept Number from user and check Wheather it Armstrong or not

#include<stdio.h>
#include<stdbool.h>

bool CheckArmstrong(int iNo)
{
    register int iCnt=0;
    int iDigit=0;
    int iDigCount=0;
    int iMult=1;
    int iTemp=0;
    int iSum=0;

    iTemp=iNo;//Copy of number

    while(iNo>0)
    {
        iDigit=iNo%10;
        iDigCount++;
        iNo=iNo/10;

    }
//after while iNo becomes 0
    iNo=iTemp;//restore iNo

    while (iNo>0)//153
    {
        iMult=1;
        iDigit=iNo%10;//3  5   1

        for (iCnt=1;iCnt<=iDigCount;iCnt++)//1  2   3 
        {
           iMult=iMult*iDigit; //1*3=3 3*3=9 9*3=27 for Digit 3
                              //1*5=5 5*5=25 25*5=125 for digit 5
                            //1*1=1 1*1=1 1*1=1  for Digit 1

           //printf("%d\n",iMult); for understand how to print multiplication
        }
        iSum=iSum+iMult;//0+27=27 
        iNo=iNo/10;
        
    }
    if (iSum==iTemp)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main()
{
     int iValue=0;
     int bRet=false;

    printf("Enter number you want to check Palindrome or not:");
    scanf("%d",&iValue);

    bRet=CheckArmstrong(iValue);
    if (bRet==true)
    {
        printf("%d is Palindrome number",iValue);
    }
    else
    {

        printf("%d is Not Palindrome number",iValue);
    }


    return 0;
}