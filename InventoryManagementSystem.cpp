// Allen Sacueza

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

    int userChoice;
    
    //  ARRAYS/TABLES
    int id[100] = {0}, quantity[100] = {0};
    //https://stackoverflow.com/questions/23509348/how-to-set-all-elements-of-an-array-to-zero-or-any-same-value
    string name[100];
    float unitCost[100];

    //ENTER VALUES INTO ARRAY
    int enterID, enterQuantity;
    string enterName;
    float enterUnitCost;

    //OTHER VARIABLES
    int emptyArray;
    int randomInt; //random value
    float randomFloat;

    //functions for menu
    void addProduct(void);
    void displayAllProducts(void);
    void searchProduct(void);
    void updateQuantity(void);
    void summaryReport(void);

    //functions to reuse
    int emptySlot();
    int noProducts();
    int totalProducts();
    float inventoryValue();

int main()
{
    do{
        //  MENU

        cout << "\n\n=========================================\n";
        cout << "Manufacturing Inventory Management System\n";
        cout << "=========================================\n\n";
        cout << "1. Add Product\n";
        cout << "2. Display All Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Quantity\n";
        cout << "5. View Summary Report\n";
        cout << "6. Exit\n\n";
        cout << "Please Enter A Number: ";

        //USER INPUTS A NUMBER (CHOICE)
        cin >> userChoice;
        cin.ignore();

        if (userChoice <= 0 || userChoice >= 7) //out of bounds
            {
                cout << "\nInvalid. Please Enter a Number From The Choices Provided.";
            }
        else if (userChoice == 1)
            {
                addProduct();
            }
        else if (userChoice == 2)
            {
                displayAllProducts();
            }
        else if (userChoice == 3)
            {
                searchProduct();
            }
        else if (userChoice == 4)
            {
                updateQuantity();
            }
        else if (userChoice == 5)
            {
                summaryReport();
            }
    } while (userChoice != 6); // End of loop. Checks if the user wants to exit the program.

    cout << "Exiting Program...\n";
    cout << "Thank you!";

    return 0;
}

void addProduct(void)
{
    emptySlot();

    if (emptyArray == -1) //checks if all slots are filled in the array
    {
        cout <<  "\nSorry! No More Slots Are Available.";
    }
    else //if the array is not yet full, program will continue
    {
        idLoop:

        cout << "\nEnter Product ID: ";
        cin >> enterID;
           cin.ignore();// consumes new line
                        // src: https://www.youtube.com/watch?v=Su3a6vTtTFw&t=179s

        if (enterID == 0)
        {
            cout << "Invalid. ID value can not be 0.";
            goto idLoop;
        }

            randomInt = 0;

        for (int i = 0; i < emptyArray; i++)
        {
            if (id[i] == enterID) //find duplicates
            {
                randomInt++;
            }
        }

        if (randomInt > 0)
        {
            cout << "Invalid. ID already exists. Please try again.";
            goto idLoop;
        }

            id[emptyArray] = enterID;  //sets entered value to be the ID 

            cout << "\nEnter Product Name: ";
            getline(cin, enterName); //used to consider spaces in between product names
                                    //inabot po ako 1 hour para ma-figure out to hahaha
                                    //src: https://cplusplus.com/doc/tutorial/basic_io/
            name[emptyArray] = enterName; //sets value to be the name

            cout << "\nEnter Unit Cost: ";
            cin >> enterUnitCost;
            unitCost[emptyArray] = enterUnitCost;  //sets value to be unit cost

            cout << "\nEnter Quantity: ";
            cin >> enterQuantity;
            quantity[emptyArray] = enterQuantity; //entered value will be the quantity

            cout << "\nProduct has been added successfully!\n";
    }
}

void displayAllProducts(void)
{
    noProducts();

    if (randomInt >= 100)
    {
        cout << "\nSorry! No products are currently available!\n";
    }
    else 
    {
        totalProducts();
        inventoryValue();

        cout << "\n" << setw(6) << "ID" << setw(25) << "NAME" << setw(12) << "UNIT COST";
        cout << setw(12) << "QUANTITY" << setw(15) << "TOTAL VALUE";
        cout << "\n-----------------------------------------------------------------";

        for (int i = 0; i < 100; i++)
        {
            if (id[i] != 0)
            {
                cout << "\n" << setw(6)  << id[i] << setw(25) << name[i] << setw(12) << fixed << setprecision(2) << unitCost[i];

                cout.unsetf(ios::fixed);

                cout << setw(12) << quantity[i] << setw(15) << fixed << setprecision(2) << quantity[i] * unitCost[i];

                cout.unsetf(ios::fixed);
            }
        }
                        
        cout << "\n-----------------------------------------------------------------";
        cout << "\nTotal number of products: " << randomInt;
        cout << "\nTotal inventory value: " << fixed << setprecision(2) << randomFloat;
        cout.unsetf(ios::fixed);
    }
}
    
