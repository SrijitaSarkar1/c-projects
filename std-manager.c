#include <stdio.h>

struct Student {
    int roll;
    char name[50];

    float physics;
    float mathematics;
    float programming;

    float average;
    char grade;
};

float calcAvg(float physics, float mathematics, float programming)
{
    return (physics + mathematics + programming) / 3;
}

char calcGrade(float average)
{
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}

int main()
{
    struct Student students[200];

    int count = 0;
    int choice;

    while (1)
    {
        printf("\n===== STUDENT GRADE MANAGER =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Find Top Student\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                if (count >= 200)
                {
                    printf("Student limit reached!\n");
                    break;
                }

                printf("\nEnter roll number: ");
                scanf("%d", &students[count].roll);

                printf("Enter name: ");
                scanf("%49s", students[count].name);

                printf("Enter Physics marks: ");
                scanf("%f", &students[count].physics);

                printf("Enter Mathematics marks: ");
                scanf("%f", &students[count].mathematics);

                printf("Enter Programming marks: ");
                scanf("%f", &students[count].programming);

                students[count].average =
                    calcAvg(
                        students[count].physics,
                        students[count].mathematics,
                        students[count].programming
                    );

                students[count].grade =
                    calcGrade(students[count].average);

                count++;

                printf("Student added successfully!\n");

                break;

            case 2:

                if (count == 0)
                {
                    printf("No students available.\n");
                    break;
                }

                for (int i = 0; i < count; i++)
                {
                    printf("\n-------------------------\n");
                    printf("Roll: %d\n", students[i].roll);
                    printf("Name: %s\n", students[i].name);
                    printf("Physics: %.2f\n", students[i].physics);
                    printf("Mathematics: %.2f\n", students[i].mathematics);
                    printf("Programming: %.2f\n", students[i].programming);
                    printf("Average: %.2f\n", students[i].average);
                    printf("Grade: %c\n", students[i].grade);
                }

                break;

            case 3:

                if (count == 0)
                {
                    printf("No students available.\n");
                    break;
                }

                int top = 0;

                for (int i = 1; i < count; i++)
                {
                    if (students[i].average >
                        students[top].average)
                    {
                        top = i;
                    }
                }

                printf("\n===== TOP STUDENT =====\n");
                printf("Name: %s\n", students[top].name);
                printf("Roll: %d\n", students[top].roll);
                printf("Average: %.2f\n", students[top].average);
                printf("Grade: %c\n", students[top].grade);

                break;

            case 4:

                printf("Exiting program...\n");
                return 0;

            default:

                printf("Invalid choice!\n");
        }
    }

    return 0;
}

