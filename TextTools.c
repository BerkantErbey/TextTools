/*#################################### Includes ########################################*/
#include <stdio.h>/*printf,scanf,fscanf,fprintf,fopen,fclose*/
#include <stdlib.h>/*free,calloc,malloc*/
/*######################################################################################*/

/*#################################### Defines ########################################*/

#define MAX_PATH 1024
#define MAX_FILENAME 128

/*######################################################################################*/

/*################################## Function Prototypes ##############################*/

void ASCIITexttoBinary();
void printProcList();
void callProc(int processNo);

/*######################################################################################*/

int main(int argc, char const *argv[])
{
	int selectedProc;
	
	printProcList();
	scanf("%d",&selectedProc);
	callProc(selectedProc);







	return 0;
}
void printProcList()
{
	
	printf("Hi,please select the process below the list\n");
	printf("1. ASCII Text to Decimal\n");

}
void ASCIITexttoBinary()
{
	FILE *inPtr;
	FILE *outPtr;
	char choose;
	char textFilePath[256];
	char outFileName[128];
	char ch;

	//textFilePath 	= (char *)malloc(MAX_PATH * sizeof(char));
	//outFileName 	= (char *)malloc(MAX_FILENAME * sizeof(char));



	
	PROCSTART:printf("Enter the path\n");
	scanf("%s",textFilePath);
	printf("%s",textFilePath);

	//sscanf(stdin,"%s",textFilePath);
	//fgets(textFilePath,sizeof(textFilePath)-1,stdin);
	//sprintf(textFilePath,"%s ",stdout);
	//puts(textFilePath);
	if((inPtr = fopen(textFilePath,"r")) == NULL)
	{
		printf("This file can't open.\n");
		printf("Press A or a for try again // Press any key for quit\n");
		scanf("%c",&choose);
		if(choose =='A' || choose == 'a')
			goto PROCSTART;
		else
		{
			//free(textFilePath);
			//free(outFileName);
			return;
		}
	}
	else
	{
		printf("\nPlease enter the output file name\n");
		
		scanf("%s",outFileName);
		printf("%s",outFileName);
		if((outPtr = fopen(outFileName,"w")) == NULL)
		{
			printf("This file can't open.\nProgram Closing...\n");
			//free(textFilePath);
			//free(outFileName);
			fclose(inPtr);
			return;
		}
		else
		{
			while(fscanf(inPtr,"%c",&ch) != EOF)
			{
				fprintf(outPtr, "%d",(int)ch);
			}
				
			
			
		}




	}
	fclose(inPtr);
	fclose(outPtr);
	//free(textFilePath);
	//free(outFileName);

	return;
}
void callProc(int processNo)
{
	switch(processNo)
	{
		case 1: ASCIITexttoBinary(); break;
		case 2:
	}
	

	return ;
}
/*######################################################################################*/
/*											END											*/
/*######################################################################################*/
