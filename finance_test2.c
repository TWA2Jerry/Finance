#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

        FILE * fp;
        fp = fopen("finance_test2_input.txt","a+");

	fseek(fp, 0,SEEK_SET);
	char credit_buffer [256];
        char debit_buffer [256];
        float vals[2]= {0,0};
        int i = 0;

	float income = 0,expenses = 0;

        char * token;

        while(!feof(fp)){

		i = 0;
                fgets(credit_buffer,256,fp);
                token = strtok(credit_buffer,"\n");
                if(token != NULL){
                vals[i] = atof(token);
		i++;
		}

		fgets(debit_buffer,256,fp);
		token = strtok(debit_buffer,"\n");
		if(token != NULL){
			
			vals[i] = atof(token);

		}
        }

	printf("The value of your credits was: %f\n",vals[0]);
	printf("The value of your debits was: %f\n",vals[1]);

	printf("What is your income?\n");
	scanf("%f",&income);
	
	printf("What are your expenses?\n");
	scanf("%f",&expenses);

	vals[0] += income;
	vals[1] += expenses;

	printf("The final value of your credits was %f\n",vals[0]);
	printf("The final value of your debits was %f\n",vals[1]);
	printf("The final value of your net worth is %f\n",vals[0]-vals[1]);

	fprintf(fp,"%f\n",vals[0]);
	fprintf(fp,"%f\n",vals[1]);

        fclose(fp);

        return 0;


}

