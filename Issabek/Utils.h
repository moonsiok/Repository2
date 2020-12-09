#pragma once
#include <iostream>
#include <string>


unsigned int GetCorrectNumber(unsigned int min, size_t max)
{
    unsigned int value;
    while ((std::cin >> value).fail() || value > max || value < min)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Only numbers from " << min << " to " << max << " can be entered: ";
    }
    return value;
}
