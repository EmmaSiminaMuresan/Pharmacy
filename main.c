/***********************************************************************************************************/
/* Complex application                                                                                     */
/* Copyright: 2020                                                                                         */
/* License: Technical University of Cluj-Napoca                                                            */
/* Author: Muresan Emma Simina <siminamuresan2002@gmail.com>, Sucala Paula Ilinca <sucala.ilinca@gmail.com>*/
/* Version: 31.12.2020                                                                                     */
/***********************************************************************************************************/


/* Include standard headers: */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


/* Include modules header that are directly invoked:  */
#include "cart.h"
#include "client.h"
#include "medicine.h"
#include "pharmacy.h"


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


int main()
{
    FILE *fptr, *f_ptr;

    /* Open the files */
    f_ptr = fopen("cart_client.txt","r");
    fptr = fopen("pharmacy_stock.txt","a+b");

    /* Read the pharmacy stock*/
    read(fptr);

    printf("Hello! Welcome to our farmacy!\n\n");

    client_employee();

    return 0;
}
