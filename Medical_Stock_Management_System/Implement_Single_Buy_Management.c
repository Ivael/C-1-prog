#include"Drug_Header.h"
#include"Supplier_Header.h"
#include"Sale_Header.h"

singleBuy readsb(drugList list)
{
    singleBuy sb;
    int identifier;
    printf("\n\nEnter the data of the item sold");
    printf("\nEnter the drug's ID ");
    drugList found;
    do{
    scanf("%d",&identifier);
    found=searchDrug(list,identifier);
    if(found==NULL)
        printf("\nDrug not found in stock please retry: ");
    }while(found==NULL);
    sb.soldDrug=found->data;
    printf("\nItem available");
    displayDrug(sb.soldDrug);
    printf("\n\nEnter the quantity you wish: ");
    do
    {
       scanf("%d",&sb.qtySold);
       if(sb.qtySold<0)
            printf("\nPlease enter a valid quantity: ");
        else if(sb.qtySold>sb.soldDrug.qty)
            printf("\nNot enough items in stock. Please retry: ");
    }while(sb.qtySold<0||sb.qtySold>sb.soldDrug.qty);
    implicitDrugSoldUpdate(list,sb.qtySold,identifier);
    sb.cost=sb.qtySold*sb.soldDrug.unitPrice;
    return sb;
};

sbList createSbList()
{
    return NULL;
};

sbList searchSb(sbList list,int identifier)
{
    sbList tmp=list;
    while(tmp!=NULL)
        {tmp=tmp->next;}
    return tmp;
}

sbList deletesb(sbList list, int identifier)
{
    sbList searchN=searchSb(list,identifier);
    if(searchN==NULL)
        {printf("\nSingle buy not found. No deletion!");}
    else
    {
        sbList tmp=list;
        if((tmp->data).soldDrug.id!=identifier)
        {
            sbList tmp2=(sbList)malloc(sizeof(sb_node));
        while((tmp->data).soldDrug.id!=identifier)
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
};

sbList insertSb(sbList list, singleBuy i,drugList List)
{
   if(list==NULL)
   {
       list=(sbList)malloc(sizeof(sb_node));
       list->data=i;
       list->next=NULL;
   }
   else
   {
       sbList f=searchSb(list,i.soldDrug.id);
       if(f!=NULL)
       {
           printf("\nCorresponding drug already found in the list. No Insertion!");
       }
       else
       {

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
   return list;
}

void displaysbList(sbList list)
{
    sbList tmp=list;
    printf("\n\nITEMS SOLD\n");
    while(tmp!=NULL)
    {
        displaysb(tmp->data);
        tmp=tmp->next;
    }
}

