/**********************************************/
/* medicine.c - See medicine.h for copyright and info */
/**********************************************/


/* System headers and application specific headers: */
#include "medicine.h"


/* Structures declarations: */
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


/*********************************************************************************/
/* AUTHOR: SUCALA PAULA ILINCA                                                   */
/* FUNCTION NAME: add_product                                                    */
/* DESCRIPTION: display the products that are no longer in the pharmacy stock    */
/* Argument     Type     IO    Descrpition                                       */
/* ------------ -------- -- -----------------------------------------------------*/
/* RETURN VALUE: void                                                            */
/* CHANGES: -                                                                    */
/*********************************************************************************/

void add_product(FILE *fptr)
{
    int ch = 0, nr_add = 0, th = 0;

    printf("Enter 1 to add products. When you are done enter 2\n");
    while(scanf(" %d", &ch) && (ch != 2))
    {
        switch (ch)
        {
        case 1:
            {
                printf("To which product do you want to add? ");
                scanf("%d", &th);

                th = th - 1;
                printf("Write how many products do you want to add: ");
                scanf("%d", &nr_add);

                st[th].ph.nr_product = st[th].ph.nr_product + nr_add;

                printf( "%d %s %.2f %d %d %s %.2f %s\n" , st[th].lot, st[th].name, st[th].ph.miligrams, st[th].ph.nr_product , st[th].ph.quant , st[th].type ,st[th].price , st[th].prescription );

            } break;
        default :   printf("You entered an incorect option. Please repeat.\n");
        }
        printf("Enter 1 to add products. When you are done enter 2\n");
    }
    return 0;
}


/**************************************************************************/
/* AUTHOR : MURESAN EMMA SIMINA                                           */
/* FUNCTION NAME: read                                                    */
/* DESCRIPTION: it opens and read the text file where are introduced all  */
/* the products from pharmacy stock and also count them                   */
/* Argument     Type     IO    Descrpition                                */
/* ------------ -------- -- ----------------------------------------------*/
/* RETURN VALUE: void                                                     */
/* CHANGES: -                                                             */
/**************************************************************************/

void read(FILE *fptr)
{
    int c,i = 0;
    while((c = fgetc(fptr)) != EOF)
    {
        fscanf( fptr , "%d" , &st[i].lot);
        fscanf( fptr , "%s" , st[i].name);
        fscanf( fptr , "%f" , &st[i].ph.miligrams);
        fscanf( fptr , "%d" , &st[i].ph.nr_product);
        fscanf( fptr , "%d" , &st[i].ph.quant);
        fscanf( fptr , "%s" , st[i].type);
        fscanf( fptr , "%f" , &st[i].price);
        fscanf( fptr , "%s" , st[i].prescription);
        i++;
    }
    SIZE = i-1;
    return 0;
}


/***************************************************************************/
/* AUTHOR: MURESAN EMMA SIMINA                                             */
/* FUNCTION NAME: search_ql                                                */
/* DESCRIPTION: It search in the stock the product needed.                 */
/* In case 1, the quantity in miligrams is known, also the number of boxes */
/* In case 2, only the number of boxes is known                            */
/* If the client entered a medicine which needs a prescription then it     */
/* won't be added to the cart.                                             */
/* Every medicine with its details will be displayed. The customer can     */
/* choose mulptiple options and then they will be added to the cart.       */
/* Argument     Type     IO    Descrpition                                 */
/* ------------ -------- -- -----------------------------------------------*/
/* RETURN VALUE: void                                                      */
/* CHANGES: -                                                              */
/***************************************************************************/


