/**********************************************/
/* pharmacy.c - See pharmacy.h for copyright and info */
/**********************************************/


/* System headers and application specific headers: */
#include "pharmacy.h"


/* Structures declarations: */
struct quantity
{
    int nr_pills;
    float miligrams;
    int quant;
    int nr_product;
};


struct pharmacy_med
{
    int lot;
    char name[50];
    char type[50];
    char prescription[4];
    float price;
    struct quantity ph;
};
struct pharmacy_med st[100];


/**********************************************************************/
/* AUTHOR : MURESAN EMMA SIMINA                                       */
/* FUNCTION NAME: display_sch_farmacy                                 */
/* DESCRIPTION: it displays the schedule of the pharmacy              */
/* Argument     Type     IO    Descrpition                            */
/* ------------ -------- -- ------------------------------------------*/
/* RETURN VALUE: void                                                 */
/* CHANGES: -                                                         */
/**********************************************************************/

void display_sch_farmacy()
{
    printf("Day of the week\t OPEN\n");
    printf("Monday\t\t 7AM-8PM\n");
    printf("Tuesday\t\t 7AM-8PM\n");
    printf("Wednesday\t 7AM-8PM\n");
    printf("Thursday\t 7AM-8PM\n");
    printf("Friday\t\t 7AM-8PM\n");
    printf("Saturday\t 10AM-6PM\n");
    printf("Sunday\t\t 10AM-6PM\n\n");

    return 0;
}


/**********************************************************************/
/* AUTHOR: SUCALA PAULA ILINCA                                        */
/* FUNCTION NAME: stock_display                                       */
/* DESCRIPTION: display the pharmacy stock                            */
/* Argument     Type     IO    Descrpition                            */
/* ------------ -------- -- ------------------------------------------*/
/* RETURN VALUE: void                                                 */
/* CHANGES: -                                                         */
/**********************************************************************/

void stock_display()
{
    for(int i = 0 ; i < SIZE ; i++)
    {
        printf( "%d %s %.2f %d %d %s %.2f %s\n" , st[i].lot, st[i].name, st[i].ph.miligrams, st[i].ph.nr_product , st[i].ph.quant , st[i].type ,st[i].price , st[i].prescription );
    }
    return 0;
}


/****************************************************************************/
/* AUTHOR: SUCALA PAULA ILINCA                                              */
/* FUNCTION NAME: no_stock                                                  */
/* DESCRIPTION: display the products that are no longer in pharmacy stock   */
/* Argument     Type     IO    Descrpition                                  */
/* ------------ -------- -- ------------------------------------------------*/
/* RETURN VALUE: void                                                       */
/* CHANGES: -                                                               */
/****************************************************************************/

void no_stock()
{
    int nr = 0;
    for(int i = 0 ; i < 67 ; i++)
    {
        nr = st[i].ph.nr_product;
        if(nr == 0)
            printf( "%d %s %.2f %d %d %s %.2f %s\n" , st[i].lot, st[i].name, st[i].ph.miligrams, st[i].ph.nr_product , st[i].ph.quant , st[i].type ,st[i].price , st[i].prescription );
    }
    return 0;
}


/********************************************************************************/
/* AUTHOR: SUCALA PAULA ILINCA                                                  */
/* FUNCTION NAME: client_employee                                               */
/* DESCRIPTION: If the user is a client the program runs the specific functions.*/
/* If the user is an employee the program runs the specific functions for it.   */
/* Also, the client can choose a delivery or not. If he doesn't want it, the    */
/* schedule of the pharmacy is displayed                                        */
/* Argument     Type     IO    Descrpition                                      */
/* ------------ -------- -- ----------------------------------------------------*/
/* RETURN VALUE: void                                                           */
/* CHANGES: -                                                                   */
/********************************************************************************/

void client_employee()
{
    int opt = 0, ok = 0, optt = 0;

    while( ok == 0 )
    {
        printf("If you are a client enter 1. If you are an employee enter 2: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            {
                ok = 1;
                customer_data();
                choise();
                amount();
                discount();
                birthmonth();
                cart_display();

                optt = 0;
                printf("Do you want a delivery? For YES press 1, for NO press 2.\n");
                scanf("%d",&optt);
                switch (optt)
                {
                case 1 : {
                            transport();
                            courier();
                         }
                    break;
                case 2:
                    {
                        printf("This is the schedule of our farmacy.\n");
                        display_sch_farmacy();
                    }
                    break;
                }
                printf("\n\nThank you for choosing us! Have a nice day!\n\n");

                } break;
        case 2:
            {
                employee();
                ok = 1;
            } break;
        default :   printf("You entered an incorect option. Please repeat.\n");
        }
    }
    return 0;
}


/********************************************************************************************************************/
/* AUTHOR: SUCALA PAULA ILINCA                                                                                      */
/* FUNCTION NAME: employee                                                                                          */
/* DESCRIPTION: check the password entered by the pharmacist and let him choose one of the options he wants to make */
/*                1. display the pharmacy stock                                                                     */
/*                2. displey the products that are no longer in stock                                               */
/*                3. add a product in stock                                                                         */
/* Argument     Type     IO    Descrpition                                                                          */
/* ------------ -------- -- ----------------------------------------------------------------------------------------*/
/* RETURN VALUE: void                                                                                               */
/* CHANGES: -                                                                                                       */
/********************************************************************************************************************/

void employee()
{
    int okk = 0, ch = 0;
    char password[20];
    while(okk == 0)
    {
        printf("Please enter the password:");
        scanf("%s", password);

        if(strcmp(password, "Pharmacy123") == 0)
        {
            printf("What do you want to do? \n");
            printf("Enter 1 to see the stock, 2 to see what products are no longer in stock or 3 to add products in stock\n");
            while(scanf(" %d", &ch) && (ch != 4))
            {
                switch (ch)
                {
                case 1:
                    {
                        stock_display();
                    } break;
                case 2:
                    {
                        no_stock();
                    } break;
                case 3:
                    {
                        add_product();
                    } break;
                default :   printf("You entered an incorect option. Please repeat.\n");
                }
                printf("Enter 1 to see the stock, 2 to see what products are no longer in stock, 3 to add products in stock or 4 for exit\n");
                }

                    okk = 1;
        }
        else printf("The password is incorrect. Try again\n");
    }
    return 0;
}
