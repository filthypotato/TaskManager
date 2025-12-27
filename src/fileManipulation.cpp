#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include "fileManipulation.h"
#include "onlyInt.h"   // Uses onlyInt() function in this file
#include "mainMenu.h"  // this is for clearing the screen
#include "encdec.h"    // for encoding / decoding

void clearScreen();

// File Manipulation Menu 
void fileManipulationMenu()
{
	std::string fileName{}; // Variable to store file name for file manipulation tasks

	std::cout << "[1] Create a file\n";
	std::cout << "[2] Read a file\n";
	std::cout << "[3] Update a file\n";
	std::cout << "[4] Delete a file\n";
	std::cout << "[5] Encryption/Decryption\n";


	int choice = onlyInt("Enter your choice: "); // only add numerical input allowed
												// check onlyInt.h
	switch (choice)
	{
	case 1:
		clearScreen();
		std::cout << "You selected Create a file.\n";
		createFile(fileName);
		break;
	case 2:
		clearScreen();
		std::cout << "You selected Read a file.\n";
		readFile(fileName);
		break;
	case 3:
		clearScreen();
		std::cout << "You selected Update a file.\n";
		updateFile(fileName);
		break;
	case 4:
		clearScreen();
		std::cout << "You selected Delete a file.\n";
		deleteFile(fileName);
		break;
	case 5:
		clearScreen();
		std::cout << "You selected file Encryption/Decryption.\n";
		cipherCryption(fileName);
		break;
	default:
		std::cout << "Invalid choice. Please try again.\n";
		break;
	}
}


void createFile(std::string& fileName)
{

	std::cout << "Enter the name of the file to create (include .txt, .md, etc): ";
	std::getline(std::cin >> std::ws, fileName);

	if (fileName.empty())
	{
		std::cout << "Sorry, you did not input anything. \n";
		return;
	}
	// Creates a file of users choice
	std::ofstream MyFile(fileName); //  
	if (!MyFile)      // checks if file was created successfully
	{
		std::cerr << "\nError creating file '" << fileName << "'!\n";
		return;
	}

	std::cout << "Enter the text to write to the file.\n";
	std::cout << "(Type 'done' on a new line to finish writing)\n";

	std::string fileLine{}; // Variable to store line of user input

	while (true)
	{
		std::getline(std::cin, fileLine);
		if (fileLine == "DONE" || fileLine == "done")
		{
			break;
		}
		MyFile << fileLine << "\n"; // writes user input to file
	}

	// Closes the file
	MyFile.close();
	std::cout << "File " << fileName << " created successfully!\n";
}

void readFile(std::string& fileName)
{
	std::cout << "Enter the name of the file to read (include .txt, .md, etc): ";
	std::getline(std::cin >> std::ws, fileName); // use std::ws to ignore leading whitespace if user inputs any

	// Reads from the text file
	std::ifstream MyReadFile(fileName);
	if (!MyReadFile)
	{
		std::cout << "File '" << fileName << "' does not exist.\n";
		return;
	}

	std::cout << "Contents of '" << fileName << "'.\n";

	// Uses a while loop together with getline() to read the file line by line
	std::string fileLine{};
	while (getline(MyReadFile, fileLine))
	{
		std::cout << fileLine << "\n";
	}

	// Closes the file
	MyReadFile.close();
}

void updateFile(std::string& fileName)
{
	// Asks user which file they would like to update
	std::cout << "Enter the name of the file you would like to update (include .txt, .md, etc): ";
	std::getline(std::cin >> std::ws, fileName);

	// Open file for reading its current contents
	std::ifstream MyUpdateFile(fileName, std::ios::in);
	if (!MyUpdateFile)
	{
		std::cout << "File '" << fileName << "' does not exist!" << '\n';
		return;
	}

	// Reads existing contents
	std::string oldContent{};   // string to hold the old content from the file
	std::string line{};   // string to store new lines of text in file

	while (std::getline(MyUpdateFile, line))
	{
		oldContent += line + '\n';
	}
	MyUpdateFile.close();

	// Shows current content
	std::cout << "\nCurrent contents of '" << fileName << "':\n";
	std::cout << "----------------------------------------\n";
	std::cout << oldContent;
	std::cout << "----------------------------------------\n";

	// Asks user if they want to update the file
	std::cout << "\nDo you want to update this file? (y/n): ";
	char answer{};
	std::cin >> answer;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear leftover newline
	if (answer != 'y' && answer != 'Y')  // if answer is not equal to either y or Y
	{
		std::cout << "File update cancelled.\n";
		return;
	}

	// If yes, get text input from user
	std::cout << "Enter the content to append to the file.\n";
	std::cout << "(Type 'done' on a new line to finish writing)\n";

	
	std::string newContent{}; // string to store new lines inputed
	std::string fileLine{};   // string to store new fileLines being added.
	while (true)
	{
		std::getline(std::cin, fileLine);
		if (fileLine == "DONE" || fileLine == "done")
		{
			break;
		}
		newContent += fileLine + '\n';
	}

	// Appends new content to selected file to update. 
	std::ofstream writeFile(fileName, std::ios::app);

	if (!writeFile)
	{
		std::cerr << "Error opening file '" << fileName << "' for appending!\n";
		return;
	}

	writeFile << newContent;
	writeFile.close();

	std::cout << "File '" << fileName << "' updated successfully!\n";
}

void deleteFile(std::string& fileName)
{
	// Asks user which file they would like to delete
	std::cout << "Enter the name of the file you would like to delete (include .txt, .md, etc): ";
	std::getline(std::cin >> std::ws, fileName);

	// checks if files does exist
	std::ifstream checkFile(fileName);
	if (!checkFile)
	{
		std::cout << "File '" << fileName << "' does not exist! :(\n";
		return;
	}
	checkFile.close();

	// to delete the file selected
	if (std::remove(fileName.c_str()) == 0)
	{
		std::cout << "'" << fileName << "' was deleted successfully!\n";
	}
	else
	{
		std::cout << "T'was an error? Does this file exist? -_-\n";
	}
}

void cipherCryption(const std::string& fileName)
{
	EncDec encdec;  

	std::cout << "Encrypt or decrypt? (E/D): ";
	char answer{};
	std::cin >> answer;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear leftover newline

	if (answer == 'E' || answer == 'e')
		encdec.encrypt();
	else if (answer == 'D' || answer == 'd')
		encdec.decrypt();
	else
		std::cout << "Not an option.\n";
	
	// Note: fileName parameter is reserved for future use when file selection is implemented
	(void)fileName; // Suppress unused parameter warning
}
