#include"Drug_Header.h"
#include"Supplier_Header.h"
#include"Category_Header.h"

supplierList createSupplierList()
{
    return NULL;
}

idList createIdList()
{
    return NULL;
}

int compareSupplier(supplier s1, supplier s2){
    return strcmp(s1.name, s2.name);
}

void insertSupplier(supplierList *list , supplier s){
    supplierList myNode;
    myNode = (supplierList)malloc(sizeof(supplier_Node));
    myNode->data = s;
    if(*list == NULL){
        *list = (supplierList)malloc(sizeof(supplier_Node));
        myNode->next = NULL;
        *list = myNode;
    }
    else if(compareSupplier((*list) -> data , s) > 0){
       myNode->next = (supplierList)malloc(sizeof(supplier_Node));
       myNode->next = *list;
       *list = myNode;
    }else {
        supplierList tmp = *list;
        while((tmp -> next!= NULL) && (compareSupplier(tmp -> next-> data, s) < 0) ){
            tmp = tmp -> next;
        }
        if(tmp -> next == NULL){
            tmp -> next = (supplierList)malloc(sizeof(supplier_Node));
            myNode->next = NULL;
            tmp -> next = myNode;
        }else{
            myNode->next = tmp -> next;
            tmp -> next = myNode;
        }
    }

}

supplierList searchSupplier(supplierList list,int identifier)
{
    supplierList tmp=list;
    while((tmp!=NULL)&&(tmp->data).id!=identifier)
    {
        tmp=tmp->next;
    }
    return tmp;
}
int readPhoneNumber()
{
    int PN;
    do
        {
          char value3[10];
            scanf(" %s",value3);
            PN=checkValidValue(value3);
           if(PN<650000000||PN>699999999)
                printf("\nFault. please enter a valid phone number: ");
        }while(PN<650000000||PN>699999999);
        return PN;
}

void updateSupplier(supplierList list,int identifier)
{
    supplierList found=searchSupplier(list,identifier);
    if(found==NULL)
        printf("\nSorry but there is no supplier with username %d \n",identifier);
    else
    {
        int Choice;
        int t=1;
        do
        {
    printf("\n*******   What do you want to update on supplier information?    *******");
    printf("\n(1)Name of supplier \n (2) Address of supplier \n (3) Telephone number of supplier\n");
    printf("\nEnter the number corresponding to your choice:");
    do
    {
        char value3[10];
        scanf(" %s",value3);
        Choice=checkValidValue(value3);
        if(Choice<1||Choice>3)
            printf("\nSorry but your entry is invalid! Try Again:");
    }
    while(Choice<1||Choice>3);
                switch(Choice)
                {

                case 1:
                    {
                        char Newname[100];
                        printf("\nEnter the new supplier name:");
                        scanf(" %c",Newname);
                        scanf("%[^\n]",Newname+1);
                        strcpy(found->data.name,Newname);
                        break;
                    }
                case 2:
                    {
                        char NewAddress[100];
                        printf("\nEnter the supplier's new address:");
                        scanf("%s",NewAddress);
                        strcpy(found->data.address,NewAddress);
                        break;
                    }
                case 3 :
                    {
                        printf("\nEnter the new supplier phone number:");
                        int newPhoneN=readPhoneNumber();
                          found->data.phoneNumber=newPhoneN;
                        break;
                    }

                }
                printf("\nDo you still want to update another property? \nType (1) for Yes or any other entry for No:");
                char value[10];
                scanf(" %s",value);
                t=checkValidValue(value);
        }
        while(t==1);
    }
}

void addSupplierdrug(supplier *s,drug newdrug)
{
    s->iden=NULL;
    insertId(&s->iden,newdrug.id);
}

