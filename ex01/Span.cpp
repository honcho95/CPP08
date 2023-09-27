#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& other) : N(other.N), nbr(other.nbr) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) 
{
    if (this != &other) 
    {
        N = other.N;
        nbr = other.nbr;
    }
    return *this;
}

void Span::addNumber(int num)
{
    if (nbr.size() >= N)
    {
        throw SpanFullException();
    }
    nbr.push_back(num);
}

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
    if(nbr.size() + std::distance(begin, end) > N)
        throw SpanFullException();
    while (begin != end)
    {
        addNumber(*begin);
        ++begin;
    }
}

int Span::shortestSpan() const
{
    if (nbr.size() <= 1)
    {
        throw NotEnoughNbrException();
    }
    std::vector<int> copy = nbr;
    std::sort(copy.begin(), copy.end());
    int shortest = copy[1] - copy[0];
    for (size_t i = 2; i < copy.size(); ++i)
    {
        if (copy[i] - copy[i-1] < shortest)
        {
            shortest = copy[i] - copy[i-1];
        }
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (nbr.size() <= 1)
    {
        throw NotEnoughNbrException();
    }
    return *std::max_element(nbr.begin(), nbr.end()) - *std::min_element(nbr.begin(), nbr.end());
}
