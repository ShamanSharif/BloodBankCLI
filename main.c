#include<stdio.h>
#include <stdlib.h>
#include<string.h>

// Master Admin
// Complete Nurse sub Function
// User List Database :: DONE
// Complete Pathologist Sub Function

void availableBloodIncrement(char bld[]) {
    FILE* file = fopen("availableBlood.txt", "r");
    FILE* fp = fopen("temp.txt", "w");
    char line[256];
    char name[7];
    char blood[4];
    int dbid, bags;

    while(fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %d", &blood, &bags);

        if(strcmp(bld, blood) == 0) fprintf(fp, "%s \t%d\n", blood, ++bags);
        else fprintf(fp, "%s", line);
    }
    fclose(file);
    fclose(fp);

    file = fopen("availableBlood.txt", "w");
    fp = fopen("temp.txt", "r");

    while(fgets(line, sizeof(line), fp)) {
        fprintf(file, "%s", line);
    }

    fclose(file);
    fclose(fp);
}

void totalDonationIncrement(int id, int bag) {
    FILE* file = fopen("userdata.txt", "r");
    FILE* fp = fopen("temp.txt", "w");
    char line[256];
    char name[7];
    char blood[4];
    int dbid, bags;

    while(fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %d %s %d", &name, &dbid, &blood, &bags);

        if(id == dbid) {
            bags = bags + bag;
            fprintf(fp, "%s \t%d \t%s \t%d\n", name, id, blood, bags);
        }
        else
            fprintf(fp, "%s", line);
    }
    fclose(file);
    fclose(fp);

    file = fopen("userdata.txt", "w");
    fp = fopen("temp.txt", "r");

    while(fgets(line, sizeof(line), fp)) {
        fprintf(file, "%s", line);
    }
    fclose(file);
    fclose(fp);
}

int usrIdDuplicate(int id) {
    char name[7];
    char blood[4];
    int dbid, bags;
    FILE* file = fopen("userdata.txt", "r");
    char line[256];
    int status = 1;

    while(fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %d %s %d", &name, &dbid, &blood, &bags);
        if (id == dbid) status = 0;
    }
    fclose(file);

    return status;
}

