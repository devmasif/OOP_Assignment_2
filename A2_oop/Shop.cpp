#include "D:\Assignment2_OOP\A2_oop\A2_oop\Shop.h" 
#include <cstring>

// Default constructor

int Length(const char* ptr) {
    if (ptr == nullptr) {
        return 0;
    }

    int len = 0;
    while (ptr[len] != '\0') {
        len++;
    }
    return len;
}

void Swap(char*& a, char*& b) {
    char* temp = a;
    a = b;
    b = temp;
}


void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

Shop::Shop() : start(NULL) {}


// Copy Constructor
Shop::Shop(const Shop& other) : start(NULL) {
    Container* temp = other.start;
    while (temp != NULL) {
        add_Container(temp->name, temp->containerno);
        temp = temp->link;
    }
}

void Shop::add_Container(char* name, int containerindex) {
    Container* newContainer = new Container;
    int nameLen = Length(name) + 1;
    newContainer->name = new char[nameLen];

    for (int i = 0; i < nameLen; i++)
    {
        newContainer->name[i] = name[i];
    }
    newContainer->containerno = containerindex;

    newContainer->link = NULL;

    if (start == NULL) {
        start = newContainer;
    }
    else {
        Container* temp = start;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newContainer;
    }
}

void Shop::print_Shop() {
    Container* temp = start;
    while (temp != NULL) {
        cout << temp->name << "-" << temp->containerno << "\n";
        temp = temp->link;
    }
}

void Shop::delete_Chain(int containerindex) {
    Container* temp = start, * prev = NULL;
    while ( temp->containerno != containerindex) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) return; // Not found

    if (prev == NULL) {
        start = temp->link;
    }
    else {
        prev->link = temp->link;
    }

    delete[] temp->name;
    delete temp;
}

void Shop::Sort_Chain() {
    bool swapped;
    Container* ptr1, * lptr = NULL;

    do {
        swapped = false;
        ptr1 = start;

        while (ptr1->link != NULL) {
            if (ptr1->containerno > ptr1->link->containerno) {
                Swap(ptr1->containerno, ptr1->link->containerno);
                Swap(ptr1->name, ptr1->link->name);
                swapped = true;
            }
            ptr1 = ptr1->link;
        }
        //lptr = ptr1;
    } while (swapped);
}

void Shop::update_name_at_containerNumber(int containerindex, char* name) {
    Container* temp = start;
    while (temp != NULL) {
        if (temp->containerno == containerindex) {
            delete[] temp->name;
            int nameLen = Length(name) + 1;
            temp->name = new char[nameLen];
            for (int i = 0; i < nameLen; i++)
            {
                temp->name[i] = name[i];
            }
            return;
        }
        temp = temp->link;
    }
}

void Shop::remove_Duplicate() {
    Container* ptr1, * ptr2, * dup, * prev;
    ptr1 = start;

    while (ptr1 != NULL && ptr1->link != NULL) {
        ptr2 = ptr1;
        while (ptr2->link != NULL) {
            // Compare names character by character
            char* name1 = ptr1->name;
            char* name2 = ptr2->link->name;
            bool isDuplicate = true;

            // Compare each character of the two names
            while (*name1 != '\0' && *name2 != '\0') {
                if (*name1 != *name2) {
                    isDuplicate = false;
                    break;
                }
                name1++;
                name2++;
            }

            // Check if both strings ended (ensuring equal length)
            if (*name1 != '\0' || *name2 != '\0') {
                isDuplicate = false;
            }

            // If names are the same, remove the duplicate
            if (isDuplicate) {
                dup = ptr2->link;
                ptr2->link = ptr2->link->link;
                delete[] dup->name;
                delete dup;
            }
            else {
                ptr2 = ptr2->link;
            }
        }
        ptr1 = ptr1->link;
    }
}


void Shop::findContainer(int containerindex) {
    Container* temp = start;
    while (temp != NULL) {
        if (temp->containerno == containerindex) {
            cout << temp->name << "\n";
            return;
        }
        temp = temp->link;
    }
}

void Shop::findContainer(int containerindex1, int containerindex2) {
    Container* temp = start;
    while (temp != NULL) {
        if (temp->containerno >= containerindex1 && temp->containerno <= containerindex2) {
            cout << temp->name << "\n";
        }
        temp = temp->link;
    }
}

Shop::~Shop() {
    Container* current = start;
    while (current != NULL) {
        Container* next = current->link;
        delete[] current->name;
        delete current;
        current = next;
    }
    start = NULL;
}
