#include <stdio.h>

struct Student {
  char name[50];
  int rollNumber;
  float marks;
};

void displayStudent(struct Student s) {
  printf("Name: %s\n", s.name);
  printf("Roll Number: %d\n", s.rollNumber);
  printf("Marks: %.2f\n", s.marks);
}

int main() {
  struct Student students[3];

  for (int i = 0; i < 3; i++) {
    printf("Enter details for student %d:\n", i + 1);
    printf("Name: ");
    scanf("%s", students[i].name);
    printf("Roll Number: ");
    scanf("%d", &students[i].rollNumber);
    printf("Marks: ");
    scanf("%f", &students[i].marks);
  }

  printf("\nDetails of the students:\n");
  for (int i = 0; i < 3; i++) {
    printf("Student %d:\n", i + 1);
    displayStudent(students[i]);
    printf("\n");
  }

  return 0;
}
