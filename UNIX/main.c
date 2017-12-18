#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */

// Master Admin

void admin();
void pathologist();
void nurse();

void goodbye();
void login();
void checkLogin();
void checkType();
int bloodGroupValidation();
int idCheck();
void addAdmin();

void listAllPathologist();
void listAllNurse();
void addPathologist();
void addNurse();

void addToVerificationList();
void listDonators();
void widrawBlood();
void bloodBank();
void bloodBankQueue();

void varifyBlood();

void userDatabase();
int usrIdDuplicate();

void totalDonationIncrement();
void totalVarificationIncrement();

int main() {
    system("clear"); // system("cls") in windows
    int a;

    // ART

    printf(RED "██████╗ ██╗      ██████╗  ██████╗ ██████╗     ██████╗  █████╗ ███╗   ██╗██╗  ██╗  \n" RESET );
    printf(RED "██╔══██╗██║     ██╔═══██╗██╔═══██╗██╔══██╗    ██╔══██╗██╔══██╗████╗  ██║██║ ██╔╝   \n" RESET );
    printf(RED "██████╔╝██║     ██║   ██║██║   ██║██║  ██║    ██████╔╝███████║██╔██╗ ██║█████╔╝    \n" RESET );
    printf(RED "██╔══██╗██║     ██║   ██║██║   ██║██║  ██║    ██╔══██╗██╔══██║██║╚██╗██║██╔═██╗    \n" RESET );
    printf(RED "██████╔╝███████╗╚██████╔╝╚██████╔╝██████╔╝    ██████╔╝██║  ██║██║ ╚████║██║  ██╗   \n" RESET );
    printf(RED "╚═════╝ ╚══════╝ ╚═════╝  ╚═════╝ ╚═════╝     ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝    \n" RESET );
    printf("\n");
    printf("\n");

    // ART

    printf("Welcome to Blood Bank Management System.\n");
    printf("Created By The Student Of");
    printf(RED " Northern University\n" RESET);

    printf("Enter '1' to login: ");
    scanf("%d", &a);
    if(a == 1) {
        system("clear"); // system("cls") in windows
        login();
    }
    return 0;
}


// Main Function Section, MASTER ADMIN, ADMIN, NURSE, PATHOLOGIST..

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
            system("clear"); // system("cls") in windows
            listAllPathologist();
            printf("\n\nEnter C to continue ...\n");
            scanf(" %c", &ch);
            admin(id, name, blood);
            break;
        case 2:
            system("clear"); // system("cls") in windows
            listAllNurse();
            printf("\n\nEnter C to continue ...\n");
            scanf(" %c", &ch);
            admin(id, name, blood);
            break;
        case 3:
            system("clear"); // system("cls") in windows
            addPathologist();
            sleep(1);
            admin(id, name, blood);
            break;
        case 4:
            system("clear"); // system("cls") in windows
            addNurse();
            sleep(1);
            admin(id, name, blood);
            break;
        case 5:
            system("clear"); // system("cls") in windows
            printf("You are successfully logged out\n\n");
            login();
            break;
        default:
            printf(RED "Incorrect Input\n" RESET);
            sleep(1);
            admin(id, name, blood);
            break;
    }
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
            system("clear"); // system("cls") in windows
            addToVerificationList();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            nurse(id, name, blood);
            break;
        case 2:
            system("clear"); // system("cls") in windows
            widrawBlood();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            nurse(id, name, blood);
            break;
        case 3:
            system("clear"); // system("cls") in windows
            listDonators();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            nurse(id, name, blood);
            break;
        case 4:
            system("clear"); // system("cls") in windows
            bloodBankQueue();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            nurse(id, name, blood);
            break;
        case 5:
            system("clear"); // system("cls") in windows
            bloodBank();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            nurse(id, name, blood);
            break;
        case 6:
            system("clear"); // system("cls") in windows
            printf("You are successfully logged out\n");
            login();
            break;
        default:
            printf("Incorrect Input\n");;
            nurse(id, name, blood);
            break;
    }
}

