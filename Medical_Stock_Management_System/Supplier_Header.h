#ifndef SUPPLIER_HEADER_H_INCLUDED
#define SUPPLIER_HEADER_H_INCLUDED
#include "Drug_Header.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
typedef struct i
{
    int identifier;
}ID;
typedef struct n
{
   ID data;
   struct n*next;
}id_Node;

typedef id_Node* idList;

typedef struct sup{
    int id;
    char name[50];
    char address[50];
    int phoneNumber;
    idList iden;

}supplier;

typedef struct su{
    supplier data;
    struct su * next;
}supplier_Node;

typedef supplier_Node * supplierList;

supplierList createSupplierList();
idList createIdList();
void insertSupplier(supplierList*,supplier);
int compareSupplier(supplier,supplier);
supplierList searchSupplier(supplierList ,int);
int readPhoneNumber();
int countSuppliers(supplierList );
void updateSupplier(supplierList ,int);
supplier readSupplier(supplierList,drugList);
supplierList deleteSupplier(supplierList ,int);
void displaySupplier(supplier s);
void displaySupplierList(supplierList );
int displaySupplierMenu();
void addSupplierdrug(supplier*,drug);
int autoSupplierID(supplierList);
void insertId(idList*,int);
void displayIdenList(idList);
void displayId(int);
supplierList searchSupplierByName(supplierList,char*);
idList deleteSupplierDrug(supplier* ,int);
void displayLimitedDrugs(drugList ,supplierList);
supplierList searchDrugSupplier(supplierList,int);
void writesupplierfile(supplierList);
supplierList readSupplierfile();
#endif // SUPPLIER_HEADER_H_INCLUDED
