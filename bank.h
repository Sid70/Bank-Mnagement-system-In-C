#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>

void menu();
void new_account();
void viewlist();
void edit();
void transact();
void search_List();
void deleteaccount();
void savingAccount();
void currentAccount();
void fixedAccount();

void checkYourTransactionDetails();

void welcome();
int takeIntegerInput();

struct newaccount
{

    char name[30];
    char dateofbirth[14];
    char phoneNumber[15];
    char  citizenshipeNumber[10];
    char setyourpin[9];
    char accountType[15];
    float intamt;
    float depamt;
    float witdamt;

    struct transaction
    {
        float netcrd,depositmoney,netdbt,withdrawmoney;
    } t;
} p;


FILE *ptr;
FILE *fp;
FILE *temp;

int takeIntegerInput()
{

    int n;
start:
    printf("\n\n\t\t\t\tEnter Your Choice: ");
    while(!scanf("%d",&n))
    {
        usleep(1000000);
        printf("\n\t\t\t\tWrong Input.Please Enter a Valid Integer Input.......");
        fflush(stdin);
        goto start;
    }
    return n;
}

void welcome()
{

    puts("\t\t\t\t------------------------------------------------------------");
    puts("\t\t\t\t|============== Mini Bank Management System ===============|");
    puts("\t\t\t\t|==============  WELCOME TO THE MAIN MENU =================|");
    puts("\t\t\t\t------------------------------------------------------------");

    printf("\n\n");

    usleep(1000000);
}

void menu()
{

    int choice;
    puts("\t\t\t\t--------------------------------------------------------------------");
    puts("\t\t\t\t|--------CUSTOMER ACCOUNT BANKING BANKING MANANGEMENT SYSTEM-------|");
    puts("\t\t\t\t|                                                                  |");
    puts("\t\t\t\t| 1. Create new account                                            |");
    puts("\t\t\t\t| 2. Update information of existing account                        |");
    puts("\t\t\t\t| 3. Search Account Details                                        |");
    puts("\t\t\t\t| 4. For Banking transaction                                       |");
    puts("\t\t\t\t| 5. Delete existing account                                       |");
    puts("\t\t\t\t| 6. View  Account details                                         |");
    puts("\t\t\t\t| 7. Check Transaction Details                                     |");
    puts("\t\t\t\t| 8. Exit                                                          |");
    puts("\t\t\t\t--------------------------------------------------------------------");

start:
    fflush(stdin);
    choice=takeIntegerInput();
    switch (choice)
    {
    case 1:
    {
        //new account
        new_account();
        break;
    }
    case 2:
    {
        //update
        edit();
        break;
    }
    case 3:
    {
        //search
        search_List();
        break;
    }
    case 4:
    {
        //Banking Transcation
        transact();
        break;
    }
    case 5:
    {
        deleteaccount();
        break;
    }
    case 6:
    {
        viewlist();
        break;
    }
    case 7:
    {
        checkYourTransactionDetails();
        break;
    }
    case 8:
    {
        exit(0);
    }
    default:
    {
        printf("\t\t\t\tWrong Choice! try again.");
        goto start;
    }

    }
}

void new_account()
{

    system("cls");
    welcome();
start:
    puts("\t\t\t\t---------------------------------------------------------------------");
    puts("\t\t\t\t|                     Creating your Account                         |");
    puts("\t\t\t\t---------------------------------------------------------------------");

    printf("\n\t\t\t\t Enter Your Account Type: \n");
    printf("\t\t\t\t\t1. Saving Account\n");
    printf("\t\t\t\t\t2. Current Account\n");
    printf("\t\t\t\t\t3. Fixed Account\n");
    printf("\t\t\t\t\t4. Exit\n");

    int choice;
    usleep(1000000);
    fflush(stdin);
    choice=takeIntegerInput();

    switch (choice)
    {
    case 1:
    {
        savingAccount();
        break;
    }
    case 2:
    {
        currentAccount();
        break;
    }
    case 3:
    {
        fixedAccount();
        break;
    }
    default:
    {
        printf("\n\n\t\t\t\tWrong Input.Please enter a valid integer...");
        goto start;
    }
    }
}

