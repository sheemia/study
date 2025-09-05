#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE* fp=fopen("output.txt","a");
    if(fp==NULL)
    {
        perror("Failed to access the fail!");
        return EXIT_FAILURE;
    }
    char ch[]="boge";
    fputs(ch,fp);
    fclose(fp);
    return 0;
}