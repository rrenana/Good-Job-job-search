#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INFN "input.txt"
#define OUTFN "output.txt"
#define N 20
#define S 10
#define EOLN '\r'
void init_employee();
struct Employee
{
	char first_name[S];
	char last_name[S];
	char gender[S];
	char id[S];
	int age[S];
	char phone_number[S];
	int password;
	char Email[25];
	char living_area[5];
	char Driving_License[5];
	char Education_level[N];
	char Employment_Catagory[N];
	int policies;
	int apply_jobs[10];
};
struct Employer
{
	char first_name[S];
	char last_name[S];
	char gender[S];
	char id[S];
	int age[S];
	char phone_number[S]; 
	int password;
	char Email[25];
	int policies;
	char company_name[N];

};
void read_Employee_Data_File(struct Employee* employee[100])
{
	int i = 0;
	FILE* fp = fopen("Employee.txt", "w");
	if (!fp)
	{
		printf("Couldn't Open File!\n");
		exit(-1);
	}
	for (i = 0; i < 3; ++i)
	{
		fgets(employee[i]->first_name, S, fp);
		fgets(employee[i]->last_name, S, fp);
		fgets(employee[i]->gender, S, fp);
		fgets(employee[i]->id, S, fp);
		fscanf(fp, "%d", &(employee[i]->age));
		fgets(employee[i]->phone_number, S, fp);
		fscanf(fp, "%d", &(employee[i]->password));
		fgets(employee[i]->Email, 25, fp);
		fgets(employee[i]->living_area, S, fp);
		fgets(employee[i]->Driving_License, S, fp);
		fgets(employee[i]->Education_level, N, fp);
		fgets(employee[i]->Employment_Catagory, N, fp);
	}
		
		
	fclose(fp);
}
void print_data_file_employer(struct Employer emp)// printing worker's data to a file.
{
	FILE* fp = fopen("C:\\Users\\gitit\\source\\repos\\Employer.txt", "w");
	if (!fp)
		exit(-1);
	fprintf(fp, "%s , %s , %s , %s , %d , %s , %d , %s ,%d\n", emp.first_name, emp.last_name, emp.gender, emp.id, emp.age, emp.phone_number,emp.password, emp.Email, emp.policies);
}
void print_data_file_employee(struct Employee worker)
{
	FILE* fp = fopen("C:\\Users\\gitit\\source\\repos\\Employee.txt", "w");
		fprintf(fp, "%s , %s , %s , %s , %d , %s , %d , %s , %s , %s , %s , %s , %d\n", worker.first_name, worker.last_name, worker.gender, worker.id, worker.age, worker.phone_number, worker.password, worker.Email, worker.living_area, worker.Driving_License, worker.Education_level, worker.Employment_Catagory, worker.policies);
	fclose(fp);
}

void init_file_employee(struct Employee arr[])//printing employer's data to a file.
{
	int i;
	FILE* fp = fopen("C:\\Users\\Administrator\\source\\repos\\נסיון לקבצים\\Employee.txt", "w");
	for (i = 0; i < 3; i++)
		fprintf(fp, "%s , %s , %s , %s , %d , %s , %d , %s , %s , %s , %s , %s , %d\n", arr[i].first_name, arr[i].last_name, arr[i].gender, arr[i].id, arr[i].age, arr[i].phone_number, arr[i].password, arr[i].Email, arr[i].living_area, arr[i].Driving_License, arr[i].Education_level, arr[i].Employment_Catagory, arr[i].policies);
	fclose(fp);
}

void logIn(struct Employee workers[3], struct Employer bosses[3])// Login function = Implemented by Esty Fridman.
{
	int numOfBosses = 3;
	int numOfWorkers = 3;
	char id[9];
	int temp;
	int index = -1;
	int password;
	printf("-------Login-------:\n ");// user inserts id number,system checks if its exists.
	do {
		printf("Enter Your Id:\n");
		scanf("%s", id);
		for (int i = 0; i < numOfWorkers; ++i)
		{
			if (strcmp(workers[i].id , id)==0)
				index = i;
		}
		if (index == -1)
		{
			for (int i = 0; i < numOfBosses; ++i)
			{
				if (strcmp(bosses[i].id, id) == 0)
					index = (i + numOfWorkers);
			}
		}
		if (index == -1)
			printf("error!\n There is no user with this id please try again");
	} while (index == -1);
	do {
		temp = 0;
		printf("Please insert your password");//המשתמש מכניס את הסיסמא שלו והמערכת בודקת האם הסיסמא נכונה
		scanf_s("%d", &password);
		if (index < numOfWorkers)
		{
			if (password != workers[index].password)
			{
				printf("error!\n Your password is incorrect please try again");
				++temp;
			}
		}
		if (index >= numOfWorkers)
		{
			if (password != bosses[index - numOfWorkers].password)
			{
				printf("error!\n Your password is incorrect please try again");
				++temp;
			}
		}
	} while (temp > 0);
	printf("have a nice day");
}

