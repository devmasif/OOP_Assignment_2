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
    explicit String(int x);                    // Constructor from integer (explicit)
    ~String();                                 // Destructor

    char* getdata() const;

    // Sub-script Operators
    const char operator[](int i) const;

    // Arithmetic Operators
    String operator+(const String& str) const;
    String operator+(const char& ch) const;
    String operator+(const char* str) const;
    String operator-(const String& substr) const;
    String operator-(const char& ch) const;
    String operator-(const char* str) const;

    // Assignment Operators
    String& operator=(const String& str);
    String& operator=(const char* str);

    // Logical Operators
    bool operator==(const String& str) const;
    bool operator==(const char* str) const;

    // Unary Operators
    bool operator!() const;

    // Function-Call Operators
    int operator()(char ch) const;
    int operator()(const String& str) const;
    int operator()(const char* str) const;

    // Conversion Operator
    operator int() const;

    // Friends
    friend std::ostream& operator<<(std::ostream& output, const String& str);
    friend std::istream& operator>>(std::istream& input, String& str);
};

#endif // STRING_H