supplier readSupplier(supplierList list,drugList List){

    supplier s; supplierList found;
    printf("\nEnter data for this supplier");
    s.id=autoSupplierID(list);
    found=searchSupplier(list,s.id);
    while(found!=NULL)
    {
        s.id+=1;
        found=searchSupplier(list,s.id);
    }
    printf("\nSupplier ID:%d ",s.id);
    printf("\nName of supplier: ");
    scanf(" %c",s.name);
    scanf("%[^\n]",s.name+1);
    printf("Supplier's address: ");
    scanf(" %c",s.address);
    scanf("%[^\n]",s.address+1);
    printf("\nEnter your phone number\n");
    printf("Supplier's telephone number:");
    s.phoneNumber=readPhoneNumber();
    drug dru;
    int i,j;
    printf("\nHow many products does this supplier wish to supply??\n");
    char value7[10];
    scanf(" %s",value7);
    j=checkValidValue(value7);
    for(i=0;i<j;i++)
    {
        printf("\nEnter the name of the product to be supplied\n");
    scanf(" %c",dru.name);
    scanf("%[^\n]",dru.name+1);
    drugList found=searchDrugbyName(List,dru.name);
    if(found==NULL)
    {
        dru=readDrugNew(List,dru.name);
        insertNewDrug(&List,dru);
        addSupplierdrug(&s,dru);
    }
     else
    {
        dru=found->data;
        printf("\nHow much do you want to buy\n");
        int i;
       char value8[10];
        scanf(" %s",value8);
        i=checkValidValue(value8);
        addSupplierdrug(&s,dru);
        implicitDrugSuppliedUpdate(List,i,found->data.id);
    }
    }



    return s;

}

supplierList deleteSupplier(supplierList list,int identifier)
{

    supplierList found=searchSupplier(list,identifier);
    if(found==NULL)
        {printf("\nThe supplier is not on the list. No deletion possible!");}
    else
    {
        supplierList tmp=list;
        if((tmp->data).id!=identifier)
        {
            supplierList tmp2=(supplierList)malloc(sizeof(supplier_Node));
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

void displaySupplier(supplier s)
{
    printf("\nSupplier ID:%d \tName:%s \tAddress:%s \t Telephone number: %d\n",s.id,s.name,s.address,s.phoneNumber);
    printf("produits fournis par %s:\n",s.name);
    displayIdenList(s.iden);
}

void displaySupplierList(supplierList list)
{

    supplierList tmp=list;
    while(tmp!=NULL)
    {
        printf("\n-----------------------------------------------------------------------------------------------");
        displaySupplier(tmp->data);
        tmp=tmp->next;
    }
}

int countSuppliers(supplierList list)
{
    supplierList tmp=list;
    int t=0;
    while(tmp!=NULL)
    {
        t++;
        tmp=tmp->next;
    }
    return t;
}

int autoSupplierID(supplierList list)
{

    int t;
    t=countSuppliers(list)+1001;
    return t;

}
drugList searchDrugbyName(drugList list,char drugName[])
{
    drugList tmp=list;
    while((tmp!=NULL)&&strcmp(tmp->data.name,drugName)!=0)
    {
        tmp=tmp->next;
    }
    return tmp;
}

void insertId(idList* list,int identifier)
{
    idList myNode;
    myNode = (idList)malloc(sizeof(id_Node));
    myNode->data.identifier = identifier;



    if(*list == NULL){
        *list = (idList)malloc(sizeof(id_Node));
        myNode->next = NULL;
        *list = myNode;
    }
    else
    {
      idList tmp = *list;
        while(tmp -> next!= NULL)
              {
            tmp = tmp -> next;
            }

            tmp -> next = (idList)malloc(sizeof(id_Node));
            myNode->next = NULL;
            tmp -> next = myNode;
    }
}

void displayIdenList(idList list){


    idList tmp=list;
    while(tmp!=NULL)
    {
        printf("\t");
        displayId(tmp->data.identifier);
        tmp=tmp->next;
    }
}

void displayId(int identifier)
{
    printf("\nProduct id: %d",identifier);
}

supplierList searchSupplierByName(supplierList list,char suppName[])
{
    supplierList tmp=list;
    while((tmp!=NULL)&&strcmp(tmp->data.name,suppName)!=0)
    {
        tmp=tmp->next;
    }
    return tmp;
}

idList deleteSupplierDrug(supplier* s,int identifier)
{
    (*s).iden=deleteDrugId((*s).iden,identifier);
    return (*s).iden;
}

