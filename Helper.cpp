#include "Header.h"

void InsertFirst(PPEmployee Head,PPEmployee Tail,int id,char *iName,int iAge,float iSalary,char *cGen,char *cCty,char *cDesg)
{
	PEmployee newn = NULL;
	int i = 0, j = 0, k = 0, l = 0;
	
	newn = (PEmployee)malloc(sizeof(Employee));
	newn->EmpId = id;

	while((*iName) != '\0')	
	{
		(newn->Name[i]) = (*iName);
		iName++;
		i++;
	}
	newn->Name[i] = '\0';
	//*iName = '\0'; //wrong

	newn->Age = iAge;
	newn->Salary = iSalary;

	while((*cGen) != '\0')
	{
		(newn->cGender[j]) = (*cGen);
		cGen++;
		j++;
	}
	newn->cGender[j] = '\0';

	while((*cCty) != '\0')
	{
		(newn->cCity[k]) = (*cCty);
		cCty++;
		k++;
	}
	newn->cCity[k] = '\0';

	while((*cDesg) != '\0')
	{	
		(newn->cDesignation[l]) = (*cDesg);
		cDesg++;
		l++;
	}
	newn->cDesignation[l] = '\0';

	newn->Next = NULL;
	newn->Prev = NULL;

	if((*Head == NULL) &&(*Tail == NULL))	//Linked List is Empty
	{
		(*Head) = newn;
		(*Tail) = newn;
	}

	else	//Linked List contains one or more Employee
	{
		newn->Next = (*Head);
		(*Head)->Prev = newn;
		(*Head) = (*Head)->Prev;
	}

	((*Tail)->Next) = (*Head);
	((*Head)->Prev) = (*Tail);
}

void InsertLast(PPEmployee Head,PPEmployee Tail,int id,char *iName,int iAge,float iSalary,char *cGen,char *cCty,char *cDesg)
{
	PEmployee newn = NULL;
	int i = 0,j = 0,k = 0,l = 0;
	newn = (PEmployee)malloc(sizeof(Employee));
	newn->EmpId = id;
	
	while(*iName != '\0')
	{
		(newn->Name[i]) = (*iName);
		iName++;
		i++;
	}
	newn->Name[i] = '\0';

	newn->Age = iAge;
	newn->Salary = iSalary;

	while((*cGen) != '\0')
	{
		(newn->cGender[j]) = (*cGen);
		cGen++;
		j++;
	}
	newn->cGender[j] = '\0';

	while((*cCty) != '\0')
	{
		(newn->cCity[k]) = (*cCty);
		cCty++;
		k++;
	}
	newn->cCity[k] = '\0';

	while((*cDesg) != '\0')
	{	
		(newn->cDesignation[l]) = (*cDesg);
		cDesg++;
		l++;
	}
	newn->cDesignation[l] = '\0';

	newn->Next=NULL;
	newn->Prev=NULL;

	if((*Head == NULL)&&(*Tail == NULL))	//if Linked List is empty
	{
		*Head = newn;
		*Tail = newn;
	}
	else	//if Linked List contains atleast one Employee
	{
		(*Tail)->Next = newn;
		newn->Prev = (*Tail);
		(*Tail) = (*Tail)->Next;
	}
	(*Tail)->Next = (*Head);
	(*Head)->Prev = (*Tail);
}

