#ifndef CATEGORY_HEADER_H_INCLUDED
#define CATEGORY_HEADER_H_INCLUDED
#include"Drug_Header.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"Supplier_Header.h"
#include<math.h>


typedef struct categories
{
    int id;
    char description[100];
    idList ident;
}category;

typedef struct c
{
    category data;
    struct c *next;
}category_Node;

typedef category_Node *stock;

category readcategory(stock);
int displayCategoryMenu();
void displaycategory(category);
void displaystock(stock);
int stockmenu();
stock createstock();
int countCategories(stock);
drugList searchcategoryDrug(category,int);
idList deletcategoryDrug(category* ,int);
void insertNewCategory(stock* , category );
void addCategorydrug(category *,drug);
stock searchcategory(stock, int);
stock deletecategory(stock, int);
stock updatecategory(stock, int,drugList);
int compareCategory(category,category);
idList deleteDrugId(idList,int);
idList searchDrugId(idList,int);
stock searchCategorybyDescription(stock,char*);
void writecategoryfile(stock);
stock readcategoryfile();
stock KnowCategoryDrug(stock,int);

int category_operations();
int supplier_operations();
int sale_operations();
int autoCategoryID(stock );

#endif // CATEGORY_HEADER_H_INCLUDED
