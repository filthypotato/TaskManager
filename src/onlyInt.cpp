#include "onlyInt.h"
#include <iostream>
#include <string>


int onlyInt(const std::string& prompt)
{
    int value{};
    std::string input{};

    std::cout << prompt;
    while (true)
    {
        std::getline(std::cin, input);
        
        // Try to extract integer from the input
        try
        {
            std::size_t pos{};
            value = std::stoi(input, &pos);
            
            // Check if entire string was consumed (no trailing non-numeric characters)
            if (pos == input.length())
            {
                return value;
            }
        }
        catch (const std::exception&)
        {
            // stoi failed, input is invalid
        }
        
        std::cout << "Invalid input, please enter a number: ";
    }
}
