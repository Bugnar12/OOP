#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "UI.h"
#include "Validator.h"


UI* createUI(Service* s)
/// This function creates the UI
/// Input: s - pointer to the service
/// Output: ui - pointer to the UI

{
    UI* ui = malloc(sizeof(UI));
    if(ui == NULL)
        return ui;
    ui->service = s;
    return ui;
}

void destroyUI(UI* ui)
/// This function destroys the UI
/// Input: ui - pointer to the UI
/// Frees the memory to avoid memory leaks

{
    if(ui == NULL)
        return;
    free(ui);
}

void printings()
/// This function prints the commands
{
    printf("\n");
    printf("Choose one of the commands below using integer number : \n");
    printf("0. Exit program\n");
    printf("1. Display estates\n");
    printf("2. Add estate\n");
    printf("3. Delete estate\n");
    printf("4. Update estate\n");
    printf("5. Second functionality\n");
    printf("6. Third functionality\n");
    printf("7. Undo\n");
    printf("8. Redo\n");
}

void addEstatesToRepo(Repository* repo)
/// This function adds estates to the repository
/// Input: repo - pointer to the repository
/// estates - pointer to the array of estates
{


    Estate* e1 = createEstate("penthouse", "Lalele", 100, 1000);
    Estate* e2 = createEstate("house", "Mere", 200, 2000);
    Estate* e3 = createEstate("house", "Alfonso", 300, 3000);
    Estate* e4 = createEstate("apartment", "Merele", 2000, 300);
    Estate* e5 = createEstate("apartment", "Highway", 500, 5050);
    Estate* e6 = createEstate("house", "Churchill", 450, 150);
    Estate* e7 = createEstate("house", "Winden", 300, 700);
    Estate* e8 = createEstate("house", "Perele", 800, 640);
    Estate* e9 = createEstate("penthouse", "Gutuile", 900, 9000);
    Estate* e10 = createEstate("house", "Broadway", 1000, 10000);

    addEstate(repo, e1);
    addEstate(repo, e2);
    addEstate(repo, e3);
    addEstate(repo, e4);
    addEstate(repo, e5);
    addEstate(repo, e6);
    addEstate(repo, e7);
    addEstate(repo, e8);
    addEstate(repo, e9);
    addEstate(repo, e10);
}

void displayEstates(UI* ui)
///Display estates
///Input: -
///Output: the estates are displayed

{
    DynamicArray *estates = getAll(ui->service->repo);
    int size = getSize(ui->service->repo);
    for (int i = 0; i < size; i++) {
        Estate *e = getByPosition(estates, i);
        printf("%s %s %d %d \n", getType(e), getAddress(e), getSurface(e), getPrice(e));
    }
}

void addEstateUI(UI* ui)
///Add estate
///Input: type, address, surface, price
///Output: the estate is added to the repo

{
   ///initial state
    char type[20];
    char address[20];
    char surface[20];
    char price[20];
    scanf("%s %s %s %s", type, address, surface, price);
    int surface1 = atoi(surface);
    int price1 = atoi(price);


    if(validateType(type) == 0 || validateAddress(address) == 0 || validateSurface(surface) == 0 || validatePrice(price) == 0)
    {
        printf("Invalid input! \n");
        return;
    }
    if(addEstateService(ui->service, type, address, surface1, price1) == 0)
        printf("The estate was added!\n");
    else
        printf("The estate already exists!\n");


}

void deleteEstateUI(UI* ui)
///Delete estate by address
///Input: address
///Output: the estate is deleted from the repo

{
    char address[20];
    scanf("%s", address);
    if(deleteEstateService(ui->service, address) != 0)
    {
        printf("The address you want to delete does not exist\n");
        return;
    }
    else {
        deleteEstateService(ui->service, address);
        printf("The estate was deleted\n");
    }
}

void updateEstateUI(UI* ui)
///Update estate by address
///Input: address, type, surface, price
///Output: the estate is updated in the repo

{
    char type[20];
    char address[20];
    char surface[20];
    char price[20];
    scanf("%s %s %s %s", type, address, surface, price);
    if(validateType(type) == 0 || validateAddress(address) == 0 || validateSurface(surface) == 0 || validatePrice(price) == 0)
    {
        printf("Invalid input! \n");
        return;
    }
    int surface1 = atoi(surface);
    int price1 = atoi(price);

    if(updateEstateService(ui->service, type, address, surface1, price1) == 1)
        printf("The address does not exist!\n");
    else
        printf("The estate was updated!\n");
}

void SortByPriceUI(UI* ui)
///Sorts the estates by price
///Input: address
///Output: the estates are sorted by price'
{
    char address[20];
    gets(address);
    gets(address);

    if(findEstateContainingAddress(ui->service->repo, address) == NULL)
    {
        printf("The address does not exist!\n");
        return;
    }

    if(strcmp(address, "") == 0)
    {
        DynamicArray* NewArray = filterIfAddressNull(ui->service);
        for(int i = 0; i < getSizeDynamic(NewArray); i++)
        {
            Estate* e = getByPosition(NewArray, i);
            printf("%s %s %d %d \n", getType(e), getAddress(e), getSurface(e), getPrice(e));
        }
    }
    else
    {
        DynamicArray* NewArray = filterAddressAscendingByPrice(ui->service, address);
        for(int i = 0; i < getSizeDynamic(NewArray); i++)
        {
            Estate* e = getByPosition(NewArray, i);
            printf("%s %s %d %d \n", getType(e), getAddress(e), getSurface(e), getPrice(e));
        }
    }

}
void filterBySurfaceUI(UI* ui)
///Filter the estates by surface
///Input: UI
{
    char surface[20];
    char type[20];
    scanf("%s %s", surface, type);
    if(validateType(type) == 0 || validateSurface(surface) == 0)
    {
        printf("The valid types are house, penthouse, apartment \n");
        return;
    }
    int surface1 = atoi(surface);
    DynamicArray* NewArray = higherSurfaceEstates(ui->service, surface1);
    for(int i = 0; i < getSizeDynamic(NewArray); i++)
    {
        Estate* e = getByPosition(NewArray, i);
        if(strcmp(getType(e), type) == 0) {
            printf("%s %s %d %d \n", getType(e), getAddress(e), getSurface(e), getPrice(e));
        }
    }
}


void run(UI *ui)
///Run the program
///Input: the UI
{
    addEstatesToRepo(ui->service->repo);

    while (1) {
        int command;
        int numScanned;
        do {
            printings();
            printf("Enter your option (0-8): \n");
            numScanned = scanf("%d", &command);
            if (numScanned != 1) {

                while (getchar() != '\n');
                printf("Invalid input. Please enter a valid option.\n");
            }
        } while (numScanned != 1 || command < 0 || command > 8);
        if (command == 1) {
            displayEstates(ui);
        } else if (command == 2) {
            printf("Input the type, address, surface and price:\n");
            addEstateUI(ui);
        } else if (command == 3) {
            printf("Input the address you want to delete : \n");
            deleteEstateUI(ui);
        } else if (command == 4) {
            printf("Input the estate you want to update : \n");
            updateEstateUI(ui);
        }
        else if(command == 5)
        {
            printf("Input the address you want to sort by price : \n");
            SortByPriceUI(ui);
        }
        else if(command == 6)
        {
            printf("Input the surface and the type you want to filter by: \n");
            filterBySurfaceUI(ui);
        }

        else if(command == 7)
        {
            undoService(ui->service);
        }

        else if(command == 8)
        {
            redoService(ui->service);
        }

        else if(command == 0)
        {
            break;
        }
        else
        {
            printf("Invalid command!\n");
        }
    }
}
