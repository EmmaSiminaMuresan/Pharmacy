/**********************************************/
/* client.c - See client.h for copyright and info */
/**********************************************/

/* System headers and application specific headers: */
#include "client.h"


/* Structures declarations: */
struct birthday
{
    int day;
    char month[10];
    int year;
};
struct birthday birth;


struct address
{
    char street[20];
    int number;
    char city[20];
};


struct client
{
    char last_name[25];
    char first_name[25];
    struct birthday bday;
    int phone[11];
    struct address ad;
    int present;
};
struct client cl;


/***************************************************************/
/* AUTHOR: SUCALA PAULA ILINCA                                 */
/* FUNCTION NAME: costumer_data                                */
/* DESCRIPTION: read and retain customer information           */
/* Argument     Type     IO    Descrpition                     */
/* ------------ -------- -- -----------------------------------*/
/* RETURN VALUE: void                                          */
/* CHANGES: -                                                  */
/***************************************************************/

void customer_data()
{
    printf("Please enter your first name: ");
    scanf("%s", cl.first_name);
    printf("Please enter your last name: ");
    scanf("%s", cl.last_name);
    printf("Please enter the day(integer number), month(string) and year(integer number) you were born: ");
    scanf("%d %s %d", &cl.bday.day, cl.bday.month, &cl.bday.year);
    return 0;
}


/*****************************************************************************************************************/
/* AUTHOR: MURESAN EMMA SIMINA                                                                                   */
/* FUNCTION NAME: choise                                                                                         */
/* DESCRIPTION: The client choose if he has a quick list of his needs or an prescription. After he introduce the */
/* medicine of one of them, he can repeat the action until his medicines are over.                               */
/* Argument     Type     IO    Descrpition                                                                       */
/* ------------ -------- -- -------------------------------------------------------------------------------------*/
/* RETURN VALUE: void                                                                                            */
/* CHANGES: -                                                                                                    */
/*****************************************************************************************************************/

void choise()
{
    int ch = 0, ok = 0, okk = 1;

    while( okk == 1 )
    {
        ok = 0;
        printf("\nIf you have a quick list of your needs enter 1.\nIf you have a prescription enter 2.\n");
        while( ok == 0 )
        {
            scanf("%d", &ch);
            switch (ch)
            {
                case 1 :
                    {
                        insert_quick_list();
                        ok = 1;
                    }
                    break;
                case 2 :
                    {
                        insert_list_prescription();
                        ok = 1;
                    }
                    break;
                default :  printf("You entered an invalid option. Enter again.\n");
            }
        }
        printf("\nDo you have something else to add?\nEnter 1 for YES.\nEnter 2 for NO.\n");
        scanf("%d", &okk);
    }
    return 0;
}


/****************************************************************************/
/* AUTHOR: MURESAN EMMA SIMINA                                              */
/* FUNCTION NAME: courier                                                   */
/* DESCRIPTION: it displays the courier schedule and then the client can    */
/* enter the day he prefers. If not the medicine will be sent soon          */
/* Argument     Type     IO    Descrpition                                  */
/* ------------ -------- -- ------------------------------------------------*/
/* RETURN VALUE: void                                                       */
/* CHANGES:                                                                 */
/****************************************************************************/

void courier()
{
    char days[5][10] = {"Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday"};
    char day[10];
    int opt = 0, ok = 0, i = 0;


    printf("This is the courier's schedule: \n\n");

    printf("Day of the week\t DELIVERY\n");
    printf("Monday\t\t 9AM-4PM\n");
    printf("Tuesday\t\t 9AM-4PM\n");
    printf("Wednesday\t 9AM-4PM\n");
    printf("Thursday\t 9AM-4PM\n");
    printf("Friday\t\t 9AM-4PM\n");
    printf("Saturday\t DOESN'T WORK\n");
    printf("Sunday\t\t DOESN'T WORK\n\n");

    while( ok == 0 ) {
        printf("If you prefer a day enter 1. If not enter 2.\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            {
                printf("Enter the day you prefer: ");
                scanf("%s", day);

                for( i = 0 ; i < 5 && ok == 0 ; i++ )
                    if(stricmp(days[i],day)==0)
                    {
                        printf("We will send you the courier in the next %s.\nYou will receive a message in that day.", day);
                        ok = 1;
                    }

                if( ok == 0 )  printf("You entered an incorect day. Please repeat.\n");

            } break;
        case 2:
            {
                printf("We will send you the courier soon.\nYou will receive a message in that day.\n");
                ok = 1;
            } break;
        default :   printf("You entered an incorect option. Please repeat.\n");
        }
    }
    return 0;
}


