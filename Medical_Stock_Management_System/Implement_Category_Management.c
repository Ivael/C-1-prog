#include"Category_Header.h"
#include"Drug_Header.h"
#include"Supplier_Header.h"


stock createstock()
{
    return NULL;
}

category readcategory(stock list)
{
    category c;stock found;
    printf("\nEnter the information for this category:");
    c.id=autoCategoryID(list);
    found=searchcategory(list,c.id);
    while(found!=NULL)
    {
        c.id+=1;
        found=searchcategory(list,c.id);
    }
    printf("\nCategory ID:%d ",c.id);
    printf("\nDescription: ");
    scanf(" %c",c.description);
    scanf("%[^\n]",c.description+1);
    c.ident=createIdList();

    return c;
}
void displaycategory(category c)
{
    printf("\nCategory information");
    printf("\nCategory ID: %d",c.id);
    printf("\tDescription: %s",c.description);
    if(c.ident==NULL)
    {
         printf("\nProducts found in this category: \n");
         printf("\nThere is no product found in this category\n");
    }

    else
    {
      printf("\nProducts found in this category: \n");
    displayIdenList(c.ident);
    }

}
int compareCategory(category c1, category c2){
    return strcmp(c1.description, c2.description);
}

void insertNewCategory(stock* list, category c)
{
   stock myNode;
    myNode = (stock)malloc(sizeof(category_Node));
    myNode->data = c;
    if(*list == NULL){
        *list = (stock)malloc(sizeof(category_Node));
        myNode->next = NULL;
        *list = myNode;
    }
    else  {
      stock tmp = *list;
        while(tmp -> next!= NULL)
              {
            tmp = tmp -> next;
            }
            if(tmp -> next == NULL){
            tmp -> next = (stock)malloc(sizeof(category_Node));
            myNode->next = NULL;
            tmp -> next = myNode;
    }

}
}

void addCategorydrug(category *c,drug newdrug)
{
    insertId(&c->ident,newdrug.id);
};

void displaystock(stock list)
{
    while(list!=NULL)
    {
        printf("\n-----------------------------------------------------------------------------------------------");
        displaycategory(list->data);
        list=list->next;
    }
}


idList deletcategoryDrug(category* c,int identifier)
{
    (*c).ident=deleteDrugId((*c).ident,identifier);
    return (*c).ident;
}


stock searchcategory(stock list,int identifier)
{
    stock tmp=list;
    while((tmp!=NULL)&&((tmp->data.id)!=identifier))
    {
        tmp=tmp->next;
    }

    return tmp;
}

stock deletecategory(stock list,int identifier)
{
    stock found=searchcategory(list,identifier);
    if(found==NULL)
        printf("\nSorry but there is no category with ID %d\n",identifier);
    else
    {
        stock tmp=list;
        if((tmp->data).id!=identifier)
        {
            stock tmp2=(stock)malloc(sizeof(category_Node));
            while((tmp->data).id!=identifier)
            {
                tmp2=tmp;
                tmp=tmp->next;
            }
            tmp2->next=tmp->next;
        }
        else
        {
            list=list->next;
        }
        tmp->next=NULL;
    }
    return list;
}

stock updatecategory(stock list,int identifier,drugList List)
{
    stock found=searchcategory(list,identifier);
    if(found==NULL)
        printf("\nSorry but there is no category with username %d\n",identifier);
    else
    {
        int Choice;

        printf("\n*******    What do you want to update on the category?    *******");
        printf("\n(1) The description of the category\n");
        printf("\nEnter the number corresponding to your choice:");
        char value[10];
        scanf(" %s",value);
        Choice=checkValidValue(value);
    do
    {
        if(Choice!=1)
            printf("\nSorry but your entry is invalid! Try Again:");
    }
    while(Choice!=1);
                switch(Choice)
                {
                case 1:
                        printf("\nEnter the description of the new category:");
                        scanf(" %c",found->data.description);
                        scanf("%[^\n]",found->data.description+1);
                        break;

                }

        }
    return list;
}

int countCategories(stock list)
{
    stock tmp=list;
    int t=0;
    while(tmp!=NULL)
    {
        t++;
        tmp=tmp->next;
    }
    return t;
}

int autoCategoryID(stock list)
{

    int t;
    t=countCategories(list)+1001;
    return t;

}

idList deleteDrugId(idList list,int identifier)
{

    idList found=searchDrugId(list,identifier);
    if(found==NULL)
        {printf("\nThe product is not on the list. No deletion possible!");}
    else
    {
        idList tmp=list;
        if((tmp->data).identifier!=identifier)
        {
            idList tmp2=(idList)malloc(sizeof(id_Node));
        while((tmp->data).identifier!=identifier)
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

idList searchDrugId(idList list,int identifier)
{
    idList tmp=list;
    while((tmp!=NULL)&&(tmp->data).identifier!=identifier)
    {
        tmp=tmp->next;
    }
    return tmp;
}

stock searchCategorybyDescription(stock list,char categoryDes[])
{
    stock tmp=list;
    while((tmp!=NULL)&&strcmp(tmp->data.description,categoryDes)!=0)
    {
        tmp=tmp->next;
    }
    return tmp;
}

stock KnowCategoryDrug(stock list,int id)
{
    stock tmp=list;
     idList found;
    while(tmp!=NULL)
    {
        found= searchDrugId(tmp->data.ident,id);
        if(found!=NULL)
        break;
        else
        tmp=tmp->next;

    }
    return tmp;

}

