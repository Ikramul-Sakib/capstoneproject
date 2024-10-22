#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

struct used {        // user profile create
    char name[100],date_of_birth[11],phone[14];
    int pin,nid;
}u2;

int choice(void); int security(void);
bool val_phn(const char* phone);
bool val_date(const char* date);

bool val_date(const char* date) {
    // Check length
    if (strlen(date) != 10) {
        return false;
    }
    
    // Check format (dd/mm/yyyy)
    if (date[2] != '/' || date[5] != '/') {
        return false;
    }
    
    // Extract day, month, year
    int day = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[3] - '0') * 10 + (date[4] - '0');
    int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 +
               (date[8] - '0') * 10 + (date[9] - '0');
    
    // Check if all characters except '/' are digits
    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5) {  // Skip the '/' positions
            if (date[i] < '0' || date[i] > '9') {
                return false;
            }
        }
    }
    
    // Validate ranges
    if (year < 1900 || year > 2024) {  // Reasonable year range
        return false;
    }
    
    if (month < 1 || month > 12) {
        return false;
    }
    
    // Array of days in each month (non-leap year)
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Adjust February for leap years
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        days_in_month[1] = 29;
    }
    
    if (day < 1 || day > days_in_month[month - 1]) {
        return false;
    }
    
    return true;
}


bool val_phn(const char* phone) {
    // Check if the length is exactly 14 (+8801XXXXXXXX)
    if (strlen(phone) != 14) {
        return false;
    }
    
    // Check if it starts with "+8801"
    if (strncmp(phone, "+8801", 5) != 0) {
        return false;
    }
    
    // Check if the remaining digits are numeric
    for (int i = 5; i < 14; i++) {
        if (phone[i] < '0' || phone[i] > '9') {
            return false;
        }
    }
    return true;
}

int security(void){
    while (1) {
        int a = random()%1000000,b;
        printf("\nYour security code is: %d",a);
        printf("\nEnter security code: ");
        scanf("%d",&b);
        if (a == b) {printf("Account create successful");
            return 0;}
        else{printf("Failed");
            security();
            return 0;
        }
    }
}

int choice(void){
    int p = 0,r;
    printf("**** Welcome to the mobile wallet management System ****\n");
    printf("What types of user you are: ");
    printf("\n1. Registered. \n2. Non-Registered\n");
    scanf("%d",&r);
    
    if (r == 1) {
        struct used u1 = {"Sakib", "13/01/2000" ,"+8801841937588", 1234, 12345678}; // pre define profile
        p= u1.pin;
    }

    else if (r == 2){
        
        printf("Enter your name: ");
        scanf("%s",u2.name);
        do {
                    printf("Enter your date of birth (dd/mm/yyyy): ");
                    scanf("%s",u2.date_of_birth);
                    if (!val_date(u2.date_of_birth)) {
                        printf("Invalid date format or date. Please use dd/mm/yyyy format and enter a valid date.\n");
                    }
                } while (!val_date(u2.date_of_birth));
        
        do {
                    printf("Enter your phone number (Start with +8801): ");
                    scanf("%s", u2.phone);
                    if (!val_phn(u2.phone)) {
                        printf("Invalid phone number. Please enter exactly 11 digits.\n");
                    }
                }
        while (!val_phn(u2.phone));
        
        printf("Enter your Pin: ");   // take pin from the user.
        scanf("%d",&u2.pin);
        printf("Enter your Nid number: ");
        scanf("%d",&u2.nid);
        p = u2.pin;
        
        FILE *file = fopen("/Users/mdikramulhassan/Desktop/Swift_Project/proj/file.txt", "a");
                if (file != NULL) {
                    fprintf(file, "Name: %s, DOB: %s, PHONE: %s, PIN: %d, NID: %d\n",
                            u2.name, u2.date_of_birth,u2.phone, u2.pin, u2.nid);
                    fclose(file);
                    printf("Account information saved to file.\n");
                } else {
                    printf("Error: Unable to save account information.\n");
                }
        
        
        security();
        printf("\n");
    }
    return p;
}





int main(void) {

    int pn = choice(); // call the function to user's type.
    
    int c,p,num,amount,balance = 100000,out;
  
    while (1) // for run the whole condition more times
    {
        
        printf("What type of operatiobn you want to do with: \n1. Send Money\n2. Send Money to non user\n3. Mobile Recharge\n4. Payment\n5. Cash Out\n6. ");
        scanf("%d",&c);
        
        if (c==1) {
            printf("Enter wallet number which you want to send money : ");
            scanf("%d",&num);
            printf("Enter the amount: ");
            scanf("%d",&amount);
            printf("Enter your pin: ");
            scanf("%d",&p);
            if (p == pn) {
                printf("Success");
                balance = balance-amount;
            }
            else{
                printf("Failed");
            }
            printf("\n");
            
        }
        
        else if (c==2){
            printf("Enter non wallet number which you want to send money : ");
            scanf("%d",&num);
            printf("Enter the amount: ");
            scanf("%d",&amount);
            printf("Enter your pin: ");
            scanf("%d",&p);
           
            if (p == pn) {
                printf("Success");
                balance = balance-amount;
            }
            else{
                printf("Failed");
            }
            printf("\n");
                        
        }
        else if (c == 3){
            printf("Enter your mobile number to recharge: ");
            scanf("%d",&num);
            printf("Entr recharge amount: ");
            scanf("%d",&amount);
            printf("Enter your pin to confirm: ");
            scanf("%d",&p);
            if (p == pn) {
                printf("%d bdt was successfully recharge to %d.",num,amount);
                balance = balance - amount;
            }
            else{
                printf("Pin number is not correct.");
            }
            printf("\n");
        }
        
        else if (c == 4){   //payment
            printf("Enter the marchent number to continue: ");
            scanf("%d",&num);
        }
        
        
        else if (c == 5){   //cash out
            printf("By which service you want to cash out:\n1. ATM Bank.\n2. Agent.\n");
            scanf("%d",&out);
            
            if (out == 1) {
                printf("Enter your amount: ");
                scanf("%d",&amount);
                printf("Enter your pin to confirm : ");
                scanf("%d",&p);
                if (p == pn) {
                   long int ra = random();
                    printf("Your generated code is : %ld\n",ra);
                    printf("Enter the above code to ATM machine.");
                    balance = balance - amount;
                }
                else{
                    printf("Wrong Pin code.");
                }
            }
            else if (out == 2){
                printf("Enter the agent number to cash out: ");
                scanf("%d",&num);
                printf("Entr your amount: ");
                scanf("%d",&amount);
                printf("Enter your pin to confirm : ");
                scanf("%d",&p);
                
                if (p == pn) {
                    printf("Cash out to number: %d and amount: %d was successful.",num,amount);
                    balance = balance - amount;
                }
                else{
                    printf("Wrong Pin code.");
                }
            }
        }
        
        else{    //exit
            return 0;
        }
        printf("\n");
        printf("balance: %d\n", balance);
    }
    return 0;
}
