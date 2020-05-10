#include"Category_Header.h"
#include"Drug_Header.h"
#include"Supplier_Header.h"
#include"Sale_Header.h"

int supplier_operations()
{


    supplierList List=readSupplierfile();
    drugList list=readdrugfile();
    int choice,choice1,identifier;
    char descrip[50];
    do
    {
            printf("                           **********************************\n");
            printf("                           *        SUPPLIER OPERATIONS  * ");
            printf("\n                           ********************************** ");
            choice=displaySupplierMenu();
            system("cls");
        switch(choice)
        {
        case 1:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Display task*****\n");
             printf("-----------------------------------------------------------------------------------------------\n");
             if(List==NULL)
                printf("\nThe supplier list is empty.");
                else{
            printf("All suppliers:\n");
            displaySupplierList(List);
             printf("\n-----------------------------------------------------------------------------------------------\n");
                }
            break;
        case 2:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Search and display task*****");
             printf("\n-----------------------------------------------------------------------------------------------\n");
            if(List==NULL)
                printf("\nThe supplier list is empty.");
            else
            {
                printf("\nWhich research method do you want to use? ");
            printf("\n[1] To search for the supplier by Id \ n [2] To search for the supplier by name\n");
             printf("\nEnter your choice\t");
              do
            {

                char value3[10];
                scanf(" %s",value3);
               choice1=checkValidValue(value3);
                if(choice1<=0||choice1>2)
                printf("Invalid entry. Please enter another number:\t ");
            }while(choice1<1||choice1>2);

             switch(choice1)
             {
             case 1:
                 printf("\nEnter the identifier of the supplier you are looking for:\t");
                 char value4[10];
        scanf(" %s",value4);
        identifier=checkValidValue(value4);
                 supplierList found=searchSupplier(List,identifier);
                 if(found!=NULL)
                    {
                    printf("\nSupplier successfully found! \ n Supplier information:\n");
                    printf("\n-----------------------------------------------------------------------------------------------\n");
                    displaySupplier(found->data);
                    }
                else
                    printf("\nSupplier not found!");
                    break;
             case 2:
                printf("\nEnter the name of the supplier you are looking for:\n");
                scanf(" %c",descrip);
                scanf("%[^\n]",descrip+1);
                supplierList found1=searchSupplierByName(List,descrip);
                 if(found1!=NULL)
                    {
                    printf("\nSupplier Finds! \n Supplier Information:\n");
                    printf("\n-----------------------------------------------------------------------------------------------\n");
                    displaySupplier(found1->data);
                    }
                else
                    printf("\nSupplier not found!");

                break;
            }
            }
            break;
        case 3:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Insert a stain*****\n");
             printf("-----------------------------------------------------------------------------------------------\n");
            int i,j;
            printf("\nHow many suppliers do you want to add??\t");
            char value[10];
        scanf(" %s",value);
       j=checkValidValue(value);
            for(i=0;i<j;i++)
            {
            printf("\n-----------------------------------------------------------------------------------------------\n");
            printf("\n*****Addition of supplier %d*****\n\n",i+1);
            supplier s=readSupplier(List,list);
            if(searchSupplierByName(List,s.name)!=NULL)
                 {
                    printf("\nThe supplier already exists");
                  continue;
                 }
            insertSupplier(&List,s);
            printf("\n-----------------------------------------------------------------------------------------------");
            printf("\nSupplier successfully adds!\n");

            }
            printf("-----------------------------------------------------------------------------------------------\n");



            break;
        case 4:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Update task*****");
             printf("\n-----------------------------------------------------------------------------------------------\n");
            if(List==NULL)
                printf("\nThe supplier list is empty.");
            else
            {
                int s,t;
                printf("\nHow many suppliers do you want to update?\t");
                char value1[10];
        scanf(" %s",value1);
        t=checkValidValue(value1);
                for(s=0;s<t;s++)
                {
                     printf("\n-----------------------------------------------------------------------------------------------\n");
                    printf("\n*****Supplier update %d*****\n\n",s+1);
                    displaySupplierList(List);
                     printf("\nEnter the provider ID you want to update:\t ");
                int id;
                char value2[10];
                scanf(" %s",value2);
                id=checkValidValue(value2);
                supplierList search=searchSupplier(List,id);
                if(search!=NULL)
                {
                    updateSupplier(List,id);
                    printf("\n-----------------------------------------------------------------------------------------------");
                    printf("\nSupplier successfully updated!");

                }

                else
                    printf("\nSupplier not found!");
                }
                  printf("\n-----------------------------------------------------------------------------------------------\n");


            }
            break;
        case 5:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Remove the stain*****");
             printf("\n-----------------------------------------------------------------------------------------------\n");
            if(List==NULL)
                printf("\nThe supplier list is empty.");
            else
            {
                int y,z;
                printf("\nHow many suppliers do you want to delete??\t");
                char valu[10];
        scanf(" %s",valu);
        z=checkValidValue(valu);
                for(y=0;y<z;y++)
                    {
                          printf("\n-----------------------------------------------------------------------------------------------\n");
                    printf("\n*****Suppression of supplier %d*****\n\n",y+1);
                    displaySupplierList(List);
                    printf("\nEnter the identifier of the supplier you wish to delete:\t ");
                    int id;
                    char val[10];
                    scanf(" %s",val);
                   id=checkValidValue(val);
                    supplierList search=searchSupplier(List,id);
                    if(search!=NULL)
                    {
                        List=deleteSupplier(List,id);
                        printf("\n-----------------------------------------------------------------------------------------------");
                        printf("\nSupplier successfully deletes!");

                    }
                  else
                    printf("\n!");
                    printf("\nSupplier not found-----------------------------------------------------------------------------------------------\n");

                    }

            }
            break;
        case 6:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Insert a product stain*****");
            printf("\n-----------------------------------------------------------------------------------------------\n");
            int h,f,g,k;
            if(List==NULL)
                printf("\nThe supplier list is empty.\n");
            else
            {
              printf("\nHow many suppliers do you want to add products for?\t");
           char va[10];
        scanf(" %s",va);
       f=checkValidValue(va);
            for(h=0;h<f;h++)
            {
            displaySupplierList(List);
            printf("\nTo which supplier do you want to insert the product (choose by ID):\t");
            int id;
            char v[10];
        scanf(" %s",v);
        id=checkValidValue(v);
            supplierList found=searchSupplier(List,id);
          if (found==NULL)
           {
             printf("\nThe supplier does not exist\n");
            }
          else
   {
            printf("\n-----------------------------------------------------------------------------------------------\n");
            printf("\nHow many products would you like to add to this supplier??\t");
            char word[10];
        scanf(" %s",word);
        k=checkValidValue(word);
            for(g=0;g<k;g++)
            {
            displayDrugList(list);
            printf("\nWhich product do you want to insert with this supplier (choose by ID):\t");
            int id2;
            char wor[10];
        scanf(" %s",wor);
       id2=checkValidValue(wor);
            drugList found2=searchDrug(list,id2);
            idList found3=searchDrugId(found->data.iden,id2);
            printf("\n*****Adding product% d to this supplier ***** \n",j+1);
            if (found2==NULL)
                printf("\nProduct not found!\n");
            else
            {
                if(found3!=NULL)
                    printf("\nThis product is already registered in the information of this supplier\n");
                else
                    {
                        addSupplierdrug(&found->data,found2->data);
                printf("\n-----------------------------------------------------------------------------------------------\n");
                printf("Product successfully added to this supplier!");
                    }

            }
            }
            }
            }
            }



            break;
        case 7:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Remove product stain*****");
            printf("\n-----------------------------------------------------------------------------------------------\n");
            int a,b,c,d;
            if (List==NULL)
                printf("\nThe supplier list is empty.\n");
            else
            {
              printf("\nHow many suppliers do you want to delete products for?\t");
            char value5[10];
        scanf(" %s",value5);
        b=checkValidValue(value5);;
            for(a=0;a<b;a++)
            {
              displaySupplierList(List);
            printf("\nFor which supplier do you want to delete a product (choose by ID):\t");
            int id3;
            char value6[10];
        scanf(" %s",value6);
        id3=checkValidValue(value6);
            supplierList found3=searchSupplier(List,id3);
             printf("\n-----------------------------------------------------------------------------------------------\n");
             printf("\nHow many products do you want to remove from this supplier??\t");
            char value7[10];
        scanf(" %s",value7);
        d=checkValidValue(value7);
            for(c=0;c<d;c++)
            {
            displayDrugList(list);
            printf("\nWhich product do you want to delete from this supplier (choose by ID):\t");
            int id4;
            char value8[10];
        scanf(" %s",value8);
       id4=checkValidValue(value8);
            drugList found4=searchDrug(list,id4);
            if (found4==NULL)
                printf("\nProduct not found!\n");
            else
            {
                deleteSupplierDrug(&found3->data,id4);

                printf("\n-----------------------------------------------------------------------------------------------\n");
                printf("\nProduct successfully removed from this supplier!");
            }
            }

            }

            }

            break;

        case 8:

            break;

        }
        writesupplierfile(List);
        writedrugfile(list);
        printf("\n\n\aPress [ENTER] to return to the menu....\n");
        getchar();
        getchar();
        system("cls");
    }while(choice!=8);
    printf("***********************************************************************************************");
    printf("\n*                               BACK TO THE MAIN MENU                                        *\n");
    printf("***********************************************************************************************\n");




        return 0;

}
