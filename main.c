#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>


void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="shithi";
    char pass[10]="peep";
    do
{

    printf("\n  ******************************  LOGIN FIRST  *********************************  ");
    printf(" \n\n                  ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n\n                  ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"shithi")==0 && strcmp(pword,"peep")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR BOOKING SYSTEM !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen

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


int i;

int tinfo(int no);  //for info
void able(int room[]); //availability
void reser(int *room);//for room booking
void bill(); //for bill details
void about(); //contact details
void roomf(); //for choose comfort suite
void restu(); //restaurant details
int confirm(); //for conformation
void rooml(); //room structure
void comment();  //for comment
int amenities();   //amenities

struct info  //used on reser
{
    char name[50];
    int num;
    char email[50];
    int room_no;
    char date[20];

};


int main()

{
    login();
    int x,room[3];
    FILE *ptr=fopen("roominfo.txt","r");
    for(i=0;i<3;i++)
    {
        fscanf(ptr,"%d\n",&room[i]); //rooms
    }

    printf("_______________________________________________________________________________________________________________\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf("                          |       |  |----- |       +----+  +-----+  |\\    /|  |-----                       \n");
    printf("                          |       |  |      |       |    |  |     |  | \\  / |  |            \n");
    printf("                          |  / \\  |  |--    |       |       |     |  |  \\/  |  |--               \n");
    printf("                          | /   \\ |  |      |       |       |     |  |      |  |                \n");
    printf("                          |/     \\|  |----- |_____  +----|  +-----+  |      |  |-----                        \n");

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("_______________________________________________________________________________________________________________\n\n");
    printf("*****************************************||>> HOTEL MANAGMANT APP <<||*****************************************\n");
    printf("===============================================================================================================\n\n");

    do
    {
        printf("                                            ***CHOOSE FROM BELOW***  \n");
        printf("                                            1.Available Room         \n");
        printf("                                            2.Reservation of Room    \n");
        printf("                                            3.Room Features          \n");
        printf("                                            4.Restaurant Facilities  \n");
        printf("                                            5.Room Structure         \n");
        printf("                                            6.Bill Method            \n");
        printf("                                            7.Comment                \n");
        printf("                                            8.Contact us             \n");
        printf("                                            9.Amenities               \n");
        printf(" \n                                            Enter Your Option-> ");
        scanf("%d",&x);

        switch(x)
        {

            case 1:
                able(room);
                break;

            case 2:
                reser(room); //booking
                break;

            case 3:
                roomf(); //about room
                break;

            case 4:
                restu();
                break;

            case 5:
                rooml(); //structure
                break;

            case 6:
                bill();
                break;

            case 7:
                comment();
                break;

            case 8:
                about(); //contact details
                break;

            case 9:
                amenities();
                break;

            default:
                printf("Wrong Selection !!!");
                break;

        }
        printf("\n\n\nPress 1 to Continue->> ");
        scanf("%d",&i);
    }

    while(i==1);

    FILE *ptr2=fopen("roominfo.txt","w"); //rooms
    for(i=0;i<3;i++)
    {
        fprintf(ptr2,"%d\n",room[i]);
    }
    return 0;
}


void roomf()
{
    int e;//for choose
    printf("\n\n1.Regular Suite\n");
    printf("2.Double Suite\n");
    printf("3.Luxury Suite\n\n");

    printf("Choose your Comfort Suite Option for Details>>");
    scanf("%d",&e);
    printf("\n\n\n");
    printf("###################################################################");

    if(e==1)
    {
        printf("\n>>>One big room with single bed.");
        printf("\n>>>One bathroom");
        printf("\n>>>Fully air conditioned");
        printf("\n>>>Refrigerator");
        printf("\n>>>TV");
        printf("\n>>>Dressing table");
        printf("\n\nPRICE-> 3000TK (per night}\n\n");

    }
    else if(e==2)
    {
        printf("\n>>>Two big room with double bed.");
        printf("\n>>>Two bathroom");
        printf("\n>>>Fully air conditioned");
        printf("\n>>>Refrigerator");
        printf("\n>>>TV");
        printf("\n>>>Dressing table");
        printf("\n\nPRICE-> 5000TK (per night}\n\n");

    }
    else if(e==3)
    {
        printf("\n>>>Three big room with two bed.");
        printf("\n>>>Two bathroom");
        printf("\n>>>Fully air conditioned");
        printf("\n>>>Refrigerator");
        printf("\n>>>TV");
        printf("\n>>>Dressing table");
        printf("\n>>>Big balcony");
        printf("\n>>>Kitchen");
        printf("\n\nPRICE-> 8000TK (per night}\n\n");

    }
    else
        printf("Wrong Choose");
}


 //available rooms
void able(int room[])
{
    printf("\n\nThere are %d Regular Suite Available\n",room[0]);
    printf("There are %d Double Suite Available\n",room[1]);
    printf("There are %d Luxury Suite Available\n",room[2]);
}


void reser(int *room)
{

    int ck;//for choose
    printf("\n\n**Choose from below**\n");
    printf("1. Book a Regular Suite\n");
    printf("2. Book a Double Suite\n");
    printf("3. Book a Luxury Suite\n");
    printf("Enter your option ->");
    scanf("%d",&ck);

    if(ck==1)
    {
        if(room[0]>0&&room[0]<11)
        {
            room[0]=room[0]-tinfo(room[0]); //give room number
        }
        else
        {
            printf("        SORRY !!!\nNo Room Left To Book !!!");
        }
    }

    else if(ck==2)
    {
        if(room[1]>0&&room[1]<6)
        {
            room[1]=room[1]-tinfo(room[1]);
        }
        else
        {
            printf("        SORRY !!!\nNo Room Left To Book !!!");
        }
    }

    else if(ck==3)
    {
        if(room[2]>0&&room[2]<3)
        {
            room[2]=room[2]-tinfo(room[2]);
        }
        else
        {
            printf("        SORRY !!!\nNo Room Left To Book !!!");
        }
    }

    else
    {
        printf("Wrong action !!!");
    }
}


void bill()
{
    int u, q;
    printf("\n\n[[Select the Suite]]");
    printf("\n1.Regular Suite");
    printf("\n2.Double Suite");
    printf("\n3.Luxury Suite");

    printf("\n\nEnter Suite_ ");
    scanf("%d",&u);

    if(u==1)
    {
        printf("\n\n\n________________________________________________________");
        printf("\n\nEnter the Day he/she stands- ");
        scanf("%d",&q);
        printf("\n\nThe Bill is--->>> %d TK\n\n",q*3000);
    }

    else if(u==2)
    {
        printf("________________________________________________________");
        printf("\n\nEnter the Day he/she stands- ");
        scanf("%d",&q);
        printf("\n\nThe Bill is--->>> %d TK\n\n",q*5000);

    }

    else if(u==3)
    {
        printf("________________________________________________________");
        printf("\n\nEnter the Day he/she stands- ");
        scanf("%d",&q);
        printf("\n\nThe Bill is--->>> %d TK\n\n",q*8000);
    }
    else
        printf("\n\nSorry !! Wrong Choice\n\n");

}


void about()
{
    printf("\n\nCONTACT US>>>>>>>>");
    printf("\n\nGulshan ,Dhaka \n");
    printf("\n+88 0341 62480 - 90\n+88 01766666530 - Hotline\n");
    printf("\n+88 01766666531 - 34\n+88-0341-64436\n");
    printf("\nreservations@hotelbd.com\n");
}


//restaurant details
void restu()
{
    printf("\n\n### Welcome to our Restaurant System ###\n");
    printf("____________________________________________________________");
    printf("\n1.  Rice                          20  TK ");
    printf("\n2.  Dal                           20  TK ");
    printf("\n3.  Chicken Carry                 90  TK ");
    printf("\n4.  Chicken Fry                   80  TK ");
    printf("\n5.  Vegetable                     40  TK ");
    printf("\n6.  Catla Fish                    120 TK ");
    printf("\n7.  Salmon Fish                   150 TK ");
    printf("\n8.  Ilish FIsh                    150 TK ");
    printf("\n9.  Beef Bhuna                    120 TK ");
    printf("\n10. Butter Nun                    25  TK ");
    printf("\n11. Quarter Grilled Chicken       80  TK ");
    printf("\n12. Shik Kabab                    100 TK ");
    printf("\n13. Special Parata                15  TK ");
    printf("\n14. Bhuna Khichuri                80  TK ");
    printf("\n15. Fried Rice                    100 TK ");
    printf("\n16. Faluda                        70  TK ");
    printf("\n17. Lassi                         50  TK ");
    printf("\n18. Coke/Fanta/7up (200ml)        20  TK ");
    printf("\n19. Tea                           20  TK ");
    printf("\n20. Coffee                        35  TK ");
    printf("\n\n**THANK YOU**\n\n");

}

//confirmed the booking
int confirm()
{
    int t;
    printf("\nEnter 1 to Confirm->> ");
    scanf("%d",&t);

    if(t==1)
    {
        printf("\nCONFIRMED !!");
        return 1;
    }
    else
    {
        printf("Try Again !!");
        return 0;
    }
}


//for room structure
void rooml()
{
    int l;
    printf("\n\n1.Regular Suite\n");
    printf("2.Double Suite\n");
    printf("3.Luxury Suite\n\n");

    printf("Choose your Comfort Suite Option>>");
    scanf("%d",&l);


    if(l==1)
    {
        printf("\n\n\n*******************************REGULAR SUITE****************************************\n\n");
        printf("\n +---------------------------------------+         ");
        printf("\n |>>           |_______|    __________   |         ");
        printf("\n |ENTRY        DRESSING     |        |   |         ");
        printf("\n |               TABLE      |        |   |         ");
        printf("\n |                          |   BED  |   |         ");
        printf("\n |-----------               |        |   |         ");
        printf("\n |          |               |--------|   |         ");
        printf("\n |  BATH    |     FREEZE                 |         ");
        printf("\n |  ROOM    |       __             TV    |         ");
        printf("\n |          |      |  |        ________  |         ");
        printf("\n +---------------------------------------+         ");

    }



    else if(l==2)
    {
        printf("\n\n\n*******************************DOUBLE SUITE****************************************\n\n");
        printf("\n                                         +-------------------------+          ");
        printf("\n                                         | ____________            |        ");
        printf("\n                                         ||            |          _|          ");
        printf("\n                                         ||            | DRESSING| |                   ");
        printf("\n                                         ||  BED       |   TABLE | |           ");
        printf("\n                                         ||____________|         | |         ");
        printf("\n +---------------------------------------|                       |_|          ");
        printf("\n |>>            |___|     __________     |                         |               ");
        printf("\n |ENTRY         FREEZE    |        |     |                         |         ");
        printf("\n |                        |        |     |                         |          ");
        printf("\n |                        |   BED  |     |              +----------|          ");
        printf("\n |-----------             |        |     |              |          |             ");
        printf("\n |          |             |--------|     |              | BATH     |          ");
        printf("\n |  BATH    |                                           |   ROOM   |           ");
        printf("\n |  ROOM    |                    TV                     |          |           ");
        printf("\n |          |                ________    |-------------------------+         ");
        printf("\n +---------------------------------------+         ");

    }



    else if(l==3)
    {
        printf("\n\n\n*******************************LUXURY SUITE****************************************\n\n");
        printf("\n  +-----------------------------------------------------------------+---------+        ");
        printf("\n  |___________________          |         |      |               |  |         |  ");
        printf("\n  |                   |         | TOILET  |      |               |  |   B     |  ");
        printf("\n  |                   |         |_________|      |               |  |   A     |    ");
        printf("\n  |      BED          |                          |      BED      |  |   L     | ");
        printf("\n  |                   |                          |               |  |   C     |  ");
        printf("\n  |___________________|         |                |               |  |   O     |    ");
        printf("\n  |                             |                |_______________|  |   N     |  ");
        printf("\n  |                            _|                                       Y     |  ");
        printf("\n  |                  DRESSING | |                                             |  ");
        printf("\n  |__                  TABLE  | |                                   |         |  ");
        printf("\n  |  |                        | |-----------------------------------+---------+               ");
        printf("\n  |  |FREEZE                  |_| |   SOFA           |              |         |   ");
        printf("\n  |__|                          | |_____________     |              | BATH    |   ");
        printf("\n  |                                             |    |              |  ROOM   |   ");
        printf("\n  |                                             |    |              |         |  ");
        printf("\n  |                             |               |____|              |_________|   ");
        printf("\n  +--    -----------------------+                                             |   ");
        printf("\n  |                             |                                             |     ");
        printf("\n  |                             |                                             |     ");
        printf("\n  |                             |                                             |     ");
        printf("\n  |          KITCHEN            |                                             |     ");
        printf("\n  |                             |          TV                                 |     ");
        printf("\n  |                             |    _______________                   ENTRY<<|     ");
        printf("\n  +------------------------------+---------------------------------------------+     ");


    }
    else
        printf("Wrong Choose");
}


//for add comments
void comment()
{
    int c;
    char comm[1000];
    printf("\n\n1.Write a Comment\n");
    printf("2.Read Comments\n\n");

    printf("Choose Operation ");
    scanf("%d",&c);

    if(c==1)
    {
        printf("Enter your comment >> ");
        fflush(stdin);
        gets(comm);
        FILE *ptr3=fopen("hotel_com.txt","a");
        fprintf(ptr3,"## %s\n",comm);
        fclose(ptr3);
    }
    else if(c==2)
    {
        printf("Comments >>>\n\n");
        FILE *ptr4=fopen("hotel_com.txt","r");
        do
        {
        fscanf(ptr4,"%s\n",comm);
        printf("%s\n",comm);
        }
        while(!feof(ptr4));
    }
    else
        printf("Wrong action!!!");

}


//booking for rooms
int tinfo(int no)
{
    struct info inf;
    printf("\nEnter your name ->");
    scanf("%s",inf.name);
    fflush(stdin);
    do
    {
    printf("\nEnter your Phone Number -> +880");
    scanf("%d",&inf.num);
    }
    while(inf.num<100000000&&inf.num>1999999999); //it will print 10 int
    printf("\nEnter your E-mail -> ");
    scanf("%s",inf.email);
    printf("\nYour Room no is %d",inf.room_no=no);
    printf("\n\nEnter Date(dd/mm/yyyy) -> ");
    scanf("%s",inf.date);
    if(confirm()==1)
    {
        FILE *ptr=fopen("history.txt","a");
        fprintf(ptr,"##\n%s\n%d\n%s\n%d\n%s\n-------------------------------\n\n",inf.name,inf.num,inf.email,inf.room_no,inf.date);
        return 1;
    }
    else
        return 0;

}


//for amenities
int amenities()
{
    printf("\n\nAMENITIES>>>>>>>>");

    printf("\n\n1. 100% Power backup.\n");
    printf("2. Automatic lift.\n");
    printf("3. Ample parking space.\n");
    printf("4. Round the clock security.\n");
    printf("5. free wifi.\n");
    printf("6. Running hot and cold water.\n");
    printf("7. 24 hour room service.\n");
    printf("8. online order for foods");

}
