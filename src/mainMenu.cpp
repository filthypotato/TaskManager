// mainMenu.cpp


#include <iostream>
#include <string>

#include "mainMenu.h"
#include "onlyInt.h"
#include "fileManipulation.h" 
 

void clearScreen() // clears screen after each selection
{
    std::cout << "\033[2J\033[1;1H"; // works on most modern terminals
}

void mainMenu()
{
    bool running = true;
    std::string fileName{}; // Variable to store file name for file manipulation tasks

    while (running)
    {
        std::cout << "Select a task to complete:\n";
        std::cout << "[1] File manipulation\n";
        std::cout << "[2] Get system information(WIP)\n";
        std::cout << "[3] Set a reminder(WIP)\n";
        std::cout << "[4] Exit\n";

        int choice = onlyInt("Enter your choice: ");
        switch (choice)
        {
        case 1:
            clearScreen();
            std::cout << "You selected File manipulation.\n\n";
            fileManipulationMenu();
            break;
        case 2:
            clearScreen();
            std::cout << "You selected Get system information.(WIP)\n\n";
            
            break;
        case 3:
            clearScreen();
            std::cout << "You selected Set a reminder.(WIP)\n\n";
            // Place holder
            break;
        case 4:
            running = false;
            std::cout << "Exiting the program. Goodbye!\n";
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}
