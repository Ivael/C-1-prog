#ifndef HEADER_FILE_H_INCLUDED
#define HEADER_FILE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct drugs
{
    int id;
    char name[50];
    double unitPrice;
    int qty;
}drug;

typedef struct d
{
    drug data;
    struct d *next;
}drug_Node;

typedef drug_Node *drugList;

typedef struct categories
{
    int id;
    char description[100];
    drugList drug;
}category;

typedef struct c
{
    category data;
    struct c *next;
}category_Node;

typedef category_Node *stock;

typedef struct sup{
    int id;
    char name[50];
    char address[50];
    int phoneNumber;
}supplier;

typedef struct su{
    supplier data;
    struct su * next;
}supplier_Node;

typedef supplier_Node * supplierList;

category readcategory();
int displayCategoryMenu();
void displaycategory(category);
void displaystock(stock);
int stockmenu();
stock createstock();
drugList searchcategoryDrug(category,int);
drugList updatecategoryDrug(category *,int);
drugList deletecategoryDrug(category *,int);
void insertcategory(stock*,category);
void addCategorydrug(category *,drug);
stock searchcategory(stock, int);
stock deletecategory(stock, int);
stock updatecategory(stock, int);
int compareCategory(category,category);

drugList createDrugList();
int drugMenu();
drug readDrug(drugList );
void displayDrugList(drugList);
int compareDrug(drug , drug );
void insertDrug(drugList*,drug);
drugList createDrugList();
drugList searchDrug(drugList,int);
drugList deleteDrug(drugList,int);
drugList updateDrug(drugList,int);
void displayDrug(drug d);
void implicitDrugSuppliedUpdate(drugList,int,int);
void implicitDrugSoldUpdate(drugList,int,int);

void displayMainMenu();

supplierList createSupplierList();
void insertSupplier(supplierList*,supplier);
int compareSupplier(supplier,supplier);
supplierList searchSupplier(supplierList ,int);
int readPhoneNumber();
supplierList updateSupplier(supplierList ,int);
supplier readSupplier(supplierList);
supplierList deleteSupplier(supplierList ,int);
void displaySupplier(supplier s);
void displaySupplierList(supplierList );
int displaySupplierMenu();
#endif // HEADER_FILE_H_INCLUDED
