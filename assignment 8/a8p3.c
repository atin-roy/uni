#include <stdio.h>

struct Student {
  char name[50];
  int age;
  float totalMarks;
};

int main() {
  struct Student students[5];

  float totalMarksSum = 0;

  for (int i = 0; i < 5; i++) {
    printf("Enter details for student %d:\n", i + 1);
    printf("Name: ");
    scanf("%s", students[i].name);
    printf("Age: ");
    scanf("%d", &students[i].age);
    printf("Total Marks: ");
    scanf("%f", &students[i].totalMarks);

    totalMarksSum += students[i].totalMarks;
  }

  printf("\nInformation of the students:\n");
  for (int i = 0; i < 5; i++) {
    printf("Student %d:\n", i + 1);
    printf("Name: %s\n", students[i].name);
    printf("Age: %d\n", students[i].age);
    printf("Total Marks: %.2f\n", students[i].totalMarks);
    printf("\n");
  }

  float averageTotalMarks = totalMarksSum / 5;

  printf("Average of total marks: %.2f\n", averageTotalMarks);

  return 0;
}
