#include "User.h"
#include "System.h"
#include "Scanner.h"

import SYSTEM System;


void delete_UserData(USERDATA *info){
    free(info->id);
    free(info->password);
}

boolean signup(USERDATA *info, FILE *fp){
    Scanner sc = new_Scanner(System.in);
    fp = fopen("user.txt", "r");
    System.out.println("Sign up");
    System.out.print("ID: ");
    info->id = sc.next();
    System.out.print("Password: ");
    info->password = sc.next();

    USERDATA user = new_UserData();
    while (fscanf(fp, "%s", user.id) != EOF){
        if(!strcmp(info->id, user.id)){
            delete_UserData(&user);
            return false;
        }
    }
    delete_UserData(&user);
    fclose(fp);

    fp = fopen("user.txt", "a");
    fprintf(fp, "%s %s\n", info->id, info->password);
    fclose(fp);
    return true;
}

boolean login(USERDATA *user, FILE *fp){
    Scanner sc = new_Scanner(System.in);
    fp = fopen("user.txt", "r");
    System.out.println("Login");
    System.out.print("ID: ");
    user->id = sc.next();
    System.out.print("Password: ");
    user->password = sc.next();
    
    USERDATA info = new_UserData();
    
    while (fscanf(fp, "%s %s", info.id, info.password) != EOF){
        if(!strcmp(user->id, info.id) && !strcmp(user->password, info.password)){
            delete_UserData(&info);
            fclose(fp);
            return true;
        }
    }
    fclose(fp);
    delete_UserData(&info);
    return false;
}

boolean logout(USERDATA *info){
    Scanner sc = new_Scanner(System.in);
    System.out.print("Do you want to logout? (y/n): ");
    char bf = sc.nextChar();
    if(bf == 'y' | 'Y'){
        info->id = NULL;
        info->password = NULL;
        delete_UserData(info);
        System.out.println("Logout success");
        return true;
    }else{
        System.out.println("Logout failed");
        return false;
    }
}

USERS new_User(){
    USERS user;
    user.logout = logout;
    user.signup = signup;
    user.login = login;
    return user;
}

USERDATA new_UserData(){
    USERDATA info;
    info.id = (String)calloc(0, sizeof(char) * 20);
    info.password = (String)calloc(0, sizeof(char) * 20);
    return info;
}