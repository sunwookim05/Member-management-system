#include "main.h"

#pragma once
#ifndef __User_H
#define __User_H

typedef struct __USERDATA__{
    String id;
    String password;
}USERDATA;

typedef struct __USERS__{
    boolean (*signup)(USERDATA *, FILE *);
    boolean (*login)(USERDATA *, FILE *);
}USERS;

USERS new_User();
USERDATA new_UserData();
void delete_UserData(USERDATA *);

#pragma warning(pop)
#endif