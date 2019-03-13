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
    printf("\n** NEW NOTE **\n");
    printf("CTRL + S to save.\n");
    printf("255 characters max.\n\n");
    do{
        str[i]=getch();
        if(str[i]==13)
        {
            printf("\n");
            sprintf(output,"%s\n",output);
        }
        else if(str[i]==19)
            break;
        else if(str[i]!=59)
        {
            printf("%c",str[i]);
            sprintf(output,"%s%c",output,str[i]);
        }
        if(str[i]==8)
            continue;
        i++;
    }while(255-i>0);
    printf("\nFilename: ");
    scanf("%s",filename);
    FILE *file;
    file = fopen(filename,"w");
    fprintf(file,str);
    fclose(file);
}
