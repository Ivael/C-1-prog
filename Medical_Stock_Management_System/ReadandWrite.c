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

};
drugList readdrugfile()
{
    FILE *drugfile;
    drugList list=NULL;
    drug d;
    int c;
    drugfile=fopen("drug_file.txt","r");
    if(drugfile==NULL)
    {
        printf("\nDrug data file does not exist");
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
};


