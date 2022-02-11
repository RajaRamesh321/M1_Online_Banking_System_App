#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct user {
	char Mobile[50];
	char Acc_no[50];
	char Password[50];
	float Balance;
};

int main(){
	struct user user,usr;
	char filename[50],Mobile[50],Password[50],Mobile2[50];
	FILE *fp,*fptr;
	int opt,choice;
	int amount;
	char cont = 'y';
    printf("******************Wellcome to Raj Bank Pvt Limited********************");
	printf("\nWhat do you want to do?");
	printf("\n\n1.Register your new account");
	printf("\n2.Login to your account");

	printf("\n\nPlease enter your choice:\t");
	scanf("%d",&opt);
	if(opt == 1){
		system("clear");
		printf("\nEnter your account number:\t");
		scanf("%s",user.Acc_no);
		printf("Enter your phone number:\t");
		scanf("%s",user.Mobile);
		printf("Enter your new password:\t");
		scanf("%s",user.Password);
		user.Balance=0;
		stpcpy(filename,user.Mobile);
		fp=fopen(strcat(filename,".dat"),"w");
		fwrite(&user,sizeof(user),1,fp);
		if(fwrite != 0){
			printf("Succesfully registered");
		}
	}
	else if(opt == 2){
		system("clear");
		printf("\nPhone No.:\t");
		scanf("%s",Mobile);
		printf("Password:\t");
		scanf("%s",Password);
		fp = fopen(strcat(Mobile,".dat"),"r");
		if(fp == NULL) printf("Account number not registered with our Bank! please check your Account number");
		else {
			fread(&user,sizeof(struct user),1,fp);
			fclose(fp);
			if(!strcmp(Password,user.Password)){
				while(cont == 'y'){
				system("clear");
				printf("\n\tWelcome %s",user.Mobile);
				printf("\nPress 1 for balance inquiry");
				printf("\nPress 2 for adding Money");
				printf("\nPress 3 for cash withdraw");
				printf("\nPress 4 for online transfer");
				printf("\nPress 5 for changing password\n\n");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("Your current balance is Rs. %.2f",user.Balance);
						break;

					case 2:
						system("clear");
						printf("Enter amount to be added:\t");
						scanf("%d",&amount);
						user.Balance += amount;
						fp = fopen(Mobile,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) printf("\n\nYou have depostied Rs.%d",amount);
						fclose(fp);
						break;

					case 3:
						system("clear");
						printf("Enter withdrawl amount:\t");
						scanf("%d",&amount);
						if(amount % 500 != 0) printf("\nSorry amount should be multiple of 500");
						else if(amount>user.Balance) printf("\nSorry insufficeint balance");
						else {
							user.Balance -= amount;
						fp = fopen(Mobile2,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) printf("\n\nYou have withdrawn Rs.%d",amount);
						fclose(fp);
						}
						break;
					
					case 4:
						printf("Please enter the phone number to trasnfer balance:\t");
						scanf("%s",Mobile);
						printf("Enter the amount to transfer:\t");
						scanf("%d",&amount);
						if(amount > user.Balance) printf("\nSorry insufficent balance");
						else {
							fptr = fopen(strcat(Mobile,".dat"),"r");
							if(fptr==NULL) printf("Sorry number is not registered");
							else {
								fread(&usr,sizeof(struct user),1,fptr);
								fclose(fptr);
							
								usr.Balance += amount;
								
								fptr = fopen(Mobile,"w");
								fwrite(&usr,sizeof(struct user),1,fptr);
								if(fwrite != 0){
								// 	printf("ACcount:%s",usr.ac);
								// printf("\npassword%s",usr.password);
								// printf("\nphone%s",usr.phone);
								// printf("\nbalance%f",usr.balance);
									printf("Your trasfer is completed. You have trasnfered Rs.%d to %s",amount,usr.Mobile);
									fclose(fptr);
									user.Balance -= amount;
									strcpy(filename,user.Mobile);
									fp = fopen(strcat(filename,".dat"),"w");
									fwrite(&user,sizeof(struct user),1,fp);
									fclose(fp);
								}
							}
						}
						break;
					case 5:
						printf("\n\nPlease enter your old password:\t");
						scanf("%s",Password);
						if(!strcmp(Password,user.Password)){
							printf("\n\nPlease enter your new password:\t");
							scanf("%s",Password);
							strcpy(user.Password,Password);
							strcpy(filename,user.Mobile);
							fp = fopen(strcat(filename,".dat"),"w");
							fwrite(&user,sizeof(struct user),1,fp);
							fclose(fp);	
							printf("\nPassword succesfullly changed");
						}else printf("\nSorry your password is wrong");
					
					default:
					break;
				}//switch ends here
				printf("\n\nDo you want to continue?[y/n]:\t");
				scanf("%s",&cont);
				}
			}
			else {
				printf("Invalid password");
			}	
		}
		printf("\n\n***Thank you for banking with Raj Bank pvt Limted***\n\n");
	}
	
	return 0;
}