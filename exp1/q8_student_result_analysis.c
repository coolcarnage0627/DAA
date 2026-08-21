#include <stdio.h>

struct Student {
    int roll;
    char name[30];
    float marks[5];
    float total;
    float percentage;
    char grade;
};

int main(void) {
    int n, i, j, topper = 0;
    float classTotal = 0.0, classAverage;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter roll number: ");
        scanf("%d", &s[i].roll);
        printf("Enter name: ");
        scanf("%s", s[i].name);

        s[i].total = 0.0;
        printf("Enter marks in 5 subjects: ");
        for (j = 0; j < 5; j++) {
            scanf("%f", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = (s[i].total / 500.0) * 100.0;
        classTotal += s[i].percentage;

        if (s[i].percentage > s[topper].percentage) {
            topper = i;
        }

        if (s[i].percentage >= 90) s[i].grade = 'A';
        else if (s[i].percentage >= 80) s[i].grade = 'B';
        else if (s[i].percentage >= 70) s[i].grade = 'C';
        else if (s[i].percentage >= 60) s[i].grade = 'D';
        else if (s[i].percentage >= 40) s[i].grade = 'E';
        else s[i].grade = 'F';
    }

    classAverage = classTotal / n;

    printf("\nClass Topper: Roll %d, Name %s, Percentage %.2f, Grade %c\n",
           s[topper].roll, s[topper].name, s[topper].percentage, s[topper].grade);
    printf("Class Average: %.2f\n", classAverage);

    printf("Students who failed in one or more subjects:\n");
    int failed = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 5; j++) {
            if (s[i].marks[j] < 40.0) {
                printf("Roll %d, Name %s\n", s[i].roll, s[i].name);
                failed = 1;
                break;
            }
        }
    }
    if (!failed) {
        printf("None\n");
    }

    return 0;
}
