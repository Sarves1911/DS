#include<stdio.h>
#include<stdlib.h>

struct student{
    int rollno;
    char name[20];
};

void insertionsort(struct student toppers[],int size){
    struct student temp;
    int i, j;

    for (i = 1; i < size; i++)
    {
        temp = toppers[i];
        j = i - 1;

        while (j >= 0 && toppers[j].rollno > temp.rollno)
        {
            toppers[j + 1] = toppers[j];
            j--;
        }

        toppers[j + 1] = temp;
    }
}


int main(){
    int size=5;
    struct student toppers[size];

    for (int i = 0; i < 5; i++)
    {
        printf("Enter The Name \n");
        scanf("%s",toppers[i].name);
        printf("Enter Roll Number \n");
        scanf("%d",&toppers[i].rollno);
    }
    
    insertionsort(toppers,size);

    printf("Sorted List : \n");

    for (int i = 0; i < size; i++)
    {
       printf("%s %d\n", toppers[i].name, toppers[i].rollno);

    }
    
    return 0;
}