void searchProduct(void)
{
    noProducts();

    if (randomInt >= 100)
    {
        cout << "\nSorry! No products are currently available!\n";
    }
    else 
    {
        searchLoop: //starts again if product is not found

        randomInt = 0;

        cout << "\nEnter Product ID to search: ";
        cin >> enterID;

        for (int i = 0; i < 100; i++)
        {
            if (id[i] == enterID)
            {
                cout << "\nProduct found!";
                cout << "\n\nID: " << id[i];
                cout << "\nName: " << name[i];
                cout << "\nUnit Cost: " << fixed << setprecision(2) << unitCost[i];
                cout.unsetf(ios::fixed);
                cout << "\nQuantity: " << quantity[i];
                cout << "\nTotal Value: " << fixed << setprecision(2) << quantity[i] * unitCost[i];
                cout.unsetf(ios::fixed);
            }
            else if (id[i] != enterID)
            {
                randomInt++;
                if (randomInt == 100)
                {
                    cout << "\nSorry! Product was not found.";
                    goto searchLoop;
                }
            }
        }           
    }
}

void updateQuantity(void)
{
    int updateQ; //update quantity

    noProducts();

    if (randomInt >= 100)
    {
        cout << "\nSorry! No products are currently available!\n";
    }
    else 
    {
        updateLoop:

        randomInt = 0;

        cout << "\nEnter Product ID to update: ";
        cin >> enterID;
                
        for (int i = 0; i < 100; i++)
        {
            if (id[i] == enterID) //if enterID matches an ID inside the array
            {
                cout << "\nEnter new product quantity: ";
                cin >> updateQ;
                quantity[i] = updateQ;
                cout << "\nProduct ID: " << id[i] << "'s quantity updated successfully!";
            }
            else if (id[i] != enterID)
            {
                randomInt++;
                if (randomInt == 100)
                {
                cout << "\nSorry! No product was found. Please try again.";
                goto updateLoop;
                }
            }
        }
    }
}

void summaryReport(void)
{
    int highestQuantity = 0, lowestQuantity = 1000000;
    int highestIndex = 0, lowestIndex = 0;

    noProducts();

    if (randomInt >= 100)
    {
        cout << "\nSorry! No products are currently available!\n";
    }
    else 
    {
        totalProducts();
        inventoryValue();

            for (int i = 0; i < 100; i++) //for product with highest quantity
            {
                if (quantity[i] > highestQuantity)
                {
                    highestQuantity = quantity[i];
                    highestIndex = i;
                }
            }

        emptySlot();

            for (int i = 0; i < emptyArray; i++) //for product with lowest quantity
            {
                if (quantity[i] < lowestQuantity)
                {
                    lowestQuantity = quantity[i];
                    lowestIndex = i;
                }
            }

        cout << "\n\n===============INVENTORY REPORT===============";
        cout << "\nTotal number of products: " << randomInt;
        cout << "\nTotal inventory value: " << fixed << setprecision(2) << randomFloat;
        cout.unsetf(ios::fixed);
        cout << "\nHighest product quantity: " << name[highestIndex] << "(" << highestQuantity << " units)";
        cout << "\nLowest product quantity: " << name[lowestIndex] << "(" << lowestQuantity << " units)";
        cout << "\n==============================================\n\n";
    }
}

int noProducts() //function definition
{
    randomInt = 0;

    for (int i = 0; i < 100; i++)
    {
        if (id[i] == 0)
        {
            randomInt++;
        }
    }

    return randomInt;
}

int totalProducts()
{
    randomInt = 0;

    for (int i = 0; i < 100; i++) //For total number of products
    {
        if (id[i] != 0)
        {
            randomInt++;
        }
    }
    
    return randomInt;
}

float inventoryValue()
{
    randomFloat = 0;

    for (int i = 0; i < 100; i++) //for total inventory value 
    {
        if (id[i] != 0)
        {
            randomFloat = (quantity[i] * unitCost[i]) + randomFloat;
        }
    }

    return randomFloat;
}

int emptySlot()
{
    emptyArray = -1;

    for (int i = 0; i < 100; i++) //used to check for the nearest empty array
    {
        if (id[i] == 0 && emptyArray == -1)
        {
            emptyArray = i;
        }
    }

    return emptyArray;
}