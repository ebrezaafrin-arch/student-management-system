#include <stdio.h>

int main() {
    int id;
    char name[50];
    float cgpa;

    printf("Enter student ID: ");
    scanf("%d", &id);

    printf("Enter student Name: ");
    scanf("%49s", name);

    printf("Enter CGPA: ");
    scanf("%f", &cgpa);

    printf("\n--- Student Information ---\n");
    printf("ID: %d\n", id);
    printf("Name: %s\n", name);
    printf("CGPA: %.2f\n", cgpa);

    return 0;
}
