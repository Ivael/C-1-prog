#include"Drug_Header.h"
#include"Supplier_Header.h"
#include"Sale_Header.h"

saleList createSalesList()
{
    return NULL;
}

double computeCost(drugList list){
    double cost=0.0;
    drugList tmp=list;
    while(tmp!=NULL)
    {
        cost=cost+(tmp->data.unitPrice)*(tmp->data.qty);
        tmp=tmp->next;
    }
    return cost;
}

double computeTotalRevnue(saleList list){
    double cost=0.0;
    saleList tmp=list;
    while(tmp!=NULL)
    {
        cost=cost+(tmp->data.cost);
        tmp=tmp->next;
    }
    return cost;
}
saleList searchSale(saleList list,int identifier)
{
    saleList tmp=list;
    while((tmp!=NULL)&&(tmp->data).id!=identifier)
    {
        tmp=tmp->next;
    }
    return tmp;
}

sale readSale(saleList list, drugList dList){

    sale s ;saleList found2;
    printf("\nEnter the data for this sale");
    s.id=autoSaleID(list);
    drugList found1=dList;
    found2=searchSale(list,s.id);
    while(found2!=NULL)
    {
        s.id+=1;
        found2=searchSale(list,s.id);
    }
    printf("\nSales ID: %d",s.id);

    time_t currentTime = time(NULL);
    strcpy(s.dateAndTime,ctime(&currentTime));
    int num;
     printf("\nHow many products do you want?");
      char value[10];
         scanf(" %s",value);
    num=checkValidValue(value);

    while(num<1)
    printf("Invalid number. Enter a correct.");
    displayDrugList(dList);
    int i;
    s.saleDrugList=createDrugList();

    for(i=0;i<num;i++)
        {
            printf("\n*****Ajout de produit %d ***** \n",i+1);
            printf("\nChoose the product you want by ID\n");
               int choice;
                char value1[10];
                scanf(" %s",value1);
                choice=checkValidValue(value1);
                    drugList found=searchDrug(found1,choice);
        if(searchDrug(s.saleDrugList,choice)!=NULL)
        {
            printf("\nFault! This product has already been registered");
           continue;
        }
        else
        {
           if(found!=NULL){
            int quantity;

            printf("Quantity available: %d\n ",found->data.qty);
            do{
                printf("\nHow much do you want\t");

                char value2[10];
                scanf(" %s",value2);
                quantity=checkValidValue(value2);
                if(quantity>found->data.qty)
                printf("Stock not available");
                }while(quantity<1 || quantity>found->data.qty);
                drug temp = found->data;
                temp.qty = quantity;
                implicitDrugSoldUpdate(dList, quantity,choice);
                //found->data.qty -= quantity;
                insertNewDrug((&s.saleDrugList) ,temp);
            }
            else
                printf("Product not found");

        }


    }
    s.cost=computeCost(s.saleDrugList);

    return s;

}

void insertSale(saleList *list , sale s){
    saleList myNode;
    myNode = (saleList)malloc(sizeof(sale_Node));
    myNode->data = s;
    if(*list == NULL){
        *list = (saleList)malloc(sizeof(sale_Node));
        myNode->next = NULL;
        *list = myNode;
    }else {
        saleList tmp = *list;
        while(tmp -> next!= NULL){
            tmp = tmp -> next;
        }
        if(tmp -> next == NULL){
            tmp -> next = (saleList)malloc(sizeof(sale_Node));
            myNode->next = NULL;
            tmp -> next = myNode;
        }else{
            myNode->next = tmp -> next;
            tmp -> next = myNode;
        }
    }

}

void displaySale(sale s){
    printf("\nDate and time: %s",s.dateAndTime);
    printf("\nSales ID: %d\t",s.id);
    printf("\n products:\n");
    displayDrugList(s.saleDrugList);
    printf("\nCost: %.2lf fcfa\n",computeCost(s.saleDrugList));
}

void displaySaleList(saleList list){
    saleList tmp=list;
    while(tmp!=NULL)
    {
        printf("\n-----------------------------------------------------------------------------------------------");
        displaySale(tmp->data);
        tmp=tmp->next;
    }
}

