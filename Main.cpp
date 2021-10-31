#include "Header.h"

int main(void)
{
	PEmployee First = NULL;
	PEmployee Last = NULL;
	int iNo = 0,id = 0, letter = 0,letter1 = 0, iPlace = 0,age = 0,iAge = 0;
	int choice = 1, choice1 = 1, choice2 = 1;
	int iRet = 0,iRet3 = 0,iRet4 = 0,iRet5 = 0,iRet6 = 0;
	float iRet1 = 0.0,iRet2 = 0.0,salary = 0.0;
	char Name[50] = {'\0'}, cName[50] = {'\0'}, cName1[50] = {'\0'}, cName2[50] = {'\0'}, cName3[50] = {'\0'}; 
	char designation[50] = {'\0'}, gender[50] = {'\0'}, city[50] = {'\0'};
	char ch1 = '\0',ch2 = '\0';

	printf("\n-------------------------------------------------------------------------------------------------------------\n");
	printf("\n-------------------Employee Database Management System using Doubly Circular Linked List---------------------\n");

	while(choice) //while(choice != 0)//for better readability
	{
		printf("\n-------------------------------------------------------------------------------------------------------------\n");
		printf("\n1: Insert First Employee");
		printf("\n2: Insert Last Employee");
		printf("\n3: Insert Employee At Position");
		printf("\n4: Delete First Employee");
		printf("\n5: Delete Last Employee");
		printf("\n6: Delete Employee At Position");
		printf("\n7: Display the Employee Details of Employees in the Company");
		printf("\n8: Count number of Employees in a Company");
		printf("\n9: SearchBy");
		printf("\n10: Minimum Salary");
		printf("\n11: Maximum Salary");
		printf("\n12: Minimum Age");
		printf("\n13: Maximum Age");
		printf("\n14: Search Name With Starting letter");
		printf("\n15: Search Name With Endining letter");
		printf("\n0: Exit");

		printf("\n----------------------------------------------------------------\n");

		printf("\nEnter your choice\n");
		scanf("%d",&choice);

		printf("\n----------------------------------------------------------------\n");

		switch(choice)
		{
			case 1:
				printf("\n............Enter the Employee Details:...........\n");
				printf("\n1:Enter EMP_ID:\n");
				scanf("%d",&iNo);

				ch1 = '\0';
				scanf("%c",&ch1);//empty scanf
				printf("\n2:Enter Employee Name:\n");
				scanf("%[^'\n']s",Name);
				// "Manali Aundhkar\0"{'M','a'.......\0'};
				//fflush(stdin);

				printf("\n3:Enter Employee Age:\n");
				scanf("%d",&age);
				printf("\n4:Enter Employee Salary:\n");
				scanf("%f",&salary);
				
				ch1 = '\0';
				scanf("%c",&ch1);//empty scanf
				printf("\n5:Enter Employee Gender:\n");
				scanf("%[^'\n']s",gender);

				ch1 = '\0';
				scanf("%c",&ch1);//empty scanf
				printf("\n6:Enter Employee City:\n");
				scanf("%[^'\n']s",city);

				ch1 = '\0';
				scanf("%c",&ch1);//empty scanf
				fflush(stdin);
				printf("\n7:Enter Employee Designation:\n");
				scanf("%[^'\n']s",designation);
				fflush(stdin);
				
				InsertFirst(&First,&Last,iNo,Name,age,salary,gender,city,designation);
				break;

			case 2:
				printf("\n............Enter the Employee Details:...........\n");
				printf("\n1:Enter EMP_ID:\n");
				scanf("%d",&iNo);

				scanf("%c",&ch1);
				printf("\n2:Enter Employee Name:\n");
				scanf("%[^\n]s",Name);
				printf("\n3:Enter Employee Age:\n");
				scanf("%d",&age);
				printf("\n4:Enter Employee Salary:\n");
				scanf("%f",&salary);

				scanf("%c",&ch1);//empty scanf
				printf("\n5:Enter Employee Gender:\n");
				scanf("%[^'\n']s",gender);

				scanf("%c",&ch1);//empty scanf
				printf("\n6:Enter Employee City:\n");
				scanf("%[^'\n']s",city);

				scanf("%c",&ch1);//empty scanf
				printf("\n7:Enter Employee Designation:\n");
				scanf("%[^'\n']s",designation);
				scanf("%c",&ch1);//empty scanf

				InsertLast(&First,&Last,iNo,Name,age,salary,gender,city,designation);
				break;

			case 3:
				printf("\n............Enter the Employee Details:...........\n");
				printf("\n1:Enter EMP_ID:\n");
				scanf("%d",&iNo);

				scanf("%c",&ch1);//empty scanf
				printf("\n2:Enter Employee Name:\n");
				scanf("%[^\n]s",Name);
				printf("\n3:Enter Employee Age:\n");
				scanf("%d",&age);
				printf("\n4:Enter Employee Salary:\n");
				scanf("%f",&salary);
				printf("\nEnter Position:\n");
				scanf("%d",&iPlace);

				scanf("%c",&ch1);//empty scanf
				printf("\n5:Enter Employee Gender:\n");
				scanf("%[^'\n']s",gender);

				scanf("%c",&ch1);//empty scanf
				printf("\n6:Enter Employee City:\n");
				scanf("%[^'\n']s",city);

				scanf("%c",&ch1);//empty scanf
				printf("\n7:Enter Employee Designation:\n");
				scanf("%[^'\n']s",designation);
				scanf("%c",&ch1);//empty scanf

				InsertAtPosition(&First,&Last,iNo,Name,age,salary,gender,city,designation,iPlace);

				break;

			case 4:
				DeleteFirst(&First,&Last);
				break;

			case 5:
				DeleteLast(&First,&Last);
				break;

			case 6:
				printf("\n1:Enter EMP_ID:\n");
				scanf("%d",&iNo);
				printf("\nEnter Position:\n");
				scanf("%d",&iPlace);
				DeleteAtPostion(&First,&Last,iPlace);
				break;

			case 7:
				Display(First,Last);
				break;

			case 8:
				iRet = Count(First,Last);
				printf("The Count of Employees in the Linked List is: %d\n",iRet);
				break;

			case 9:
				printf("Select from Search By:");
				while(choice1)
				{
					printf("\n1. Search by Employee id");
					printf("\n2. Search by  Employee Name");
					printf("\n3. Search by  Employee City");
					printf("\n4. Search by  Employee Salary");
					printf("\n5. Search by  Employee Designation");
					printf("\n6. Search by  Employee Gender");
					printf("\n7. Search by  Employee Age");
					printf("\n0. Exit");

					printf("\nEnter your choice\n");
					scanf("%d",&choice1);

					switch(choice1)
					{
						case 1:
							printf("Enter Employee id you want to search\n");
							scanf("%d",&id);
							SearchByID(First,Last,id);
							break;
						
						case 2:
							scanf("%c",&ch1);//empty scanf
							printf("Enter Employee Name you want to search\n");
							scanf("%[^'\n']s",cName);
							SearchByName(First,Last,cName);
							break;
						
						case 3:
							scanf("%c",&ch1);//empty scanf
							printf("Enter Employee's City Name you want to search\n");
							scanf("%[^'\n']s",cName1);
							SearchByCity(First,Last,cName1);
							break;
						
						case 4:
								printf("Enter a salary and choice you want to search\n");
                                printf("Enter Employee Salary you want to search\n");
								scanf("%f",&salary);
								printf("1:Grater salaries amount than %f: \n",salary);
                                printf("2:Less salaries amount than %f: \n",salary);
                                printf("3:salaries amount Equal  to %f: \n",salary);
                                printf("0:exit\n");
								while(choice2)
                                {
                                    printf("\nEnter your choice\n");
					                 scanf("%d",&choice2);
								switch(choice2)
								{
                                     case 1:
                                     SearchGrtSalary(First,Last,salary);
                                     break;
                                     case 2:
                                     SearchLesSalary(First,Last,salary);
                                     break;
                                     case 3:
                                     SearchEqaSalary(First,Last,salary);
                                     break;
                                     case 0:
                                     break;
								}
                                }
								break;
						case 5:
							scanf("%c",&ch1);//empty scanf
							printf("Enter Employee's Designation you want to search\n");
							scanf("%[^'\n']s",cName2);
							SearchByDesignation(First,Last,cName2);
							break;
						
						case 6:
							scanf("%c",&ch1);//empty scanf
							printf("Enter Employee's Gender you want to search\n");
							scanf("%[^'\n']s",cName3);
							SearchByGender(First,Last,cName3);
							break;

						case 7:
								printf("Enter Employee Age you want to search\n");
								scanf("%d",&iAge);
								SearchByAge(First,Last,iAge);
								break;

						case 0:
							printf("\nThank You for SearchBy Operation\n");
							break;

						default:
							printf("\nWrong Choice\n");
							break;
					}
				}
				break;

			case 10:
				iRet1 = MinimumSalary(First,Last);
				printf("Minimum Salary of an Employee is %0.2f",iRet1);
				break;

			case 11:
				iRet2 = MaximumSalary(First,Last);
				printf("Maximum Salary of an Employee is %0.2f",iRet2);
				break;

			case 12:
				iRet3 = MinimumAge(First,Last);
				printf("Minimum Age of an Employee is %d",iRet3);
				break;

			case 13:
				iRet4 = MaximumAge(First,Last);
				printf("Maximum Age of an Employee is %d",iRet4);
				break;

			case 14:
				scanf("%c",&ch1);//empty scanf
				printf("Enter starting letter of Employee Name that you want to search :\n");
				scanf("%c",&letter);

				iRet5 = Like(First,Last,letter);
				if(iRet5 == FALSE)
				{
					printf("No Name found starting with letter %c\n",letter);
				}
				break;

			case 15:
				scanf("%c",&ch1);//empty scanf
				printf("Enter ending letter of Employee Name that you want to search :\n");
				scanf("%c",&letter1);

				iRet6 = Like1(First,Last,letter1);
				if(iRet6 == FALSE)
				{
					printf("No Name found ending with letter %c\n",letter1);
				}
				break;

			case 0:
				printf("\nThank You for using the Application\n");
				break;

			default:
				printf("\nWrong Choice\n");
				break;
		}
	}

	return 0;
}