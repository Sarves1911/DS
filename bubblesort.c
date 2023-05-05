#include<stdio.h>
struct student{
    int roll_no;
    char name[100];
};

int main()
{

    int size;
    int swaps=0;
    printf("Enter Number of students \n");
    scanf("%d",&size);
    struct student students[size];
    printf("Enter Details Of Each student \n");

    for (int i = 0; i < size; i++)
    {
        printf("Name :\n");
        scanf("%s",& students[i].name);
        printf("Roll Number :\n");
        scanf("%d",& students[i].roll_no);
    }

    for (int i = 0; i < size -1; i++)
    {
        for(int j=0;j<size -i -1;j++){

            if (students[j].roll_no > students[j+1].roll_no)
        {
            int temp = students[j].roll_no;
            students[j].roll_no= students[j+1].roll_no;
            students[j+1].roll_no=temp;
            swaps++;

        }
        }
       }
    
    printf("\nDetails of all students:\n");
    for (int i = 0; i < size; i++)
    {        
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].roll_no);
    }
    printf("Number of swaps performed %d ",swaps);
    return 0;
}