void savingAccount()
{

    float t=0;
    system("cls");
    welcome();
    usleep(2000000);

    ptr =fopen("New.txt","a+");

    if (ptr == NULL)
    {
        exit(2);
    }

    puts("\t\t\t\t---------------------------------------------------------------------");
    puts("\t\t\t\t|                        1. Saving Account                          |");
    puts("\t\t\t\t---------------------------------------------------------------------");

    printf("\n\t\t\t\tEnter Name: ");
    while(getchar() != '\n');
    scanf("%[^\n]%*c",p.name);

    printf("\t\t\t\tEnter Date of Birth: ");
    scanf("%[^\n]%*c",p.dateofbirth);

    printf("\t\t\t\tEnter Mobile number: ");
    scanf("%[^\n]%*c",p.phoneNumber);

    printf("\t\t\t\tEnter Citizenship number: ");
    scanf("%[^\n]%*c",p.citizenshipeNumber);

    fflush(stdin);

    printf("\t\t\t\tEnter Account Type Name: ");
    scanf("%[^\n]%*c",p.accountType);

    printf("\t\t\t\tSet 4 digit PIN: ");
    scanf("%[^\n]%*c",p.setyourpin);


    printf("\n\t\t\t\tPlease wait............");
    usleep(2000000);

    printf("\n\t\t\t\tCongratulation! Your saving account is created successfully.");
    usleep(2000000);
    printf("\n\t\t\t\tGo to the Counter Number-4 for your passbook.");
    usleep(1000000);
    printf("\n\n\t\t\t\tYou have to deposit Rs. 5000.00 minimum.");

start:
    printf("\n\t\t\t\tDeposit your initial money: ");
    fflush(stdin);
    scanf("%f",&p.intamt);

    t=p.intamt+t;

    if ( t < 5000.00)
    {
        printf("\n\t\t\t\tYour Money cannot be less than Rs.5000 .Please deposit Rs.%.2f more.. ",5000 - t);


        goto start;
    }
    p.intamt = t;
    p.depamt = p.intamt;

    fwrite(&p,sizeof(p),1,ptr);
    fclose(ptr);

    printf("\n\t\t\t\tThank You!");
    printf("\n\n\t\t\t\tPress Enter to go to the main page..........");
    getch();

    system("cls");
    welcome();
    menu();
}

void currentAccount()
{

    float t=0;
    system("cls");
    welcome();
    usleep(2000000);

    ptr =fopen("New.txt","a+");

    if (ptr == NULL)
    {
        exit(2);
    }
    puts("\t\t\t\t---------------------------------------------------------------------");
    puts("\t\t\t\t|                        2. Current Account                         |");
    puts("\t\t\t\t---------------------------------------------------------------------");

    printf("\n\t\t\t\tEnter Name: ");
    while(getchar() != '\n');
    scanf("%[^\n]%*c",p.name);

    printf("\t\t\t\tEnter Date of Birth: ");
    scanf("%[^\n]%*c",p.dateofbirth);

    printf("\t\t\t\tEnter Mobile number: ");
    scanf("%[^\n]%*c",p.phoneNumber);

    printf("\t\t\t\tEnter citizenship number: ");
    scanf("%[^\n]%*c",p.citizenshipeNumber);

    fflush(stdin);

    printf("\t\t\t\tEnter Account Type Name: ");
    scanf("%[^\n]%*c",p.accountType);

    fflush(stdin);


    printf("\t\t\t\tSet 4 digit PIN: ");
    scanf("%[^\n]%*c",p.setyourpin);


    printf("\n\t\t\t\t Please wait............");
    usleep(2000000);

    printf("\n\t\t\t\tCongratulation! Your Current account is created successfully.");
    usleep(2000000);
    printf("\n\t\t\t\tGo to the Counter Number-4 for your passbook.");
    usleep(1000000);
    printf("\n\n\t\t\t\tYou have to deposit Rs. 5000.00 minimum.");

start:
    printf("\n\t\t\t\tDeposit your initial money: ");
    fflush(stdin);
    scanf("%f",&p.intamt);

    t=p.intamt+t;

    if ( t < 5000.00)
    {
        printf("\n\t\t\t\tYour Money cannot be less than Rs.5000 .Please deposit Rs.%.2f more.. ",5000 - t);


        goto start;
    }
    p.intamt = t;
    p.depamt = p.intamt;

    fwrite(&p,sizeof(p),1,ptr);
    fclose(ptr);

    printf("\n\t\t\t\tThank You!");

    printf("\n\n\t\t\t\tPress Enter to go to the main page..........");
    getch();

    system("cls");
    welcome();
    menu();
}

