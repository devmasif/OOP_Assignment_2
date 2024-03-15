#include "D:\Assignment2_OOP\A2_oop\A2_oop\String.h"
#include <iostream>



int length(const char* ptr) {
    if (ptr == nullptr) {
        return 0;
    }

    int len = 0;
    while (ptr[len] != '\0') {
        len++;
    }
    return len;
}

String::String() : data(NULL), size(0) { }

String::String(const char* data )  {
    // Assuming length function correctly computes the length of the string
    data = nullptr;
    this->size = length(data);
    

    if (this->size != 0) {
        this->data = new char[this->size + 1];
        for (int i = 0; i < this->size; ++i) {
            this->data[i] = data[i]; // Copying contents
        }
        this->data[this->size] = '\0'; // Null-terminating the string
    }
    else {
        this->data = nullptr; // Assign nullptr if the input is nullptr
    }
}

 String::String(int x ) {
    if (x >= 0) {
        data = new char[1];
        data[0] = '\0';
        size = 0;
    }
    else {
        data = nullptr;
        size = 0;
    }
}

String::~String() {
    delete[] data;
}

String::String(const String& copy){
    this -> size = copy.size;
    if (this->size != 0) {
        this->data = new char[size + 1];
        for (int i = 0; i < this->size; i++)
        {
            this->data[i] = copy.data[i];
        }
        this->data[size] = '\0';
    }
    else
        this->data = nullptr;

}



char* String::getdata() const {
    return data; // Directly return the pointer to the internal character array
}

// Sub-script Operators
const char String::operator[](int i) const {
    return 0;
}


// Arithmetic Operators
String String::operator+(const String& str) const {
    return 0;
}
String String::operator+(const char& ch) const {
    return 0;
}
String String::operator+(const char* str) const {
    return 0;
}
String String::operator-(const String& substr) const {
    return 0;
}
String String::operator-(const char& ch) const { 
    return 0;
}
String String::operator-(const char* str) const {
    return 0;
}

// Assignment Operators
String& String::operator=(const String& str) {
    if (this != &str) { // Protect against self-assignment
        delete[] this->data; // Free existing resource
        this->size = str.size;
        this->data = new char[this->size + 1];
        for (int i = 0; i < this->size; ++i) {
            this->data[i] = str.data[i];
        }
        this->data[this->size] = '\0';
    }
    return *this;
}

String& String::operator=(const char* str) {
    delete[] this->data; // Free existing resource
    this->size = length(str);
    this->data = new char[this->size + 1];
    for (int i = 0; i < this->size; ++i) {
        this->data[i] = str[i];
    }
    this->data[this->size] = '\0';
    return *this;
}


// Logical Operators
bool String::operator==(const String& str) const {
    return 0;
}
bool String::operator==(const char* str) const {
    return 0;

}

// Unary Operators
bool String::operator!() const { 
    return 0;
}

// Function-Call Operators
int String::operator()(char ch) const {
    return 0;
}
int String::operator()(const String& str) const {
    return 0;
}
int String::operator()(const char* str) const {
    return 0;
}

// Conversion Operator
String::operator int() const {
    return 0;
}

// Friends
std::ostream& operator<<(std::ostream& output, const String& str) {
    if (str.getdata()) {
        output << str.getdata();
    }
    return output;
}

// The operator>> definition for String class
std::istream& operator>>(std::istream& input, String& str) {
    // Here we assume there is a member function `setdata` to set the string data.
    // Replace with the actual method you have for setting data.
    // You need to handle dynamic memory here, resizing buffer as needed to read input.

    char buffer[1024]; // or dynamically allocate a larger buffer if needed
    input >> buffer;

    // Assume setdata() frees any existing memory and sets the new value
   // str.setdata(buffer);

    return input;
}

