#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>

class SpanFullException : public std::exception 
{
    public:
        virtual const char *what() const throw()
        {
            return "Exceeding maximum N size";
        }
};

class NotEnoughNbrException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "Not enough numbers";
        }
};

class Span  
{
    private:
        unsigned int        N;
        std::vector<int>    nbr;

    public:
        Span(unsigned int N);
        Span(const Span& other);
        ~Span();
        Span& operator=(const Span& other);

        void addNumber(int num);

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end);

        int shortestSpan() const;
        int longestSpan() const;
};

#endif