void fixedAccount()
{

    float t=0;
    system("cls");
    welcome();
    usleep(2000000);

    ptr =fopen("New.txt","a+");

    if (ptr == NULL)
    {
        exit(2);
    }

    puts("\t\t\t\t---------------------------------------------------------------------");
    puts("\t\t\t\t|                        3. Fixed Account                           |");
    puts("\t\t\t\t---------------------------------------------------------------------");

    printf("\n\t\t\t\tEnter Your Name: ");
    while(getchar() != '\n');
    scanf("%[^\n]%*c",p.name);

    printf("\t\t\t\tEnter Date of Birth: ");
    scanf("%[^\n]%*c",p.dateofbirth);

    printf("\t\t\t\tEnter Mobile number: ");
    scanf("%[^\n]%*c",p.phoneNumber);

    printf("\t\t\t\tEnter Citizenship number: ");
    scanf("%[^\n]%*c",p.citizenshipeNumber);

    fflush(stdin);

    printf("\t\t\t\tEnter Account Type Name: ");
    scanf("%[^\n]%*c",p.accountType);

    fflush(stdin);

    printf("\t\t\t\tSet 4 digit PIN: ");
    scanf("%[^\n]%*c",p.setyourpin);

    printf("\n\t\t\t\tPlease wait............");
    usleep(2000000);

    printf("\n\t\t\t\tCongratulation! Your Fixed account is created successfully.");
    usleep(2000000);
    printf("\n\n\t\t\t\tYou have to deposit Rs. 5000.00 minimum.");

start:
    printf("\n\t\t\t\tDeposit your initial money: ");
    fflush(stdin);
    scanf("%f",&p.intamt);

    t=p.intamt+t;

    if ( t < 5000.00)
    {
        printf("\n\t\t\t\tYour Money cannot be less than Rs.5000 .Please deposit Rs.%.2f more.. ",5000 - t);


        goto start;
    }
    p.intamt = t;
    p.depamt = p.intamt;

    fwrite(&p,sizeof(p),1,ptr);
    fclose(ptr);

    printf("\n\t\t\t\tGo to the Counter Number-4 for your passbook and follow their instruction.");
    usleep(1000000);
    printf("\n\t\t\t\tThank You!");

    printf("\n\n\t\t\t\tPress Enter to go to the main page..........");
    getch();

    system("cls");

    welcome();

    menu();
}

void viewlist()
{

    system("cls");
    welcome();

    ptr =fopen("New.txt","r");

    if (ptr == NULL)
    {
        printf("\n\t\t\t\tEmpty List.Create Some Account first.");
        exit(8);
    }

    puts("\n\n\t\t\t\t---------------------------------------------------------------------");
    puts("\t\t\t\t|                          Customer List                            |");
    puts("\t\t\t\t---------------------------------------------------------------------");

    char yourtype[15];
    printf("\n\n\t\t\t\tEnter Account Type: ");
    fflush(stdin);
    scanf("%[^\n]%*c",yourtype);


    while(fread(&p,sizeof(p),1,ptr) != 0)
    {
        if ( strcmp(yourtype,p.accountType) == 0)
        {
            usleep(1000000);
            printf("\n\n\t\t\t\t---------------------------------------------------------------------");
            printf("\n\t\t\t\t                           %s account                              ",p.accountType);
            printf("\n\t\t\t\t---------------------------------------------------------------------");
            printf("\n\n\t\t\t\tName: %s",p.name);
            printf("\n\t\t\t\tDate of Birth: %s",p.dateofbirth);
            printf("\n\t\t\t\tMobile number: %s",p.phoneNumber);
            printf("\n\t\t\t\tPIN: %s", p.setyourpin);
            printf("\n\t\t\t\tCitizenship number: %s",p.citizenshipeNumber);
            printf("\n\t\t\t\tYour Balance: %.2f",p.intamt);
        }
        else if (strcmp(yourtype,p.accountType) != 0)
        {
            continue;
        }
    }

    fclose(ptr);

    usleep(2000000);
    printf("\n\n\t\t\t\tPress Enter to go to the main page..........");
    getch();

    system("cls");
    welcome();
    menu();

}