void search_ql(int j,const int pres)
{

    int i = 0 ,  oks = 0 , okp = 0 , k = 0 , nr = 0 , optn = 0;
    int v[SIZE];

    switch (pres)
    {
    case 1 :
        {

            for( i = 0 ; i < SIZE ; i++ ) {
                if(st[i].ph.miligrams == (med_ptr + j) -> q.miligrams )
                {
                    if( strnicmp(st[i].name, (med_ptr + j) -> name, strlen((med_ptr + j) -> name)) == 0)
                    {

                        if( st[i].ph.nr_product >=  (med_ptr + j) -> q.nr_product )
                        {
                            oks = 1;
                            if( strcmp(st[i].prescription,"NO" )==0)
                               {
                                    okp = 1;
                                    k++;
                                    v[k-1] = i;
                                    printf("\nThe option number %d is: \n%s\nMiligrams: %.2f\nIn stock: %d\nQuantity of product(grams/milliliters/pills): %d\nType: %s\nPrice: %.2f\n\n", k , st[i].name, st[i].ph.miligrams, st[i].ph.nr_product , st[i].ph.quant ,st[i].type, st[i].price );
                               }
                            else printf("Sorry. You need a prescription for this med.\n\n");
                        }
                    }

                }
            }
            if( oks == 0 && okp == 0) printf("Sorry. We don't have the product you want.\n\n");
            if( oks == 1 && okp == 1 )
            {
                printf("Please enter the number of options you want.\n");
                scanf("%d", &nr );
                while( nr != 0)
                {
                    nr--;
                    printf("Enter the number of your option: ");
                    scanf("%d" , &optn );
                    add_cart(v[optn-1], j);
                    printf("The product was added to your cart succesfully.\n");
                }

            }

        } break;
    case 2 :
        {
            for( i = 0 ; i < SIZE ; i++ ) {
                if(st[i].ph.nr_product >=  (med_ptr + j) -> q.nr_product)
                {
                   if( strnicmp(st[i].name, (med_ptr + j) -> name, strlen((med_ptr + j) -> name)) == 0)
                    {
                        oks = 1;
                        if( strcmp(st[i].prescription,"NO"  )==0)
                           {
                                okp = 1;
                                k++;
                                v[k-1] = i;
                                printf("The option number %d is: \n%s\nMiligrams: %.2f\nIn stock: %d\nQuantity of product(grams/milliliters/pills): %d\nType: %s\nPrice: %.2f\n\n", k , st[i].name, st[i].ph.miligrams, st[i].ph.nr_product , st[i].ph.quant ,st[i].type, st[i].price );
                           }
                        else printf("Sorry. You need a prescription for %s %.2f\n\n", st[i].name, st[i].ph.miligrams);
                    }
                }
            }
            if( oks == 0 && okp == 0) printf("Sorry. We don't have the product you want.\n\n");
            if( oks == 1 && okp == 1 )
            {
                printf("Please enter the number of options you want.\n");
                scanf("%d", &nr );
                while( nr != 0)
                {
                    nr--;
                    printf("Enter the number of your option:\n");
                    scanf("%d" , &optn );
                    add_cart(v[optn - 1], j);
                    printf("The product was added to your cart succesfully.\n");
                }

            }
        } break;

    }
    return 0;
}


/***************************************************************************************************/
/* AUTHOR: MURESAN EMMA SIMINA                                                                     */
/* FUNCTION NAME: search_p                                                                         */
/* DESCRIPTION: It search in the stock the product needed.                                         */
/* In case 1, the quantity in miligrams is known, also the total number of pills the client needs. */
/* In case 2, only the number of pills is known.                                                   */
/* In case 3, only the number of tubes/boxes is knownn                                             */
/* The client can request for products which can be sold only if they have a prescription, but     */
/* also he can request for over-the-counter medications                                            */
/* Every medicine with its details will be displayed. The customer can                             */
/* add it to the cart or not                                                                       */
/* Argument     Type     IO    Descrpition                                                         */
/* ------------ -------- -- -----------------------------------------------------------------------*/
/* RETURN VALUE: void                                                                              */
/* CHANGES: -                                                                                      */
/***************************************************************************************************/


