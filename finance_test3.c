#include <stdio.h>
#include <stdlib.h>

int main(void) {

	FILE * fp = fopen("finance_test2_input.txt","a+");
	float credits = 0;
	float  debits = 0;
	float income, expense;
	float net;

	fseek(fp,0,SEEK_SET);
	while(fscanf(fp,"%f",&credits) == 1){

		fscanf(fp,"%f",&debits);
		

	} 

	printf("Your current credit balance is: %f\n",credits);
	printf("Your current debit balance is: %f\n",debits);

	printf("What was your income?\n");
	scanf("%f",&income);
	printf("What was your expense?\n");
	scanf("%f",&expense);

	credits += income;
	debits += expense;
	net = credits-debits;
	printf("The calculated net balance was %f\n",net);
	checkit(income, expense, (double)net);	
	printf("Your final credit balance was: %f\n",credits);
	printf("Your final debit balance was: %f\n", debits);
	printf("Your final net balance was: %f\n", credits-debits);
	fprintf(fp,"%f\n",credits);
	fprintf(fp,"%f\n",debits);


	
	fclose(fp);

}