void deleteaccount()
{

    int choice,f=0;
    char name[30],dob[14],phone[15];
    system("cls");
    welcome();


    ptr = fopen("New.txt","r");
    fp = fopen("Temp.txt","w");

    if (ptr == NULL)
    {
        printf("\n\t\t\t\tEmpty List.Create Some Account first.");
        exit(8);
    }
    if (fp == NULL)
    {
        printf("\n\t\t\t\tEmpty List.Create Some Account first.");
        exit(8);
    }

    puts("\n\n\t\t\t\t---------------------------------------------------------------------");
    puts("\t\t\t\t|                   Delete Customer  Details                        |");
    puts("\t\t\t\t---------------------------------------------------------------------");

    printf("\n\t\t\t\t1. Delete by Customer Name and Customer Date of Birth");
    printf("\n\t\t\t\t2. Delete by Customer Phone Number and Date of Birth\n");

    choice=takeIntegerInput();

    switch (choice)
    {
    case 1:
    {

        printf("\n\n\t\t\t\tEnter Customer Name: ");
        fflush(stdin);
        scanf("%[^\n]%*c",name);

        printf("\t\t\t\tEnter Customer Date of Birth: ");
        scanf("%[^\n]%*c",dob);

        while (fread(&p,sizeof(p),1,ptr) != 0)
        {
            if ( strcmp(name,p.name) == 0 && strcmp(dob,p.dateofbirth) == 0)
            {
                f++;
            }
            else
            {
                fwrite(&p,sizeof(p),1,fp);
            }
        }
        break;
    }
    case 2:
    {
        printf("\n\n\t\t\t\tEnter Customer Mobile Number: ");
        fflush(stdin);
        scanf("%[^\n]%*c",phone);

        printf("\t\t\t\tEnter Customer Date of Birth: ");
        scanf("%[^\n]%*c",dob);

        while (fread(&p,sizeof(p),1,ptr) != 0)
        {
            if ( strcmp(phone,p.phoneNumber) == 0 && strcmp(dob,p.dateofbirth) == 0)
            {
                f++;
            }
            else
            {
                fwrite(&p,sizeof(p),1,fp);
            }
        }
        break;
    }
    default:
    {
        printf("\n\n\t\t\t\tWrong Choice....");
        exit(0);
    }
    }

    fclose(fp);
    fclose(ptr);

    remove("New.txt");
    rename("Temp.txt","New.txt");

    usleep(1000000);
    (f==0)?printf("\n\n\t\t\t\tRecord Not Found..........."):printf("\n\n\t\t\t\tDeleted Successfully..........");

    usleep(1000000);
    printf("\n\n\t\t\t\tPress Enter to go to the menu page.....");

    system("cls");
    welcome();
    menu();
}

