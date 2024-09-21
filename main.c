
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

struct used {        // user profile create
    char name[100],date_of_birth[11];
    int pin,nid;
}u2;
int choice(void);
int security(void);


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
        struct used u1 = {"Sakib", "13/01/2000" , 1234, 12345678}; // pre define profile
        p= u1.pin;
    }

    else if (r == 2){
        
        printf("Enter your name: ");
        scanf("%s",u2.name);
        printf("Enter your date of birth: ");
        scanf("%s",u2.date_of_birth);
        printf("Enter your Pin: ");   // take pin from the user.
        scanf("%d",&u2.pin);
        printf("Enter your Nid number: ");
        scanf("%d",&u2.nid);
        p = u2.pin;
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
