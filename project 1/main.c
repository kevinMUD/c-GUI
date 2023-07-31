#include<stdio.h>
#include <stdlib.h>
struct book
{
    char names[20];
    char site[30];
    int pay;
};
struct site
{
    char site_name[20];
    char trip_date[11];
    int site_price;
};
FILE *a,*b;
void add()
{
    FILE *booking;
    struct book b;
    printf("\t\t\t TRIP BOOKING PANEL\n");
    printf("\t\t\t ===================\n\n");
    printf("Enter client's names : \n");
    scanf("%s",&b.names);
    printf("\n Available sites\n");
    trip_a();
     printf("Enter a site: \n");
    scanf("%s",&b.site);
    printf("Enter paid amount: \n");
    scanf("%d",&b.pay);
    booking=fopen("Clients.txt","a");
    fprintf(booking,"\t%s\t\t%s\t\t%d",b.names,b.site,b.pay);
    fclose(booking);
        printf("\n Successfully added!");


}
void client()
{
FILE *cl;
struct book c;
printf("\t\t\t CLIENTS' LIST\n");
printf("\t\t\t==============\n\n");
cl=fopen("Clients.txt","r");
printf("\n\t Name \t\t Site \t\t Payment made\n");
while (!feof(cl))
    {
    fscanf(cl,"\t%s\t\t%s\t\t%d",&c.names,&c.site,&c.pay);
printf("\t%s\t\t%s\t\t%d\n", c.names,c.site,c.pay);
}
fclose(cl);
}
void trip ()
{


    struct site c;
    int i;
printf("\t\tAVAILABLE TRIPS PANEL\n ");
printf("\t\t=====================\n\n");
printf("\t 1. Available sites \n \t 2. Add new sites\n\n");
printf("\tEnter your choice: ");
scanf("%d",&i);
switch(i)
{
case 1:
    system("cls");
    trip_a();
    break;
case 2:
    system("cls");
    trip_b();
    break;
default:
    system(0);
}
}
void trip_a()
{

struct site z;
a=fopen("site.txt","r");
printf("\n\t Name \t\t Date \t\t Price\n");
while (!feof(a))
    {
    fscanf(a,"\t%s\t\t%s\t%d",&z.site_name,&z.trip_date,&z.site_price);
printf("\t%s\t\t%s\t%d\n", z.site_name,z.trip_date,z.site_price);
}
fclose(a);
}
void trip_b()
{
    struct site z;
    printf("Enter site's names : \n");
    scanf("%s",&z.site_name);
     printf("Enter the date (D/M/Y): \n");
    scanf("%s",&z.trip_date);
    printf("Enter the price: \n");
    scanf("%d",&z.site_price);
    b=fopen("site.txt","a");
    fprintf(b,"\t%s\t%s\t%d",z.site_name,z.trip_date,z.site_price);
    fclose(b);
        printf("\n Successfully added!");

}
void search()
{
char key[20];
FILE *cl;
struct book b;
printf("Enter the name you're searching for: ");
scanf("%s",&key);
cl=fopen("Clients.txt","r");
while (!feof(cl)){
        fscanf(cl,"\t%s\t\t%s\t\t%d\n",&b.names,&b.site,&b.pay);
        if(b.names==key)
            {
    printf("\n%s%s%d",b.names,b.site,b.pay);
    fclose(cl);
    return 0;
        }}
        printf("\n Client not found!");
fclose(cl);
}
int main()
{
    int p;
    printf("\t\t\t WELCOME TO B TOURS MANAGEMEMT SYSTEM");
    printf("\n\t\t\t=====================================\n\n");
    do
    {
        printf(" 1.BOOKING \t 2.CLIENTS \t 3.TRIPS \t 4.SEARCH CLIENT 5.EXIT\n\n");
        printf ("Enter your choice : ");
        scanf("%d",&p);
        switch(p){
    case 1:
        system("cls");
        add();
        printf("\n");
        break;
        // function for booking a client
    case 2:
        system("cls");
        client();
        printf("\n");
        // function for displaying all clients
        break;
    case 3:
        system("cls");
        trip();
        printf("\n");
        // function for displaying all available trips and add more
        break;
    case 4:
        system("cls");
        search();
        printf("\n");
        // function for searching for a client
        break;
    case 5:
        exit (0);
        break;
    default:
        system(0);
        }
    }
    while (p=!5);

    return 0;
}