void edit()
{

    int choice,f=0;
    char name[30],dob[14],phone[15];
    system("cls");
    welcome();


    ptr = fopen("New.txt","r");
    fp = fopen("Temp.txt","w");

    if (ptr == NULL)
    {
        printf("\n\t\t\t\tEmpty List.Create Some Account first.");
        exit(8);
    }
    if (fp == NULL)
    {
        printf("\n\t\t\t\tEmpty List.Create Some Account first.");
        exit(8);
    }

    puts("\n\n\t\t\t\t---------------------------------------------------------------------");
    puts("\t\t\t\t|                     Edit Customer  Details                        |");
    puts("\t\t\t\t---------------------------------------------------------------------");

    printf("\n\t\t\t\t1. Edit by Customer Name and Customer Date of Birth");
    printf("\n\t\t\t\t2. Edit by Customer Phone Number and Date of Birth\n");

    choice=takeIntegerInput();

    switch (choice)
    {
    case 1:
    {

        printf("\n\n\t\t\t\tEnter Customer Name: ");
        fflush(stdin);
        scanf("%[^\n]%*c",name);

        printf("\t\t\t\tEnter Customer Date of Birth: ");
        scanf("%[^\n]%*c",dob);

        while (fread(&p,sizeof(p),1,ptr) != 0)
        {
            if ( strcmp(name,p.name) == 0 && strcmp(dob,p.dateofbirth) == 0)
            {

                printf("\n\t\t\t\tEnter Name: ");
                scanf("%[^\n]%*c",p.name);

                printf("\t\t\t\tEnter Date of Birth: ");
                scanf("%[^\n]%*c",p.dateofbirth);

                printf("\t\t\t\tEnter mobile number: ");
                scanf("%[^\n]%*c",p.phoneNumber);

                printf("\t\t\t\tEnter citizenship number: ");
                scanf("%[^\n]%*c",p.citizenshipeNumber);

                fflush(stdin);

                printf("\t\t\t\tEnter Account Type Name: ");
                scanf("%[^\n]%*c",p.accountType);

                printf("\t\t\t\tSet  4 digit PIN: ");
                scanf("%[^\n]%*c",p.setyourpin);

                fwrite(&p,sizeof(p),1,fp);

                f++;
            }
            else
            {
                fwrite(&p,sizeof(p),1,fp);
            }
        }
        break;
    }
    case 2:
    {
        printf("\n\n\t\t\t\tEnter Customer Mobile Number: ");
        fflush(stdin);
        scanf("%[^\n]%*c",phone);

        printf("\t\t\t\tEnter Customer Date of Birth: ");
        scanf("%[^\n]%*c",dob);

        while (fread(&p,sizeof(p),1,ptr) != 0)
        {
            if ( strcmp(phone,p.phoneNumber) == 0 && strcmp(dob,p.dateofbirth) == 0)
            {

                printf("\n\t\t\t\tEnter Name: ");
                scanf("%[^\n]%*c",p.name);

                printf("\t\t\t\tEnter Date of Birth: ");
                scanf("%[^\n]%*c",p.dateofbirth);

                printf("\t\t\t\tEnter mobile number: ");
                scanf("%[^\n]%*c",p.phoneNumber);

                printf("\t\t\t\tEnter citizenship number: ");
                scanf("%[^\n]%*c",p.citizenshipeNumber);

                fflush(stdin);

                printf("\t\t\t\tEnter Account Type Name: ");
                scanf("%[^\n]%*c",p.accountType);

                printf("\t\t\t\tSet  4 digit PIN: ");
                scanf("%[^\n]%*c",p.setyourpin);

                fwrite(&p,sizeof(p),1,fp);

                f++;

            }
            else
            {
                fwrite(&p,sizeof(p),1,fp);
            }
        }
        break;
    }
    default:
    {
        printf("\n\n\t\t\t\tWrong Choice....");
        exit(0);
    }
    }

    fclose(fp);
    fclose(ptr);

    remove("New.txt");
    rename("Temp.txt","New.txt");

    usleep(1000000);
    (f==1)?printf("\n\n\t\t\t\tRecord Updated successfully.........."):printf("\n\n\t\t\t\tRecord Not found..........");

    usleep(1000000);
    printf("\n\n\t\t\t\tPress Enter to go to the menu page.....");
    getch();

    system("cls");
    welcome();
    menu();

}

