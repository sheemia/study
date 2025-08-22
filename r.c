#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE* fp=fopen("./input.txt","r");
    if(fp==NULL)
    {
        perror("Failed to access the file!");
        return EXIT_FAILURE;
    }
    char ch=fgetc(fp);
    while(ch!=EOF)
    {
        printf("%c",ch);
        ch=fgetc(fp);
    }
    fclose(fp);
    return 0;
}