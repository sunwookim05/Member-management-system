#include "main.h"

#pragma once
#ifndef __User_H
#define __User_H

typedef struct __USERDATA__{
    String id;
    String password;
}USERDATA;

typedef struct __USERS__{
    void (*writeLog)(uint8_t, USERDATA, FILE *);
    boolean (*logout)(USERDATA *);
    boolean (*signup)(USERDATA *, FILE *);
    boolean (*login)(USERDATA *, FILE *);
}USERS;

typedef enum __MENU__{
    SIGNUP = 1, LOGIN, LOGOUT, USERINFO,  EXIT
}__MENU__;

typedef uint8_t MENU;

USERS new_User();
USERDATA new_UserData();
void delete_UserData(USERDATA *);

#pragma warning(pop)
#endif