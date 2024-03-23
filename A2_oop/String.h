#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
    char* data;
    int size;

public:
    String();                                  // Default constructor
    String(const char* str);                   // Constructor from C-string
    String(const String& other);               // Copy constructor
    String(int x);                             // Constructor from integer
    ~String();                                 // Destructor

    char* getdata() const;

    // Sub-script Operators
    const char operator[](int i) const;

    // Arithmetic Operators
    String operator+(const String& str) ;
    String operator+(const char& ch);
    String operator+(const char* str) ;
    String operator-(const String& substr) ;
    String operator-(const char& ch) ;
    String operator-(const char* str) ;

    // Assignment Operators
    String& operator=(const String& str);
    String& operator=(const char* str);

    // Logical Operators
    bool operator==(const String& str) const;
    bool operator==(const char* str) const;

    // Unary Operators
    bool operator!() ;

    // Function-Call Operators
    int operator()(char ch) const;
    int operator()(const String& str) const;
    int operator()(const char* str) const;

    // Conversion Operator
    operator int() const;

    // Friends
    friend ostream& operator<<(ostream& output, const String& str);
    friend istream& operator>>(istream& input, String& str);
};

#endif // STRING_H
