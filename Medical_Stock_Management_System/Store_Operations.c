#include"Category_Header.h"
#include"Drug_Header.h"
#include"Supplier_Header.h"
#include"Sale_Header.h"

int drug_operations()
{
   drugList list=readdrugfile();
   supplierList List=readSupplierfile();
   stock LIst=readcategoryfile();
   int choice;
   int choice1,identifier;
   char dname[20];

    do
    {
    printf(" \n                           **********************************\n");
    printf("                           *           PRODUCT OPERATIONS     * ");
    printf("\n                           ********************************** ");
        choice=drugMenu();
         system("cls");
        switch(choice)
        {
        case 1:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Research task*****");
             printf("\n-----------------------------------------------------------------------------------------------");
            if(list==NULL){
                printf("\nThe product list is empty.");
            }
            else
            {
            printf("\nWhat do you want to do? Enter");
            printf("\n[1] Search for a product by Identifier \n[2] Search for a product by name");
            printf("\nEnter your choice:\t");
              do
            {

                char value3[10];
                scanf(" %s",value3);
                choice1=checkValidValue(value3);
                if(choice1<=0||choice1>2)
                printf("Invalid entry. Please enter a valid number: ");
            }while(choice1<=0||choice1>2);

             switch(choice1)
             {
             case 1:
                 printf("\nEnter the identifier of the product you are looking for\n");
                 char value2[10];
                scanf(" %s",value2);
                identifier=checkValidValue(value2);
                 drugList found=searchDrug(list,identifier);
                 if(found!=NULL)
                    {
                    printf("\nProduct detected! \n Product information:\n");
                    printf("\n-----------------------------------------------------------------------------------------------\n");
                    displayDrug(found->data);
                    }
                else
                    printf("\nProduct not found!");
                 break;
             case 2:
                printf("\nEnter the name of the product you are looking for\n");
                scanf(" %c",dname);
                scanf("%[^\n]",dname+1);
                drugList found1=searchDrugbyName(list,dname);
                 if(found1!=NULL)
                    {
                     printf("\nProduct detected! \n Product information:\n");
                     printf("\n-----------------------------------------------------------------------------------------------\n");
                    displayDrug(found1->data);
                    }
                else
                    printf("\nProduct not found!");
                break;
             }

            }
            break;
        case 2:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Insert a task*****");
            printf("\n-----------------------------------------------------------------------------------------------\n");
            int i,j;
            printf("\nHow many products do you want to add?\t");
            char value[10];
            scanf(" %s",value);
            j=checkValidValue(value);
            for(i=0;i<j;i++)
                {
                printf("\n-----------------------------------------------------------------------------------------------\n");
                printf("\n*****Add product %d*****\n\n",i+1);
                drug i=readDrug(list);
                 if(searchDrugbyName(list,i.name)!=NULL)
                 {
                    printf("\nThe product already exists");
                 continue;
                 }

                insertNewDrug(&list,i);
                printf("\n-----------------------------------------------------------------------------------------------");
                printf("\nProduct successfully added!");

                }
                printf("\n-----------------------------------------------------------------------------------------------\n");

            break;

        case 3:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Update task*****");
            printf("\n-----------------------------------------------------------------------------------------------");
            if(list==NULL)
                printf("\nThe product list is empty.");
            else
            {
                int k,l;
            printf("\nHow many products do you want to update??\t");
            char value4[10];
            scanf(" %s",value4);
            l=checkValidValue(value4);
            for(k=0;k<l;k++)
            {
                printf("\n*****Product update %d*****\n\n",k+1);
                displayDrugList(list);
                printf("\nEnter the ID of the product you want to update: ");
                int id;
                char value5[10];
                scanf(" %s",value5);
                id=checkValidValue(value5);
                updateDrug(list,id);
                printf("\n-----------------------------------------------------------------------------------------------");
                printf("\nProduct successfully updated!");
            }
              printf("\n-----------------------------------------------------------------------------------------------");
            }
            break;
        case 4:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Remove the task*****");
            printf("\n-----------------------------------------------------------------------------------------------");
            if(list==NULL)
                printf("\nThe product list is empty.");
            else
            {
                int m,n;
            printf("\nHow many products do you want to delete??\t");
            char value6[10];
            scanf(" %s",value6);
            n=checkValidValue(value6);
            displayDrugList(list);
            for(m=0;m<n;m++)
            {
                printf("\n-----------------------------------------------------------------------------------------------\n");
                printf("\n*****Deletion of product %d*****\n\n",m+1);
                printf("\nEnter the identifier of the product you wish to delete: ");
                int id;
                char value7[10];
                scanf(" %s",value7);
                id=checkValidValue(value7);
                list=deleteDrug(list,id);
                printf("\n-----------------------------------------------------------------------------------------------");
                printf("\nProduct successfully deleted!");
            }
            printf("\n-----------------------------------------------------------------------------------------------");

            }
            break;
        case 5:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Display task*****");
            printf("\n-----------------------------------------------------------------------------------------------");
            if(list==NULL)
                printf("\nThe product list is empty.");
            else
                {
                printf("\nList of products:\n");
                displayDrugList(list);}
            break;
        case 6:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Display task*****");
            printf("\n-----------------------------------------------------------------------------------------------");
            drugList shortDrugs=LimitedDrugs(list);
            if(shortDrugs==NULL)
            {
                printf("\nThere is no product in shortage\n");
            }
            else
            displayLimitedDrugs(shortDrugs,List);
            break;
        case 7:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Research task*****");
            printf("\n-----------------------------------------------------------------------------------------------");
            char z[20];
            printf("\nEnter the name of the product you want to know the category\n");
            scanf(" %c",z);
            scanf("%[^\n]",z+1);
            drugList found1=searchDrugbyName(list,z);
            if(found1==NULL)
                printf("\nSorry, the product doesn't exist pas\n");
            else
            {
               stock found=KnowCategoryDrug(LIst,found1->data.id);
            if(found==NULL)
                printf("\nSorry, the product is not yet classified.\n");
            else

                printf("\nThe product is in the category: \nID of the Category:% of description of the category:%s",found->data.id,found->data.description);
            }
            break;
        case 8:
            break;
        }
       writedrugfile(list);
        printf("\n\nPress [ENTER] to return to the menu....\n");
        getchar();
        getchar();
        system("cls");


    }while(choice!=8);

    printf("***********************************************************************************************");
    printf("\n*                              BACK TO THE MAIN MENU                                        *\n");
    printf("***********************************************************************************************\n");

    return 0;

};

