#include "D:\Assignment2_OOP\A2_oop\A2_oop\String.h"
#include <iostream>
using namespace std;




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



String::String() : data{ 0 }, size(0) {
    
}

String::String(const char* data )  {
    this->size = length(data);
    

    if (this->size != 0) {
        this->data = new char[this->size + 1];
        for (int i = 0; i < this->size; ++i) {
            this->data[i] = data[i]; 
        }
        this->data[this->size] = '\0'; 
    }
    else {
        this->data = nullptr; 
    }
}

String::String(const String& copy) {
    this->size = copy.size;
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





char* String::getdata() const {
    return data; // Directly return the pointer to the internal character array
}

// Sub-script Operators
const char String::operator[](int i) const {
    while(i<0)
    {
        i += this->size;
    }
    return this->data[i];
}


// Arithmetic Operators

String String::operator+(const String& str) {
    int newSize = this->size + str.size;
    char* newData = new char[newSize + 1];

    for (int i = 0; i < this->size; ++i) {
        newData[i] = this->data[i];
    }
    for (int i = 0; i < str.size; ++i) {
        newData[this->size + i] = str.data[i];
    }
    newData[newSize] = '\0';

    this->data = newData;
    this->size = newSize;
    return data;
}

String String::operator+(const char& c) {
    int newSize = this->size + 1;
    char* newData = new char[newSize + 1];

    for (int i = 0; i < this->size; ++i) {
        newData[i] = this->data[i];
    }
    newData[this->size] = c;
    newData[newSize] = '\0';

    this->data = newData;
    this->size = newSize;
    return data;
}


String String::operator+(const char* str) {
    int strLength = length(str);
    int newSize = this->size + strLength;
    char* newData = new char[newSize + 1];

    for (int i = 0; i < this->size; ++i) {
        newData[i] = this->data[i];
    }
    for (int i = 0; i < strLength; ++i) {
        newData[this->size + i] = str[i];
    }
    newData[newSize] = '\0';

    this->data = newData;
    this->size = newSize;
    
    return data;
}

String String::operator-(const String& substr) {
    
    int new_len = 0;

    for (int i = 0; i < this->size; )
    {
        bool check = false;
        for (int j = 0; j < (int)substr; j++)
        {
            if (this->data[i + j] == substr.data[j])
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
        }
        if (check == false)
        {
            new_len++;
            i++;
        }
        else
        {
            i += (int)substr;
        }
    }


    char* newData = new char[new_len + 1];

    for (int i = 0, k = 0; i < this->size; )
    {
        bool add = false;
        for (int j = 0; j < (int)substr ; j++)
        {
            if (this->data[i + j] == substr.data[j])
            {
                add = true;
            }
            else
            {
                add = false;
                break;
            }
        }
        if (add == false)
        {
            newData[k++] = this->data[i++];
            // i++;
        }
        else
        {
            i += (int)substr;
        }

    }
    newData[new_len] = '\0';

    delete[] this->data;
    this->data = newData;
    this->size = new_len;

    return *this;
}


String String::operator-(const char& ch) {

    int newSize = 0;
    for (int i = 0; i < this->size; i++)
    {
        if (this->data[i] != ch) {
            newSize++;
        }
    }

    char* newData = new char[newSize + 1];

    for (int i = 0 , j=0; i < this->size; i++)
    {
        if (this->data[i] != ch) {
            newData[j++] = this->data[i];
        }
    }
    newData[newSize] = '\0';
    delete[] this->data;
    this->data = newData;
    this->size = newSize;
    
    return *this;
    
}

String String::operator-(const char* str) {
    if (str == nullptr) {
        return *this; 
    }

    int new_len = 0;

    for (int i = 0; i < this->size; )
    {
        bool check = false;
        for (int j = 0; j < length(str); j++)
        {
            if (this->data[i + j] == str[j])
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
        }
        if (check == false)
        {
            new_len++;
            i++;
        }
        else
        {
            i += length(str);
        }
    }

    char* newData = new char[new_len + 1];

    for (int i = 0,k=0; i < this->size; )
    {
        bool add = false;
        for (int j = 0; j<length(str); j++)
        {
            if (this->data[i+j] == str[j])
            {
                add = true;
            }
            else
            {
                add = false;
                break;
            }
        }
        if (add==false)
        {
            newData[k++] = this->data[i++] ;
           
        }
        else
        {
            i += length(str);
        }

    }
    newData[new_len] = '\0';
    
    delete[] this->data;
    this->data = newData;


    return *this;
}


// Assignment Operators
String& String::operator=(const String& copy) {
    if (this->size != 0){
        delete[] this->data;
    }
    this->size = copy.size;
    if (copy.data != nullptr){
        this->data = new char[this->size + 1];
        for (int i = 0; i<this->size; i++)
        {
            this->data[i] = copy.data[i];
        }
        this->data[size] = '\0';
    }
    else {
        this->data = nullptr;
    }
    return *this;
}

String& String::operator=(const char* str) {
    if (this->size != 0)
    {
        delete[] this->data;
    }
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
    for (int i = 0; i < this->size; i++)
    {
        if (str.data[i] != this->data[i])
            return false;
    }
    return true;
}
bool String::operator==(const char* str) const {
    for (int i = 0; i < this->size; i++)
    {
        if (str[i] != this->data[i])
            return false;
    }
    return true;

}

// Unary Operators
bool String::operator!(){ 
    if (this->size != 0)
        return false;
    else
        return true;
}

// Function-Call Operators
int String::operator()(char ch) const {
    for (int i = 0; i < this->size; i++)
    {
        if (this->data[i] == ch)
        {
            return i;
        }
    }
    return -1;
}
int String::operator()(const String& str) const {
    for (int i = 0; i < this->size; i++)
    {
        bool found = false;
        for (int j = 0; j < (int)str; j++)
        {
            if (this->data[i] == str.data[j])
            {
                found = true;
            }
            else
            {
                found = false;
                break;
            }
            if (found)
            {
                return i;
            }
        }
    }
    return -1;
}
int String::operator()(const char* str) const {
    for (int i = 0; i < this->size; i++)
    {
        bool found = false;
        for (int j = 0; j < length(str); j++)
        {
            if (this->data[i+j] == str[j])
            {
                found = true;
            }
            else
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return i;
        }
    }
    return -1;
}

// Conversion Operator
String::operator int() const {
    int length = 0;
    for (int i = 0; data[i] != '\0'; i++)
    {
        length++;
    }
   
    return length;
}

ostream& operator<<(std::ostream& output, const String& str) {
    if (str.getdata()) {
        output << str.getdata();
    }
    else {
        output << "";
    }
    return output;
}

std::istream& operator>>(std::istream& input, String& str) {
    char buffer[1024]; // Temporary buffer to store input

    input.getline(buffer, 1024); // Read a line of text into buffer

    delete[] str.data; // Free existing memory

    str.size = length(buffer); // Update the size
    str.data = new char[str.size + 1]; // Allocate new memory

    for (int i = 0; i < str.size; ++i) {
        str.data[i] = buffer[i];
    }
    str.data[str.size] = '\0'; // Null-terminate the string

    return input;
}



