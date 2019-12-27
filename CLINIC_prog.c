#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LBTY.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "CLINIC_int.h"
#include "CLINIC_privt.h"
#include "CLINIC_config.h"
//write here the initialization of all the functions you used

static f32 times[5] = {2.00 , 2.30 , 3.00, 3.30 , 4.00 , 4.30 , 5.00};// array of times available to reserve
struct new_record* head1 = NULL;
struct new_appointment* head2 = NULL;

Error_Status CLINIC_enuNewRecord(u8* u8_name , u16 u16_age , u8 u8_gendar , u16 u16_recordNumber)
{
    struct new_record* link = (struct new_record*)malloc(sizeof(struct new_record));//create new record
    Error_Status error ;
    struct new_record* current == head1;
    struct new_record* previous == NULL;
    u8 u8_count = 0;
    if(link == NULL) //if memory location couldn't be allocated
    {
        error = LBTY_NULL_POINTER;
    }
    else
    {
            if(head1 == NULL) //if no records
                {
                    link->u8_name[50] = u8_name[50];
                    link->u16_age = u16_age;
                    link->u8_gendar = u8_gendar;
                    link->u16_recordNumber = u16_recordNumber;
                    link ->next = NULL;
                    head1 = link ;
                }
                else
                {
                    while(current->u16_recordNumber != u16_recordNumber) //to search for the record number in the stored records
                    {
                        if(current->next == NULL) //record number wasn't used before
                        {
                          error = LBTY_OK;
                          link->u8_name[50] = u8_name[50];
                          link->u16_age = u16_age;
                          link->u8_gendar = u8_gendar;
                          link->u16_recordNumber = u16_recordNumber;
                          link ->next = head1;
                          head1 = link ;
                          u8_count++;
                        }
                        else
                        {
                            previous = current ;
                            current = current->next;
                        }
                    }

                }
    }
    if(u8_count == 0)
    {
        error = LBTY_NOT_OK;
    }
    return error;
}
Error_Status CLINIC_enuEditRecord(u8* u8_name , u16 u16_age , u8 u8_gendar , u16 u16_recordNumber)
{
    struct new_record* current = head1;
    Error_Status error;
    while(current->u8_name != u8_name)//search for the record
    {
        if(current->next == NULL) //no record has entered name
        {
            error = LBTY_NOT_OK;
        }
        else
        {
            current = current->next;
        }
    }
    if(current->u8_name == u8_name)
    {
        error = LBTY_OK;
        current->u8_name[50] = u8_name[50];
        current->u16_age=u16_age;
        current->u8_gendar = u8_gendar ;
        current->u16_recordNumber= u16_recordNumber;
    }
    return error;
}

Error_Status CLINIC_enuNewReservation(u8* u8_name , f32 f32_time)
{
    struct new_appointment* link = (struct new_appointment*)malloc(sizeof(struct new_appointment));//create new reservation
    Error_Status error;
    u8 u8_count = 0;
    for(int i =0 ; i<5 ; i++)
    {
        if(f32_time == times[i]) //check if time available
        {
            error = LBTY_OK;
            u8_count++;
            for (u8 u8_c = i; u8_c < 5; u8_c++) //remove time from times available
                {
                    times[u8_c] = times[u8_c+1];
                }
            if(head2 == NULL) //if no reservations
            {
                link->u8_name[50] = u8_name[50];
                link->f32_time = f32_time;
                link ->next = NULL;
                head2 = link ;
            }
            else // if there are reservations
            {
                link->u8_name[50] = u8_name[50];
                link->f32_time = f32_time;
                link ->next = head2;
                head2 = link ;
            }
        }
    }
    if(u8_count ==0) //reservation wasn't made
    {
        error = LBTY_NOT_OK;
         //printf("The time you entered is not available");
    }
   return error;
}
Error_Status CLINIC_enuRemoveReservation(u8* u8_name)
{
    Error_Status error;
	int item;
	struct new_appointment *tmp = head2;
    struct new_appointment *previous = NULL;

	if( CLINIC_enuResEmpty()== LBTY_NULL_POINTER ) //if there's no appointments
	{
	    error = LBTY_NULL_POINTER;
	}
	while(tmp->u8_name[50] != u8_name[50]) //search for reservation with the patient's name
    {
        if(tmp->next == NULL) //Reservation not found
        {
            error = LBTY_NOT_OK;
        }
        else
        {
            previous = tmp ;
            tmp = tmp -> next;
        }
    }
	if(u8_name[50] == tmp->u8_name[50] && tmp==head2)  /*If only one reservation*/
	{
	    error = LBTY_OK;
		head2=head2->next;
	}
	else if(u8_name[50] == tmp->u8_name[50] && tmp!=head2) //if there is more than one reservation
	{
	    error = LBTY_OK;
		previous ->next = tmp->next;
	}
	item=tmp->f32_time;
	free(tmp);
	times[4] = item; // add time back to the available times
	u8 u8_temp;
	for(u8 u8_i=0 ; u8_i<5 ; u8_i++) //sort the times available
    {
        for(u8 u8_j=0 ; u8_j<4-u8_i ; u8_j++)
        {
            if(times[u8_j] > times[u8_j+1])
            {
                u8_temp = times[u8_j];
                times[u8_j] = times[u8_j+1];
                times[u8_j+1] = u8_temp;
            }
        }
    }
    return error;
}
Error_Status CLINIC_enuDisplayRecords()
{
    Error_Status error;
	struct new_record *p;
	if(CLINIC_enuRecEmpty()== LBTY_NULL_POINTER)//no records
	{
	    error = LBTY_NOT_OK;
	}
	else
    {
        error = LBTY_OK;
        printf("\nAvailable Records :\n");
	p=head1->next;
	do
	{
	    printf("\nname : ");
        puts(p->u8_name);
		printf("\nage :%d \n gender :%c \n record number :%d \n",p->u8_name[50] , p->u16_age , p->u8_gendar , p->u16_recordNumber);
		p=p->next;
	}while(p!=head1->next);
	printf("\n");
	}
	return error;
}
Error_Status CLINIC_enuDisplayReservation()
{
    Error_Status error;
	struct new_appointment *p;
	if(CLINIC_enuResEmpty()== LBTY_NULL_POINTER) //no reservations
	{
	    error = LBTY_NOT_OK;
	}
	else
    {
      error = LBTY_OK;
      printf("\nReservations :\n");
        p=head2->next;
        do
        {
            printf("\nname : ");
            puts(p->u8_name);
            printf("\ntime : %0.2f\n" , p->f32_time);
            p=p->next;
        }while(p!=head2->next);
        printf("\n");
	}
	return error;
}

Error_Status CLINIC_enuRecEmpty()
{
    Error_Status error;
	if( head1 == NULL )
		error = LBTY_NULL_POINTER; //empty
	else
		error = LBTY_OK; //not empty
}
Error_Status CLINIC_enuResEmpty()
{
    Error_Status error;
	if( head2 == NULL )
		error = LBTY_NULL_POINTER; //empty
	else
		error = LBTY_OK; //not empty
}

