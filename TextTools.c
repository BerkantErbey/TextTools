#include <stdio.h>
#include <stdlib.h>/*free,calloc,malloc*/


#define MAX_PATH 1024
#define MAX_FILENAME 128
void ASCIItoText();
void printProcList();
void callProc(int processNo);


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
	printf("1. ASCII to Text\n");

}
void ASCIItoText()
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
	fgets(textFilePath,256,stdin);
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
		printf("Please enter the output file name\n");
		fgets(outFileName,sizeof(outFileName),stdin);
		puts(outFileName);
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
	/*switch(processNo)
	{
		case 1: ASCIItoText(); break;
	}*/
	if(processNo == 1)
		ASCIItoText();


	return ;
}
