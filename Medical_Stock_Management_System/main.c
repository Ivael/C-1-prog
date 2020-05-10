#include"Category_Header.h"
#include"Drug_Header.h"
#include"Supplier_Header.h"
#include"Sale_Header.h"

int main()

{
    displayWelcomeMessage();
        getchar();
        system("cls");
    int choice;
    do
    {
       choice=displayMainMenu();
        system("cls");
        switch(choice)
        {
        case 1:
            drug_operations();
            break;
        case 2:
            category_operations();
            break;
        case 3:
            sale_operations();
            break;
        case 4:
            supplier_operations();
            break;
        case 5:
            system("cls");
                displayGoodbyeMessage();
            break;
        }
    }while(choice!=5);

return 0;
}
