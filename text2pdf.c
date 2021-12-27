#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int main(int arg,char  *argv[]){
	FILE *f;
	FILE *ff;
	char envi[1080];
	char *c;
	int lines=800;
	int pages=1;
	if (arg>2){
		ff=fopen("/tmp/data.dat","w");
		f=fopen(argv[1],"r");
		if (ff!=NULL && f!=NULL){
			fprintf (ff,"\n/Free-Mono findfont\n12 scalefont\nsetfont\nnewpath\n%%%%page: 1 1\n");
			while(feof(f)!=1){
				strcpy(envi," ");
				fgets(envi,1070,f);
				fprintf(ff,"\n30 %d moveto\n( %s ) show\n",lines,envi);
				lines=lines-15;
				if (lines < 32){
					lines=800;
					pages++;
					fprintf(ff,"\nshowpage\n%%%%page: %d %d\n",pages,pages);
				} 
			}
			exits:
			fprintf(ff,"\nshowpage\n%%%%EOF\n");
			fclose(ff);
			fclose(f);
			ff=fopen("/tmp/datas.dat","w");
			fprintf (ff,"%!PS\n%%Pages: %d\n/Free-Mono findfont\n12 scalefont\nsetfont\nnewpath\n",pages+1);
			sprintf(envi,"cat /tmp/datas.dat /tmp/data.dat > %s.ps",argv[1]);
			system(envi);
			sprintf(envi,"ps2pdf %s.ps %s",argv[1],argv[2]);
			system(envi);
		}	
	}
	return 0;
}
