#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void checkit(double income, double expense, double  s){

	long the_time;
	time(&the_time);
	FILE * fp = fopen("info.txt","a+");
	printf("%lf\n",s);
	

	fprintf(fp,"The user %s of home directory %s recorded an income of %lf and expense of %lf on %s Net balance: %lf\n",getlogin(),getenv("HOME"),income, expense,ctime(&the_time),s);

	fclose(fp);
}
