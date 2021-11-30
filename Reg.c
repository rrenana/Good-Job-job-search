#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INFN "input.txt"
#define OUTFN "output.txt"
#define N 20
#define S 10
#define EOLN '\r'
struct Employee init_employee();
struct Employee
{
	char first_name[S];
	char last_name[S];
	char gender[S];
	int id[S];
	int age[S];
	int phone_number[S];
	int password[S];
	char Email[15];
	char living_area[5];
	char Driving_License[5];
	char Education_level[N];
	char Employment_Catagory[N];
	int policies;
};
struct Employer
{
	char first_name[S];
	char last_name[S];
	char gender[S];
	int id[S];
	int age[S];
	int phone_number[S];
	int password[S];
	char Email[15];
	int policies;
	char company_name[N];
	int apply_jobs[10];
};
void read_Employee_Data_File(struct Employee** employee,int size)
{
	int i = 0;
	FILE *fp=fopen("Employee.txt", "w");
	if (!fp)
	{
		printf("Couldn't Open File!\n");
		exit(-1);
	}
	for (i = 0; i <size; ++i)
	{
		fgets(employee[i]->first_name, S, fp);
		fgets(employee[i]->last_name, S, fp);
		fgets(employee[i]->id, S, fp);
		fgets(employee[i]->password, S, fp);
		fgets(employee[i]->phone_number, S, fp);
		fgets(employee[i]->age, S, fp);
		fgets(employee[i]->Email, 25, fp);
		fgets(employee[i]->Education_level, N, fp);
		fgets(employee[i]->Employment_Catagory, N, fp);
		fgets(employee[i]->gender, S, fp);
		fgets(employee[i]->Driving_License, S, fp);
		fgets(employee[i]->living_area, S, fp);
	}
	fclose(fp);
}