void transact()
{

    system("cls");
    welcome();
    int f=0;

    char ch,phone[15];
    char gpin[9];
    ptr = fopen("New.txt","a+");
    fp =  fopen("transaction.txt","a+");
    temp =  fopen("TempTransaction.txt","w+");

    if (ptr == NULL)
    {
        printf("\n\t\t\t\tEmpty List.Create Some Account first.");
        exit(8);
    }
    if (fp == NULL)
    {
        printf("\n\t\t\t\tEmpty List.Create Some Account first.");
        exit(8);
    }

    if (temp == NULL)
    {
        exit(8);
    }


    printf("\n\t\t\t\t-------------------------------------------------------------------");
    printf("\n\t\t\t\t|                          Transaction                            |");
    printf("\n\t\t\t\t-------------------------------------------------------------------");


    printf("\n\n\t\t\t\tEnter your 4-digit pin: ");
    fflush(stdin);
    scanf("%[^\n]%*c",gpin);

    printf("\t\t\t\tEnter your Mobile Number: ");
    fflush(stdin);
    scanf("%[^\n]%*c",phone);


    while (fread(&p,sizeof(p),1,ptr) != 0)
    {
        if ( strcmp(gpin,p.setyourpin) == 0 && strcmp(phone,p.phoneNumber) == 0)
        {

            usleep(1000000);

            printf("\n\n\t\t\t\tWel Come Mr. %s. This is your %s type account.\n",p.name,p.accountType);
            printf("\t\t\t\tIf it's you then Click Yes/No: ");
            fflush(stdin);
            ch = getchar();

            while ( ch == 'Y' || ch == 'y')
            {

                f++;
                printf("\n\t\t\t\t1. Credit");
                printf("\n\t\t\t\t2. Debit");
                printf("\n\t\t\t\t3. Exit");

                usleep(2000000);

                int choice;
                choice=takeIntegerInput();

                switch(choice)
                {
                case 1:
                {
                    printf("\t\t\t\tEnter Your Deposit money :Rs.");
                    scanf("%f",&p.t.depositmoney);

                    p.t.netcrd = p.intamt + p.t.depositmoney;
                    usleep(2000000);
                    printf("\t\t\t\tCurrent Money :Rs.%.2f",p.t.netcrd);
                    p.intamt = p.t.netcrd;
                    p.depamt += p.t.depositmoney;
                    p.t.depositmoney = 0;
                    break;
                }
                case 2:
                {
                    printf("\t\t\t\tEnter your withdrawal Money :Rs.");
                    scanf("%f",&p.t.withdrawmoney);

                    if ( p.t.withdrawmoney > p.intamt )
                    {
                        usleep(2000000);
                        printf("\t\t\t\tNo Required money. you have Rs.%.2f money only.",p.intamt);
                        f=0;
                        p.t.withdrawmoney = 0.00;
                    }
                    else
                    {
                        usleep(2000000);
                        p.t.netdbt = p.intamt - p.t.withdrawmoney;
                        printf("\t\t\t\tCurrent money: Rs.%.2f",p.t.netdbt);
                        p.intamt = p.t.netdbt;
                        p.witdamt += p.t.withdrawmoney;
                        p.t.withdrawmoney = 0;
                    }
                    break;
                }
                case 3:
                {
                    exit(0);
                }
                default:
                {
                    usleep(2000000);
                    printf("\n\t\t\t\tWrong Input! please try again.....");
                    exit(0);
                }
                }
                fwrite(&p,sizeof(p),1,temp);
                fwrite(&p.t,sizeof(p.t),1,fp);
                goto last;
            }
        }
    }
last:
    usleep(1000000);
    (f == 1)?printf("\n\n\t\t\t\tTransaction Complete.........."):printf("\n\n\t\t\t\tTransaction failed...........");

    fclose(ptr);
    fclose(fp);
    fclose(temp);

    remove("New.txt");
    rename("TempTransaction.txt","New.txt");



    printf("\n\n\t\t\t\tPress Enter to go to the main page..........");
    getch();

    system("cls");
    welcome();
    menu();

}

void search_List()
{

    int choice,f=0;
    char name[30],dob[14],phone[15];
    system("cls");
    welcome();


    ptr = fopen("New.txt","r");

    if (ptr == NULL)
    {
        printf("\n\t\t\t\tEmpty List.Create Some Account first.");
        exit(8);
    }

    puts("\n\n\t\t\t\t---------------------------------------------------------------------");
    puts("\t\t\t\t|                   Search Customer  Details                        |");
    puts("\t\t\t\t---------------------------------------------------------------------");

    printf("\n\t\t\t\t1. Search by Customer Name and Customer Date of Birth");
    printf("\n\t\t\t\t2. Search by Customer Phone Number and Date of Birth\n");

    choice=takeIntegerInput();

    switch (choice)
    {
    case 1:
    {

        printf("\n\n\t\t\t\tEnter Customer Name: ");
        fflush(stdin);
        scanf("%[^\n]%*c",name);

        printf("\t\t\t\tEnter Customer Date of Birth: ");
        scanf("%[^\n]%*c",dob);

        while (fread(&p,sizeof(p),1,ptr) != 0)
        {
            if ( strcmp(name,p.name) == 0 && strcmp(dob,p.dateofbirth) == 0)
            {

                printf("\n\t\t\t\tCustomer Name: %s\n",p.name);
                printf("\t\t\t\tDate of Birth: %s\n",p.dateofbirth);
                printf("\t\t\t\tMobile number: %s\n",p.phoneNumber);
                printf("\t\t\t\tCitizenship number: %s\n",p.citizenshipeNumber);
                printf("\t\t\t\tAccount Type Name: %s\n",p.accountType);
                printf("\t\t\t\tPIN: %s\n",p.setyourpin);
                printf("\t\t\t\tYour Balance: %.2f",p.intamt);
                f++;
            }
        }
        break;
    }
    case 2:
    {
        printf("\n\n\t\t\t\tEnter Customer Mobile Number: ");
        fflush(stdin);
        scanf("%[^\n]%*c",phone);

        printf("\t\t\t\tEnter Customer Date of Birth: ");
        scanf("%[^\n]%*c",dob);

        while (fread(&p,sizeof(p),1,ptr) != 0)
        {
            if ( strcmp(phone,p.phoneNumber) == 0 && strcmp(dob,p.dateofbirth) == 0)
            {

                printf("\n\t\t\t\tCustomer Name: %s\n",p.name);
                printf("\t\t\t\tDate of Birth: %s\n",p.dateofbirth);
                printf("\t\t\t\tMobile number: %s\n",p.phoneNumber);
                printf("\t\t\t\tCitizenship number: %s\n",p.citizenshipeNumber);
                printf("\t\t\t\tAccount Type Name: %s\n",p.accountType);
                printf("\t\t\t\tPIN: %s\n",p.setyourpin);
                printf("\t\t\t\tYour Balance: %.2f",p.intamt);
                f++;

            }
        }
        break;
    }
    default:
    {
        printf("\n\n\t\t\t\tWrong Choice....");
        exit(0);
    }
    }
    fclose(ptr);


    usleep(1000000);
    if (f==0)
    {
        printf("\n\n\t\t\t\tRecord Not found..........");
    }


    usleep(2000000);
    printf("\n\n\t\t\t\tPress Enter to go to the menu page.....");
    getch();

    system("cls");
    welcome();
    menu();
}

