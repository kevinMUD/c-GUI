# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct person
{
    int id;
    char name[20];
    char district[10];
    int Nvaccine;
    char day [10];
};

void record()
{
    struct person prs;
    FILE *p;
    p = fopen("speed.txt","w");
    printf("Enter information of christian:\n");
    printf("christian ID:\n");
    scanf("%s",prs.id);
    printf("name:\n");
    scanf("%d",&prs.name);
    printf("district:\n");
    scanf("%d",prs.district);
    printf("number of vaccine:\n");
    scanf("%s",prs.Nvaccine);
    printf("service day:\n");
    scanf("%d",prs.day);
    fprintf(p,"%s\t%d\t%d\t%s\t%d\n",prs.id,&prs.name,prs.district,prs.Nvaccine,prs.day);
    fclose(p);
    return;
}

void display()
{
    FILE *p;
    p = fopen("speed.txt","r");
    while(!feof(p))
    {
        struct person prs;
        fscanf(p,"%s\t%d\t%d\t%s\t%d\n",prs.id,&prs.name,prs.district,prs.Nvaccine,prs.day);
        printf("%s\t%d\t%d\t%s\t%d\n",prs.id,&prs.name,prs.district,prs.Nvaccine,prs.day);
    }

}

void service()
{
    struct person prs;
    char dayz[10];
    FILE *p;
    p = fopen("speed.txt","r");
    printf("Enter service to find day:\n");
    scanf("%s",dayz);

    while(!feof(p))
    {
        fscanf(p,"%s\t%d\t%d\t%s\t%d\n",prs.id,&prs.name,prs.district,prs.Nvaccine,prs.day);
        if(strcmp(dayz,prs.day)==0)
        {
            printf("%s\t%d\t%d\t%s\t%d\n",prs.id,&prs.name,prs.district,prs.Nvaccine,prs.day);
            exit(0);
        }
        else
        {
            service();
        }
    }


}

void organisation()
{
    int choice;
    printf("===========================\nWelcome to AUCA church\n===========================\n");
    do
    {

    printf("Enter your choice:\n");
    printf("1. Record\n2.Display\n3.Search\n0.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            record();
            break;
        case 2:
            display();
            break;
        case 3:
            service();
            break;
        case 0:
            break;
    }
    }while(choice!=0);
return;
}

void main(){
    organisation();

return;
}