void read_Employer_Data_File(struct Employer* employer[100])// saving all employer data to a file.
{
	int i = 0;
	FILE* fp = fopen("C:\\Users\\gitit\\source\\repos\\Employer.txt", "r");
	if (!fp)
	{
		printf("Couldn't Open File!\n");
		exit(-1);
	}
	for (i = 0; i < 2; ++i)
	{
		fgets(employer[i]->first_name, S, fp);
		fgets(employer[i]->last_name, S, fp);
		fgets(employer[i]->gender, S, fp);
		fscanf(fp, "%d", &(employer[i]->id));
		fscanf(fp, "%d", &(employer[i]->age));
		fgets(employer[i]->phone_number, S, fp);
		fscanf(fp, "%d", &(employer[i]->password));
		fgets(employer[i]->Email, 25, fp);
		fgets(employer[i]->company_name, N, fp);
		
	}
	fclose(fp);
}
void init_employee() // initalizes worker's personal data.
{
	char id[S];
	int gender_choose, licence, level_educ;
	struct Employee worker;
	char other1[20];
	char location[5][20] = { "North", "South","West","East" };
	char employment_catagory[20][20] = { "education","engineering","medicene","office" };
	char educ_level[4][30] = { "SchoolYears" ,"Student" ,"BA" , "MA" };
	int choose, choose_educ;
	printf("Please Enter First Name:\n");
	scanf("%s", &(worker.first_name));
	printf("Please Enter Last Name:\n ");
	scanf("%s", &(worker.last_name));
	printf("Please Enter ID Number (9 digits):");
	scanf("%s", id);
	if (strlen(id)!=9)
	{
		/*printf("Invaild ID Number!\n");*/   // compiler is ignoring if statements,need to figure out.
	}
	if (worker.id == id)
	{
		printf("User Already Exists In The System!\n");
	}
	else
		worker.id == id;
	printf("Please Enter Your Age:\n");
	scanf("%d", &(worker.age));
	if (worker.age < 16 || worker.age > 60)
	{
		/*printf("Illegal age to look for a job.\n");*/ // same weird prroblem.
	}
	printf("Enter Your Phone Number (10 digits):\n");
	scanf("%d", &(worker.phone_number));
	if (strlen(worker.phone_number)!=10)
	{
		/*printf("Phone Number Must Contain 10 Digits.\n");*/
	}
	printf("Please Choose Your Password (password must contain 6-10 digits):\n");
	scanf("%d", &(worker.password));
	if (worker.password <= 99999 || worker.password > 9999999999)
		/*printf("Expected 6-10 Digits.");*/
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
	printf(worker.living_area);
	printf("Do You Own A Driving License?\n 1.yes\n2.No\n");
	scanf("%d", &licence);
	if (licence == 1)
		strcpy(worker.Driving_License, "yes");
	if (licence == 2)
		strcpy(worker.Driving_License, "No");
	printf("Please Enter Employment Catagory:\n1.Education\n2.Engineering\n3.Medicne\n4.Office\n");
	scanf("%d", &choose_educ);
	strcpy(worker.Employment_Catagory, employment_catagory[choose_educ - 1]);
	/*printf(worker.Employment_Catagory);*/
	printf("Please Select education Level:\n1.12 school years\n2.student\n3.B.A\n4.M.A\n");
	scanf("%d", &level_educ);
	strcpy(worker.Education_level, educ_level[level_educ - 1]);
	/*printf(worker.Education_level);*/
	printf("Final Step: In Order To Complete The Registration Process Please Enter 1 To Approve Our Webstite's Policies:\n");
	scanf("%d", &(worker.policies));
	if ((worker.policies) != 1)
	{
		while ((worker.policies) != 1)
		{
			printf("Please Enter 1 To Approve Our Policies and Regulations\n");
			scanf("%d", &(worker.policies));
			if ((worker.policies) == 1)
			{
				break;
			}
		}
	}
		
	else
	{
		printf("%s , Welcome To Our Website! You Have Succesfuly Signed-up.\n", worker.first_name);
		print_data_file_employee(worker);
	}
	return worker;
}
struct Employer init_employer()// initializes employer's personal data.
{
	struct Employer emp;
	FILE* fp= fopen("C:\\Users\\gitit\\source\\repos\\Employer.txt", "a");
	char id[S];
	printf("Please Enter First Name:\n");
	scanf("%s", &(emp.first_name));
	printf("Please Enter Last Name:\n ");
	scanf("%s", &(emp.last_name));
	printf("Please Enter ID Number (9 digits):");
	scanf("%s",(id));
	if (strlen(id) != 9)
		/*printf("Invaild ID Number!\n");*/
		if (id == emp.id)
		{
			printf("User Already Exists In The System.\n");
		}
		else
			emp.id == id;
			fgets(emp.id, S, fp);
	printf("Please Enter Your Age:\n");
	scanf("%d", &(emp.age));
	if (emp.age < 16 || emp.age > 60)
		/*printf("Illegal age to look for a job.");*/
	printf("Enter Your Phone Number (10 digits):\n");
	scanf("%d", &(emp.phone_number));
	if (strlen(emp.phone_number) != 10)
		/*printf("Phone Number Must Contain 10 Digits.\n");*/
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
	print_data_file_employer(emp);
	return emp;
}
void Registration_Process()
{
	int option;
	printf("Hello User! , In Order To Start With The Registration Process, Follow The Next Steps:");
	printf("\nPlease Select Type Of User:\n 1. Employee\n 2.Employer");
	scanf("%d", &option);
	switch (option)
	{
	case 1:
				init_employee();		
	case 2:

		
			    init_employer();
	}
}
int main()
{
	struct Employee workers[100];
	struct Employer employer[100];
	int size = 100;
	int option;
	
	printf("Please Choose an option:\n 1.Sign-up\n 2.Sign-In\n");
	scanf("%d", &option);
	switch (option)
	{
	case 1:
		Registration_Process(&employer, size, &workers);
	case 2:
		for (int i = 0; i < 100; ++i)
		{
			read_Employee_Data_File(&workers[i]);
			read_Employer_Data_File(&employer[i]);
		}
		logIn(workers,employer);
	}
}



