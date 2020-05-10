#ifndef SINGLE_SALE_HEADER_H_INCLUDED
#define SINGLE_SALE_HEADER_H_INCLUDED
#include"Drug_Header.h"
#include"Supplier_Header.h"
#include"Single_sale_Header.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

typedef struct sb
{
    drug soldDrug;
    int qtySold;
    double cost;
}singleBuy;
typedef struct sbn
{
    singleBuy data;
    struct sbn *next;
}sb_node;
typedef sb_node *sbList;

singleBuy readsb(drugList );
sbList createSbList();






#endif // SINGLE_SALE_HEADER_H_INCLUDED
