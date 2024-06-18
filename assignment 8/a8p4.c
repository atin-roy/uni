#include <stdio.h>

struct Address {
  char street[50];
  char city[50];
  char state[50];
};

struct Employee {
  int emp_id;
  char name[50];
  char designation[50];
  struct Address address;
  float basic_salary;
  float da;
  float hra;
  float gross_salary;
};

int main() {
  struct Employee employees[3];

  for (int i = 0; i < 3; i++) {
    printf("Enter details for employee %d:\n", i + 1);
    printf("Employee ID: ");
    scanf("%d", &employees[i].emp_id);
    printf("Name: ");
    scanf("%s", employees[i].name);
    printf("Designation: ");
    scanf("%s", employees[i].designation);
    printf("Address:\n");
    printf("Street: ");
    scanf("%s", employees[i].address.street);
    printf("City: ");
    scanf("%s", employees[i].address.city);
    printf("State: ");
    scanf("%s", employees[i].address.state);
    printf("Basic Salary: ");
    scanf("%f", &employees[i].basic_salary);
    printf("DA: ");
    scanf("%f", &employees[i].da);
    printf("HRA: ");
    scanf("%f", &employees[i].hra);

    employees[i].gross_salary =
        employees[i].basic_salary + employees[i].da + employees[i].hra;
  }

  printf("\nDetails of the employees and their gross salary:\n");
  for (int i = 0; i < 3; i++) {
    printf("Employee %d:\n", i + 1);
    printf("Employee ID: %d\n", employees[i].emp_id);
    printf("Name: %s\n", employees[i].name);
    printf("Designation: %s\n", employees[i].designation);
    printf("Address:\n");
    printf("Street: %s\n", employees[i].address.street);
    printf("City: %s\n", employees[i].address.city);
    printf("State: %s\n", employees[i].address.state);
    printf("Basic Salary: %.2f\n", employees[i].basic_salary);
    printf("DA: %.2f\n", employees[i].da);
    printf("HRA: %.2f\n", employees[i].hra);
    printf("Gross Salary: %.2f\n", employees[i].gross_salary);
    printf("\n");
  }

  return 0;
}
