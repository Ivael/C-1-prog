#ifndef SALE_HEADER_H_INCLUDED
#define SALE_HEADER_H_INCLUDED
#include"Drug_Header.h"
#include"Supplier_Header.h"
#include"Single_sale_Header.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>


typedef struct s
{
    int id;
    char dateAndTime[25];
    drugList saleDrugList;
    double cost;
}sale;
typedef struct sn
{
    sale data;
    struct sn *next;
}sale_Node;
typedef sale_Node *saleList;

saleList createSalesList();
double computeCost(drugList);
double computeTotalRevnue(saleList);
int countSales(saleList);
saleList searchSale(saleList,int );
sale readSale(saleList, drugList);
void insertSale(saleList *, sale );
saleList updateSale(saleList,int,drugList);
void displaySale(sale );
void displaySaleList(saleList);
saleList deleteSale(saleList ,int );
int displaySaleMenu();
int autoSaleID(saleList);
void writesalefile(saleList);
saleList readsalefile();


#endif // SALE_HEADER_H_INCLUDED