void checkYourTransactionDetails()
{

    system("cls");
    welcome();
    int f=0;

    char ch,phone[15],dob[14];
    char gpin[9];
    ptr = fopen("New.txt","r");
    fp =  fopen("transaction.txt","a+");

    if (ptr == NULL)
    {
        printf("\n\t\t\t\tEmpty List.Create Some Account first.");
        exit(8);
    }

    if (fp == NULL)
    {
        printf("\n\t\t\t\tEmpty List.Create Some Account first.");
        exit(8);
    }

    while(fread(&p.t,sizeof(p.t),1,fp) == 0)
    {
        p.t.withdrawmoney = 0;
        p.t.depositmoney = 0;
        break;
    }

    char yourtype[15];
    printf("\n\n\t\t\t\tEnter Account Type: ");
    fflush(stdin);
    scanf("%[^\n]%*c",yourtype);

    //pin
    printf("\t\t\t\tEnter 4 digit PIN: ");
    scanf("%[^\n]%*c",gpin);

    //mobile Number and DOB

    printf("\t\t\t\tEnter Mobile Number: ");
    scanf("%[^\n]%*c",phone);

    printf("\t\t\t\tEnter Date of Birth: ");
    scanf("%[^\n]%*c",dob);

    printf("\n\t\t\t\t-----------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t|                           Customer Transaction Details                                |");
    printf("\n\t\t\t\t-----------------------------------------------------------------------------------------");

    while ( fread(&p,sizeof(p),1,ptr) != 0 || fread(&p.t,sizeof(p.t),1,fp) != 0 )
    {


        if ((strcmp(yourtype,p.accountType) == 0 && strcmp(gpin,p.setyourpin) == 0)&&(strcmp(dob,p.dateofbirth) == 0 && strcmp(phone,p.phoneNumber) == 0))
        {
            usleep(1000000);
            printf("\n\n\t\t\t\t----------------------------------------------------------------------------");
            printf("\n\t\t\t\t                                  %s account                                  ",p.accountType);
            printf("\n\t\t\t\t------------------------------------------------------------------------------");

            //Account Holder Name   //DoB  //Balance  //Credit  //Debit

            printf("\n\n\t\t\t\t Account Holder Name: %s\t\tDOB: %s",p.name,p.dateofbirth);
            printf("\n\t\t\t\t----------------------------------------------------------------------------------\n");
            printf("\t\t\t\t Balance\t\t\t  Credit\t\t\t   Debit\n");
            printf("\n\t\t\t\t-----------------------------------------------------------------------------------\n");
            printf("\t\t\t\t Rs.%.2f\t\t\t Rs.%.2f\t\t\t Rs.%.2f",p.intamt,p.depamt,p.witdamt);
            printf("\n\t\t\t\t----------------------------------------------------------------------------------\n");
            break;
        }
    }
    usleep(1000000);
    fclose(ptr);
    fclose(fp);


    printf("\n\n\t\t\t\tPress Enter to go to the main page..........");
    getch();

    system("cls");
    welcome();
    menu();
}
