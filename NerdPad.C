/*-------------------------------------------------*/
/*                     NerdPad                     */
/*-------------------------------------------------*/
/*  A very simple developed in C language notepad. */
/*-------------------------------------------------*/
/*             Developed by carlostojal            */
/*-------------------------------------------------*/
/*     https://github.com/carlostojal/NerdPad      */
/*-------------------------------------------------*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int menu();
void newNote();

int main()
{
    int menuOpt;
    do{
        menuOpt = menu();
        switch(menuOpt)
        {
            case 1:
                newNote();
                break;
        }
    }while(menuOpt!=0);
    return 0;
}

int menu()
{
    int opt;
    do{
        printf("\n** NerdPad **\n\n");
        printf("1. New note\n");
        printf("0. Exit\n\n");
        printf("Option: ");
        scanf("%d",&opt);
    }while(opt<0||opt>2);
    return opt;
}

void newNote()
{
    char ch;
    char filename[127];
    char output[255];
    int i=0;
    do{
        system("cls");
        printf("\n** NEW NOTE **\n");
        printf("CTRL + S to save.\n");
        printf("%d characters remaining.\n\n",255-i); //(total of characters) - (characters already written)
        printf("%s",output);
        ch=getch();
        if((255-i==0 && output[i]!=8) || output[i]==127) //if were already written 256 characters or del was pressed
            continue;
        if(ch==8 && i>=0) //if backspace was pressed
        {
            output[i--]='\0';
            continue;
        }
        if(ch==9)
            printf("    ");
        if(ch==13) //if enter was pressed
        {
            printf("\n");
            sprintf(output,"%s\n",output);
        }
        else if(ch==19) //if CTRL+S was pressed
            break;
        else //else, saves the written character to output string
            sprintf(output,"%s%c",output,ch);
        i++;
    }while(1);
    printf("\nFilename: ");
    scanf("%s",filename); //get filename
    FILE *file; //create a new FILE variable named "file"
    file = fopen(filename,"w"); //open file for write with the name "filename"
    fprintf(file,output); //write to file
    fclose(file); //close file
}
