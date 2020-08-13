#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

/*
Build an algorithm to read 3 grades of a class with 5 students. 
For each student, calculate the average like: avg = (g1 + g2 + g3)/3. 
Grades are between 0(lowest) and 20(maximum).
Besides that, calculate the class average. 
Show the students average with a message like "Aproved" case the average is greater than 10 or "Failed" if below 10.
*/

void checkifexists(struct aluno *a);
int checkifisvalid(int n);

struct student{
	int number;
    float grade1;
    float grade2;
    float grade3;
    float average;
};

struct schoolclass{
	struct student students[5];
    float average;
};

void checkifexists(struct student *a){
	int i=0;
	int number=0;
	here:
	scanf("%i",&number);
	for (i=0;i<5;i++){
		if (a[i].number==number){
			printf("Existing number\nWrite the right one: ");
			goto here;
		}
		a[i].number=number;
	}
}

int checkifisvalid(int number){  
	if (number >= 0 && number <= 20){
		 return true;
	    } else {
	    	printf("Grade not valid\n");
	    	return false;
	    }	
}

void class_average(struct schoolclass *c,struct student *students){
	 int i = 0;
	 float sumgrades = 0;
	 float grades = 0;
	 for(i=0;i<5;i++){
	   grades = 0;
	   grades = students[i].grade1 + students[i].grade2 + students[i].grade3;
	   sumgrades = sumgrades + grades;	
	 }
	 c->average = sumgrades / 15;
	 printf("\nClass average: %0.2f\n",c->average);
	 
}

void getgrades(struct student *a){
	int i = 0; 
	int number = 0; 
	float grade1 = 0; float grade2 = 0; float grade3 = 0;
    
	for (i=0;i<5;i++){
		printf("Student number':");
		checkifexists(a);
		
		g1:	
		printf("Grade 1 = ");
		scanf("%f",&grade1);
		if (checkifisvalid(grade1)==1){
			a[i].grade1=grade1;
		} else {
			goto g1;
		}
		
		g2:
		printf("Grade 2 = ");
		scanf("%f",&grade2);
	    if (checkifisvalid(grade2)==1){
			a[i].grade2=grade2;
		} else {
			goto g2;
		}
		
		g3:
		printf("Grade 3 = ");
		scanf("%f",&grade3);
	    if (checkifisvalid(grade3)==1){
			a[i].grade3=grade3;
		} else {
			goto g3;
		}
		
		a[i].average=(a[i].grade1 + a[i].grade2 + a[i].grade3 ) / 3;
		if (a[i].average >=10){
			printf ("The student number %i passed with an average of: %0.2f\n",a[i].number,a[i].average);
		} else {
			printf ("he student number %i did not pass. Average: %0.2f\n",a[i].number,a[i].average);
		}	
	}
}


int main(){
	struct student a;
	getgrades(&a);
	struct schoolclass b;
	class_average(&b,&a);
	return 0;
}
