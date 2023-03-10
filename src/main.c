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
    boolean isLogout = true;
    MENU menu = 0;

    while (true){
        System.out.print("Select menu\n1. Sign up\n2. Login\n3. Logout\n4. LOGININFO\n5. EXIT\n");
        menu = sc.nextUByte();
        if(menu == SIGNUP){
            isSignup = users.signup(&user, fp);
            System.out.println(isSignup ? "Sign up success" : "Sign up failed");
            if (isSignup) users.writeLog(SIGNUP, user, fp);
        }else if(menu == LOGIN){
            if(isLogin){
                System.out.println("Already login");
            }else{
                isLogin = users.login(&user, fp);
                System.out.println(isLogin ? "Login success" : "Login failed");
                users.writeLog(LOGIN, user, fp);
            }
        }else if(menu == LOGOUT){
            if(!isLogin){
                System.out.println("Already logout");
            }else{
                users.writeLog(LOGOUT, user, fp);
                isLogout = users.logout(&user);
                if(isLogout) isLogin = false;
            }
        }else if(menu == USERINFO){
            if(isLogin) System.out.println("ID: %s\nPassword: %s", user.id, user.password);
            else System.out.println("Please login");
        }else if(menu == EXIT){
            break;
        }else{
            System.out.println("Wrong menu");
        }
    }

    delete_UserData(&user);
    return 0;
}