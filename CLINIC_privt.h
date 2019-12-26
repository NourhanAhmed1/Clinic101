#ifndef CLINIC_privt
#define CLINIC_privt

struct new_record
{
    u8 u8_name[50] ;
    u16 u16_age ;
    u8 u8_gendar ;
    u16 u16_recordNumber ;
    struct new_record* next;
};

struct new_appointment
{
     u8 u8_name[50] ;
     f32 f32_time;
     struct new_appointment* next;
};
#endif // CLINIC_privt