saleList updateSale(saleList list1,int identifier,drugList list2)
{
    saleList found=searchSale(list1,identifier);
     int idNewDrug;
    if(found==NULL)
        printf("\nSorry but there is no sale with ID %d \n",identifier);
    else
    {
        int Choice,choice1;
        int t=1;
        do
        {
    printf("\n*******    What do you want to update on the sales information?    *******");
    printf("\n(1)The list of products for sale\n");

    do
    {
         printf("\nEnter the number corresponding to your choice:");
         char value[10];
         scanf(" %s",value);
         Choice=checkValidValue(value);
        if(Choice!=1)
            printf("\nSorry but your entry is invalid! Try Again:");
    }
    while(Choice!=1);

    int f;
            do
            {
                printf("\n*******    What do you want to update in the product list?    *******");
                printf("\n(1)Insert a product \ n (2) Delete a product \ n (3) Change the quantity of product\n");
                printf("\nEnter the number corresponding to your choice:");
                do
                {
                    char value1[10];
                    scanf(" %s",value1);
                    choice1=checkValidValue(value1);
                    if(choice1<1||choice1>3)
                    printf("\nSorry but your entry is invalid! Try Again:");
                            }
                while(choice1<1||choice1>3);
                switch(choice1)
                {
                    case 1:


                                displayDrugList(list2);
                                printf("\nEnter the id of the product you wish to insert\n");
                                char value2[10];
                                scanf(" %s",value2);
                                idNewDrug=checkValidValue(value2);
                                drugList f=searchDrug(list2,idNewDrug);
                                if(f!=NULL)
                                {
                                    insertNewDrug(&found->data.saleDrugList ,f->data);
                                    printf("\nHow much do you want");
                                     char l[10];
                                    scanf(" %s",l);
                                    int quantity=checkValidValue(l);
                                    if(quantity>f->data.qty)
                                    printf("Stock not available");
                                    implicitDrugSoldUpdate(list2, quantity,idNewDrug);
                                   found->data.saleDrugList->data.qty=quantity;
                }


                                else
                                    printf("\nThe product does not exist\n");
                                break;

                    case 2:

                        displayDrugList(found->data.saleDrugList);
                        printf("\nChoose the identifier of the product you wish to delete");
                        int id;
                        char value3[10];
                        scanf(" %s",value3);
                        id=checkValidValue(value3);
                        drugList g=searchDrug(found->data.saleDrugList,id);
                        if(g!=NULL)
                            found->data.saleDrugList=deleteDrug(found->data.saleDrugList,id);
                        else
                            printf("\nThe product does not exist in this sale\n");
                        break;

                     case 3:

                        displayDrugList(found->data.saleDrugList);
                        printf("\nchoose the product whose quantity you want to change\n");
                        int id1, newQty ;
                        char value4[10];
                        scanf(" %s",value4);
                        id1=checkValidValue(value4);
                        drugList tmp2=searchDrug(found->data.saleDrugList,id1);
                        if (tmp2!=NULL)
                            {
                                printf("Enter the new quantity\n");
                                scanf("%d", &newQty);
                                tmp2->data.qty=newQty;
                                found->data.cost=computeCost(found->data.saleDrugList);
                            }
                        else
                            printf("\nSorry the product does not exist\n");


                    }
                    printf("\nDo you still want to update another property in the product list? \ nType (1) for Yes or any other entry for No:");
                    char value5[10];
                    scanf(" %s",value5);
                    f=checkValidValue(value5);

                }while (f==1);
                printf("\nDo you still want to update another property on this? \ nType (1) for Yes or any other entry for No:");
                scanf("%d",&t);

        }while(t==1);
        list1->data.cost=computeCost(list1->data.saleDrugList);

    }
    return list1;
}

int countSales(saleList list)
{
    saleList tmp=list;
    int t=0;
    while(tmp!=NULL)
    {
        t++;
        tmp=tmp->next;
    }
    return t;
}

saleList deleteSale(saleList list,int identifier)
{

    saleList found=searchSale(list,identifier);
    if(found==NULL)
        {printf("\nThe sale is not on the list. No deletion possible!");}
    else
    {
        saleList tmp=list;
        if((tmp->data).id!=identifier)
        {
            saleList tmp2=(saleList)malloc(sizeof(sale_Node));
        while((tmp->data).id!=identifier)
        {
            tmp2=tmp;
            tmp=tmp->next;
        }
        tmp2->next=tmp->next;
        }
        else
        {
            list=tmp->next;
        }
        tmp->next=NULL;
    }
    return list;
}

int autoSaleID(saleList list)
{

    int t;
    t=countSales(list)+1001;
    return t;

}




