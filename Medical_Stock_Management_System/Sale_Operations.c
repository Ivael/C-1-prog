#include"Category_Header.h"
#include"Drug_Header.h"
#include"Supplier_Header.h"
#include"Sale_Header.h"

int sale_operations()
{

    int choice,identifier;
    saleList List=readsalefile();
    drugList list=readdrugfile();
    do
    {
         printf("                           ************************************\n");
         printf("                           *           SALES OPERATIONS      * ");
         printf("\n                           ************************************ ");

        choice=displaySaleMenu();
         system("cls");

        switch(choice)
        {
        case 1:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n*****Research task*****");
            if(List==NULL){
                printf("\nThe sales list is empty.");
            }
            else
            {
                 printf("\nEnter the identifier of the sale you are looking for\n");
                char value3[10];
                scanf(" %s",value3);
                identifier=checkValidValue(value3);
                 saleList found=searchSale(List,identifier);
                 if(found!=NULL)
                    {
                    printf("\nSale successfully found !! \ nSales information:\n");
                    displaySale(found->data);
                    }
                else
                    printf("\nSale not found!");
            }
            break;

        case 2:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n*****Insert Task*****");
            if (list==NULL)
                printf("\nNo product available for sale\n");
            else
            {
             sale i=readSale(List,list);
            insertSale(&List,i);
            printf("\n-----------------------------------------------------------------------------------------------");
            printf("\nSale successfully added");
            }
            break;

        case 3:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n*****Update Task*****");
            if(List==NULL)
                printf("\nLa sales list is empty.");
            else
            {
                int i,j;
                printf("\nHow many sales do you want to update?\t");
                char value2[10];
                scanf(" %s",value2);
                j=checkValidValue(value2);
                for (i=0;i<j;i++)
                {
                    displaySaleList(List);
                    printf("\nEnter the identifier of the sale you wish to update: ");
                int id;
                char value[10];
                scanf(" %s",value);
                id=checkValidValue(value);
                saleList found=searchSale(List,id);
                if (found==NULL)
                    printf("\nSorry, the sale does not exist\n");
                else{
                printf("\nSale successfully found\n");
                List=updateSale(List,id,list );
                printf("\n\nSale successfully updated!");
                }

                }
            }
            break;
        case 4:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n*****Remove the stain*****");
            if(List==NULL)
                printf("\nThe sales list is empty.");
            else
            {
                int s,t;
                printf("\nHow many products do you want to cancel?");
                char value4[10];
                scanf(" %s",value4);
                t=checkValidValue(value4);
                displaySaleList(List);
                for (s=0;s<t;s++)
                {
                printf("\nEnter the identifier of the sale you wish to cancel: ");
                int id;
                scanf("%d",&id);

                List=deleteSale(List,id);
                printf("\n-----------------------------------------------------------------------------------------------");
                printf("\nSale successfully canceled!");
                }
            }
            break;
        case 5:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n*****Display task*****");
            if(List==NULL)
                printf("\nThe sales list is empty.");
            else
                {printf("\nList:\n");
                displaySaleList(List);}
            break;
        case 6:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n*****Calculation of total income*****");
            double total=computeTotalRevnue(List);
            displaySaleList(List);
            printf("\n\nThe total amount of sales you have made: \n");
            printf("\n\n\n      *****Total income :%.2lfFCFA*****\n",total);
            break;
        case 7 :
            break;
        }
          writedrugfile(list);
          writesalefile(List);
          printf("\n\nPress [ENTER] to return to the menu....\n");
          getchar();
          getchar();
          system("cls");
    }while(choice!=7);

    printf("***********************************************************************************************");
    printf("\n*                               BACK TO THE MAIN MENU                                        *\n");
    printf("***********************************************************************************************\n");

    return 0;

}
