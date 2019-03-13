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
        system("@cls||clear");
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
    char filename[127];
    char str[255];
    char output[255];
    int i=0;
    do{
        system("@cls||clear");
        printf("\n** NEW NOTE **\n");
        printf("CTRL + S to save.\n");
        printf("%d characters remaining.\n\n",255-i); //(total of characters) - (characters already written)
        printf("%s",output);
        str[i]=getch();
        if(255-i==0) //if were already written 255 characters
            continue;
        if(str[i]==8) //if backspace was pressed
        {
            str[i-1]='\0';
            i--;
            continue;
        }
        if(str[i]==13) //if enter was pressed
        {
            printf("\n");
            sprintf(output,"%s\n",output);
        }
        else if(str[i]==19) //if CTRL+S was pressed
            break;
        else //else, prints the written character and saves it to output string
        {
            printf("%c",str[i]);
            sprintf(output,"%s%c",output,str[i]);
        }
        i++;
    }while(1);
    printf("\nFilename: ");
    scanf("%s",filename); //get filename
    FILE *file; //create a new FILE variable named "file"
    file = fopen(filename,"w"); //open file for write
    fprintf(file,str); //write to file
    fclose(file); //close file
}
