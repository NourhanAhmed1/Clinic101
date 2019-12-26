#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LBTY.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "CLINIC_privt.h"
#include "CLINIC_int.h"
#include "CLINIC_config.h"

int main()
{
    Error_Status Error1, Error2, Error3, Error4, Error5 ,Error6;
    u8 u8_choice, u8_gender;
    u8* u8_name[50];
    u16 u16_age , u16_rec_num;
    f32 f32_time;
	while(1)
	{
		printf("\n1.Create New Record\n");
		printf("2.Edit Record\n");
		printf("3.Add Reservation\n");
		printf("4.Delete Reservation\n");
		printf("5.Display All Records\n");
		printf("6.Display All Reservations\n");
		printf("7.Quit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&u8_choice);

		switch(u8_choice)
		{
		 case 1:
			printf("\nEnter the patient's name : ");
			fgets(u8_name, sizeof(u8_name), stdin);
            printf("\nEnter the patient's age : ");
            scanf("%d" , &u16_age);
            printf("\nEnter the patient's gender : ");
            scanf("%c" , &u8_gender);
            printf("\nEnter the patient's record number : ");
            scanf("%d" , &u16_rec_num);
			Error1 = CLINIC_enuNewRecord(u8_name ,u16_age ,u8_gender ,u16_rec_num);
			if(Error1 == LBTY_OK) printf("\n New Record was added successfully\n");
			else printf("\n New Record couldn't be added please try again\n");
			break;
		 case 2:
			printf("\nEnter the patient's name to edit : ");
			fgets(u8_name, sizeof(u8_name), stdin);
            printf("\nEnter the edited age : ");
            scanf("%d" , &u16_age);
            printf("\nEnter the edited gender : ");
            scanf("%c" , &u8_gender);
            printf("\nEnter the edited record number : ");
            scanf("%d" , &u16_rec_num);
			Error2 = CLINIC_enuEditRecord(u8_name ,u16_age ,u8_gender ,u16_rec_num);
			if(Error2 == LBTY_OK) printf("\n Record was edited successfully\n");
			else printf("\nPatient not found\n");
			break;
		 case 3:
            printf("\nEnter the patient's name to make reservation : ");
			fgets(u8_name, sizeof(u8_name), stdin);
            printf("\nEnter the appointment time(choose 2.00 , 2:30 , 3.00 ,3.30 , 4.00 , 4.30, 5.00): ");
            scanf("%d" , &f32_time);
			Error3 = CLINIC_enuNewReservation(u8_name , f32_time);
			if(Error3 == LBTY_NOT_OK) printf("\nThe time you entered is not available\n");
			else printf("\nReservation was added successfully\n");
			break;
		 case 4:
			printf("\nEnter the patient's name to remove reservation : ");
			fgets(u8_name, sizeof(u8_name), stdin);
			Error4 = CLINIC_enuRemoveReservation(u8_name);
			if(Error4 == LBTY_NULL_POINTER) printf("\nNo Reservations\n");
			else if(Error4 == LBTY_NOT_OK) printf("\nReservation not found\n");
			else printf("\nReservation was removed successfully \n");
			break;

         case 5:
            Error5 = CLINIC_enuDisplayRecords();
            if(Error5 == LBTY_NOT_OK) printf("\nNo Records to print\n");
         case 6 :
            Error6 = CLINIC_enuDisplayReservation();
            if(Error6 == LBTY_NOT_OK) printf("\nNo Reservations to print\n");
		 case 7:
			exit(1);
		 default:
			printf("\nWrong choice\n");
		}/*End of switch*/
	}//end of while

    return 0;
}
