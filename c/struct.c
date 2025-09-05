#include<stdio.h>

struct Person
{
    char name[10];
    int age;
    float height;
};

int main()
{
    struct Person person1={"zhangsan",20,169.99};
    printf("Name:%s\n",person1.name);
    printf("Age:%d\n",person1.age);
    printf("Height:%.2f\n",person1.height);
    person1.age=31;
    printf("Age:%d\n",person1.age);
    return 0;
}