void Display(PEmployee Head,PEmployee Tail)
{
	do
	{
		if(Head->Next == Tail->Next)	//if node is the last node
		{
			printf("\n|Employee id is : %d  \nEmployee Age is : %d \n Employee Salary is : %0.2f \n Employee Name is : %s \n Employee Gender is : %s \n Employee City is : %s \n Employee Designation is : %s|\n",Head->EmpId,Head->Age,Head->Salary,Head->Name,Head->cGender,Head->cCity,Head->cDesignation);
		}
		else
		{
			printf("\n|Employee id is : %d  \nEmployee Age is : %d \n Employee Salary is : %0.2f \n Employee Name is : %s \n Employee Gender is : %s \n Employee City is : %s \n Employee Designation is : %s|\n",Head->EmpId,Head->Age,Head->Salary,Head->Name,Head->cGender,Head->cCity,Head->cDesignation);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);
}

int Count(PEmployee Head,PEmployee Tail)
{
	int iCnt = 0;

	do
	{
		iCnt++;
		Head = Head->Next;
	}while(Head != Tail->Next);

	return iCnt;
}

void DeleteFirst(PPEmployee Head,PPEmployee Tail)
{
	if((*Head == NULL)&&(*Tail == NULL))
	{
		return;
	}
	else if(*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		(*Head) = (*Head)->Next;
		free((*Head)->Prev);
		((*Head)->Prev) = (*Tail);
		((*Tail)->Next) = (*Head);
	}
}

void DeleteLast(PPEmployee Head,PPEmployee Tail)
{
	if((*Head == NULL)&&(*Tail == NULL))
	{
		return;
	}
	else if(*Head == *Tail)
	{
		free(*Tail);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		(*Tail) = (*Tail)->Prev;
		free((*Tail)->Next);

		((*Head)->Prev) = (*Tail);
		((*Tail)->Next) = (*Head);
	}
}

void InsertAtPosition(PPEmployee Head,PPEmployee Tail,int id,char *iName,int iAge,float iSalary,char *cGen,char *cCty,char *cDesg,int iPos)
{
	PEmployee temp = NULL;
	PEmployee newn = NULL;
	PEmployee Head2 = NULL;
	PEmployee Tail2 = NULL;

	int iSize = 0,iCnt = 0;
	int i = 0,j = 0,k = 0,l = 0;

	iSize = Count(*Head,*Tail);	

	if((iPos < 0) || (iPos > (iSize+1)))
	{
		return;
	}
	else if(iPos == 1)
	{
		InsertFirst(Head,Tail,id,iName,iAge,iSalary,cGen,cCty,cDesg);
	}
	else if(iPos == (iSize+1))
	{
		InsertLast(Head,Tail,id,iName,iAge,iSalary,cGen,cCty,cDesg);
	}
	else
	{
		/*if(iPos < (iSize/2))
		{
			//InsertAtPosition from starting end
			//Maintain a pointer Head2
		}
		else if(iPos < (iSize/2))
		{
			//InsertAtPosition from Terminating end
			//Maintain a pointer Tail2
		}*/
		temp = *Head;
		newn = (PEmployee)malloc(sizeof(Employee));
		newn->EmpId = id;

		while(*iName != '\0')
		{
			(newn->Name[i]) = (*iName);
			iName++;
			i++;
		}
		newn->Name[i] = '\0';
		
		newn->Age = iAge;
		newn->Salary = iSalary;
		
		while((*cGen) != '\0')
		{
			(newn->cGender[j]) = (*cGen);
			cGen++;
			j++;
		}
		newn->cGender[j] = '\0';

		while((*cCty) != '\0')
		{
			(newn->cCity[k]) = (*cCty);
			cCty++;
			k++;
		}
		newn->cCity[k] = '\0';

		while((*cDesg) != '\0')
		{	
			(newn->cDesignation[l]) = (*cDesg);
			cDesg++;
			l++;
		}
		newn->cDesignation[l] = '\0';

		newn->Prev=NULL;
		newn->Next=NULL;

		for(iCnt=1;iCnt<(iPos-1);iCnt++)
		{
			temp=temp->Next;
		}

		(newn->Next) = (temp->Next);
		(temp->Next->Prev) = newn;
		(temp->Next) = newn;
		(newn->Prev) = temp;
	}
}

void DeleteAtPostion(PPEmployee Head,PPEmployee Tail,int iPos)
{
	PEmployee temp = NULL;
	int iSize = 0,iCnt = 0;
	PEmployee Head2 = NULL;
	PEmployee Tail2 = NULL;

	iSize = Count(*Head,*Tail);

	if((iPos < 0) || (iPos > iSize))
	{
		return;
	}

	if(iPos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(iPos == iSize)
	{
		DeleteLast(Head,Tail);
	}
	else
	{
		/*if(iPos < (iSize/2))
		{
			//DeleteAtPosition from starting end
			//Maintain a pointer Head2
		}
		else if(iPos < (iSize/2))
		{
			//DeleteAtPosition from Terminating end
			//Maintain a pointer Tail2
		}*/
		temp = (*Head);
		for(iCnt=1;iCnt<(iPos-1);iCnt++)
		{
			temp = temp->Next;
		}

		temp->Next = temp->Next->Next;
		free(temp->Next->Prev);
		temp->Next->Prev=temp;
	}
}

/*
	SearchBySalary(conditions)
		1. Display salary of all employees same as input taken from the user.(for same salary)
		2. Display salary of all employees below input taken from user.(for less salary)
		3. Display salary of all employees above input taken from user.(for more salary)
*/

void SearchBySalary(PEmployee Head,PEmployee Tail,float fSal)
{
	do
	{
		if((Head->Salary) == fSal)
		{
			printf("\n|Employee id is : %d \t Employee Salary is : %0.2f|\n",Head->EmpId,Head->Salary);
		}
		else if(fSal <= 50000)
		{
			printf("\n|Employee id is : %d \t Employee Salary is : %0.2f|\n",Head->EmpId,Head->Salary);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);
}

void SearchGrtSalary(PEmployee Head,PEmployee Tail,float fSal)
{
	do
	{
		if((Head->Salary)>fSal)
		{
			printf("\n|Employee id is : %d \t Employee Salary is : %0.2f|\n",Head->EmpId,Head->Salary);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);
}

void SearchLesSalary(PEmployee Head,PEmployee Tail,float fSal)
{
	do
	{
		if((Head->Salary)<fSal)
		{
			printf("\n|Employee id is : %d \t Employee Salary is : %0.2f|\n",Head->EmpId,Head->Salary);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);
}

void SearchEqaSalary(PEmployee Head,PEmployee Tail,float fSal)
{
	do
	{
		if((Head->Salary)==fSal)
		{
			printf("\n|Employee id is : %d \t Employee Salary is : %0.2f|\n",Head->EmpId,Head->Salary);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);
}

void SearchByID(PEmployee Head,PEmployee Tail,int iID)
{
	int iFlag = 1;
	printf("\nSearching Employee by ID:\n");
	do
	{
		if((Head->EmpId) == iID)
		{
			iFlag++;
			printf("\n|Employee id is : %d \tEmployee Age is : %d \t Employee Salary is : %0.2f \t Employee Name is : %s|\n",Head->EmpId,Head->Age,Head->Salary,Head->Name);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	if(iFlag == 1)
	{
		printf("No Employee ID Found according to user input\n");
	}
}

float MinimumSalary(PEmployee Head,PEmployee Tail)
{
	float iMin = 0;
	iMin = Head->Salary;

	printf("\nSearching minimum salary of an Employee :\n");
	do
	{
		if((Head->Salary) < iMin)
		{
			iMin = (Head->Salary);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	return iMin;
}

float MaximumSalary(PEmployee Head,PEmployee Tail)
{
	float iMax = 0;
	iMax = Head->Salary;

	printf("\nSearching Maximum salary of an Employee :\n");
	do
	{
		if((Head->Salary) > iMax)
		{
			iMax = (Head->Salary);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	return iMax;
}

int MinimumAge(PEmployee Head,PEmployee Tail)
{
	int iMin = 0;
	iMin = Head->Age;

	printf("\nSearching minimum age of an Employee :\n");
	do
	{
		if((Head->Age) < iMin)
		{
			iMin = (Head->Age);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	return iMin;
}

int MaximumAge(PEmployee Head,PEmployee Tail)
{
	int iMax = 0;
	iMax = Head->Age;

	printf("\nSearching Maximum age of an Employee :\n");
	do
	{
		if((Head->Age) > iMax)
		{
			iMax = (Head->Age);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	return iMax;
}

BOOL Like(PEmployee Head,PEmployee Tail,char ch)
{
	int flag = 0;
	int iCnt = 0;
	printf("\nFinding Employee name with %c :\n",ch);
	do
	{
		if((Head->Name[0]) == ch)
		{
			flag = 1;
			iCnt++;
			printf("Employee Name is : %s\n",Head->Name);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	if(flag == 1)
	{
		printf("Total Employees found starting with letter %c are %d\n",ch,iCnt);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL Like1(PEmployee Head,PEmployee Tail,char ch)
{
	int flag = 0;
	int iCnt = 0;
	int i = 0 , j = 0;
	char FName[50] = {'\0'};

	printf("\nFinding Employee name with %c :\n",ch);
	do
	{
		while((Head->Name[i]) != 32)
		{
			FName[j] = Head->Name[i];
			i++;
			j++;
		}
		if(FName[j-1] == ch)
		{
			flag = 1;
			iCnt++;
			printf("Employee Name is : %s\n",Head->Name);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	if(flag == 1)
	{
		printf("Total Employees found ending with letter %c are %d\n",ch,iCnt);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void SearchByAge(PEmployee Head,PEmployee Tail,int iAge)
{
	do
	{
		if((Head->Age) == iAge)
		{
			printf("\n|Employee id is : %d \t Employee Age is : %d|\n",Head->EmpId,Head->Age);

		}
		Head = Head->Next;
	}while(Head != Tail->Next);
}

void SearchByName(PEmployee Head,PEmployee Tail,char *name)
{
	int i = 0,flag = 0;
	do
	{
		i = 0;
		while((Head->Name[i] != '\0') && (*name != '\0'))
		{
			if((Head->Name[i]) == *name)
			{
				i++;
				name++;
			}
			else
			{
				break;
			}
		}
		if(Head->Name[i] == *name)
		{
			flag++;
			printf("\n|Employee id is : %d \t Employee Name is : %s|\n",Head->EmpId,Head->Name);
		}
		Head = Head->Next;		
	}while(Head != Tail->Next);

	if(flag == 0)
	{
		printf("No Employee found according to the user input\n");
	}
}

void SearchByCity(PEmployee Head,PEmployee Tail,char *city)
{
	int i = 0,flag = 0;
	do
	{
		i = 0;
		while((Head->cCity[i] != '\0') && (*city != '\0'))
		{
			if((Head->cCity[i]) == *city)
			{
				i++;
				city++;
			}
			else
			{
				break;
			}
		}
		if(Head->cCity[i] == *city)
		{
			flag++;
			printf("\n|Employee id is : %d \t Employee Name is : %s \t Employee City is : %s|\n",Head->EmpId,Head->Name,Head->cCity);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	if(flag == 0)
	{
		printf("No Employee found with the same city\n");
	}
}

void SearchByDesignation(PEmployee Head,PEmployee Tail,char *cDesg)
{
	int i = 0,flag = 0;
	do
	{
		i = 0;
		while((Head->cDesignation[i] != '\0') && (*cDesg != '\0'))
		{
			if((Head->cDesignation[i]) == (*cDesg))
			{
				i++;
				cDesg++;
			}
			else
			{
				break;
			}
		}
		if(Head->cDesignation[i] == *cDesg)
		{
			flag++;
			printf("\n|Employee id is : %d \t Employee Name is : %s \t Employee Designation is : %s|\n",Head->EmpId,Head->Name,Head->cDesignation);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	if(flag == 0)
	{
		printf("No Employee found with the same designation\n");
	}
}

void SearchByGender(PEmployee Head,PEmployee Tail,char *gender)
{
	int i = 0,flag = 0;
	do
	{
		i = 0;
		while((Head->cGender[i] != '\0') && (*gender != '\0'))
		{
			if((Head->cGender[i]) == *gender)
			{
				i++;
				gender++;
			}
			else
			{
				break;
			}
		}
		if(Head->cGender[i] == *gender)
		{
			flag++;
			printf("\n|Employee id is : %d \t Employee Name is : %s \t Employee Gender is : %s|\n",Head->EmpId,Head->Name,Head->cGender);
		}
		Head = Head->Next;
	}while(Head != Tail->Next);

	if(flag == 0)
	{
		printf("No Employee found with the same Gender\n");
	}
}
