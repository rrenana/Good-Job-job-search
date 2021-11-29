#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define N 30

//Employer** employers = NULL;
void job_search()//Employer** employers,int num_of_employers)//ôïð÷öéä ìççéôåù îùøä ìôé ñéðåï äî÷áìú îòøê ùì îöáéòéí ìîòñé÷éí åâåãìå
{
	int choose, i, j , code_of_job;
	char location[5][N] = { "North", "South","West","East","Unfiltered" };
	char employment_catagory[5][N] = { "Education","Engineering","Medicene","Office","Unfiltered" };
	char scope_of_job[5][N] = { "Full time","Part time","Third job","Shifts","Unfiltered" };//äé÷ó äîùøä
	char salary_range[5][N] = { "Minimum wage","35 to 50 per hour","50 to 100 per hour", "100 or more per hour","Unfiltered" };//èååç äùëø
	
	char temp_catagory[N], temp_area[N], temp_scope[N], temp_salary[N];//úçåí,àéæåø,äé÷ó,ùëø
	do {
		printf("Please Choose the location area of the work:\n1.North\n2.South\n.3.West\n4.East\n5.Unfiltered");
		scanf("%d", &choose);
		strcpy(temp_area, location[choose - 1]);
		printf(temp_area);//check=good
	} while (choose > 5 || choose < 1);

	do {
		printf("Please Choose Employment Catagory:\n1.Education\n2.Engineering\n3.Medicne\n4.Office\n5.Unfiltered");
		scanf("%d", &choose);
		strcpy(temp_catagory, employment_catagory[choose - 1]);
		printf(temp_catagory);//check=good
	} while (choose > 5 || choose < 1);

	do {
		printf("Please Choose scope of the job : \n1.Full time\n2.Part time\n3.Third job\n4.Shifts\n5.Unfiltered");
		scanf("%d", &choose);
		strcpy(temp_scope,scope_of_job[choose - 1]);
		printf(temp_scope);//check=good
	} while (choose > 5 || choose < 1);

	do {
		printf("Please Choose the salary range of the job:\n1.Minimum wage\n2.35 to 50 per hour\n3.50 to 100 per hour\n4.100 or more per hour\n5.Unfiltered");
		scanf("%d", &choose);
		strcpy(temp_salary, salary_range[choose - 1]);
		printf(temp_salary);//check=good
	} while (choose > 5 || choose < 1);

	//do//úçåí îùøä
	//{
	//	printf("\n\nSelect the field of the work:\n1- Education\n2 - Engineering\n3 - Medicine\n4 - Office\n5-Unfiltered");
	//	scanf_s("%d", &choice);
	//	switch (choice)
	//	{
	//	case 1:
	//		strcpy(temp_field, "Education");
	//		break;
	//	case 2:
	//		strcpy(temp_field, "Engineering");
	//		break;
	//	case 3:
	//		strcpy(temp_field, "Medicine");
	//		break;
	//	case 4:
	//		strcpy(temp_field, "Office");
	//		break;
	//	case 5://ììà ñéðåï
	//		strcpy(temp_field, "Unfiltered");
	//		break;
	//	default:
	//		printf("Error\n");
	//		break;
	//	}
	//} while (choice > 5 || choice < 1);

	//do//îé÷åí
	//{
	//	printf("\n\nSelect the location area of the work:\n1-South\n2 - North\n3 - Center\n4 - Jerusalem and its environs\n5-Unfiltered");
	//	scanf_s("%d", &choice);
	//	switch (choice)
	//	{
	//	case 1:
	//		strcpy(temp_area, "South");
	//		break;
	//	case 2:
	//		strcpy(temp_area, "North");
	//		break;
	//	case 3:
	//		strcpy(temp_area, "Center");
	//		break;
	//	case 4:
	//		strcpy(temp_area, "Jerusalem and its environs");
	//		break;
	//	case 5://ììà ñéðåï
	//		strcpy(temp_area, "Unfiltered");
	//		break;
	//	default:
	//		//printf("Error\n");
	//		break;
	//	}
	//} while (choice > 5 || choice < 1);

	//do//äé÷ó îùøä
	//{
	//	printf("\n\nSelect the scope of the job:\n1-Full time\n2-Part time\n3-Third job\n4 -Shifts\n5-Unfiltered");
	//	scanf_s("%d", &choice);
	//	switch (choice)
	//	{
	//	case 1:
	//		strcpy(temp_scope, "Full time");
	//		break;
	//	case 2:
	//		strcpy(temp_scope, "Part time");
	//		break;
	//	case 3:
	//		strcpy(temp_scope, "Third job");
	//		break;
	//	case 4:
	//		strcpy(temp_scope, "Shifts");
	//		break;
	//	case 5://ììà ñéðåï
	//		strcpy(temp_scope, "Unfiltered");
	//		break;
	//	default:
	//		//printf("Error\n");
	//		break;
	//	}
	//} while (choice > 5 || choice < 1);

	//do//èååç äùëø
	//{
	//	printf("\n\nSelect the salary range of the job:\n1-Minimum wage\n2-35 to 50 per hour\n3-50 to 100 per hour\n4 -100 or more per hour\n5-Unfiltered");
	//	scanf_s("%d", &choice);
	//	switch (choice)
	//	{
	//	case 1:
	//		strcpy(temp_salary, "Minimum wage");
	//		break;
	//	case 2:
	//		strcpy(temp_salary, "35 to 50 per hour");
	//		break;
	//	case 3:
	//		strcpy(temp_salary, "50 to 100 per hour");
	//		break;
	//	case 4:
	//		strcpy(temp_salary, "100 or more per hour");
	//		break;
	//	case 5://ììà ñéðåï
	//		strcpy(temp_salary, "Unfiltered");
	//		break;
	//	default:
	//		//printf("Error\n");
	//		break;
	//	}
	//} while (choice > 5 || choice < 1);


	
	printf("The jobs found are right for you:\n");
	for (i = 0; i < num_of_employers; ++i)
		for (j = 0; j < 10; ++j)
			if (cmp(Employer[i]->arr_jobs[j]->employment_catagory, temp_catagory) == 0 &&
				cmp(Employer[i]->arr_jobs[j]->location_area, temp_area) == 0 &&
				cmp(Employer[i]->arr_jobs[j]->scope_of_the_job, temp_scope) == 0 &&
				cmp(Employer[i]->arr_jobs[j]->salary_range, temp_salary) == 0)
				fprintf()//ìäëðéñ àú äîùøåú ùòìå áñéðåï ìúåê îòøê çãù
				code_of_job = (i * 10 + j);


}

