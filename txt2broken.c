#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char *argv[]){
	char envi[1080];
	char e[1080];
	char ss[80];
	char s[80];
	char *c;
	int n;
	int nn;
	FILE *f;
	printf("\ec\n\e[44;36m\n\n");
	if (argc<1) exit(0);
	strcpy(envi,argv[1]);
	n=atoi(envi);
	f=fopen("/dev/stdin","r");
	while(feof(f)!=1){
			strcpy(envi,"");
			fgets(envi,1070,f);
			nn=0;
			c=envi;
		
			while(nn!=1){
				if (strlen(c)>n){
					strncpy(e,c,n);
					e[n]=0;
					printf("%s\n",e);
					c=c+n;
				}else{
					printf("%s",c);
					nn=1;
				}
			}
			
		
	}
	
	return 0;
}
