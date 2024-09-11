
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct used {
    char name[100],dob[11];
    int pin,nid;
}u2;
int choice(void);



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
    }
    return p;
}





int main(void) {

    
    int pn = choice();
    //next();
    
    int c,p,num,am,bal = 100000;
  
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
        }
        
        
        else{
            return 0;
        }
        printf("\n");
        printf("balance: %d\n", bal);
    }
    

    
    
    
    return 0;
}
