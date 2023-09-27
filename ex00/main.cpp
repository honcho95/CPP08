#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

#include <vector>
#include <iostream>
#include "easyfind.hpp"

#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;
    for (int i = 1; i <= 10; ++i) 
    {
        numbers.push_back(i * 10);
    }
    numbers.push_back(30);

    std::cout << "Vector contents: ";
    for (std::vector<int>::const_iterator nb = numbers.begin(); nb != numbers.end(); ++nb)
    {
        std::cout << *nb << ';';
    }
    std::cout << std::endl;

    try 
    {
        int foundValue = easyfind(numbers, 30);
        int firstOccurrenceIndex = std::find(numbers.begin(), numbers.end(), foundValue) - numbers.begin();
        std::cout << "Found value : " << foundValue << " at index : " << firstOccurrenceIndex << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Trying to find a non-existing value : " << easyfind(numbers, 110) << std::endl;
    } 
    catch (const std::exception& e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    return 0;
}


