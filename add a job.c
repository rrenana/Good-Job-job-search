#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 30
//#define M 10//כל מעסיק יוכל להוסיף עד 10 משרות


typedef struct 
{
	char name_of_job[N];
	char name_of_company[N];
	char employment_catagory[N];//תחום המשרה
	char location_area[N];//מיקום 
	char scope_of_the_job[N];//היקף המשרה
	char salary_range[N];//טווח השכר לשעה
	int index_boss;
	int arr_index_worker[100];//את מערך כל המגישים לאתחל לנאל?????????????
	int code;//מספר קוד של משרה
	
}Job;



Job* arr_jobs[1000];//לאתחל לנאל????????????

//זוהי פונקציה למילוי פרטים עבור משרה בודדת
void add_job(Job* arr_jobs[1000], int index)//אסתי התחייבה לדאוג לאינדקס הבוס
{
	//Job* job;
	int index_boss = index;
	int count = 0;

	char name_of_job[N];
	char name_of_company[N];
	char location[5][N] = { "North", "South","West","East" };
	char employment_catagory[5][N] = { "Education","Engineering","Medicene","Office" };
	char scope_of_the_job[5][N] = { "Full time","Part time","Third job","Shifts" };//היקף המשרה
	char salary_range[5][N] = { "Minimum wage","35 to 50 per hour","50 to 100 per hour", "100 or more per hour" };//טווח השכר
	int code;
	int arr_index_worker[100];
	int choose;


	//אסתיייייייייייייי כאן צריך לייבא  את הקובץ של המשרות כדי להוסיף את המשרה הזו
	//Job* arr_jobs[1000];//לאתחל לנאל????????????
	
	//for (int i = 0; i < 100; ++i)
	//{
	//	arr_index_worker = NULL;//איתחול מערך מגישי המשרה לנאל
	//}


	for (int i = index * 10; i < (index * 10) + 10; ++i)//לכל בוס יש מערך של 10 משרות
	{
		if (!arr_jobs[i])//אם המיקום פנוי
		{
			code = i;
			//arr_jobs[i] ;//נוסיף כאן את המשרה
			
		}
		++count;
	}
	if (count == 10)
	{
		printf("Dear Boss You have finished your maximum job quota\n");
		return;
	}


	printf("Enter please name of the job:\n");
	gets_s(arr_jobs[code]->name_of_job,N);
	
	printf("Enter please name of the company:\n");
	gets_s(arr_jobs[code]->name_of_company,N);

	do {
		printf("Please Choose location Area:\n1.North\n2.South\n.3.West\n4.East\n");
		scanf_s("%d", &choose);
		strcpy(arr_jobs[code]->location_area, location[choose - 1]);
		printf(arr_jobs[code]->location_area);//check=good
	} while (choose > 4 || choose < 1);
	
	do {
		printf("Please Choose Employment Catagory:\n1.Education\n2.Engineering\n3.Medicne\n4.Office\n");
		scanf_s("%d", &choose);
		strcpy(arr_jobs[code]->employment_catagory, employment_catagory[choose - 1]);
		printf(arr_jobs[code]->employment_catagory);//check=good

	} while (choose > 4 || choose < 1);
	
	do {
		printf("Please Choose scope of the job:\n1.Full time\n2.Part time\n3.Third job\n4.Shifts");
		scanf_s("%d", &choose);
		strcpy(arr_jobs[code]->scope_of_the_job, scope_of_the_job[choose - 1]);
		printf(arr_jobs[code]->scope_of_the_job);//check=good

	} while (choose > 4 || choose < 1);
	
	do {
		printf("Please Choose the salary range of the job:\n1-Minimum wage\n2-35 to 50 per hour\n3-50 to 100 per hour\n4 -100 or more per hour");
		scanf_s("%d", &choose);
		strcpy(arr_jobs[code]->salary_range, salary_range[choose - 1]);
		printf(arr_jobs[code]->salary_range);//check=good

	} while (choose > 4 || choose < 1);
	
	//לאסתייייייייייי לדחוף את מערך המשרות לקובץ בחזרה ולסגור	
}
