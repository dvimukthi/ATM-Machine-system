#include <stdio.h>
#include <windows.h>
#include <time.h>


int main()
{
    system("color 3F");
    int pin = 1234,option,enteredPin,count=0,amount=1;
    float balance = 5000;
    int continueTransaction = 1;

    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t            %s",ctime(&now));
    printf("\n\t\t\t====================*Welcome To ATM Machine*====================");

    while(pin != enteredPin){
       printf("\nPlease Enter Your Pin :");
       scanf("%d",&enteredPin);
       if(enteredPin != pin){
        Beep(610,500);
        printf("Invalid Pin!!!");
       }
        count++;
        if(count == 3 && pin != enteredPin){
            exit(0);
        }
    }
    while(continueTransaction != 0){
        printf("\n\t\t\t====================*Available Transactions*====================");
        printf("\n\n\t\t1.Withdrawl");
        printf("\n\n\t\t2.Deposit");
        printf("\n\n\t\t3.Check Balance");
        printf("\n\n\t\tPlease Select The Option : ");
        scanf("%d",&option);

        switch(option){

        case 1:
            while(amount % 500 != 0){
                printf("\n\t\tEnter the Amount : ");
                scanf("%d",&amount);
                if(amount % 500 !=0)
                    printf("\n\t The Amount Should Be Multiple Of 500");
            }
            if(balance < amount){
                printf("\n\t Sorry Insufficient Balance");
                amount = 1;
                break;
            }
            else {
                balance -= amount;
                printf("\n\t\tYou Have Withdrawn Rs.%d. Your New Balance Is %.2f",amount,balance);
                printf("====================*Thank You For Banking With Us*====================");
                amount = 1;
                break;
            }

        case 2:
            printf("\n\t\t Please Enter The Amount : ");
            scanf("%d",&amount);
            balance +=amount;
            printf("\n\t\tYou Have Deposited Rs.%d. Your New Balance is %.2f",amount,balance);
            printf("====================*Thank You For Banking With Us*====================");
            amount =1;
            break;

        case 3:
            printf("\n\t\t Your Balance Is Rs.%.2f",balance);
            break;

        default:
            Beep(610,500);
            printf("\n\t\t Invalid Option!!!");
        }

        printf("\n\t\tDo You Wish To Perform Another Transaction?Press 1[Yes], 0[No]");
        scanf("%d",continueTransaction);
    }



    return 0;
}
