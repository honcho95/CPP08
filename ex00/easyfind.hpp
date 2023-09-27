#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class notFoundException : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "An occurence wasn't found!";
    }
};

template <typename T>
int easyfind(T const& container, int value)
{
    typename T::const_iterator it;

    it = std::find(container.begin(), container.end(), value); // end pointe vers un elem fictif a la fin  de container
    if (it == container.end())
        throw notFoundException();
    return *it;
}

#endif
