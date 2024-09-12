
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

struct used {
    char name[100],dob[11];
    int pin,nid;
}u2;
int choice(void);
int rando(void);


int rando(void){
    while (1) {
        long int a = random(),b;
        printf("\nYour security code is: %ld",a);
        printf("\nEnter security code: ");
        scanf("%ld",&b);
        if (a == b) {printf("Account create successful");
            return 0;}
        else{printf("Failed");
            rando();
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
        struct used u1 = {"Sakib", "13/01/2000" , 1234, 12345678};
        p= u1.pin;
    }

    else if (r == 2){
        
        printf("Enter your name: ");
        scanf("%s",u2.name);
        printf("Enter your date of birth: ");
        scanf("%s",u2.dob);
        printf("Enter your Pin: ");
        scanf("%d",&u2.pin);
        printf("Enter your Nid number: ");
        scanf("%d",&u2.nid);
        p = u2.pin;
        rando();
        printf("\n");
    }
    return p;
}





int main(void) {

    int pn = choice();
    //next();
    
    int c,p,num,am,bal = 100000,out;
  
    while (1) {
        
        printf("What type of operatiobn you want to do with: \n1. Send Money\n2. Send Money to non user\n3. Mobile Recharge\n4. Payment\n5. Cash Out\n6. ");
        scanf("%d",&c);
        
        if (c==1) {
            printf("Enter wallet number which you want to send money : ");
            scanf("%d",&num);
            printf("Enter the amount: ");
            scanf("%d",&am);
            printf("Enter your pin: ");
            scanf("%d",&p);
            if (p == pn) {
                printf("Success");
                bal = bal-am;
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
            scanf("%d",&am);
            printf("Enter your pin: ");
            scanf("%d",&p);
           
            if (p == pn) {
                printf("Success");
                bal = bal-am;
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
            scanf("%d",&am);
            printf("Enter your pin to confirm: ");
            scanf("%d",&p);
            if (p == pn) {
                printf("%d bdt was successfully recharge to %d.",num,am);
                bal = bal - am;
            }
            else{
                printf("Pin number is not correct.");
            }
            printf("\n");
        }
        
        else if (c == 4){   //payment
            
        }
        
        
        else if (c == 5){   //cash out
            printf("By which service you want to cash out:\n1. ATM Bank.\n2. Agent.\n");
            scanf("%d",&out);
            
            if (out == 1) {
                printf("Entr your amount: ");
                scanf("%d",&am);
                printf("Enter your pin to confirm : ");
                scanf("%d",&p);
                if (p == pn) {
                   long int ra = random();
                    printf("Your generated code is : %ld\n",ra);
                    printf("Enter the above code to ATM machine.");
                    bal = bal - am;
                }
                else{
                    printf("Wrong Pin code.");
                }
            }
            else if (out == 2){
                printf("Enter the agent number to cash out: ");
                scanf("%d",&num);
                printf("Entr your amount: ");
                scanf("%d",&am);
                printf("Enter your pin to confirm : ");
                scanf("%d",&p);
                
                if (p == pn) {
                    printf("Cash out to number: %d and amount: %d was successful.",num,am);
                    bal = bal - am;
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
        printf("balance: %d\n", bal);
    }
    return 0;
}
