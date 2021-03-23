#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using std::ostream, std::istream;

class Array{
    friend ostream &operator<<( ostream &, const Array &);

    friend istream &operator>>( istream &, Array &);

    friend Array operator+(Array &, Array &);
public:
    Array( int = 10 );
    Array(const Array &);
    ~Array();

    int getSize() const;

    
    const Array &operator=( const Array & );

    bool operator==( const Array & );

    bool operator!=( const Array &dir)
    {
        return !(*this == dir);
    }

    int &operator[](int);
    int operator[](int) const;

    const Array &operator+=( const Array & );

private:
    int tam;
    int *arr;
};

#endif