int category_operations()
{

    stock List=readcategoryfile();
    drugList list=readdrugfile();
    int choice,choice1,identifier;
    char descrip[50];
    do
    {
        printf(" \n                           **********************************\n");
        printf("                           *       CATEGORY OF OPERATIONS     * ");
        printf("\n                           ********************************** ");
        choice=displayCategoryMenu();
         system("cls");
        switch(choice)
        {
        case 1:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n                 *****Display task*****\n");
            printf("-----------------------------------------------------------------------------------------------");
            if(List==NULL)
                printf("\n\nThe list of categories is empty\n ");
            else
            {
                printf("\nList of categories :\n");
            displaystock(List);
            }

            break;
        case 2:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Search and display*****");
            printf("\n-----------------------------------------------------------------------------------------------");
            if(List==NULL)
                printf("\nThe list of categories is empty.");
            else
            {
                printf("\nWhat do you want to do? ");
            printf("\n[1] Search for a category by identifier \n[2] Search for a category by description");
            printf("\nEnter your choice:\t ");
              do
            {
                char value3[10];
                scanf(" %s",value3);
                choice1=checkValidValue(value3);
                if(choice1<=0||choice1>2)
                printf("Invalid entry. Please enter a valid number: ");
            }while(choice1<=0||choice1>2);

             switch(choice1)
             {
             case 1:
                 printf("\nEnter the identifier of the category you are looking for\n");
                 char value4[10];
                scanf(" %s",value4);
               identifier=checkValidValue(value4);
                 stock found=searchcategory(List,identifier);
                 if(found!=NULL)
                    {
                        printf("\nCategory successfully found\n");
                    displaycategory(found->data);
                    }
                else
                    printf("\nCategory not found!");
                    break;
             case 2:
                printf("\nEnter the description of the category you are looking for\n");
                scanf(" %c",descrip);
                scanf("%[^\n]",descrip+1);
                stock found1=searchCategorybyDescription(List,descrip);
                 if(found1!=NULL)
                    {
                    printf("\nCategory successfully found. \nCategory information:\n");
                    displaycategory(found1->data);
                    }
                else
                    printf("\nCategory not found!");

                break;
            }
            }
            break;
        case 3:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Insert a task*****");
            printf("\n-----------------------------------------------------------------------------------------------\n");
            int i,j;
            printf("\nHow many categories do you want to add?\t");
            char value[10];
        scanf(" %s",value);
        j=checkValidValue(value);

            for(i=0;i<j;i++)
            {
                    printf("\n*****Add category %d ***** \n",i+1);
            printf("\n-----------------------------------------------------------------------------------------------");
            category i=readcategory(List);
            if(searchCategorybyDescription(List,i.description)!=NULL)
            {
              printf("\nThe category already exists");
            continue;
            }

            int v,w;
            displayDrugList(list);
            printf("\nHow many products do you want to add in this category\t");
           char value1[10];
        scanf(" %s",value1);
        w=checkValidValue(value1);
            for (v=0;v<w;v++)
            {
                    printf("\n*****Adding product %d to this category***** \n",v+1);

                printf("\nEnter the product you want to add in this category (choose by ID)\n");
                int id5;
                char value2[10];
        scanf(" %s",value2);
       id5=checkValidValue(value2);
                drugList found2=searchDrug(list,id5);
            if (found2==NULL)
                printf("\nProduct not found!\n");
            else
            {
                addCategorydrug(&i,found2->data);
                printf("\n-----------------------------------------------------------------------------------------------\n");
                printf("Product successfully added to this category!");


            }
            }
            insertNewCategory(&List,i);
            printf("\n-----------------------------------------------------------------------------------------------");
            printf("\nCategory successfully added");
            }

            break;
        case 4:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n                 *****Update task******");
             printf("\n-----------------------------------------------------------------------------------------------");
            if(List==NULL)
                printf("\nThe list category is empty.");
            else
            {
                int k,l;
            printf("\nHow many categories do you want to update?\t");
            char value5[10];
        scanf(" %s",value5);
        l=checkValidValue(value5);
            for(k=0;k<l;k++)
            {
                displaystock(List);
            printf("\n-----------------------------------------------------------------------------------------------");
                printf("\nEnter the Identifier of the category you wish to update: ");
                int id;
               char value6[10];
        scanf(" %s",value6);
        id=checkValidValue(value6);
                stock found=searchcategory(List,id);
                if (found==NULL)
                printf("\nThe category does not exist\n");
                else{
                 printf("\nCategory successfully found! \nInformation on the category:\n");
                  printf("\n-----------------------------------------------------------------------------------------------");
                 List=updatecategory(List,id,list);
                 printf("Category successfully updated!\n");

                }
            }
            }
            break;
        case 5:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Remove the task*****");
             printf("\n-----------------------------------------------------------------------------------------------");
            if(List==NULL)
                printf("\nThe list of categories is empty.");
            else
            {
                   int m,n;
            printf("\nHow many categories do you want to delete??\t");
            char value7[10];
        scanf(" %s",value7);
        n=checkValidValue(value7);
            for(m=0;m<n;m++)
            {
                displaystock(List);
                printf("\n-----------------------------------------------------------------------------------------------");
                printf("\nEnter the Identifier of the category you wish to delete: ");
                int id;
               char value8[10];
        scanf(" %s",value8);
        id=checkValidValue(value8);
                List=deletecategory(List,id);
                printf("\n-----------------------------------------------------------------------------------------------");
                printf("\nCategory successfully deleted!");
            }
            break;
        case 6:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n                *****Insert a product stain *****");
            printf("\n-----------------------------------------------------------------------------------------------");
            displaystock(List);
            int h,f,o,p;
            printf("\nFor how many categories do you want to add products?\t");
            char valu[10];
        scanf(" %s",valu);
       f=checkValidValue(valu);
            for(h=0;h<f;h++)
            {
                displaystock(List);
            printf("In which category do you want to insert the product (choose by ID):\n");
            int id;
            char val[10];
        scanf(" %s",val);
        id=checkValidValue(val);
            stock found=searchcategory(List,id);

            printf("\nHow many products do you want to add to this category?\t");
            char va[10];
        scanf(" %s",va);
       p=checkValidValue(va);
            for(o=0;o<p;o++)
            {
            displayDrugList(list);
            printf("Which product do you want to insert in the category (choose by ID):\t");
            int id2;
            char v[10];
        scanf(" %s",v);
        id2=checkValidValue(v);
            drugList found2=searchDrug(list,id2);
            idList found3=searchDrugId(found->data.ident,id2);
            if (found2==NULL)
            {
                printf("\nProduct not found\n");
            }

            else
            {
                if(found3!=NULL)
                    printf("\nThe product already exists in this category\n");
                else
                {
                    printf("Product successfully found\n");
                addCategorydrug(&found->data,found2->data);
                printf("\nProduct successfully added to the category!");
                }

            }
            }
            }
            break;
        case 7:
            printf("-----------------------------------------------------------------------------------------------");
            printf("\n               *****Remove product task******");
            printf("\n-----------------------------------------------------------------------------------------------");
            int a,b,c,d;
            printf("\nHow many categories do you want to delete products for?\t");
            char word[10];
        scanf(" %s",word);
        b=checkValidValue(word);
            for(a=0;a<b;a++)
          {
     displaystock(List);
            printf("\nIn which category do you want to delete a product (choose by ID):\n");
            int id3;
           char wor[10];
        scanf(" %s",wor);
       id3=checkValidValue(wor);
            stock found3=searchcategory(List,id3);
            if (found3==NULL)
                printf("\n The category does not exist\n");
            else{
             printf("\nHow many products do you want to remove from this category??\t");
           char wo[10];
        scanf(" %s",wo);
        d=checkValidValue(wo);
             for(c=0;c<d;c++)
            {
            displayDrugList(list);
            printf("\nWhich product do you want to delete in this category (choose by ID):\n");
            int id4;
            char wa[10];
        scanf(" %s",wa);
        id4=checkValidValue(wa);
            drugList found4=searchDrug(list,id4);
            if (found4==NULL)
                printf("\nProduct not found\n");
            else
            {
                deletcategoryDrug(&found3->data,id4);
                printf("\n-----------------------------------------------------------------------------------------------\n");

                printf("Product successfully removed from category!");
            }
            }
                printf("\n-----------------------------------------------------------------------------------------------\n");

            }
            }

            break;
        case 8:

            break;
        }
            }
           writecategoryfile(List);
            writedrugfile(list);
        printf("\n\nPress [ENTER] to return to the menu....\n");
        getchar();
        getchar();
        system("cls");

    }while(choice!=8);

    printf("*************************************************************************************************");
    printf("\n*                               BACK TO THE MAIN MENU                                       *\n");
    printf("***********************************************************************************************\n");

    return 0;

}


