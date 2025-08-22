#include<stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("no_such_file.txt", "r");
    if (fp == NULL) 
    {
        perror("打开文件时出错");
        return EXIT_FAILURE;//也可以写成-1或其他非0的数字
    }
    return 0;
}