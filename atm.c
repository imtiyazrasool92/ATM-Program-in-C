#include<stdio.h>
#include<stdlib.h>

char name[20];
unsigned int balance = 0;

void drawMain();
void drawFcash();
void withdraw(int);

int main(){

        int input;
        printf("Enter Name : ");
        scanf("%[^\n]s",name);
        printf("Add Balance : ");
        scanf("%u",&balance);


        while(1){
                drawMain();
                printf("Enter Input : ");
                scanf("%d",&input);
                if(input==1){
                        again:
                        system("clear");
                        drawFcash();
                        scanf("%d",&input);
                        if(input==1){
                                if(balance<2000){
                                        printf("Insufficient Balance\n");
                                        sleep(1);
                                } else {
                                        withdraw(2000);
                                }
                        } else if(input==2){
                                if(balance<1000){
                                        printf("insufficient Balance\n");
                                        sleep(1);
                                } else {
                                        withdraw(1000);
                                }
                        } else if(input==3){
                                if(balance<500){
                                        printf("insufficient Balance\n");
                                        sleep(1);
                                } else {
                                        withdraw(500);
                                }
                        } else if(input==4){
                                if(balance<200){
                                        printf("insufficient Balance\n");
                                        sleep(1);
                                } else {
                                        withdraw(200);
                                }
                        } else if(input==5){
                                system("clear");
                        } else {
                                goto again;
                        }
                } else if(input==2){
                        system("clear");
                        printf("Current Balance = %d\n\n",balance);
                } else if(input==3){
                        int tempCash = 0;
                        system("clear");
                        printf("Enter Amount : ");
                        scanf("%d",&tempCash);
                        if(balance<tempCash){
                                printf("insufficient Balance\n");
                                sleep(1);
                        } else {
                              withdraw(tempCash);
                        }
                } else if(input==4){
                        int tempCash = 0;
                        system("clear");
                        printf("Enter Amount : ");
                        scanf("%d",&tempCash);
                        if(tempCash<0){
                                system("clear");
                                printf("Error Cant Add -ve Amount");
                        } else
                        {
                                balance += tempCash;
                                system("clear");
                                printf("%d is Added to your account\n Now Current Balance is %d\n\n",tempCash,balance);
                        }
                        
                } else if(input==5){
                        system("clear");
                        printf("Thanks for using atm\n");
                        return 0;
                } else {
                        system("clear");
                        printf("Wrong Input\n");
                }
        }


}

void drawMain(){

        printf("-----------------------\n");
        printf("(1) - Fast Cash\n");
        printf("(2) - Check Balance\n");
        printf("(3) - Withdraw\n");
        printf("(4) - Add Cash\n");
        printf("(5) - Exit\n");
        printf("_______________________\n\n");

}

void drawFcash(){
        printf("-----------------------\n");
        printf("(1) - Rs 2000\n");
        printf("(2) - Rs 1000\n");
        printf("(3) - Rs 500\n");
        printf("(4) - Rs 200\n");
        printf("(5) - Back\n");
        printf("_______________________\n\n");
}

void withdraw(int cash){
        int tempcash = 0;
       if(cash%10==0){
               balance -= cash;
               system("clear");
               printf("%d is withdrawn from your Account\n",cash);
       } else {
               tempcash = cash%10;
               cash /= 10;
               cash *= 10;
                system("clear");
               printf("%d is withdrawn from your Account\n%d is not withdrable Amount\n\n",cash,tempcash);
       }
        
}