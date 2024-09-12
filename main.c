#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct used {
    char name[100],dob[11];
    int pin,nid;
}u2;

struct used u1 = {"Sakib", "13/01/2000" , 1234, 12345678};
int next(void);
int pin(void);
int sd(void);
int registered(void);
int sendnon(void);
int recharge(void);
int cash_out(void);
int payment(void);
int nonreg(void);





int sd(void){
    int pn;
    int p;
    scanf("%d",&p);
    if (p == pn) {
        printf("Success");
    }
    else{
        printf("Failed");
    }
    
    
    return 0;
}

int sendnon(void){
    
    return 0;
}


int recharge(void){
    
    
    return 0;
}

int payment(void){
    
    
    return 0;
}



int cash_out(void)
{
    
    
    
    return 0;
}



int next(void){
    int c;
    printf("What type of operatiobn you want to do with: \n1. Send Money\n2. Send Money to non user\n3. Mobile Recharge\n4. Payment\n5. Cash Out\n");
    scanf("%d",&c);
    
    switch (c) {
        case 1:
            sd();
            
        case 2:
            sendnon();
        default:
            break;
    }
    
    
    return 1;
}


int registered(void){
    
   
    
    
    next();
    return 1;
}

int nonreg(void){
    printf("Enter your name: ");
    scanf("%s",u2.name);
    printf("Enter your date of birth: ");
    scanf("%s",u2.dob);
    printf("Enter your Pin: ");
    scanf("%d",&u2.pin);
    printf("Enter your Nid number: ");
    scanf("%d",&u2.nid);
    next();
    return 1;
}

int pin(void){
    
    int p;
    if (u2.pin) {
        p = u2.pin;
    }
    else{
        p = u1.pin;
    }
    
    return p;
}

int main(void) {
    
            
        int r;
        
        printf("**** Welcome to the mobile wallet management System ****\n");
        printf("What types of user you are: ");
        printf("\n1. Registered. \n2. Non-Registered\n");
        scanf("%d",&r);
        
        if (r == 1) {
            registered();
        }
        else if (r == 2){
            nonreg();
        }
    
    
    
    
    return 0;
}
