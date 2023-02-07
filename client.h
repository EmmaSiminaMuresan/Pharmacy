/***********************************************************************************************************/
/* client.h - Header file for client options                                                               */
/* Copyright: 2020                                                                                         */
/* License: Technical University of Cluj-Napoca                                                            */
/* Author: Muresan Emma Simina <siminamuresan2002@gmail.com>, Sucala Paula Ilinca <sucala.ilinca@gmail.com>*/
/* Version: 31.12.2020                                                                                     */
/***********************************************************************************************************/

#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED


/* Headers required by the following definitions/declarations: */
#include <stdlib.h>
#include <stdio.h>


/* Global variables declarations: */
int SIZE;
int SIZE_C;
float suma;


/* Used structures */
extern struct address;
extern struct birthday;
extern struct client;


/* Function prototypes: */
extern void choise();
extern void customer_data();
extern void courier();


#endif // CLIENT_H_INCLUDED