void pathologist(int id, char name[7], char blood[4]) {
    system("clear"); // system("cls") in windows
    int choice;
    char ch;
    printf("Welcome %s\n", name);
    printf("================================\n");
    printf("Enter 1 to list Unvarified Bloods \nEnter 2 to Check Blood Bank \nEnter 3 for Logout \n\n\n%s@bloodBank:~$ ", name);
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            system("clear"); // system("cls") in windows
            bloodBankQueue();
            printf("Enter V to Varify or C to continue ...\n");
            scanf(" %c", &ch);
            if(ch == 'V') {
                int id;
                char c;
                printf("Enter ID<space>(V or U), V for Varify and U for Unvarify\n\n%s@bloodBank:~$ ", name);
                scanf("%d %c", &id, &c);
                varifyBlood(id, c);
            }
            pathologist(id, name, blood);
            break;
        case 2:
            printf("Two\n");
            system("clear"); // system("cls") in windows
            bloodBank();
            printf("Enter C to continue ...\n");
            scanf(" %c", &ch);
            pathologist(id, name, blood);
            break;
        case 3:
            printf("Three\n");
            system("clear"); // system("cls") in windows
            printf("You are successfully logged out\n");
            login();
            break;
        default:
            printf("Incorrect Input\n");
            pathologist(id, name, blood);
            break;
    }
}

// This is a mess ..........

void queueToData(int id, int bags, char blood[4], char name[7]) {
    if(id > 10000 && bloodGroupValidation(blood) && userIdDuplicate(id)) {
        FILE* dataAdd = fopen("userdata.txt", "a");
        fprintf(dataAdd, "%s \t%d \t%s \t%d\n", name, id, blood, bags);
        printf("Successfully Added Blood\n");
        fclose(dataAdd);
        availableBloodIncrement(blood, bags);
    } else if(id > 10000 && bloodGroupValidation(blood) && !userIdDuplicate(id)) {
        totalDonationIncrement(id, bags);
        printf("Successfully Added Blood\n");
        availableBloodIncrement(blood, bags);
    }
}

void varifyBlood(int id, char c[2]) {

    if(c == 'V') {
        FILE* vfile = fopen("yetTocheck.txt", "r");
        FILE* vfp = fopen("temp2.txt", "w");
        char line[256];
        int dbid, bags;
        char blood[4];
        char name[7];

        while(fgets(line, sizeof(line), vfile)) {
            sscanf(line, "%s %d %s %d", &name, &dbid, &blood, &bags);
            if(id == dbid) {
                queueToData(dbid, bags, blood, name);
                break;
            } else {
                fprintf(vfp, "%s", line);
            }
        }
        fclose(vfile);
        fclose(vfp);

        vfile = fopen("yetTocheck.txt", "w");
        vfp = fopen("temp2.txt", "r");

        while(fgets(line, sizeof(line), vfp)) {
            fprintf(vfile, "%s", line);
        }
        fclose(vfile);
        fclose(vfp);
    }

    else if (c == 'U') {
        FILE* vfile = fopen("yetTocheck.txt", "r");
        FILE* vfp = fopen("temp2.txt", "w");
        char line[256];
        int dbid, bags;
        char blood[4];
        char name[7];

        while(fgets(line, sizeof(line), vfile)) {
            sscanf(line, "%s %d %s %d", &name, &dbid, &blood, &bags);
            if(id == dbid) {
                continue;
            } else {
                fprintf(vfp, "%s", line);
            }
        }
        fclose(vfile);
        fclose(vfp);

        vfile = fopen("yetTocheck.txt", "w");
        vfp = fopen("temp2.txt", "r");

        while(fgets(line, sizeof(line), vfp)) {
            fprintf(vfile, "%s", line);
        }
        fclose(vfile);
        fclose(vfp);
    }
    sleep(2);
}


