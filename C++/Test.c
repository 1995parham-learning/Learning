//#define _GNU_SOURCE
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <complex.h>
#include <limits.h>
#include <stdarg.h>
#include <math.h>
#include <error.h>
#include <malloc.h>
#include <mcheck.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc,char *argv[]){
	printf("this is a test \n");
	/*union fuck{    //Test 1
		int n;
		int m;
	};
	union fuck f={.n=10};
	printf("The value of n after declare is %d\n",f.n);
	f.m=100;
	printf("The value of n & m after declare m is %d && %d\n",f.n,f.m);*/
	/*for(int i=0;i<10;i++){	//Test 2
		for(int j=0;j<10;j++){
			static int sum=0;
			sum++;
			printf("%d ",sum);
		}
		printf("\n");
	}*/
	/*const int* P1; //Test 3
	P1=(int *)12321321;
	printf("%d\n",*P1);*/
	/*union fuck{	//Test 4 
		int n;
		int m;
	};
	union fuck f={.n=10};
	union fuck* fp;
	fp=&f;
	printf("%X\n",fp);*/
	/*struct point;
	struct point *P;
	printf("%X\n",P);
	struct point{
		int x;
		int y;
	};
	printf("%d - %d\n",P->x,P->y);*/
	/*complex int x=10+10i; //Test 5
	printf("%d \n",(int)(x*~x));*/
	/*int d=12; //Test 6
	int m=6;
	int y=1983;
	int x=(((y<<4)+m)<<5)+d;
	printf("%d / %d / %d\n",x%32,(x>>5)%16,x>>9);*/
	/*fuck : printf("I am call for say fuck to u and then go\n");   //Test 7
	void* salam=&&fuck;
	goto *salam;*/
	/*int x,y; //Test 7
	scanf("%d %d",&x,&y);
	x*=2,y+=x;
	printf("%d %d\n",x,y);*/
	/*static int a=1;	//Test 8
	int f(){
		a=100;
		return 3;
	};
	printf("%d\n",a);
	int foo(){
		return ++a*f();
	};
	foo();
	int x=0;
	x=++x+1;
	printf("%d\n",x);
	printf("%d\n",a);*/
	/*for(int i=0;i<20;i++)	//Test 9
		printf("%s\n",strerror(i));*/
	/*int x=0;   //Test 10
	int foo(int n,int m){
		return n+m;
	}
	printf("%d\n",foo(++x,++x));
	int n=1,m=++n;
	printf("%d\n",m);*/
	/*static volatile int *P=(int*)0x111; 		//Test 11
	printf("I have error ???\t %X \n",*P);*/
	/*int n;		//Test 12
	scanf("%d",&n);
	switch(n){
		case 1 ... 10:
			printf("Your number in beetwin 1 and 10 and my english is suck !!!\n");
	}*/
	/*while(1){  //Test 12
		int n;
		int counter=INT_MAX+1;
		while(1){
			//scanf("%d",&n);
			if(n==13730321){
				counter;
				printf("Password is correct\n");
				break;
			}
			else if(counter++==INT_MAX)
				printf("You are fucking my program !!%d!! \n",counter);
			else
				printf("%d Password is not correct\n",counter);
		}
		printf("You are get superuser privileges\n");
		break;
	}*/
	/*char c;  //Test 13
	c=getchar();
	if(c=='\n')
		printf("You are enter enter :D and ascii code of enter is %d\n",c);
	else 
		printf("You enter character %c and it's ascii code is %d\n",c,c);
	int n;
	scanf("%d",&n);
	printf("%d\n",n);
	scanf("%x",&n);
	printf("%X\n",n);
	scanf("%i",&n);
	printf("%d\n",n);*/
	/*int func(int n, ... ){
		va_list A;
		va_start(A,n);
		for(int i=0;i<n;i++){
			int m;
			m=printf("%d\n",va_arg(A,int));
			printf("I count %d bit\n",m);
			
		}
		return 0;
	}
	func(10,1,2,3,4,5,6,7,8,9,10);*/
	/*int n;	//Test 14
	scanf("%d",&n);
	errno=0;
	double d=sqrt(n);
	if(errno==0)
		printf("%lf\n",d);
	else
		printf("Fuck u for wrong input !!! :D\n%s\n%s\n",strerror(errno),program_invocation_short_name);*/
	/*int ID=fork();	//Test 15
	printf("I am Program Number %d\n",atoi(argv[1]));
	printf("%d Iam printing now and my number is %d \n",ID,atoi(argv[1]));
	printf("I am doubling in here \n");*/
	/*int n;		//Test 15
	scanf("%d",&n);
	errno=0;
	double result=sqrt(n);
	if(errno!=0)
		error(1,errno,"Hey dude what wrong with u\n");
	else
		printf("%lf\n",result);
	printf("application successfully finish\n");*/
	/*printf("%d %d %d %d\n",sizeof(void *),sizeof(int *),sizeof(int),sizeof(char));	//Test 16
	int *a;
	int b=0;
	a=&b;
	printf("%p\n",a);
	a=(int *)memalign(16,128);
	printf("%p\n",a);
	a++;
	printf("%p\n",a);
	a++;
	printf("%p\n",a);
	printf("%d\n",getpagesize());*/
	/*mallopt(M_PERTURB,1);		//Test 17
	int n;
	printf("%d\n",n);
	int *p;
	p=(int *)malloc(sizeof(int));
	printf("%d\n",*p);*/
	/*mcheck(NULL);			//Test 18
	int* p;
	p=(int *)malloc(sizeof(int)*10);
	for(int i=0;i<10;i++)
		p++;
	enum mcheck_statuc ME=mprobe((void*)p);
	if(ME==MCHECK_OK)
		printf("Hey I am really ok\n");
	if(ME==MCHECK_TAIL)
		printf("Hey I am really mist\n");*/
	/*struct stat P; 	//Test 19
	stat("UVa",&P);
	printf("%ld\n",P.st_size);
	char *p;
	p=(char*)malloc(256);
	getcwd(p,256);
	printf("%s\n",p);
	struct termios t;
	speed_t baud;
	tcgetattr(fileno(stdout),&t);
	baud=cfgetospeed(&t);
	switch(baud){
		case B0:
			baud=0;
			break;
		case B50:
			baud=50;
			break;
		case B75:
			baud=75;
			break;
		case B110:
			baud=110;
			break;
		case B134:
			baud=134;
			break;
		case B150:
			baud=150;
			break;
		case B2400:
			baud=2400;
			break;
		case B19200:
			baud=19200;
			break;
	}
	printf("%d\n",baud);*/
	/*mkdir("SALAM",S_IROTH|S_IWOTH|S_IXOTH);*/	//Test 20
	/*char* buf;	//Test 21
	buf=(char*)get_current_dir_name();
	printf("%s\n",buf);
	DIR* dir;
	if(argc>1)
		dir=opendir(argv[1]);
	else
		dir=opendir(buf);
	struct dirent* dirent;
	while(1){
		dirent=readdir(dir);
		if(dirent==NULL)
			break;
		printf("%s\n",dirent->d_name);
	}*/
	/*int n;		//Test 22
	n=open("b.out",0);
	printf("n = %d\n",n);
	int m;
	m=open("b.out",0);
	printf("m = %d -- n = %d\n",m,n);*/
	//printf("%c[1;32mHello, world!\n", 27);	//Test 23
	/*int n=open("b.out",O_CREAT|O_RDWR,0777);	//Test 24
	printf("%d\n",n);
	//fprintf(stderr,"%d\n",close(1));
	//fprintf(stderr,"HI EVERY BODY I AM COMMING AFTER STDOUT IS CLOSE\n");
	const char* buf="salam salam to khobi";
	int len=strlen(buf);
	off_t seek=10;
	lseek(n,seek,SEEK_CUR);
	int check=write(n,buf,len);
	printf("%d\n",check);
	perror("hi see an error in writing in b.out");
	fsync(n);
	printf("I back !!!\n");
	lseek(n,seek,SEEK_SET);
	char* see;
	check=read(n,see,len);
	printf("%d\n",check);
	perror("hi see an error in reading in b.out");
	if(check==-1)
		return -1;
	see[check]='\0';
	printf("%s\n",see);
	close(n);*/
	/*FILE* fp=fopen("b.out","w+b");    //Test 25
	struct point{
		int x;
		int y;
	};
	struct point p={10,2};
	fwrite(&p,sizeof(p),1,fp);
	fseek(fp,0,SEEK_SET);
	struct point P;
	fread(&P,sizeof(P),1,fp);
	printf("%d %d\n",P.x,P.y);*/
}
