#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 30
#define M 10//ëì îòñé÷ éåëì ìäåñéó òã 10 îùøåú

//int main(){
//	struct Job arr[10];
//	int i;
//	FILE* fp = fopen("secret.log", "r");
//	for (i = 0; i < 10; i++)
//		fprintf(fp, "%s # %d # %f ", arr[i].name, &arr[i].age,
//			&arr[i].price);
//	fclose(fp);
//	return 0;
//}

typedef struct 
{
	char name_of_job[N];
	char name_of_company[N];
	char catagory_of_job[N];//úçåí äîùøä
	char location_area[N];//îé÷åí 
	char scope_of_the_job[N];//äé÷ó äîùøä
	char salary_range[N];//èååç äùëø ìùòä
	//int code;//îñôø ñéãåøé ùì îùøä
	//char job_requirements[N];//ãøéùåú äúô÷éã
}Job;




void add_job(Job* job)
{
	char name_of_job[N];
	char name_of_company[N];
	char location[5][N] = { "North", "South","West","East" };
	char employment_catagory[5][N] = { "Education","Engineering","Medicene","Office" };
	char scope_of_the_job[5][N] = { "Full time","Part time","Third job","Shifts" };//äé÷ó äîùøä
	char salary_range[5][N]={ "Minimum wage","35 to 50 per hour","50 to 100 per hour", "100 or more per hour" };//èååç äùëø
	//int cood;
	int choose;

	printf("Enter please name of the job:\n");
	gets_s(name_of_job, N);
	
	printf("Enter please name of the company:\n");
	gets_s(name_of_company, N);

	do {
		printf("Please Choose location Area:\n1.North\n2.South\n.3.West\n4.East\n");
		scanf_s("%d", &choose);
		strcpy(job->location_area, location[choose - 1]);
		printf(job->location_area);//check=good
	} while (choose > 4 || choose < 1);
	
	do {
		printf("Please Choose Employment Catagory:\n1.Education\n2.Engineering\n3.Medicne\n4.Office\n");
		scanf_s("%d", &choose);
		strcpy(job->catagory_of_job, employment_catagory[choose - 1]);
		printf(job->catagory_of_job);//check=good

	} while (choose > 4 || choose < 1);
	
	do {
		printf("Please Choose scope of the job:\n1.Full time\n2.Part time\n3.Third job\n4.Shifts");
		scanf_s("%d", &choose);
		strcpy(job->scope_of_the_job, scope_of_the_job[choose - 1]);
		printf(job->scope_of_the_job);//check=good

	} while (choose > 4 || choose < 1);
	
	do {
		printf("Please Choose the salary range of the job:\n1-Minimum wage\n2-35 to 50 per hour\n3-50 to 100 per hour\n4 -100 or more per hour");
		scanf_s("%d", &choose);
		strcpy(job->salary_range, salary_range[choose - 1]);
		printf(job->salary_range);//check=good

	} while (choose > 4 || choose < 1);
	

	//do//úçåí îùøä
	//{
	//	printf("\n\nSelect the field of the work:\n1- Education\n2 - Engineering\n3 - Medicine\n4 - Office");
	//	scanf_s("%d",&choice);
	//	switch (choice)
	//	{
	//	case 1:
	//		strcpy(job->field_of_work, "Education");
	//		break;
	//	case 2:
	//		strcpy(job->field_of_work, "Engineering");
	//		break;
	//	case 3:
	//		strcpy(job->field_of_work, "Medicine");
	//		break;
	//	case 4:
	//		strcpy(job->field_of_work, "Office");
	//		break;
	//	default:
	//		printf("Error\n");
	//		break;
	//	}
	//} while (choice > 4 || choice < 1);

	//do//îé÷åí
	//{
	//	printf("\n\nSelect the location area of the work:\n1-South\n2 - North\n3 - Center\n4 - Jerusalem and its environs");
	//	scanf_s("%d", &choice);
	//	switch (choice)
	//	{
	//	case 1:
	//		strcpy(job->location_area, "South");
	//		break;
	//	case 2:
	//		strcpy(job->location_area, "North");
	//		break;
	//	case 3:
	//		strcpy(job->location_area, "Center");
	//		break;
	//	case 4:
	//		strcpy(job->location_area, "Jerusalem and its environs");
	//		break;
	//	default:
	//		//printf("Error\n");
	//		break;
	//	}
	//} while (choice > 4 || choice < 1);

	//do//äé÷ó îùøä
	//{
	//	printf("\n\nSelect the scope of the job:\n1-Full time\n2-Part time\n3-Third job\n4 -Shifts");
	//	scanf_s("%d", &choice);
	//	switch (choice)
	//	{
	//		
	//	case 1:
	//		strcpy(job->scope_of_the_job, "Full time");
	//		break;
	//	case 2:
	//		strcpy(job->scope_of_the_job, "Part time");
	//		break;
	//	case 3:
	//		strcpy(job->scope_of_the_job, "Third job");
	//		break;
	//	case 4:
	//		strcpy(job->scope_of_the_job, "Shifts");
	//		break;
	//	default:
	//		//printf("Error\n");
	//		break;
	//	}
	//} while (choice > 4 || choice < 1);

	//do//èååç äùëø
	//{
	//	printf("\n\nSelect the salary range of the job:\n1-Minimum wage\n2-35 to 50 per hour\n3-50 to 100 per hour\n4 -100 or more per hour");
	//	scanf_s("%d", &choice);
	//	switch (choice)
	//	{ 
	//	case 1:
	//		strcpy(job->salary_range, "Minimum wage");
	//		break;
	//	case 2:
	//		strcpy(job->salary_range, "35 to 50 per hour");
	//		break;
	//	case 3:
	//		strcpy(job->salary_range, "50 to 100 per hour");
	//		break;
	//	case 4:
	//		strcpy(job->salary_range, "100 or more per hour");
	//		break;
	//	default:
	//		//printf("Error\n");
	//		break;
	//	}
	//} while (choice > 4 || choice < 1);

	
		
	//getchar();

}
//int main()
//{
//	Job* arr_jobs[M];
//	return 0;
//
//}

//void printCourse(const Course* c)
//{
//
//	printf("The name of course: %s\n", c->name);
//	printf("The grade: %d\n", c->grade);
//}
