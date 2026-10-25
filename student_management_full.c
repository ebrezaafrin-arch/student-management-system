#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    float cgpa;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter CGPA: ");
    scanf("%f", &students[count].cgpa);

    count++;

    printf("\nStudent added successfully!\n");
}

void viewStudents() {
    if (count == 0) {
        printf("\nNo student found!\n");
        return;
    }

    printf("\n--- Student List ---\n");

    for (int i = 0; i < count; i++) {
        printf("\nID: %d", students[i].id);
        printf("\nName: %s", students[i].name);
        printf("\nCGPA: %.2f\n", students[i].cgpa);
    }
}

void searchStudent() {
    int id;
    int found = 0;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("CGPA: %.2f\n", students[i].cgpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
}

void deleteStudent() {
    int id;
    int found = 0;

    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {

            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;
            found = 1;

            printf("\nStudent deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n==============================");
        printf("\n   STUDENT MANAGEMENT SYSTEM");
        printf("\n==============================");
        printf("\n1. Add Student");
        printf("\n2. View Students");
        printf("\n3. Search Student");
        printf("\n4. Delete Student");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                printf("\nThank you!\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
