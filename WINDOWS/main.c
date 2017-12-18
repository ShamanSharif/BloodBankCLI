#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    system("cls"); // system("cls") in windows
    int a;

    // ART

    printf("                                                                                                                                                           \n");
    printf("                                                                         dddddddd                                                                          \n");
    printf("BBBBBBBBBBBBBBBBB   lllllll                                              d::::::dBBBBBBBBBBBBBBBBB                                      kkkkkkkk           \n");
    printf("B::::::::::::::::B  l:::::l                                              d::::::dB::::::::::::::::B                                     k::::::k            \n");
    printf("B::::::BBBBBB:::::B l:::::l                                              d::::::dB::::::BBBBBB:::::B                                    k::::::k            \n");
    printf("BB:::::B     B:::::Bl:::::l                                              d:::::d BB:::::B     B:::::B                                   k::::::k            \n");
    printf("  B::::B     B:::::B l::::l    ooooooooooo     ooooooooooo       ddddddddd:::::d   B::::B     B:::::B  aaaaaaaaaaaaa  nnnn  nnnnnnnn     k:::::k    kkkkkkk \n");
    printf("  B::::B     B:::::B l::::l  oo:::::::::::oo oo:::::::::::oo   dd::::::::::::::d   B::::B     B:::::B  a::::::::::::a n:::nn::::::::nn   k:::::k   k:::::k  \n");
    printf("  B::::BBBBBB:::::B  l::::l o:::::::::::::::o:::::::::::::::o d::::::::::::::::d   B::::BBBBBB:::::B   aaaaaaaaa:::::an::::::::::::::nn  k:::::k  k:::::k   \n");
    printf("  B:::::::::::::BB   l::::l o:::::ooooo:::::o:::::ooooo:::::od:::::::ddddd:::::d   B:::::::::::::BB             a::::ann:::::::::::::::n k:::::k k:::::k   \n");
    printf("  B::::BBBBBB:::::B  l::::l o::::o     o::::o::::o     o::::od::::::d    d:::::d   B::::BBBBBB:::::B     aaaaaaa:::::a  n:::::nnnn:::::n k::::::k:::::k    \n");
    printf("  B::::B     B:::::B l::::l o::::o     o::::o::::o     o::::od:::::d     d:::::d   B::::B     B:::::B  aa::::::::::::a  n::::n    n::::n k:::::::::::k      \n");
    printf("  B::::B     B:::::B l::::l o::::o     o::::o::::o     o::::od:::::d     d:::::d   B::::B     B:::::B a::::aaaa::::::a  n::::n    n::::n k:::::::::::k      \n");
    printf("  B::::B     B:::::B l::::l o::::o     o::::o::::o     o::::od:::::d     d:::::d   B::::B     B:::::Ba::::a    a:::::a  n::::n    n::::n k::::::k:::::k     \n");
    printf("BB:::::BBBBBB::::::Bl::::::lo:::::ooooo:::::o:::::ooooo:::::od::::::ddddd::::::ddBB:::::BBBBBB::::::Ba::::a    a:::::a  n::::n    n::::nk::::::k k:::::k   \n");
    printf("B:::::::::::::::::B l::::::lo:::::::::::::::o:::::::::::::::o d:::::::::::::::::dB:::::::::::::::::B a:::::aaaa::::::a  n::::n    n::::nk::::::k  k:::::k   \n");
    printf("B::::::::::::::::B  l::::::l oo:::::::::::oo oo:::::::::::oo   d:::::::::ddd::::dB::::::::::::::::B   a::::::::::aa:::a n::::n    n::::nk::::::k   k:::::k  \n");
    printf("BBBBBBBBBBBBBBBBB   llllllll   ooooooooooo     ooooooooooo      ddddddddd   dddddBBBBBBBBBBBBBBBBB     aaaaaaaaaa  aaaa nnnnnn    nnnnnnkkkkkkkk    kkkkkkk \n");
    printf(" \n");
    printf(" \n");

    // ART

    printf("Welcome to Blood Bank Management System.\n");
    printf("Created By The Student Of");
    printf(" Northern University\n");

    printf("Enter '1' to login: ");
    scanf("%d", &a);
    if(a == 1) {
        system("cls"); // system("cls") in windows
        login();
    }
    return 0;
}


// Main Function Section, MASTER ADMIN, ADMIN, NURSE, PATHOLOGIST..

