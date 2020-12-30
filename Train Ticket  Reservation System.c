/**********************************************PREPROCESSORS**********************************************************/
//Train Reservation System
//Working on basic structure
//including all libraries for now
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

/*******************************************GLOBAL VARIABLES**********************************************************/
//ALl the globle variables and the composite data types will be declared here
typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;




/*******************************************FUNCTION PROTOTYPE**********************************************************/
//function prototypes to be used
void reservation(void);							//main reservation function
void viewdetails(void);							//view details of all the trains
void cancel(void);
void printticket(char name[],int,int,float);	//print ticket
void specifictrain(int);						//print data related to specific train
float charge(int,int);							//charge automatically w.r.t number of seats and train
void login();


/******************************************FUNCTION DECLARATION**********************************************************/

/*********************************************MAIN()*************************************************/

int main()

{
		system("cls");
	printf("\t\t\t\t#######################################################\n");
	printf("\t\t\t\t#||*************************************************||#\n");
	printf("\t\t\t\t#||*********|                             |*********||#\n");
	printf("\t\t\t\t#||**********|  TRAIN TICKET RERS. SYSTEM  |*********||#\n");
	printf("\t\t\t\t#||*********|                             |*********||#\n");
	printf("\t\t\t\t#||*************************************************||#\n");
	printf("\t\t\t\t#||*************************************************||#\n");
	printf("\t\t\t\t#||*********|     BROUGHT TO YOU BY       |*********||#\n");
	printf("\t\t\t\t#||*********|     MINHAJ  UDDIN.ORG       |*********||#\n");
	printf("\t\t\t\t#||*************************************************||#\n");
	printf("\t\t\t\t#######################################################\n\n\n");


	printf(" \n \t\t\t\tPress any key to continue:");

	getch();
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("     TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n\t1. Reserve A Ticket");
	printf("\n\t------------------------");
	printf("\n\t2. View All Trains");
	printf("\n\t------------------------");
	printf("\n\t3. Cancel Reservation");
	printf("\n\t------------------------");
	printf("\n\t4. Exit");
	printf("\n\t------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();		//Fucntion still not added
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			cancel();
			//function not added. code has been removed due to some errors
			break;
		case 4:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

/*********************************************VIEWDETAILS()*************************************************/

//The function is yet not completed, need more details to be added!
//timings of the trains are still missing

void viewdetails(void)
{
	system("cls");
	printf("-------------------------------------------------------------------------------------");
	printf("\nTr.No\tName\t\t\tDestinations\t\t\tCharges\t\tTime\n");
	printf("-------------------------------------------------------------------------------------");
	printf("\n1001\tTurna Express          \tBoston to Manhattan     \tTK.500     \t9am");
	printf("\n1002\tSunar bangla Express   \tManhattan To Boston     \tTK.700     \t12pm");
	printf("\n1003\tSubarna Express        \tBoston To L.A           \tTK.650     \t8am");
	printf("\n1004\tMohanogor Express      \tL.A To Boston           \tTk.450     \t11am");
	printf("\n1005\tUdaion Express         \tBoston To Chicago       \tTK.400     \t7am");
	printf("\n1006\tCottrola Express       \tChicago To Boston       \tTK.400     \t9.30am");
    printf("\n1007\tKornofulli Express     \tBoston To Washington    \tTK.350     \t1pm");
    printf("\n1008\tGodoli Express         \tWashington To Boston    \tTK.350     \t4pm");
    printf("\n1009\tMeteor Express         \tBoston To Miami         \tTK.600     \t3.35pm");
    printf("\n1009\tMeteor Express         \tMiami To Boston         \tTK.600     \t4.15pm");
}

/*********************************************RESERVATION()*************************************************/

void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	system("cls");

	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}

	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

/*********************************************CHARGE()*************************************************/

float charge(int train_num,int num_of_seats)
{
		if (train_num==1001)
	{
		return(500.0*num_of_seats);
	}
	if (train_num==1002)
	{
		return(700.0*num_of_seats);
	}
	if (train_num==1003)
	{
		return(650.0*num_of_seats);
	}
	if (train_num==1004)
	{
		return(450.0*num_of_seats);
	}
	if (train_num==1005)
	{
		return(400.0*num_of_seats);
	}
	if (train_num==1006)
	{
		return(400.0*num_of_seats);
	}
	if (train_num==1007)
	{
		return(350.0*num_of_seats);
	}
	if (train_num==1008)
	{
		return(350.0*num_of_seats);
	}
	if (train_num==1009)
	{
		return(600.0*num_of_seats);
	}
	if (train_num==1010)
	{
		return(600.0*num_of_seats);
	}
}


/*********************************************PRINTTICKET()*************************************************/

void printticket(char name[],int num_of_seats,int train_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%.2f",charges);
}

/*********************************************SPECIFICTRAIN()*************************************************/

void specifictrain(int train_num)
{

	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tRed Lines Express");
		printf("\nDestination:\t\tBoston to Manhattan");
		printf("\nDeparture:\t\t9am ");
	}
	if (train_num==702)
	{
		printf("\nTrain:\t\t\tSUNAR BANGLA Express");
		printf("\nDestination:\t\tCHITTAGONG TO DHAKA");
		printf("\nDeparture:\t\t7:00Am");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\tLA City Express");
		printf("\nDestination:\t\tBoston to L.A");
		printf("\nDeparture:\t\t8am");
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\tLA City Express");
		printf("\nDestination:\t\tL.A to Boston");
		printf("\nDeparture:\t\t11am ");
	}
	if (train_num==1005)
	{
		printf("\nTrain:\t\t\tIron City Express");
		printf("\nDestination:\t\tBoston to Chicago");
		printf("\nDeparture:\t\t7am");
	}
	if (train_num==1006)
	{
		printf("\ntrain:\t\t\tIron City Express");
		printf("\nDestination:\t\tChicago to Boston");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (train_num==1007)
	{
		printf("\ntrain:\t\t\tKeystone Express");
		printf("\nDestination:\t\tBoston to Washington");
		printf("\nDeparture:\t\t1pm ");
	}
	if (train_num==1008)
	{
		printf("\ntrain:\t\t\tKeystone Express");
		printf("\n Destination:\t\tWashington to Boston");
		printf("\nDeparture:\t\t4pm ");
	}
	if (train_num==1009)
	{
		printf("\ntrain:\t\t\tMeteor Express");
		printf("\nDestination:\t\tBoston to Miami");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (train_num==1010)
	{
		printf("\ntrain:\t\t\tMeteor Express");
		printf("\nDestination:\t\tMiami to Boston");
		printf("\nDeparture:\t\t1.15 ");
	}
}

void login()
{
	int a=0,i=0;
    char username[30],c=' ';
    char password[30],code[30];
    char user[30]="username";
    char pass[30]="password";
    do
{

    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &username);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<11)
	{
	    password[i]=getch();
	    c=password[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	password[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(username,"minhajuddi@gmail.com")==0 && strcmp(password,"Minhaj@660")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}

void cancel(void)   /* Sorry this function does not work. Coding is not completed. Codes have been removed due to some errors  */
{
	/*FILE *f,*t;
	int i=0;
	int trainnum;
	t=fopen("seats_reserved.txt","w");
	if ((f=fopen("seats_reserved.txt","r"))==NULL)
	{
		printf("NO RECORD ADDED.");
		main();
		* * * * *
		*
		*
		*
		*
		*
		*
		*  /  missing codes  /
	}
	else*/
	system("cls");
	int trainnum;
	printf("-----------------------\n");
		printf("Enter the train number: \n");
			printf("-----------------------\n");
		fflush(stdin);
		scanf("%i",&trainnum);
		printf("\n\nCancelled");
		getch();
}





