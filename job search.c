#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h> 
#include "add a job.c"

#define N 30


void job_search_no_filter(Job* arr_jobs[])
{
	printf("The jobs found are right for you:\n");
	for (int x = 0; x < 1000; ++x)
	{
		printf(arr_jobs[x]);
	}
	//פשוט להדפיס לו את כל מאגר המשרות
}

void job_search_filter(Job* arr_jobs)
{
	int choose, i, j, code_of_job;
	char location[5][N] = { "North", "South","West","East" };
	char employment_catagory[5][N] = { "Education","Engineering","Medicene","Office" };
	char scope_of_job[5][N] = { "Full time","Part time","Third job","Shifts" };//היקף המשרה
	char salary_range[5][N] = { "Minimum wage","35 to 50 per hour","50 to 100 per hour", "100 or more per hour" };//טווח השכר

	char temp_catagory[N], temp_area[N], temp_scope[N], temp_salary[N];//תחום,איזור,היקף,שכר
	do {
		printf("Please Choose the location area of the work:\n1.North\n2.South\n.3.West\n4.East\n");
		scanf("%d", &choose);
		strcpy(temp_area, location[choose - 1]);
		printf(temp_area);//check=good
	} while (choose > 4 || choose < 1);

	do {
		printf("Please Choose Employment Catagory:\n1.Education\n2.Engineering\n3.Medicne\n4.Office\n");
		scanf("%d", &choose);
		strcpy(temp_catagory, employment_catagory[choose - 1]);
		printf(temp_catagory);//check=good
	} while (choose > 4 || choose < 1);

	do {
		printf("Please Choose scope of the job : \n1.Full time\n2.Part time\n3.Third job\n4.Shifts\n");
		scanf("%d", &choose);
		strcpy(temp_scope, scope_of_job[choose - 1]);
		printf(temp_scope);//check=good
	} while (choose > 4 || choose < 1);

	do {
		printf("Please Choose the salary range of the job:\n1.Minimum wage\n2.35 to 50 per hour\n3.50 to 100 per hour\n4.100 or more per hour\n");
		scanf("%d", &choose);
		strcpy(temp_salary, salary_range[choose - 1]);

		printf(temp_salary);//check=good
	} while (choose > 4 || choose < 1);


	printf("The jobs found are right for you:\n");
	for (int x = 0; x < 1000; ++x)
	{
		if (strcmp(arr_jobs->employment_catagory, temp_catagory) == 0 &&
			strcmp(arr_jobs->location_area, temp_area) == 0 &&
			strcmp(arr_jobs->scope_of_the_job, temp_scope) == 0 &&
			strcmp(arr_jobs->salary_range, temp_salary) == 0)
			printf(arr_jobs);

	}	

}