void admin(int id, char name[7], char blood[4]) {
    system("cls"); // system("cls") in windows
    int choice;
    printf("Welcome %s\n", name);
    printf("================================\n");
    printf("Enter 1 to list all Pathologist \nEnter 2 to list all Nurse \nEnter 3 to Add Pathologist \nEnter 4 to Add Nurse \nEnter 5 for Logout \n\n\n%s@bloodBank:~$ ", name);
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            system("cls"); // system("cls") in windows
            listAllPathologist();
            system("pause");
            admin(id, name, blood);
            break;
        case 2:
            system("cls"); // system("cls") in windows
            listAllNurse();
            system("pause");
            admin(id, name, blood);
            break;
        case 3:
            system("cls"); // system("cls") in windows
            addPathologist();
            system("pause");
            admin(id, name, blood);
            break;
        case 4:
            system("cls"); // system("cls") in windows
            addNurse();
            system("pause");
            admin(id, name, blood);
            break;
        case 5:
            system("cls"); // system("cls") in windows
            printf("You are successfully logged out\n\n");
            login();
            break;
        default:
            printf("Incorrect Input\n");
            system("pause");
            admin(id, name, blood);
            break;
    }
}

void nurse(int id, char name[7], char blood[4]) {
    system("cls"); // system("cls") in windows
    int choice;
    printf("Welcome %s\n", name);
    printf("================================\n");
    printf("Enter 1 to add Blood to BloodBank \nEnter 2 to Use Blood from BloodBank \nEnter 3 to List all Donators \nEnter 4 to Check Still to Varified List \nEnter 5 to Check Blood Bank \nEnter 6 for Logout \n\n\n%s@bloodBank:~$ ", name);
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            system("cls"); // system("cls") in windows
            addToVerificationList();
            system("pause");
            nurse(id, name, blood);
            break;
        case 2:
            system("cls"); // system("cls") in windows
            widrawBlood();
            system("pause");
            nurse(id, name, blood);
            break;
        case 3:
            system("cls"); // system("cls") in windows
            listDonators();
            system("pause");
            nurse(id, name, blood);
            break;
        case 4:
            system("cls"); // system("cls") in windows
            bloodBankQueue();
            system("pause");
            nurse(id, name, blood);
            break;
        case 5:
            system("cls"); // system("cls") in windows
            bloodBank();
            system("pause");
            nurse(id, name, blood);
            break;
        case 6:
            system("cls"); // system("cls") in windows
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
    system("cls"); // system("cls") in windows
    int choice;
    char ch;
    printf("Welcome %s\n", name);
    printf("================================\n");
    printf("Enter 1 to list Unvarified Bloods \nEnter 2 to Check Blood Bank \nEnter 3 for Logout \n\n\n%s@bloodBank:~$ ", name);
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            system("cls"); // system("cls") in windows
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
            system("cls"); // system("cls") in windows
            bloodBank();
            system("pause");
            pathologist(id, name, blood);
            break;
        case 3:
            system("cls"); // system("cls") in windows
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
    system("pause");
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
    // system("cls"); // system("cls") in windows
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
    // system("cls"); // system("cls") in windows
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
    // system("cls"); // system("cls") in windows
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
    // system("cls"); // system("cls") in windows
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
    // system("cls"); // system("cls") in windows
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
    // system("cls"); // system("cls") in windows
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
    // system("cls"); // system("cls") in windows
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
    // system("cls"); // system("cls") in windows
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
        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("\tWelcome Master ADMIN\n");
        printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("You can Delete all the Data. Use with Caution\n");
        printf("This account will auto LOGOUT after any activity\n");
        printf("x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n");
        printf("x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n");
        printf("Enter 1 to add Admin\n");
        printf("Enter 2 to Reset LOGIN Database\n");
        printf("Enter 3 to Reset USER DATABASE\n");
        printf("Enter 4 to Reset Available Blood Data\n");
        printf("Enter 5 to Reset Yet to Check List Data\n");
        printf("Enter 6 to Reset All\n");
        printf("Enter 7 to LOGOUT\n");
        printf("x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n");
        printf("Enter Choice :: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nThis Setting cannot be Undone\n");
                printf("Enter Pin to Confirm :: ");
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
                printf("Enter Pin to Confirm :: ");
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
                printf("Enter Pin to Confirm :: ");
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
                printf("Enter Pin to Confirm :: ");
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
                printf("Enter Pin to Confirm :: ");
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
                printf("Enter Pin to Confirm :: ");
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
                system("cls");
                printf("You are LOGGED Out\n");
                login();
                break;
            default:
                printf("Invalid Command Given\n");
                system("pause");
                system("cls");
                login();
                break;
        }
    }
    else {
        printf("Unable to Access Master Admin\n\n");
        system("pause");
        system("cls");
        login();
    }
}

void goodbye() {
    system("cls"); // system("cls") on Windows or DOS
    printf("Thank You Using Our Service.\n");
    system("pause");
    system("cls");
    exit(0);
}
