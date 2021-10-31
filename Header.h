#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct Employee
{
	int EmpId;
	int Age;
	char Name[50];
	float Salary;
	char cGender[50];
	char cCity[50];
	char cDesignation[50];

	struct Employee *Next;
	struct Employee *Prev;
};

typedef struct Employee Employee;
typedef struct Employee* PEmployee;
typedef struct Employee** PPEmployee;

void InsertFirst(PPEmployee, PPEmployee, int, char*, int, float, char*, char*, char*);

void InsertLast(PPEmployee, PPEmployee, int, char*, int, float, char*, char*, char*);

void Display(PEmployee, PEmployee);

int Count(PEmployee, PEmployee);

void DeleteFirst(PPEmployee, PPEmployee);

void DeleteLast(PPEmployee, PPEmployee);

void InsertAtPosition(PPEmployee, PPEmployee, int, char*, int, float, char*, char*, char*, int);

void DeleteAtPostion(PPEmployee, PPEmployee, int);

void SearchBySalary(PEmployee, PEmployee, float);

void SearchGrtSalary(PEmployee ,PEmployee ,float);

void SearchLesSalary(PEmployee, PEmployee, float);

void SearchEqaSalary(PEmployee, PEmployee, float);

void SearchByID(PEmployee, PEmployee, int);

float MinimumSalary(PEmployee, PEmployee);

float MaximumSalary(PEmployee, PEmployee);

int MinimumAge(PEmployee, PEmployee);

int MaximumAge(PEmployee, PEmployee);

BOOL Like(PEmployee, PEmployee, char);

BOOL Like1(PEmployee, PEmployee, char);

void SearchByAge(PEmployee, PEmployee, int);

void SearchByName(PEmployee, PEmployee, char*);

void SearchByCity(PEmployee, PEmployee, char*);

void SearchByDesignation(PEmployee, PEmployee, char*);

void SearchByGender(PEmployee, PEmployee, char*);

