#include "encdec.h"

#include <fstream>
#include <iostream>

void EncDec::encrypt()
{
    std::string fileName{}; // stores the name of the file to encrypt
    
    // Asks user for file that they want to encrypt
    std::cout << "Enter the name of the file to encrypt (include .txt, .md, etc): ";
    std::getline(std::cin >> std::ws, fileName);

    // Asks user for a pharse to encrypt file with
    std::cout << "Enter a phrase key to encrypt with: ";
    std::getline(std::cin >> std::ws, phrase);

    if (phrase.empty()) // Checks if phrase input is empty
    {
        std::cout << "Phrase cannot be empty!\n";
        return; // stops the encryption if no phrase is entered
    }


    // Check if file exists and opens for reading in binary mode
    std::ifstream fin(fileName, std::ios::binary);
    if (!fin) // If the file fails to open
    {
        std::cout << "File '" << fileName << "' does not exist! :(\n";
        return; // Stops the encryption since file cannot be found
    }

    // Output File

     // outName variable is fileName + .enc extension to file
    std::string outName = fileName + ".enc"; 

    // Opens the output file to write in binary mode    trunc overwrites
    std::ofstream fout(outName, std::ios::binary | std::ios::trunc);
    if (!fout) // checks to see if file could be opened
    {
        std::cout << "Could not open '" << outName << "' for writing.\n";
        return;  // Stops encryption if file is not writable
    }

    char ch{};   // stores each char from file being read
    std::size_t index = 0;   // tracks char in phrase to use encryption
    const std::size_t phraseLen = phrase.size(); // stores the phrase length

    while (fin.get(ch)) // read each byte / char from the file
    {
        // converts file char into bite values (0-255)
        unsigned char plain = static_cast<unsigned char>(ch);

        // % makes the phrase loops back to the start when it gets to the end
        unsigned char keyByte = static_cast<unsigned char>(phrase[index % phraseLen]);
        
        // XOR encryption / reversible combo of file byte and key byte 
        unsigned char cipher = plain ^ keyByte;

        // Writes the encrypted byte to output file
        fout.put(static_cast<char>(cipher));
        ++index; // moves down to the next char in the phrase for next loop
    }

    std::cout << "File '" << fileName << "' encrypted as '" << outName << "'.\n";


    // need to delete the original file that gets encyrpted or make the whole file convert instead of making a new file??
  
}

void EncDec::decrypt()
{
    std::string fileName{}; // stores the name of the file to encrypt

    // Asks user for file that they want to encrypt
    std::cout << "Enter the name of the file to decrypt (include .txt, .md, etc): ";
    std::getline(std::cin >> std::ws, fileName);

    // Asks user for a pharse to encrypt file with
    std::cout << "Enter the encryption key to decrypt: ";
    std::getline(std::cin >> std::ws, phrase);

    if (phrase.empty()) // Checks if phrase input is empty
    {
        std::cout << "Phrase cannot be empty!\n";
        return; // stops the decryption if no phrase is entered
    }

    // Opens the encryption file for reading in binary
    std::ifstream fin(fileName, std::ios::binary);
    if (!fin) //  If file does NOT exist, it cannot be opened
    {
        std::cout << "File '" << fileName << "' does not exist! :(\n";
        return; // stops decryption
    }

    // creates the decrypted outName file
    std::string outName = fileName + ".dec";     // adds .dec to end of file

    // Opens files for writing in binary
    // trunc overwrites the file if it already exists
    std::ofstream fout(outName, std::ios::binary | std::ios::trunc); // opens file to take file and encrypt with binary
    if (!fout) // if you cannot write to the file
    {
        std::cout << "Could not open '" << outName << "' for writing.\n";
        return; // Stops decryption  if file cannot be wrote too
    }

    
    char ch{}; // stores each encrypted byte
    std::size_t index = 0; // tracks which phrase char to use for decryption
    const std::size_t phraseLen = phrase.size();

    // reads the encrypted data one byte at a time
    while (fin.get(ch))
    {
        // encrypted byte value of (0 - 255)
        unsigned char cipher = static_cast<unsigned char>(ch);

        // gets the matching byte phrase. % to loop the phrase
        unsigned char keyByte = static_cast<unsigned char>(phrase[index % phraseLen]);  

        // XOR to reverse the encryption and restores the original bytes to the file
        unsigned char plain = cipher ^ keyByte;   

        // Writes the decrypted byte data to the output file
        fout.put(static_cast<char>(plain));
        ++index; // Moves to the next char in phrase
    }

    std::cout << "File '" << fileName << "' decrypted as '" << outName << "'.\n";
}