void bloodBankQueue() {
    FILE* file = fopen("yetTocheck.txt", "r");
    char line[256];

    while(fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
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

void availableBloodIncrement(char bld[4], int bag) {
    FILE* avbFile = fopen("availableBlood.txt", "r");
    FILE* avbTemp = fopen("tempavb.txt", "w");
    char line[256];
    char blood[4];
    int bags;
    while(fgets(line, sizeof(line), avbFile)) {
        sscanf(line, "%s %d", &blood, &bags);

        if(strcmp(bld, blood) == 0) {
            bags = bags + bag;
            fprintf(avbTemp, "%s \t%d\n", blood, bags);
            continue;
        }
        else {
            fprintf(avbTemp, "%s", line);
        }
    }

    fclose(avbFile);
    fclose(avbTemp);

    avbFile = fopen("availableBlood.txt", "w");
    avbTemp = fopen("tempavb.txt", "r");

    while(fgets(line, sizeof(line), avbTemp)) {
        fprintf(avbFile, "%s", line);
    }

    fclose(avbTemp);
    fclose(avbFile);
}


void totalVarificationIncrement(int id, int bag) {
    FILE* file = fopen("yetTocheck.txt", "r");
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

    file = fopen("yetTocheck.txt", "w");
    fp = fopen("temp.txt", "r");

    while(fgets(line, sizeof(line), fp)) {
        fprintf(file, "%s", line);
    }
    fclose(file);
    fclose(fp);
}

int userIdDuplicate(int id) {
    char name[7];
    char blood[4];
    int dbid, bags;
    FILE* checkDup = fopen("userdata.txt", "r");
    char line[256];
    int status = 1;

    while(fgets(line, sizeof(line), checkDup)) {
        sscanf(line, "%s %d %s %d", &name, &dbid, &blood, &bags);
        if (id == dbid) status = 0;
    }
    fclose(checkDup);

    return status;
}

int usrIdDuplicate(int id) {
    char name[7];
    char blood[4];
    int dbid, bags;
    FILE* file = fopen("yetTocheck.txt", "r");
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

void addToVerificationList() {
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
        FILE* file = fopen("yetTocheck.txt", "a");
        fprintf(file, "%s \t%d \t%s \t%d\n", name, id, blood, bags);
        printf("Successfully Added For Ckeckup\n");
        fclose(file);
    } else if(id > 10000 && bloodGroupValidation(blood) && !usrIdDuplicate(id)) {
        totalVarificationIncrement(id, bags);
        printf("Successfully Added For Checkup\n");
    } else {
        printf("Something Went Wrong. Check Your Form Again.\n");
        addToVerificationList();
    }
}

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
        FILE* file = fopen("yetTocheck.txt", "a");
        fprintf(file, "%s \t%d \t%s \t%d\n", name, id, blood, bags);
        printf("Successfully Added Blood\n");
        fclose(file);
    } else if(id > 10000 && bloodGroupValidation(blood) && !usrIdDuplicate(id)) {
        totalDonationIncrement(id, bags);
        printf("Successfully Added Blood\n");
    } else {
        printf("Something Went Wrong. Check Your Form Again.\n");
        addBlood();
    }
}

void bloodBank() {
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
    if(idCheck(id) && id > 100 && id < 1000 && pin > 999 && pin < 10000 && bloodGroupValidation(blood)) {
        fprintf(file, "%d \t%d \t%s \t\t%s\n", id, pin, name, blood);
        printf("Successfully Created Pathologist\n");
        fclose(file);
    } else {
        printf("Something Went Wrong. Check Your Form Again.\n");
        fclose(file);
        addPathologist();
    }
}

