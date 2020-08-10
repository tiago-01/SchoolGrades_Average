#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

/*
Construa um algoritmo que leia as três notas de
50 alunos de uma turma. Para cada aluno, calcule a
média ponderada, como segue:
MP = ( n1*2 + n2*4 + n3*3 ) / 10. Além disso,
calcule a média geral da
turma. Mostre a média de cada aluno e uma mensagem "Aprovado",
caso a média seja maior ou igual a
sete, e uma mensagem "Reprovado", caso contrário. No final,
mostre a média geral
*/

void checkifexists(struct aluno *a);
int checkifisvalid(int n);

struct student{
	int n;
    float g1;
    float g2;
    float g3;
    float avg;
};

struct schoolclass{
	struct student students[5];
    float avg;
};

void checkifexists(struct student *a){
	int i=0;
	int n=0;
	here:
	scanf("%i",&n);
	for (i=0;i<5;i++){
		if (a[i].n==n){
			printf("Existing number\nWrite the right one: ");
			goto here;
		}
		a[i].n=n;
	}
}

int checkifisvalid(int n){  
	if (n>=0 && n<=20){
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
	   grades = students[i].g1 + students[i].g2 + students[i].g3;
	   sumgrades = sumgrades + grades;	
	 }
	 c->avg = sumgrades / 15;
	 printf("\nClass average: %0.2f\n",c->avg);
	 
}

void grades(struct student *a){
	int i=0; int n=0; float g1=0; float g2=0; float g3=0;
    
	for (i=0;i<5;i++){
		printf("Student number':");
		checkifexists(a);
		
		g1:	
		printf("Grade 1 = ");
		scanf("%f",&g1);
		if (checkifisvalid(g1)==1){
			a[i].g1=g1;
		} else {
			goto g1;
		}
		
		g2:
		printf("Grade 2 = ");
		scanf("%f",&g2);
	    if (checkifisvalid(g2)==1){
			a[i].g2=g2;
		} else {
			goto g2;
		}
		
		g3:
		printf("Grade 3 = ");
		scanf("%f",&g3);
	    if (checkifisvalid(g3)==1){
			a[i].g3=g3;
		} else {
			goto g3;
		}
		
		a[i].avg=(a[i].g1 + a[i].g2 + a[i].g3 ) / 3;
		if (a[i].avg >=10){
			printf ("The student number %i passed with an average of: %0.2f\n",a[i].n,a[i].avg);
		} else {
			printf ("he student number %i did not pass. Average: %0.2f\n",a[i].n,a[i].avg);
		}	
	}
}


int main(){
	struct student a;
	grades(&a);
	struct schoolclass b;
	class_average(&b,&a);
	return 0;
}
