#include "main.h"
#include "System.h"
#include "Scanner.h"
#include "User.h"

import SYSTEM System;

int main(void){
    Scanner sc = new_Scanner(System.in);
    USERS users = new_User();
    USERDATA user = new_UserData();
    FILE *fp;
    boolean isSignup = false;
    boolean isLogin = false;
    uint8_t menu = 0;

    while (true){
        System.out.print("Select menu\n1. Sign up\n2. Login\n3. Logout\n");
        menu = sc.nextByte();

        if(menu == 1){
            isSignup = users.signup(&user, fp);
            System.out.println(isSignup ? "Sign up success" : "Sign up failed");
        }else if(menu == 2){
            isLogin = users.login(&user, fp);
            System.out.println(isLogin ? "Login success" : "Login failed");
        }else if(menu == 3){
            break;
        }    
    }

    delete_UserData(&user);
    return 0;
}