void addAdmin() {
    // system("clear"); // system("cls") in windows
    int id, pin;
    char name[7];
    char blood[4];
    FILE* file = fopen("database.txt", "a");

    printf("Enter Id (Must be in range 1 to 99): ");
    scanf("%d", &id);
    printf("Enter Pin (Must Contain 4 DIGIT): ");
    scanf("%d", &pin);
    printf("Enter Name (Must be in range 1 to 6, without space): ");
    scanf("%s", &name);
    printf("Enter Blood Group: ");
    scanf("%s", &blood);
    if(idCheck(id) && id > 0 && id < 100 && pin > 999 && pin < 10000 && bloodGroupValidation(blood)) {
        fprintf(file, "%d \t%d \t%s \t\t%s\n", id, pin, name, blood);
        printf("Successfully Created Admin\n");
        fclose(file);
    } else {
        printf("Something Went Wrong. Check Your Form Again.\n");
        fclose(file);
        addAdmin();
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
    if(id != 998877)
        checkLogin(id, pin);
    else if (pin == 989878) {
        int ch;
        printf(RED "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" RESET);
        printf(RED "\tWelcome Master ADMIN\n" RESET);
        printf(RED "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" RESET);
        printf(RED "You can Delete all the Data. Use with Caution\n" RESET);
        printf(RED "This account will auto LOGOUT after any activity\n" RESET);
        printf(RED "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n" RESET);
        printf(RED "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n" RESET);
        printf(RED "Enter 1 to add Admin\n" RESET);
        printf(RED "Enter 2 to Reset LOGIN Database\n" RESET);
        printf(RED "Enter 3 to Reset USER DATABASE\n" RESET);
        printf(RED "Enter 4 to Reset Available Blood Data\n" RESET);
        printf(RED "Enter 5 to Reset Yet to Check List Data\n" RESET);
        printf(RED "Enter 6 to Reset All\n" RESET);
        printf("Enter 7 to LOGOUT\n");
        printf(RED "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n" RESET);
        printf(RED "Enter Choice :: " RESET);
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nThis Setting cannot be Undone\n");
                printf(RED "Enter Pin to Confirm :: " RESET);
                scanf("%d", &pin);
                if(pin == 989878) {
                    addAdmin();
                } else {
                    printf("Invalid PIN Given\n");
                }
                login();
                break;
            case 2:
                printf("\nThis Setting cannot be Undone\n");
                printf(RED "Enter Pin to Confirm :: " RESET);
                scanf("%d", &pin);
                if(pin == 989878) {
                    FILE* file = fopen("database.txt", "w");
                    fclose(file);
                } else {
                    printf("Invalid PIN Given\n");
                }
                login();
                break;
            case 3:
                printf("\nThis Setting cannot be Undone\n");
                printf(RED "Enter Pin to Confirm :: " RESET);
                scanf("%d", &pin);
                if(pin == 989878) {
                    FILE* file = fopen("userdata.txt", "w");
                    fclose(file);
                } else {
                    printf("Invalid PIN Given\n");
                }
                login();
                break;
            case 4:
                printf("\nThis Setting cannot be Undone\n");
                printf(RED "Enter Pin to Confirm :: " RESET);
                scanf("%d", &pin);
                if(pin == 989878) {
                    FILE* file = fopen("availableBlood.txt", "w");
                    fclose(file);
                } else {
                    printf("Invalid PIN Given\n");
                }
                login();
                break;
            case 5:
                printf("\nThis Setting cannot be Undone\n");
                printf(RED "Enter Pin to Confirm :: " RESET);
                scanf("%d", &pin);
                if(pin == 989878) {
                    FILE* file = fopen("yetTocheck.txt", "w");
                    fclose(file);
                } else {
                    printf("Invalid PIN Given\n");
                }
                login();
                break;
            case 6:
                printf("\nThis Setting cannot be Undone\n");
                printf(RED "Enter Pin to Confirm :: " RESET);
                scanf("%d", &pin);
                if(pin == 989878) {
                    FILE* file = fopen("database.txt", "w");
                    fclose(file);
                    fopen("userdata.txt", "w");
                    fclose(file);
                    fopen("availableBlood.txt", "w");
                    fclose(file);
                    fopen("yetTocheck.txt", "w");
                    fclose(file);
                } else {
                    printf("Invalid PIN Given\n");
                }
                login();
                break;
            case 7:
                system("clear");
                printf("You are LOGGED Out\n");
                login();
                break;
            default:
                printf("Invalid Command Given\n");
                sleep(1);
                system("clear");
                login();
                break;
        }
    }
    else {
        printf("Unable to Access Master Admin\n\n");
        sleep(2);
        system("clear");
        login();
    }
}

void goodbye() {
    system("clear"); // system("cls") on Windows or DOS
    printf("Thank You Using Our Service.\n");
    sleep(2);
    system("clear");
    exit(0);
}