void search_p(int j,const int pres)
{

    int i = 0 ,  ok = 0 ,optt = 0, k = 0;

    switch (pres)
    {
    case 1 :
        {

            for( i = 0 ; i < SIZE && ok == 0; i++ ) {
                if((st[i].ph.miligrams == (med_ptr + j) -> q.miligrams) && ((st[i].ph.quant) * (st[i].ph.nr_product) >= (med_ptr + j) -> q.nr_pills))
                {
                    if( strnicmp(st[i].name, (med_ptr + j) -> name, strlen((med_ptr + j) -> name)) == 0)
                    {
                        ok = 1;
                        printf("\nThis is the product: \nName: %s \nMiligrams: %.2f\nIn stock: %d\nQuantity of product(grams/milliliters/pills): %d\nType: %s\nPrice: %.2f\n\n",  st[i].name, st[i].ph.miligrams, st[i].ph.nr_product , st[i].ph.quant ,st[i].type, st[i].price );
                        printf("\nDo you want to add it to cart?\nEnter 1 for YES\nEnter 2 for NO.");
                        scanf("%d", &optt);
                        if( optt == 1 )
                        {
                            k = 0;
                            (med_ptr + j) -> q.nr_product = 0;
                            while(k <= (med_ptr + j) -> q.nr_pills)
                            {
                                k += st[i].ph.quant;
                                ((med_ptr + j) -> q.nr_product)++;
                            }
                            add_cart(i, j);
                        }

                    }
                }
            }
            if( ok == 0 ) printf("Sorry. We don't have what you need.\n\n");

        } break;
    case 2 :
        {
            for( i = 0 ; i < SIZE && ok == 0; i++ ) {
                if((st[i].ph.quant) * (st[i].ph.nr_product) >= (med_ptr + j) -> q.nr_pills)
                {
                    if( strnicmp(st[i].name, (med_ptr + j) -> name, strlen((med_ptr + j) -> name)) == 0)
                    {
                        ok = 1;
                        printf("\nThis is the product: \nName: %s \nMiligrams: %.2f\nIn stock: %d\nQuantity of product(grams/milliliters/pills): %d\nType: %s\nPrice: %.2f\n\n",  st[i].name, st[i].ph.miligrams, st[i].ph.nr_product , st[i].ph.quant ,st[i].type, st[i].price );
                        printf("\nDo you want to add it to cart?\nEnter 1 for YES\nEnter 2 for NO.");
                        scanf("%d", &optt);
                        if( optt == 1 )
                        {
                            k = 0;
                            (med_ptr + j) -> q.nr_product = 0;
                            while(k <= (med_ptr + j) -> q.nr_pills)
                            {
                                k += st[i].ph.quant;
                                ((med_ptr + j) -> q.nr_product)++;
                            }
                            add_cart(i, j);
                        }
                    }
                }
            }
            if( ok == 0 ) printf("Sorry. We don't have what you need.\n\n");
        } break;
    case 3:
        {
            for( i = 0 ; i < SIZE ; i++ ) {
                if(st[i].ph.nr_product >= (med_ptr + j) -> q.nr_product)
                {
                    if( strnicmp(st[i].name, (med_ptr + j) -> name, strlen((med_ptr + j) -> name)) == 0)
                    {
                        ok = 1;
                        printf("\nThis is the product: \nName: %s \nMiligrams: %.2f\nIn stock: %d\nQuantity of product(grams/milliliters/pills): %d\nType: %s\nPrice: %.2f\n\n",  st[i].name, st[i].ph.miligrams, st[i].ph.nr_product , st[i].ph.quant ,st[i].type, st[i].price );
                        printf("\nDo you want to add it to cart?\nEnter 1 for YES\nEnter 2 for NO.");
                        scanf("%d", &optt);
                        if( optt == 1 )
                            add_cart(i, j);
                    }
                }
            }
            if( ok == 0 ) printf("Sorry. We don't have what you need.\n\n");
        } break;

    }
    return 0;
}


/****************************************************************************************************/
/* AUTHOR: MURESAN EMMA SIMINA                                                                      */
/* FUNCTION NAME: insert_quick_list                                                                 */
/* DESCRIPTION: The client insert the number of medicine he wants, then he enteres each one of them.*/
/* In the case 1: he has the name of the medicine, the miligrams, and the number of products.       */
/* In the case 2: he has only the name and the number of products he needs.                         */
/* Argument     Type     IO    Descrpition                                                          */
/* ------------ -------- -- ------------------------------------------------------------------------*/
/* RETURN VALUE: void                                                                               */
/* CHANGES: -                                                                                       */
/****************************************************************************************************/


