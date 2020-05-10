#ifndef DRUG_HEADER_H_INCLUDED
#define DRUG_HEADER_H_INCLUDED
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

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

drugList createDrugList();
int drugMenu();
drug readDrug(drugList);
void displayDrugList(drugList);
int countDrugs(drugList);
drugList searchDrug(drugList,int);
drugList deleteDrug(drugList,int);
void updateDrug(drugList,int);
void displayDrug(drug d);
void implicitDrugSuppliedUpdate(drugList,int,int);
void implicitDrugSoldUpdate(drugList,int,int);
int autoDrugID(drugList);
void insertNewDrug(drugList*,drug);
drugList searchDrugbyName(drugList,char*);
int drug_operations();
void writedrugfile(drugList);
drugList readdrugfile();
drug readDrugNew(drugList,char[] );
int checkValidValue(char *);
int isdigit(int);
drugList LimitedDrugs(drugList);

int displayMainMenu();
void displayGoodbyeMessage();
void displayWelcomeMessage();

#endif // DRUG_HEADER_H_INCLUDED
