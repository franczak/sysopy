#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
//#include <sys/resource.h>
#include "list.h"

char * random_email(){
	char * result = malloc(sizeof(char)*20);
	strcpy(result,"aaaaaaaaa@gmail.com");
	for(int i=0;i<9;i++){
		result[i]=rand()%('z'-'a')+'a';
	}
	return result;
}
char * random_phone(){
	char * result = malloc(sizeof(char)*10);
	for(int i=0;i<9;i++){
		result[i]=rand()%10+'0';
	}
	result[9]='\0';
	return result;
}
char * random_address(char**cities){
	char * result = malloc(sizeof(char)*30);
	strcpy(result,cities[rand()%20]);
	strcat(result," randomstreet");
	char number[4] = {rand()%10+'0',rand()%10+'0',rand()%10+'0','\0'};
	strcat(result, number);
	return result;
}
node *create_person(char** names, char** surname, char** birthdays, char** cities){
	node *person1 ;//= (node*)malloc(sizeof(node));
	char* name=names[rand()%20];
	char* surnam=surname[rand()%20];
	char* birth=birthdays[rand()%20];
	char* address=random_address(cities);
	char* phone=random_phone();
	char* mail=random_email();
	person1=create_contact(name,surnam,birth,mail,phone,address);
	return person1;
	
}



int main(){
	char * name[]={"Karlyn","Dionna","Arlette","Felisha",
"Neda","Mohamed","Laurie","Krystina","Kira","Jason","Alida",
"Annice","Patrice","Lelah","Lynwood","Layla","Tiffani",
"Syreeta","Cathi","Milagro"};
	char * surname[]={"Dunmore","Hause","Skeens","Pease",
"Fulp","Sutterfield","Kindred","Morrell","Hoopes","Smyth",
"Belser","Bottorff","Watlington","Baldree","Corliss",
"Erbe","Kaylor","Houk","Berrios","Mayweather"};
	char * birthDate[]={"1961-10-28","1962-11-26","1963-08-22",
"1963-12-22","1965-03-06","1973-09-10","1974-12-09",
"1976-09-07","1976-10-21","1977-06-12","1978-07-14",
"1979-04-24","1981-05-03","1981-08-19","1982-10-26",
"1987-03-21","1990-03-25","1992-03-11","1994-07-02",
"1995-02-28"};
char * cities[]={"Yangon","Santiago","Bangalore","Seoul",
"Tehran","Durban","New York","Petersburg",
"Dongguan","Guangzhou","Hanoi","Moscow",
"Suzhou","Shenzhen","Sao Paulo","Lahore",
"Pyongyang","Kinshasa","Dhaka","Mumbai"};

struct timespec * real0 = malloc(sizeof(struct timespec));
	struct timespec * real1 = malloc(sizeof(struct timespec));
	struct timespec * real2 = malloc(sizeof(struct timespec));
	struct timespec * real3 = malloc(sizeof(struct timespec));
	struct timeval user0;
	struct timeval user1;
	struct timeval user2;
	struct timeval user3;
	struct timeval system0;
	struct timeval system1;
	struct timeval system2;
	struct timeval system3; 
	struct rusage * usage = malloc(sizeof(struct timespec));
	
	//checkpoint 0
	clock_gettime(CLOCK_REALTIME, real0);
	getrusage(RUSAGE_SELF,usage);
	user0 = usage->ru_utime;
	system0 = usage->ru_stime;
	printf("\nStarting program\nreal:%lld\nuser:%ld\nsystem:%ld\n",
		(long long)real0->tv_sec*1000000+real0->tv_nsec/1000,
		user0.tv_sec*1000000+user0.tv_usec,
		system0.tv_sec*1000000+system0.tv_usec
	);

	srand(time(NULL));
	node *tmp;
	list * lista = create_list();
	for(int i=0;i<100000;i++){
		tmp=create_person(name,surname,birthDate,cities);
		add_contact(lista,tmp);
	}



	return 0;
}