void insert_quick_list()
{
    char option[4] = {'\n'};
    int i = 0, number = 0 ,opt = 0 , ok = 0;
    printf("\nPlease insert the number of medicine you need: ");
    scanf("%d", &number);

    med_ptr = (struct medicine*) malloc( number * sizeof(struct medicine));

    printf("Optional, if you know the quantity in miligrams, you can insert it.\n\n");

    for( i = 0 ; i < number ; i++ ) {
        printf("\nEnter the name of the %d medicine\n", i+1 );
        scanf("%s", (med_ptr + i) -> name);
        printf("Do you have the quantity in miligrams? \n");
        ok = 0;
        while( ok == 0 )
        {
            printf("Enter YES/NO.\n");
            scanf("%s", option);
            if(strcmp(option , "YES") == 0) opt = 1;
            if(strcmp(option , "NO") == 0) opt = 2;
            switch (opt)
            {
            case 1:
                {
                    printf("Please enter the quantity in miligrams.\n");
                    scanf("%f", &(med_ptr + i) -> q.miligrams);
                    printf("Now enter the number of products you need.\n");
                    scanf("%d", &(med_ptr + i) -> q.nr_product);
                    ok = 1;
                    search_ql( i , 1 );
                } break;
            case 2:
                {
                    printf("Now enter the number of products you need.\n");
                    scanf("%d", &(med_ptr + i) -> q.nr_product);
                    ok = 1;
                    search_ql( i, 2 );
                } break;
            default : printf("You entered an invalid option. Please reapeat!\n\n");
            }
        }
    }
    return 0;
}


/*****************************************************************************************************************/
/* AUTHOR: MURESAN EMMA SIMINA                                                                                   */
/* FUNCTION NAME: insert_list_prescription                                                                       */
/* DESCRIPTION: The client insert the number of medicine he needs, then he enteres each one of them.             */
/* In the case 1: he has the name of the medicine, the miligrams, the number of pills/day and the number of days.*/
/* In the case 2: he has only the name and the number of pills/day and the number of days.                       */
/* In the case 3: he has only the number of tubes/boxes                                                          */
/* Argument     Type     IO    Descrpition                                                                       */
/* ------------ -------- -- -------------------------------------------------------------------------------------*/
/* RETURN VALUE: void                                                                                            */
/* CHANGES: -                                                                                                    */
/*****************************************************************************************************************/


void insert_list_prescription()
{
    int i = 0, number = 0, option = 0, days = 0, pills = 0, ok = 0;

    printf("\nPlease insert the number of medicine you need: ");
    scanf("%d", &number);

    med_ptr = (struct medicine*) malloc( number * sizeof(struct medicine));

    printf("\nNext you have to enter your medicine.\nYou should have the quantity in miligrams after each medicine.\n");
    printf("If you don't have this quantity it means that the medicine is only of one type.\n");
    printf("If you don't have the quantity in miligrams, you can write the number of pills/day you have to take and the number of days.\n");
    printf("If you don't have any of those, you can enter the number of tubes or boxes you need.\n\n");

    for( i = 0 ; i < number ; i++ ) {
        printf("\nEnter the name of the %d medicine: \n", i+1 );
        scanf("%s", (med_ptr + i) -> name);

        printf("Enter 1 if you have the quantity in miligrams and the number of pills/day.\nEnter 2 if you have only the number of pills/day.\nEnter 3 if you have only the number of products.\n");
        scanf("%d", &option);

        ok = 0;
        while(ok == 0)
        {
                switch (option)
            {
            case 1:
                {
                    ok = 1;
                    printf("\nThe quantity in miligrams is: \n");
                    scanf("%f", &(med_ptr + i) -> q.miligrams);

                    printf("The number of days you have to take this medicine is:\n");
                    scanf("%d", &days);

                    printf("And the number of pills/day is:\n");
                    scanf("%d", &pills);

                    (med_ptr + i) -> q.nr_pills = days * pills;
                    search_p( i , 1 );

                } break;
            case 2:
                {
                    ok = 1;
                    printf("\nThe number of days you have to take this medicine is:\n");
                    scanf("%d", &days);

                    printf("And the number of pills/day is:\n");
                    scanf("%d", &pills);

                    (med_ptr + i) -> q.nr_pills = days * pills;
                    search_p( i , 2 );
                } break;
            case 3:
                {
                    ok = 1;
                    printf("\nEnter the number of tubes or boxes:\n");
                    scanf("%d", &(med_ptr + i) -> q.nr_product);
                    search_p( i , 3 );
                } break;
            default : printf("\nYou entered an invalid number. Enter again the correct option.\n");
            }
        }
    }
    return 0;
}

