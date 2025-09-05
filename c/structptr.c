#include<stdio.h>

struct Person
{
    char name[10];
    int age;
    float height;
};

int main()
{
    struct Person person1={"zhangsan",21,169.99};
    struct Person *personptr1=&person1;
    printf("Name:%s",personptr1->name);
    printf("Age:%d",personptr1->age);
    printf("Height:%.2f",personptr1->height);
    personptr1->age=31;
    printf("Age:%d",personptr1->age);
    return 0;
}