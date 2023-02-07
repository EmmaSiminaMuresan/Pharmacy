/**********************************************/
/* cart.c - See cart.h for copyright and info */
/**********************************************/

/* System headers and application specific headers: */
#include "cart.h"


/* Structures declarations: */
struct cart
{
    float price;
    int number;
    char name[50];
    float miligrams;
    char type[50];
};
struct cart ca[100];


struct quantity
{
    int nr_pills;
    float miligrams;
    int quant;
    int nr_product;
};


struct medicine
{
    char name[50];
    struct quantity q;
};
struct medicine *med_ptr;


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
/* FUNCTION NAME: cart_display                                 */
/* DESCRIPTION: displays the products in the buyer's cart      */
/* Argument     Type     IO    Descrpition                     */
/* ------------ -------- -- -----------------------------------*/
/* RETURN VALUE: void                                          */
/* CHANGES: -                                                  */
/***************************************************************/

void cart_display()
{
    printf("\nName:\t\t\t Miligrams:\t Number products:\t Price:\t\t Type:\n");
    for(int i = 1 ; i <= SIZE_C ; i++)
    {
        printf( "%s\t\t\t %.2f\t\t %d\t\t\t %.2f\t\t %s\n" , ca[i].name, ca[i].miligrams, ca[i].number ,ca[i].price, ca[i].type);
    }
    if(cl.present != 0)
    {
        printf("\nAnd your gift : ");
        printf( "%s\n\n",  st[cl.present].name);
    }
    return 0;
}


/*****************************************************************************/
/* AUTHOR : MURESAN EMMA SIMINA                                              */
/* FUNCTION NAME: discount                                                   */
/* DESCRIPTION: it finds out if the day of today is even or odd and display  */
/* the discount which will be applied to the cart.                           */
/* Argument     Type     IO    Descrpition                                   */
/* ------------ -------- -- -------------------------------------------------*/
/* RETURN VALUE: void                                                        */
/* CHANGES: -                                                                */
/*****************************************************************************/

void discount()
{
    int d;
    int disc[3] = {0, 5, 10};
    char date[11];

    strcpy(date, __DATE__);

    if( isdigit(date[4]))
        d = (date[4] - '0')*10 + (date[5] - '0');
    else
        d = date[5] - '0';

    if( d % 2 == 0 )
    {
        suma = suma - (disc[1] * suma) /100;
        printf("\nIt's an even day. You have a discount of %d%c.\n", disc[1], '%');
        printf("The total price of your cart is: %.2f lei\n\n", suma);
    }
    else
    {
        suma = suma - (disc[2] * suma) /100;
        printf("\nIt's an odd day. You have a discount of %d%c.\n", disc[2], '%');
        printf("The total price of your cart is: %.2f lei\n\n", suma);
    }
    return 0;
}


/**************************************************************************/
/* AUTHOR : MURESAN EMMA SIMINA                                           */
/* FUNCTION NAME: birthmonth                                              */
/* DESCRIPTION: it compares the month of this day and the birthday month  */
/* of the client. If they are the same then, if the client wants, he will */
/* receive one of the gifts.                                              */
/* Argument     Type     IO    Descrpition                                */
/* ------------ -------- -- ----------------------------------------------*/
/* RETURN VALUE: void                                                     */
/* CHANGES: -                                                             */
/**************************************************************************/

void birthmonth()
{
    int opt = 0, ok = 0;
    char date[11], birthday[10];
    strcpy(date, __DATE__);
    strcpy(birthday, cl.bday.month);

    if(strnicmp(date,birthday,3)==0)
    {
        printf("\nCONGRATULATIONS!\nIt's your birthmonth. You get for FREE:\n\n");
        printf( "%s or %s\n\n", st[SIZE-1].name, st[SIZE-2].name);
        while(ok == 0)
        {
            printf("Press 1 for %s.\nPress 2 for %s.\nIf you don't want your present press 0.\n", st[SIZE-1].name, st[SIZE-2].name);
            scanf("%d", &opt);
            switch (opt)
            {
            case 1:
                {
                    cl.present = SIZE-1;
                    printf("The present was added.\n");
                    ok = 1;
                }
                break;
            case 2:
                {
                    cl.present = SIZE-2;
                    printf("The present was added.\n");
                    ok = 1;
                }
                break;
            case 0: ok = 1;
                    break;
            default: printf("Please choose a valid option.\n");
            }
        }
    }
    return 0;
}


/****************************************************************************************************/
/* AUTHOR: SUCALA PAULA ILINCA                                                                      */
/* FUNCTION NAME: amount                                                                            */
/* DESCRIPTION: calculates the calculates the price of the products that the customer wants to buy  */
/* Argument     Type     IO    Descrpition                                                          */
/* ------------ -------- -- ------------------------------------------------------------------------*/
/* RETURN VALUE: void                                                                               */
/* CHANGES: the amount                                                                              */
/****************************************************************************************************/

void amount()
{
    for(int i = 1; i <= SIZE_C; i++)
    {
        suma = suma + (ca[i].price * ca[i].number);
    }
    printf("\nThe total is: %.2f\n", suma);
    return 0;
}


/************************************************************************************/
/* AUTHOR: SUCALA PAULA ILINCA                                                      */
/* FUNCTION NAME: transport                                                         */
/* DESCRIPTION: calculates the amount the customer has to pay for transportation    */
/* Argument     Type     IO    Descrpition                                          */
/* ------------ -------- -- --------------------------------------------------------*/
/* RETURN VALUE: void                                                               */
/* CHANGES: the total amount                                                        */
/************************************************************************************/

void transport()
{
    printf("Please enter your phone number: ");
    scanf("%d", &cl.phone);
    printf("Please enter your address.\nCity: ");
    scanf("%s", cl.ad.city );
    printf("Street: ");
    scanf("%s", cl.ad.street );
    printf("Number: ");
    scanf("%d", &cl.ad.number );

    if(suma < 50)
    {
        printf("Shipping fee is 15 lei. ");
        suma = suma + 15;
    }
    else if(suma >= 50 && suma < 100)
    {
        printf("Shipping fee is 7 lei. ");
        suma = suma + 7;
    }
    else if(suma >= 100)
    {
        printf("Shipping fee is 0 lei. ");
        suma = suma + 0;
    }
    printf("The total price is: %.2f\n", suma);
    return 0;
}


/***************************************************************/
/* AUTHOR: SUCALA PAULA ILINCA                                 */
/* FUNCTION NAME: add_cart                                     */
/* DESCRIPTION: add a product to the client cart               */
/* Argument     Type     IO    Descrpition                     */
/* ------------ -------- -- -----------------------------------*/
/* RETURN VALUE: void                                          */
/* CHANGES: -                                                  */
/***************************************************************/

void add_cart(int i, int j)
{
    FILE *f_ptr;
    f_ptr = fopen("cart_client.txt","a");

    SIZE_C++;

    if(f_ptr == NULL)
    {
       printf("Error!");
       exit(1);
    }

    fprintf(f_ptr,"%s %.2f %s %.2f %d\n" ,  st[i].name, st[i].ph.miligrams, st[i].type ,st[i].price, (med_ptr + j) -> q.nr_product);
    ca[SIZE_C].price = st[i].price;
    ca[SIZE_C].number = (med_ptr + j) -> q.nr_product;
    strcat(ca[SIZE_C].name, st[i].name);
    ca[SIZE_C].miligrams = st[i].ph.miligrams;
    strcat(ca[SIZE_C].type, st[i].type);

    fclose(f_ptr);
    return 0;
}

