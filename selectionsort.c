#include<stdio.h>

struct student{
    int rollno;
    char name[100];
};

void selectionsort(struct student students[],int size){

int imin;
    for (int i = 0; i < size-1; i++)
    {
        imin=i;
        for (int j = i+1; j < size -1; j++)
        {
            if (students[imin].rollno>students[j].rollno)
            {
                imin=j;
            }

            
        }
        int temp= students[i].rollno;
        students[i].rollno=students[imin].rollno;
        students[imin].rollno=temp;

        
    }
    

}
int main(){

    int size;
    printf("Enter Size\n");
    scanf("%d",&size);
    struct student students[size];

    for (int i = 0; i < size; i++)
    {
        printf("Roll Number :\n");
        scanf("%d",&students[i].rollno);
        printf("Name :\n");
        scanf("%s",students[i].name);
    }


    selectionsort(students,size);

    for (int i = 0; i < size; i++)
    {
        printf("Roll No : %d \n",students[i].rollno);
        printf("Name : %s",students[i].name);

    }
    
    


    return 0;
}