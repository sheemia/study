#include<stdio.h>

int main()
{
   int score = 0;
   char grade;
   printf("Please enter the score: ");
   scanf("%d",&score);
   switch(score / 10)
   {
        case 10:
        case 9:
            grade =  'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'E';
            break;
    }
    printf("The grade is %c\n", grade);
   return 0; 
}