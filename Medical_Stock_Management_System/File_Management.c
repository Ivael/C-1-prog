#include"Category_Header.h"
#include"Drug_Header.h"
#include"Supplier_Header.h"
#include"Sale_Header.h"

void writedrugfile(drugList list)
{
    FILE *drugfile;
    drugfile=fopen("drug_file.txt","w");
    drugList tmp; drug d;
    for(tmp=list;tmp!=NULL;tmp=tmp->next)
    {
        d=tmp->data;
        fprintf(drugfile,"%d\t;%s;\t%lf\t%d\n",d.id,d.name,d.unitPrice,d.qty);
    }
    fclose(drugfile);

}

void writecategoryfile(stock list)
{
    FILE *categoryfile;
    categoryfile=fopen("category_file.txt","w");
    stock tmp; category c;
    for(tmp=list;tmp!=NULL;tmp=tmp->next)
    {
        c=tmp->data;
        fprintf(categoryfile,"%d\t;%s;\n",c.id,c.description);
        idList il; ID i;
        for(il=c.ident;il!=NULL;il=il->next)
        {
            i=il->data;
            fprintf(categoryfile,"%d\t",i.identifier);
        }
        fprintf(categoryfile,"-1\n");
    }
    fclose(categoryfile);

}

void writesupplierfile(supplierList list)
{
    FILE *supplierfile;
    supplierfile=fopen("supplier_file.txt","w");
    supplierList tmp; supplier s;
    for(tmp=list;tmp!=NULL;tmp=tmp->next)
    {
        s=tmp->data;
        fprintf(supplierfile,"%d\t;%s;\t;%s;\t%d\n",s.id,s.name,s.address,s.phoneNumber);
        idList il; ID i;
        for(il=s.iden;il!=NULL;il=il->next)
        {
            i=il->data;
            fprintf(supplierfile,"%d\t",i.identifier);
        }
        fprintf(supplierfile,"-1\n");
    }
    fclose(supplierfile);

}

void writesalefile(saleList list)
{
    FILE *salefile;
    salefile=fopen("sale_file.txt","w");
    saleList tmp; sale s;
    for(tmp=list;tmp!=NULL;tmp=tmp->next)
    {
        s=tmp->data;
        fprintf(salefile,"%d\t;%s;\n",s.id,s.dateAndTime);
        drugList dl; drug d;
        for(dl=s.saleDrugList;dl!=NULL;dl=dl->next)
        {
            d=dl->data;
            fprintf(salefile,"%d\t;%s;\t%lf\t%d\n",d.id,d.name,d.unitPrice,d.qty);
        }
        fprintf(salefile,"-1\n");
        fprintf(salefile,"%.2lf\n",s.cost);
    }
    fclose(salefile);

}

drugList readdrugfile()
{
    FILE *drugfile;
    drugList list=NULL;
    drug d;
    int c;
    drugfile=fopen("drug_file.txt","r");
    if(drugfile==NULL)
    {
        printf("\nProduct data file does not exist or is corrupt!\n");
    }
    else{
        do
        {
            c = fscanf(drugfile,"%d",&d.id);
            char cc; int i=0;
            if(c!=EOF)
            {
                while((cc=fgetc(drugfile))!=';')
                {}
                while((cc=fgetc(drugfile))!=';'){
                    d.name[i]=cc;
                    i++;
                }
                d.name[i]='\0';
                c = fscanf(drugfile,"%lf %d",&d.unitPrice,&d.qty);
                insertNewDrug(&list,d);
            }
        }while(c!=EOF);
        fclose(drugfile);
    }
    return list;
}

saleList readsalefile()
{
    FILE *salefile;
    saleList list=NULL;
    sale s;
    int c;
    salefile=fopen("sale_file.txt","r");
    if(salefile==NULL)
    {
        printf("\nThe sales data file does not exist or is corrupted!\n");
    }
    else{
        drug d; char cc,dat; int i;
        do
        {
            i=0;
             c=fscanf(salefile,"%d",&s.id);
            if(c!=EOF)
            {
                while((dat=fgetc(salefile))!=';')
                {}
                while((dat=fgetc(salefile))!=';')
                {
                    s.dateAndTime[i]=dat;
                    i++;
                }
                s.dateAndTime[i]='\0';
                s.saleDrugList = createDrugList();
                do
                {
                    fscanf(salefile,"%d",&d.id);
                    if(d.id!=-1)
                    {
                        while((cc=fgetc(salefile))!=';')
                        {}
                        while((cc=fgetc(salefile))!=';')
                        {
                            d.name[i]=cc;
                            i++;
                        }
                        d.name[i]='\0';
                        fscanf(salefile,"%lf %d",&d.unitPrice,&d.qty);
                        insertNewDrug(&s.saleDrugList,d);
                    }
                }while(d.id!=-1);
                fscanf(salefile,"%lf",&s.cost);
                insertSale(&list,s);
            }
        }while(c!=EOF);
        fclose(salefile);
    }
    return list;


}


stock readcategoryfile()
{
    FILE *categoryfile;
    stock list=NULL;
    category c;
    int s;
    categoryfile=fopen("category_file.txt","r");
    if(categoryfile==NULL)
    {
        printf("\nData category File does not exist or is corrupt!\n");
    }
    else{
        ID id; char dat;int i;
        do
        {
            s=fscanf(categoryfile,"%d",&c.id);
            if (s!=EOF)
            {
                i=0;

                while((dat=fgetc(categoryfile))!=';')
                {}
                while((dat=fgetc(categoryfile))!=';')
                {
                    c.description[i]=dat;
                    i++;
                }
                c.description[i]='\0';
                c.ident= createIdList();
                do
                {
                    fscanf(categoryfile,"%d",&id.identifier);
                    if(id.identifier != -1)
                        insertId(&c.ident,id.identifier);

                }while(id.identifier!=-1);
                insertNewCategory(&list,c);


        }
        } while (s!=EOF);

        fclose(categoryfile);
    }
    return list;

}

supplierList readSupplierfile()
{
    FILE *supplierfile;
    supplierList list=NULL;
    supplier s;
    int c;
    supplierfile=fopen("supplier_file.txt","r");
    if(supplierfile==NULL)
    {
        printf("\nSupplier data file does not exist or is corrupt!\n");
    }
    else{
        ID id; char nam,add;int i,j;
        do
        {
            i=0;
            j=0;
            c=fscanf(supplierfile,"%d",&s.id);
            if(c!=EOF)
            {

                while((nam=fgetc(supplierfile))!=';')
                {}
                while((nam=fgetc(supplierfile))!=';')
                {
                    s.name[i]=nam;
                    i++;
                }
                s.name[i]='\0';
                while((add=fgetc(supplierfile))!=';')
                {}
                while((add=fgetc(supplierfile))!=';')
                {
                    s.address[j]=add;
                    j++;
                }
                s.name[j]='\0';
                fscanf(supplierfile,"%d",&s.phoneNumber);
                s.iden= createIdList();
                do
                {
                    fscanf(supplierfile,"%d",&id.identifier);
                    if(id.identifier != -1)
                        insertId(&s.iden,id.identifier);

                }while(id.identifier!=-1);
                insertSupplier(&list,s);
            }
        }while(c!=EOF);

    }
      fclose(supplierfile);
    return list;

}



