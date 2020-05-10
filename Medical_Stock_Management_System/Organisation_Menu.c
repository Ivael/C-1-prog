#include"Category_Header.h"
#include"Drug_Header.h"
#include"Supplier_Header.h"
#include"Sale_Header.h"

int drugMenu()
{
    int choice;
    printf("\n-----------------------------------------------------------------------------------------------");
    printf("\nWhat do you want to do? Enter");
    printf("\n[1] Search for a product in the list");
    printf("\n[2] Add a new product to the list");
    printf("\n[3] Update an existing product");
    printf("\n[4] Remove a product from the product list");
    printf("\n[5] View all products");
    printf("\n[6] View all out of stock products");
    printf("\n[7] Know the category of a product\n");
    printf("\n[8] Save current products and return to the main menu");
    printf("\n\nEnter your choice: ");
    do
    {
        char value3[10];
        scanf(" %s",value3);
        choice=checkValidValue(value3);
        if(choice<1||choice>8)
            printf("Invalid entry. Try Again: ");
    }while(choice<1||choice>8);
    return choice;
}

int displayCategoryMenu()
{

     int choice;
    printf("\n-----------------------------------------------------------------------------------------------");
    printf("\nWhat do you want to do?");
    printf("\n[1] Display the list of all categories");
    printf("\n[2] Find and view a category");
    printf("\n[3] Insert a new category");
    printf("\n[4] Update a category\n");
    printf("[5]   Delete a category");
    printf("\n[6] Insert a new product in a category");
    printf("\n[7] Delete a product in a category");
    printf("\n\n[8]  Save the current stock and return to the main menu");
    printf("\n\nEnter the number corresponding to your choice:");
    do
    {
        char value3[10];
        scanf(" %s",value3);
        choice=checkValidValue(value3);
        if(choice<1||choice>8)
            printf("\nSorry your entry is not valid! Try Again:");
    }
    while(choice<1||choice>8);
    return choice;

}


int displaySupplierMenu()
{
    int choice;
    printf("\n-----------------------------------------------------------------------------------------------");
    printf("\nQWhat do you want to do? Enter");
    printf("\n[1] Show all suppliers");
    printf("\n[2] Search and display a supplier");
    printf("\n[3] Insert a new supplier");
    printf("\n[4] Update an existing supplier ");
    printf("\n[5] Delete a supplier");
    printf("\n[6] Insert a product supplied by a supplier");
    printf("\n[7] Delete a product supplied by a supplier");
    printf("\n\n[8] Save current suppliers and return to the main menu");

    printf("\n\nEnter your choice: \t");
    do
    {
        char value3[10];
        scanf(" %s",value3);
        choice=checkValidValue(value3);
        if(choice<1||choice>8)
            printf("Invalid entry. Try Again:\t ");
    }while(choice<1||choice>8);
    return choice;
}


int displaySaleMenu()
{
    int choice;
    printf("\n-----------------------------------------------------------------------------------------------");
    printf("\nWhat do you want to do? Enter");
    printf("\n[1] Search for a sale");
    printf("\n[2] Add a new sale");
    printf("\n[3] Update an existing sale");
    printf("\n[4] Cancel a sale");
    printf("\n[5] View all sales");
    printf("\n[6] View total revenue\n\n");
    printf("\n\n[7] Save current sales and return to the main menu");

    printf("\n\nEnter your choice: ");
    do
    {
        char value3[10];
        scanf(" %s",value3);
        choice=checkValidValue(value3);
        if(choice<1||choice>7)
            printf("Invalid entry. Try Again: ");
    }while(choice<1||choice>7);
    return choice;
}

void displayWelcomeMessage()
{
    printf("\n\n\n\n \n\n \n\n \n\n \n\n \n\n \n\n                                         ***************************************************************************************\n");
    printf("                                         *                        WELCOME TO MRDICAL STORE MANAGEMENT              *");
    printf("\n                                         ***************************************************************************************");
    printf("\n\n\n \n\n           Our software was designed by YANKAM YVAEL to manage , sales and supply of the products of a medical store..\n");
    printf("  \n          I hope that this will be satisfactory and will meet your expectations.\n");
    printf("\n\n\nPress [ENTER] to start the program...\n");
}


void displayGoodbyeMessage()
{
    printf("\n \n \n \n\n \n\n \n\n \n\n \n\n \n\n \n\n \n                                         ****************************************************************************************\n");
    printf("                                         *               THANK YOU FOR USING THE ETS RAYAN SMALL SERVICE SOFTWARE !!!             *");
    printf("\n                                         ****************************************************************************************");

}

int displayMainMenu()
{
    int choice;
    printf("\n\nWhat operation do you want to perform? Enter:\n");
    printf("\n[1] PRODUCT MANAGEMENT.");
    printf("\n[2] MANAGEMENT BY CATEGORY.");
    printf("\n[3] SALES MANAGEMENT.");
    printf("\n[4] MANAGEMENT OF SUPPLIERS.");
    printf("\n\n[5]  EXIT from the program");
    printf("\n\nYour choice: ");
        char value[10];
         scanf(" %s",value);
    choice=checkValidValue(value);
        do
        {
            if(choice<1&&choice>5)
                printf("Invalid. Please enter a valid choice: ");
        }while(choice<1&&choice>5);
        return choice;
}