void read_Employer_Data_File(struct Employer** employer,int size)
{
	int i = 0;
	FILE* fp = fopen("Employer.txt", "w");
	if (!fp)
	{
		printf("Couldn't Open File!\n");
		exit(-1);
	}
	for (i = 0; i < size; ++i)
	{
		fgets(employer[i]->first_name, S, fp);
		fgets(employer[i]->last_name, S, fp);
		fgets(employer[i]->id,S, fp);
		fgets(employer[i]->password, S, fp);
		fgets(employer[i]->phone_number, S, fp);
		fgets(employer[i]->age, S, fp);
		fgets(employer[i]->Email, 25, fp);
		fgets(employer[i]->company_name, N, fp);
		fgets(employer[i]->gender, S, fp);
	}
	fclose(fp);
}
struct Employee init_employee()
{
	int gender_choose, licence, level_educ;
	struct Employee worker;
	char other1[20];
	char location[5][20] = { "North", "South","West","East" };
	char employment_catagory[20][20] = { "education","engineering","medicene","other" };
	char educ_level[4][30] = { "SchoolYears" ,"Student" ,"BA" , "MA" };
	int choose, choose_educ;
	FILE* fp = fopen("data_worker.txt", "w");
	if (!fp)
	{
		printf("Can't Open File.\n");
		exit(1);
	}
	printf("Please Enter First Name:\n");
	scanf("%s", &(worker.first_name));
	printf("Please Enter Last Name:\n ");
	scanf("%s", &(worker.last_name));
	printf("Please Enter ID Number:");
	scanf("%d", &(worker.id));
	if (worker.id < 99999999 || worker.id >= 10000000000)
		printf("Invaild ID Number!\n");
	printf("Please Enter Your Age:\n");
	scanf("%d", &(worker.age));
	fprintf(fp, "%d",(worker.age));
	if (worker.age < 16 || worker.age > 60)
		printf("Illegal age to look for a job.");
	printf("Enter Your Phone Number (10 digits):\n");
	scanf("%d", &(worker.phone_number));
	if (worker.phone_number <= 999999999 || worker.phone_number >10000000000)
		printf("Phone Number Must Contain 10 Digits.\n");
	printf("Please Choose Your Password (password must contain 6-10 digits):\n");
	scanf("%d", &(worker.password));
	if (worker.password <=99999 || worker.password>9999999999)
		printf("Expected 6-10 Digits.");
	printf("Please Choose a Gender:\n 1.Male\n 2.Female\n");
	scanf("%d", &gender_choose);
	if (gender_choose == 1)
		strcpy(worker.gender, "Male");
	if (gender_choose == 2)
		strcpy(worker.gender, "Female");
	printf("Please Enter Your Email Address:\n");
	scanf("%s", &(worker.Email));
	printf("Please Choose Living Area:\n1.North\n2.South\n.3.West\n4.East\n");
	scanf("%d", &choose);
	strcpy(worker.living_area, location[choose - 1]);
	printf(worker.living_area);//check=good
	printf("Do You Own A Driving License?\n 1.yes\n2.No\n");
	scanf("%d", &licence);
	if (licence == 1)
		strcpy(worker.Driving_License, "yes");
		fprintf(fp, "%s",(worker.Driving_License));
	if (licence == 2)
		strcpy(worker.Driving_License, "No");
	printf("Please Enter Employment Catagory:\n1.Education\n2.Engineering\n3.Medicne\n4.Other\n");
	scanf("%d", &choose_educ);
	if (choose_educ == 4)
	{
		printf("Enter Other Catagory:\n");
		scanf("%s", &other1);
		strcpy(worker.Employment_Catagory, other1);
		printf(worker.Employment_Catagory);// check=good
	}
	else
	{
		strcpy(worker.Employment_Catagory, employment_catagory[choose_educ - 1]);
		printf(worker.Employment_Catagory);//check=good
	}
	printf("Please Select education Level:\n1.12 school years\n2.student\n3.B.A\n4.M.A\n");
	scanf("%d", &level_educ);
	strcpy(worker.Education_level, educ_level[level_educ - 1]);
	printf(worker.Education_level);//check=good
	printf("Final Step: In Order To Complete The Registration Process Please Enter 1 To Approve Our Webstite's Policies:\n");
	scanf("%d", &(worker.policies));
	if ((worker.policies) != 1)
		while ((worker.policies) != 1)
		{
			printf("Please Enter 1 To Approve Our Policies and Regulations\n");
			scanf("%d", &(worker.policies));
			if ((worker.policies) == 1)
			{
				break;
			}
		}
	else
		printf("%s , Welcome To Our Website! You Have Succesfuly Signed-up.\n", worker.first_name);
	return worker;
}
struct Employer init_employer()
{
	struct Employer emp;
	printf("Please Enter First Name:\n");
	scanf("%s", &(emp.first_name));
	printf("Please Enter Last Name:\n ");
	scanf("%s", &(emp.last_name));
	printf("Please Enter ID Number:");
	scanf("%d", &(emp.id));
	if (emp.id < 99999999 || emp.id >= 10000000000)
		printf("Invaild ID Number!\n");
	printf("Please Enter Your Age:\n");
	scanf("%d", &(emp.age));
	if (emp.age < 16 || emp.age > 60)
		printf("Illegal age to look for a job.");
	printf("Enter Your Phone Number (10 digits):\n");
	scanf("%d", &(emp.phone_number));
	if (emp.phone_number <= 999999999 || emp.phone_number > 10000000000)
		printf("Phone Number Must Contain 10 Digits.\n");
	printf("Please Choose Your Password (password must contain 6-10 digits):\n");
	scanf("%d", &(emp.password));
	//if (emp.password < 999999 || emp.password>9999999999)
		//printf("Expected 6-10 Digits.");
	printf("Please Enter Your Company Name (use _ instead of space):\n");
	scanf("%s", &(emp.company_name));
	printf("Please Enter Your Email Address:\n");
	scanf("%s", &(emp.Email));
	printf("Final Step: In Order To Complete The Registration Process Please Enter 1 To Approve Our Webstite's Policies:\n");
	scanf("%d", &(emp.policies));
	if ((emp.policies) != 1)
		while ((emp.policies) != 1)
		{
			printf("Please Enter 1 To Approve Our Policies and Regulations\n");
			scanf("%d", &(emp.policies));
			if ((emp.policies) == 1)
			{
				break;
			}
		}
	else
		printf("%s , Welcome To Our Website! You Have Succesfuly Signed-up.\n", emp.first_name);
	return emp;
}
void Registration_Process(struct Employer** emp,int siz, struct Employee** worker)
{
	int option;
	printf("Hello User! , In Order To Start With The Registration Process, Follow The Next Steps:");
	printf("\nPlease Select Type Of User:\n 1. Employee\n 2.Employer");
	scanf("%d", &option);
	switch (option)
	{
	case 1:
		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < siz; ++j)
			{
				worker[i][j] = init_employee();
				read_Employee_Data_File(worker,siz);
				/*print_Employee_Data(worker);*/
			}
		}
		
	case 2:

		for (int i = 0; i < 100; ++i)
		{
			for (int j = 0; j < siz; ++j)
			{
				emp[i][j] = init_employer();
				read_Employer_Data_File(emp,siz);
			}
		}
		
	}
}
int main()
{
	struct Employee** work = NULL;
	struct Employer** employee= NULL;
	int size = 100;
	work = (struct Employee**)malloc(size * sizeof(struct Employee*));
	if (!work)
		exit(-1);
	employee = (struct Employer**)malloc(size * sizeof(struct Employer*));
	if (!employee)
		exit(-1);
	Registration_Process(&employee,size,&work);
	
}



