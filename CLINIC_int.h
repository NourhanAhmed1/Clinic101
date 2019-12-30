#ifndef CLINIC_int
#define CLINIC_int
//here is the declaration of all the functions used


Error_Status CLINIC_enuNewRecord(char* u8_name ,  u16_age , u8 u8_gender , u16 u16_recordNumber);//function to create new patient record
Error_Status CLINIC_enuEditRecord(char* u8_name , u16 u16_age , u8 u8_gender , u16 u16_recordNumber);//Function to edit the patient's record
Error_Status CLINIC_enuNewReservation(char* u8_name , f32 f32_time);//function to create new reservation
Error_Status CLINIC_enuRemoveReservation(char* u8_name);//Function to remove a reservation
Error_Status CLINIC_enuDisplayRecords();//function to display the records of the patients
Error_Status CLINIC_enuDisplayReservation();//function to display the reservations
Error_Status CLINIC_enuRecEmpty();//Function to check if there's any records
Error_Status CLINIC_enuResEmpty();//Function to check if there's any reservations


#endif // CLINIC_int
