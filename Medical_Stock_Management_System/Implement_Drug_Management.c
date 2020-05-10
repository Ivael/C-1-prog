#include"Category_Header.h"
#include"Drug_Header.h"

drugList createDrugList()
{
    return NULL;
}


drugList searchDrug(drugList list,int identifier)
{
    drugList tmp=list;
    while((tmp!=NULL)&&(tmp->data).id!=identifier)
    {
        tmp=tmp->next;
    }
    return tmp;
}

void insertNewDrug(drugList* list, drug d)
{
   drugList myNode;
    myNode = (drugList)malloc(sizeof(drug_Node));
    myNode->data = d;
    if(*list == NULL){
        *list = (drugList)malloc(sizeof(drug_Node));
        myNode->next = NULL;
        *list = myNode;
    }
    else  {
      drugList tmp = *list;
        while(tmp -> next!= NULL)
              {
            tmp = tmp -> next;
            }
            if(tmp -> next == NULL){
            tmp -> next = (drugList)malloc(sizeof(drug_Node));
            myNode->next = NULL;
            tmp -> next = myNode;
    }

}
}


void updateDrug(drugList list,int identifier)
{
    drugList found=searchDrug(list,identifier);
    if(found==NULL)
        printf("\nSorry but there is no product with ID %d \n",identifier);
    else
    {
        int Choice;
        int t=1;
        do
        {

            printf("\n*******    What do you want to update on the product?    *******");
            printf("\n(1)The name of the product \n(2) The unit price of the product\n");
                printf("\nEnter the number corresponding to your choice:");
    char value[10];
         scanf(" %s",value);
        Choice=checkValidValue(value);
    do
    {
        if(Choice<1&&Choice>2)
            printf("\nSorry but your entry is invalid! Try Again:");
    }
    while(Choice<1&&Choice>2);
                switch(Choice)
                {

                case 1:
                    {
                        char Newname[100];
                        printf("\nEnter the new product name:");
                        scanf(" %c",Newname);
                        scanf("%[^\n]",Newname+1);
                        strcpy(found->data.name,Newname);
                        break;
                    }
                case 2:
                    {
                        double Newup;
                        printf("\nEnter the new unit price of the products:");
                         do
                            {
                               scanf("%lf",&Newup);
                               if(Newup<=0)
                                    printf("\nSorry, your registration is not valid. Please enter a price greater than zero.:");
                            }while(Newup<=0);
                            found->data.unitPrice=Newup;
                        break;
                    }

                }
                printf("\nDo you still want to update another property? \nType (1) for Yes or any other entry for No:");
                char value1[10];
                scanf(" %s",value1);
                t=checkValidValue(value1);
        }
        while(t==1);
    }
}

drug readDrug(drugList list){

    drug d ;drugList found;
    char value[10];
    d.id=autoDrugID(list);
    found=searchDrug(list,d.id);
    while(found!=NULL)
    {
        d.id+=1;
        found=searchDrug(list,d.id);
    }

    printf("\nEnter data for this product");
    printf("\nProduct id:%d ",d.id);
    printf("\nProduct Name: ");
    scanf(" %c",d.name);
    scanf("%[^\n]",d.name+1);
    printf("Unit price of the product: ");

    do
    {
        scanf("%lf",&d.unitPrice);
        if(d.unitPrice<=0)
            printf("Invalid entry. Please enter a positive number: ");
    }while(d.unitPrice<=0);
     printf("The amount of product:");
     scanf(" %s",value);
     d.qty=checkValidValue(value);
    do
    {
        if(d.qty<=0)
            printf("Invalid entry. Please enter a positive number: ");
    }while(d.qty<=0);


    return d;

}

drugList deleteDrug(drugList list,int identifier)
{

    drugList found=searchDrug(list,identifier);
    if(found==NULL)
        {printf("\nThe product is not on the list. No deletion possible!");}
    else
    {
        drugList tmp=list;
        if((tmp->data).id!=identifier)
        {
            drugList tmp2=(drugList)malloc(sizeof(drug_Node));
        while((tmp->data).id!=identifier)
        {
            tmp2=tmp;
            tmp=tmp->next;
        }
        tmp2->next=tmp->next;}
        else
        {
            list=tmp->next;
        }
        tmp->next=NULL;
    }
    return list;
}

void displayDrug(drug d)
{
    printf("\nProduct id: %d\tName: %s\tUnit Price: %.2lffcfa\tQuantity: %d Products",d.id,d.name,d.unitPrice,d.qty);
}

