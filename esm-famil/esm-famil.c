#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
void search_add_name(char name[30])
{
	FILE *fname=fopen("name.dat","r");
	char temp[30];
	while(feof(fname)==0)
		{
			fscanf(fname," %s",temp);
			if(strncmp(name,temp,strlen(temp)-1)==0)
				{
					fclose(fname);
					return;
				}
		}
	fname=fopen("name.dat","a");
	fprintf(fname,"%s\n",name);
	fclose(fname);
	return;
	/*FILE *fname=fopen("name.dat","r");
	char temp[30];
	while(fgets(temp,40,fname)!=NULL)
		{
			if(strncmp(name,temp,strlen(temp)-1)==0)
				{
					fclose(fname);
					return;
				}
		}
	fclose(fname);
	fname=fopen("name.dat","a");
	fprintf(fname,"%s\n",name);
	fclose(fname);
	return;*/
}
void search_add_city(char city[30])
{
	FILE *fcity=fopen("city.dat","r");
	char temp[30];
	while(feof(fcity)==0)
		{
			fscanf(fcity," %s",temp);
			if(strncmp(city,temp,strlen(temp)-1)==0)
				{
					fclose(fcity);
					return;
				}
		}
	fcity=fopen("city.dat","a");
	fprintf(fcity,"%s\n",city);
	fclose(fcity);
	return;
}
char* select_name(char* name,char ch)
{
	int n=0,x,i=0;
	FILE *fname=fopen("name.dat","r");
	if(fname==NULL)
    {
        printf("Can't Find Files \n");
        return;
    }
    while(fgets(name,40,fname)!=NULL)
    	{
			if(name[0]==ch || name[0]==toupper(ch)) n++;
		}
	x=rand()%n+1;
	rewind(fname);
	for(i=0;i<x;)
		{
			fscanf(fname," %s",name);
			if(name[0]==ch || name[0]==toupper(ch)) i++;
		}
	fclose(fname);
	return name;
}
char* select_city(char*city,char ch)
{
	int n=0,x,i=0;
	FILE *fcity=fopen("city.dat","r");
	if(fcity==NULL)
    {
        printf("Can't Find Files \n");
        return;
    }
    while(fgets(city,40,fcity)!=NULL)
    	{
			if(city[0]==ch || city[0]==toupper(ch)) n++;
		}
	x=rand()%n+1;
	rewind(fcity);
	for(i=0;i<x;)
		{
			fscanf(fcity," %s",city);
			if(city[0]==ch||city[0]==toupper(ch)) i++;
		}
	fclose(fcity);
	return city;
}
int main()
{
	srand(time(NULL));
	char z;
	do
	{
	int c=rand()%4+1;
	char name[30],city[30],comname[30],comcity[30];
	int user=0,computer=0;
	if (c==1)
		{
			char ch='a';
			printf("Enter a name start with A:");
			gets(name);
			printf("Enter name of a city start with A:");
			gets(city);
			select_name(comname,ch);
			select_city(comcity,ch);
			printf("\ncomputer selected name: %s",comname);
			printf("\tcomputer selected city: %s\n",comcity);
			if(name[0]!='a'&&name[0]!='A')
				{
					user+=0;
					computer+=10;
			
				}
			if(city[0]!='a'&&city[0]!='A')
				{
					user+=0;
					computer+=10;
		
				}
			if(strncmp(name,comname,strlen(comname)-1)==0)
				{
					user+=5;
					computer+=5;
				}
			if(strncmp(city,comcity,strlen(comcity)-1)==0)
				{
					user+=5;
					computer+=5;
				}
			if(strncmp(name,comname,strlen(comname)-1)!=0&& name[0]=='a')
				{
					user+=10;
					computer+=10;
					search_add_name(name);
				}
			if(strncmp(city,comcity,strlen(comcity)-1)!=0&& city[0]=='a')
				{
					user+=10;
					computer+=10;
					search_add_city(city);
				}
		}
	if (c==2)
		{
			char ch='b';
			printf("Enter a name start with B:");
			gets(name);
			printf("Enter name of a city start with B:");
			gets(city);
			select_name(comname,ch);
			select_city(comcity,ch);
			printf("\ncomputer selected name: %s",comname);
			printf("\tcomputer selected city: %s\n",comcity);
			if(name[0]!='b'&&name[0]!='B')
				{
					user+=0;
					computer+=10;
		
				}
			if(city[0]!='b'&&city[0]!='B')
				{
					user+=0;
					computer+=10;
		
				}
			if(strncmp(name,comname,strlen(comname)-1)==0)
				{
					user+=5;
					computer+=5;
				}
			if(strncmp(city,comcity,strlen(comcity)-1)==0)
				{
					user+=5;
					computer+=5;
				}
			if(strncmp(name,comname,strlen(comname)-1)!=0&& name[0]=='b')
				{
					user+=10;
					computer+=10;
					search_add_name(name);
				}
			if(strncmp(city,comcity,strlen(comcity)-1)!=0&& city[0]=='b')
				{
					user+=10;
					computer+=10;
					search_add_city(city);
				}
		}
	if (c==3)
		{
			char ch='c';
			printf("Enter a name start with C:");
			gets(name);
			printf("Enter name of a city start with C:");
			gets(city);
			select_name(comname,ch);
			select_city(comcity,ch);
			printf("\ncomputer selected name: %s",comname);
			printf("\tcomputer selected city: %s\n",comcity);
			if(name[0]!='c'&&name[0]!='C')
				{
					user+=0;
					computer+=10;
			
				}
			if(city[0]!='c'&&city[0]!='C')
				{
					user+=0;
					computer+=10;
			
				}
			if(strncmp(name,comname,strlen(comname)-1)==0)
				{
					user+=5;
					computer+=5;
				}
			if(strncmp(city,comcity,strlen(comcity)-1)==0)
				{
					user+=5;
					computer+=5;
				}
			if(strncmp(name,comname,strlen(comname)-1)!=0&& name[0]=='c')
				{
					user+=10;
					computer+=10;
					search_add_name(name);
				}
			if(strncmp(city,comcity,strlen(comcity)-1)!=0&& city[0]=='c')
				{
					user+=10;
					computer+=10;
					search_add_city(city);
				}
		}
	if (c==4)
		{
			char ch='d';
			printf("Enter a name start with D:");
			gets(name);
			printf("Enter name of a city start with D:");
			gets(city);
			select_name(comname,ch);
			select_city(comcity,ch);
			printf("\ncomputer selected name: %s",comname);
			printf("\tcomputer selected city: %s\n",comcity);
			if(name[0]!='d'&&name[0]!='D')
				{
					user+=0;
					computer+=10;
	
				}
			if(city[0]!='d'&&city[0]!='D')
				{
					user+=0;
					computer+=10;
		
				}
			if(strncmp(name,comname,strlen(comname)-1)==0)
				{
					user+=5;
					computer+=5;
				}
			if(strncmp(city,comcity,strlen(comcity)-1)==0)
				{
					user+=5;
					computer+=5;
				}
			if(strncmp(name,comname,strlen(comname)-1)!=0&& name[0]=='d')
				{
					user+=10;
					computer+=10;
					search_add_name(name);
				}
			if(strncmp(city,comcity,strlen(comcity)-1)!=0&& city[0]=='d')
				{
					user+=10;
					computer+=10;
					search_add_city(city);
				}
		}
	printf("user:%d				computer:%d\n",user,computer);
	printf("\n\tAnother round?(y/n):");
	scanf(" %c",&z);
    char tmp[1];
    gets(tmp);
	printf("\n");
	}while(z=='y');

}