void userDatabase() {
    FILE* file = fopen("userdata.txt", "r");
    char line[256];

    while(fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// void addAvailableBlood(int bags, char blood[4]) {
//     char dbblood[4];
//     int dbbags;
//     int ap = 0, an = 0, bp = 0, bn = 0, abp = 0, abn = 0, op = 0, on = 0;
//     char apos[4] = "A+";
//     char aneg[4] = "A-";
//     char bpos[4] = "B+";
//     char bneg[4] = "B-";
//     char abpos[4] = "AB+";
//     char abneg[4] = "AB-";
//     char opos[4] = "O+";
//     char oneg[4] = "O-";
//     FILE* file = fopen("availableBlood.txt", "r");
//     char line[256];

//     while(fgets(line, sizeof(line), file)) {
//         sscanf(line,"%s %d", &dbblood, &dbbags);
//         printf("%s", line);
//     }
//     fclose(file);
// }

void addBlood() {
    // system("clear"); // system("cls") in windows
    char name[7];
    char blood[4];
    int id, bags;


    printf("Enter Name (Must be in range 1 to 6, without space): ");
    scanf("%s", &name);
    printf("Enter Blood Group: ");
    scanf("%s", &blood);
    printf("Enter Id (Must be in range 1001 to 9999): ");
    scanf("%d", &id);
    printf("Enter Bag: ");
    scanf("%d", &bags);


    if(id > 10000 && bloodGroupValidation(blood) && usrIdDuplicate(id)) {
        FILE* file = fopen("userdata.txt", "a");
        fprintf(file, "%s \t%d \t%s \t%d\n", name, id, blood, bags);
        printf("Successfully Added Blood\n");
        fclose(file);
        availableBloodIncrement(blood);
    } else if(id > 10000 && bloodGroupValidation(blood) && !usrIdDuplicate(id)) {
        totalDonationIncrement(id, bags);
        printf("Successfully Added Blood\n");
        availableBloodIncrement(blood);
    } else {
        printf("Something Went Wrong. Check Your Form Again.\n");
        addBlood();
    }
}

void bloodBank() {
    // int bags;
    // char blood[4];
    // int ap = 0, an = 0, bp = 0, bn = 0, abp = 0, abn = 0, op = 0, on = 0;
    // char apos[4] = "A+";
    // char aneg[4] = "A-";
    // char bpos[4] = "B+";
    // char bneg[4] = "B-";
    // char abpos[4] = "AB+";
    // char abneg[4] = "AB-";
    // char opos[4] = "O+";
    // char oneg[4] = "O-";
    FILE* file = fopen("availableBlood.txt", "r");
    char line[256];

    while(fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void widrawBlood() {
    int bag;
    char bld[4];
    printf("Which Group: ");
    scanf("%s", bld);
    printf("How many bags: ");
    scanf("%d", &bag);

    FILE* file = fopen("availableBlood.txt", "r");
    FILE* fp = fopen("temp.txt", "w");
    char line[256];
    char blood[4];
    int bags;

    while(fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %d", &blood, &bags);

        if(strcmp(bld, blood) == 0) {
            bags = bags - bag;
            fprintf(fp, "%s \t%d\n", blood, bags);
        }
        else fprintf(fp, "%s", line);
    }
    fclose(file);
    fclose(fp);

    file = fopen("availableBlood.txt", "w");
    fp = fopen("temp.txt", "r");

    while(fgets(line, sizeof(line), fp)) {
        fprintf(file, "%s", line);
    }

    fclose(file);
    fclose(fp);

    printf("Widrawn Completed\n");
}

void listDonators() {
    FILE* file = fopen("userdata.txt", "r");
    char line[256];

    while(fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

int idCheck(int id) {
    printf("Yet to be varified\n");
    int dbid, dbpn;
    char name[7];
    char blood[4];
    FILE* file = fopen("database.txt", "r");
    char line[256];

    printf("ID \tPIN \tNAME \tBlood Group\n");
    printf("----------------------------------------------\n");
    while(fgets(line, sizeof(line), file)) {
        sscanf(line,"%d %d %s %s", &dbid, &dbpn, &name, &blood);
        if(id == dbid) {
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return 1;
}

void nurse(int id, char name[7], char blood[4]) {
    system("clear"); // system("cls") in windows
    int choice;
    char ch;
    printf("Welcome %s\n", name);
    printf("================================\n");
    printf("Enter 1 to add Blood to BloodBank \nEnter 2 to Use Blood from BloodBank \nEnter 3 to List all Donators \nEnter 4 to Check Still to Varified List \nEnter 5 to Check Blood Bank \nEnter 6 for Logout \n\n\n%s@bloodBank:~$ ", name);
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("One\n");
            system("clear"); // system("cls") in windows
            addBlood();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            nurse(id, name, blood);
            break;
        case 2:
            printf("Two\n");
            system("clear"); // system("cls") in windows
            widrawBlood();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            nurse(id, name, blood);
            break;
        case 3:
            printf("Three\n");
            system("clear"); // system("cls") in windows
            listDonators();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            nurse(id, name, blood);
            break;
        case 4:
            printf("Four\n");
            system("clear"); // system("cls") in windows
            //varificationList();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            nurse(id, name, blood);
            break;
        case 5:
            printf("Four\n");
            system("clear"); // system("cls") in windows
            bloodBank();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            nurse(id, name, blood);
            break;
        case 6:
            printf("Six\n");
            system("clear"); // system("cls") in windows
            printf("You are successfully logged out\n");
            login();
            break;
        default:
            printf("Incorrect Input\n");
            // printf("Enter C to continue ...\n");
            // scanf(" %c", &ch);
            // admin(id, name, blood);
            nurse(id, name[7], blood[4]);
            break;
    }
}

void pathologist(int id, char name[7], char blood[4]) {
    system("clear"); // system("cls") in windows
    int choice;
    char ch;
    printf("Welcome %s\n", name);
    printf("================================\n");
    printf("Enter 1 to list Unvarified Bloods \nEnter 2 to Check Blood Bank \nEnter 3 to Add Pathologist \nEnter 4 to Add Nurse \nEnter 5 for Logout \n\n\n%s@bloodBank:~$ ", name);
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("One\n");
            system("clear"); // system("cls") in windows
            // listAllPathologist();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            pathologist(id, name, blood);
            break;
        case 2:
            printf("Two\n");
            system("clear"); // system("cls") in windows
            // listAllNurse();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            pathologist(id, name, blood);
            break;
        case 3:
            printf("Three\n");
            system("clear"); // system("cls") in windows
            // addPathologist();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            pathologist(id, name, blood);
            break;
        case 4:
            printf("Four\n");
            system("clear"); // system("cls") in windows
            // addNurse();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            pathologist(id, name, blood);
            break;
        case 5:
            printf("Five\n");
            system("clear"); // system("cls") in windows
            printf("You are successfully logged out\n");
            login();
            break;
        default:
            printf("Incorrect Input\n");
            // printf("Enter C to continue ...\n");
            // scanf(" %c", &ch);
            // admin(id, name, blood);
            pathologist(id, name[7], blood[4]);
            break;
    }
}



int bloodGroupValidation(char blood[4]) {
    char apos[4] = "A+";
    char aneg[4] = "A-";
    char bpos[4] = "B+";
    char bneg[4] = "B-";
    char abpos[4] = "AB+";
    char abneg[4] = "AB-";
    char opos[4] = "O+";
    char oneg[4] = "O-";
    if (strcasecmp(blood, apos) == 0) {
        return 1;
    } else if (strcasecmp(blood, aneg) == 0) {
        return 1;
    } else if (strcasecmp(blood, bpos) == 0) {
        return 1;
    } else if (strcasecmp(blood, bneg) == 0) {
        return 1;
    } else if (strcasecmp(blood, abpos) == 0) {
        return 1;
    } else if (strcasecmp(blood, abneg) == 0) {
        return 1;
    } else if (strcasecmp(blood, opos) == 0) {
        return 1;
    } else if (strcasecmp(blood, oneg) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void addNurse() {
    // system("clear"); // system("cls") in windows
    int id, pin;
    char name[7];
    char blood[4];
    FILE* file = fopen("database.txt", "a");

    printf("Enter Id (Must be in range 1001 to 9999): ");
    scanf("%d", &id);
    printf("Enter Pin (Must Contain 4 DIGIT): ");
    scanf("%d", &pin);
    printf("Enter Name (Must be in range 1 to 6, without space): ");
    scanf("%s", &name);
    printf("Enter Blood Group: ");
    scanf("%s", &blood);
    if(idCheck(id) && id > 1000 && id < 10000 && pin > 999 && pin < 10000 && bloodGroupValidation(blood)) {
        fprintf(file, "%d \t%d \t%s \t\t%s\n", id, pin, name, blood);
        printf("Successfully Created Nurse\n");
        fclose(file);
    } else {
        printf("Something Went Wrong. Check Your Form Again.\n");
        fclose(file);
        addNurse();
    }
}

void addPathologist() {
    // system("clear"); // system("cls") in windows
    int id, pin;
    char name[7];
    char blood[4];
    FILE* file = fopen("database.txt", "a");

    printf("Enter Id (Must be in range 101 to 999): ");
    scanf("%d", &id);
    printf("Enter Pin (Must Contain 4 DIGIT): ");
    scanf("%d", &pin);
    printf("Enter Name (Must be in range 1 to 6, without space): ");
    scanf("%s", &name);
    printf("Enter Blood Group: ");
    scanf("%s", &blood);
    if(id > 100 && id < 1000 && pin > 999 && pin < 10000 && bloodGroupValidation(blood)) {
        fprintf(file, "%d \t%d \t%s \t\t%s\n", id, pin, name, blood);
        printf("Successfully Created Pathologist\n");
        fclose(file);
    } else {
        printf("Something Went Wrong. Check Your Form Again.\n");
        fclose(file);
        addPathologist();
    }
}

void listAllNurse() {
    // system("clear"); // system("cls") in windows
    int dbid, dbpn;
    char name[7];
    char blood[4];
    FILE* file = fopen("database.txt", "r");
    char line[256];

    printf("ID \tPIN \tNAME \tBlood Group\n");
    printf("----------------------------------------------\n");
    while(fgets(line, sizeof(line), file)) {
        sscanf(line,"%d %d %s %s", &dbid, &dbpn, &name, &blood);
        if(dbid > 1000) {
            printf("%s", line);
        }
    }
}

void listAllPathologist() {
    // system("clear"); // system("cls") in windows
    int dbid, dbpn;
    char name[7];
    char blood[4];
    FILE* file = fopen("database.txt", "r");
    char line[256];

    printf("ID \tPIN \tNAME \tBlood Group\n");
    printf("----------------------------------------------\n");
    while(fgets(line, sizeof(line), file)) {
        sscanf(line,"%d %d %s %s", &dbid, &dbpn, &name, &blood);
        if(dbid > 100 && dbid < 1000) {
            printf("%s", line);
        }
    }
}

void admin(int id, char name[7], char blood[4]) {
    system("clear"); // system("cls") in windows
    int choice;
    char ch;
    printf("Welcome %s\n", name);
    printf("================================\n");
    printf("Enter 1 to list all Pathologist \nEnter 2 to list all Nurse \nEnter 3 to Add Pathologist \nEnter 4 to Add Nurse \nEnter 5 for Logout \n\n\n%s@bloodBank:~$ ", name);
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("One\n");
            system("clear"); // system("cls") in windows
            listAllPathologist();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            admin(id, name, blood);
            break;
        case 2:
            printf("Two\n");
            system("clear"); // system("cls") in windows
            listAllNurse();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            admin(id, name, blood);
            break;
        case 3:
            printf("Three\n");
            system("clear"); // system("cls") in windows
            addPathologist();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            admin(id, name, blood);
            break;
        case 4:
            printf("Four\n");
            system("clear"); // system("cls") in windows
            addNurse();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            admin(id, name, blood);
            break;
        case 5:
            printf("Five\n");
            system("clear"); // system("cls") in windows
            printf("You are successfully logged out\n");
            login();
            break;
        default:
            printf("Incorrect Input\n");
            admin(id, name[7], blood[4]);
            break;
    }
}

void checkType(int id, char name[7], char blood[4]) {
    if (id < 100) {
        admin(id, name, blood);
    }
    else if (id < 1000) {
        pathologist(id, name, blood);
    }
    else if (id > 1000) {
        nurse(id, name, blood);
    }
}

void checkLogin(int id, int pin) {
    int dbid, dbpn, loginStatus = 0;
    char name[7];
    char blood[4];
    FILE* file = fopen("database.txt", "r");
    char line[256];

    while(fgets(line, sizeof(line), file)) {
        sscanf(line,"%d %d %s %s", &dbid, &dbpn, &name, &blood);
        if(id == dbid && pin == dbpn) {
            printf("Login Successful\n");
            fclose(file);
            checkType(dbid, name, blood);
            loginStatus = 1;
        }
    }

    if(!loginStatus) {
        printf("Unauthorised access\n");
        fclose(file);
        login();
    }
}

void login() {
    // system("clear"); // system("cls") in windows
    int id, pin;
    printf("Enter ID (Or -1 to Exit): ");
    scanf("%d", &id);
    if(id == -1) goodbye();
    printf("Enter Pin: ");
    scanf("%d", &pin);
    checkLogin(id, pin);
}

void goodbye() {
    system("clear"); // system("cls") on Windows or DOS
    char ch;
    printf("Thank You Using Our Service.\n");
    printf("Enter Q for exit: ");
    scanf(" %c", ch);
    system("clear");
    exit(0);
}

int main() {
    system("clear"); // system("cls") in windows
    int a;

    printf("Welcome to Blood Bank Management System.\n");
    printf("Created By The Student Of Northern University\n");

    printf("Enter '1' to login: ");
    scanf("%d", &a);
    if(a == 1) {
        system("clear"); // system("cls") in windows
        login();
    }
    return 0;
}