void displayDrugList(drugList list){


    drugList tmp=list;
    while(tmp!=NULL)
    {
        printf("\n-----------------------------------------------------------------------------------------------");
        displayDrug(tmp->data);
        tmp=tmp->next;
    }
}

void implicitDrugSuppliedUpdate(drugList list,int qtySupplied,int identifier )
{
    drugList L=searchDrug(list,identifier);
    L->data.qty += qtySupplied;

}

void implicitDrugSoldUpdate(drugList list,int qtySold,int identifier )
{
    drugList L=searchDrug(list,identifier);
    L->data.qty -= qtySold;

};

int countDrugs(drugList list)
{
    drugList tmp=list;
    int t=0;
    while(tmp!=NULL)
    {
        t++;
        tmp=tmp->next;
    }
    return t;
}

int autoDrugID(drugList list)
{
    int t;
    t=countDrugs(list)+1001;
    return t;
}


drugList LimitedDrugs(drugList list)
{
    drugList tmp=NULL;
    while(list!=NULL)
    {
        if(list->data.qty<5)
            insertNewDrug(&tmp,list->data);
        list=list->next;
    }
    return tmp;
}
supplierList searchDrugSupplier(supplierList list,int id)
{
    supplierList tmp=list;
     idList found;
    while(tmp!=NULL)
    {
        found= searchDrugId(tmp->data.iden,id);
        if(found!=NULL)
        break;
        else
        tmp=tmp->next;

    }
    return tmp;
}

void displayLimitedDrugs(drugList list,supplierList List)
{
    drugList tmp2=list;
    while(tmp2!=NULL)
    {
        supplierList found=searchDrugSupplier(List,tmp2->data.id);
        if(found==NULL)
        {
           displayDrug(tmp2->data);
           printf("\nNo supplier registered yet.\n");
                printf("\n-----------------------------------------------------------------------------------------------");
        }

        else
        {
            displayDrug(tmp2->data);
                printf(" \nThis product can be supplied by MR / MRS%s with the telephone number.: %d",found->data.name,found->data.phoneNumber);
               printf("\n-----------------------------------------------------------------------------------------------");
        }

      tmp2=tmp2->next;
    }

}

drug readDrugNew(drugList list,char x[]){

    drug d ;
    printf("\nEnter data for this product");
    d.id=autoDrugID(list);
    printf("\nProduct id:%d ",d.id);
    strcpy(d.name,x);
    printf("\nProduct Name: %s\n",d.name);
    printf("Unit Product Price: ");
  char c;
  while (scanf("%lf",&d.unitPrice)!=1)
  {
      while((c=getchar())!='\n')
      {
          putchar(c);
          printf("\nInvalid entry! \nPlease enter a valid value\n");
      }
  }

    do
    {
//        scanf("%lf",&d.unitPrice);

        if(d.unitPrice<=0)
            printf("Invalid entry. Please enter a positive number: ");
    }while(d.unitPrice<=0);
     printf("Product quantity:");
     char value[10];
    scanf(" %s",value);
    d.qty=checkValidValue(value);

    do
    {
        if(d.qty<=0)
            printf("Invalid entry. Please enter a positive number: ");
    }while(d.qty<=0);


    return d;

}


int checkValidValue(char value[])
{
    int i=0, f, p, s=strlen(value);
check: do
    {
        f= isdigit(value[i]);
        if (f == 0)
            break;
        i++;
    }while(i < s );

    if (i == s){
        p=atoi(value);
    }else{
        printf("\nInvalid entry! \nPlease enter a valid value\n");
        char newValue[10];
        scanf("%s",newValue);
        strcpy(value,newValue);
        i=0;
         s=strlen(value);
        goto check;
    }
    return p;
}
/*drugList addDrug(drugList list, drug d)
{
    drugList myNode;
    myNode = (drugList)malloc(sizeof(drug_Node));
    myNode->data = d;
   if(list==NULL)
   {
       list=(drugList)malloc(sizeof(drug_Node));
       list->data=d;
       list->next=NULL;
   }
   else
    {
      drugList tmp = list;
        while(tmp -> next!= NULL)
            {
            tmp = tmp -> next;
            }
            tmp -> next = (drugList)malloc(sizeof(drug_Node));
            myNode->next = NULL;
            tmp -> next = myNode;
    }
    return list;
}

*/







