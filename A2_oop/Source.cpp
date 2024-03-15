#include <iostream>
#include <cstring>
using namespace std;

struct Container {
    char* name;
    int containerno;
    Container* link;
};

class Shop {
public:
    Container* start;

    // Default constructor
    Shop() : start(NULL) {}

    // Copy Constructor
    Shop(const Shop& other) : start(NULL) {
        Container* temp = other.start;
        while (temp != NULL) {
            add_Container(temp->name, temp->containerno);
            temp = temp->link;
        }
    }

    void add_Container(char* name, int containerindex) {
        Container* newContainer = new Container;
        size_t nameLen = strlen(name) + 1;
        newContainer->name = new char[nameLen];
        strcpy_s(newContainer->name, nameLen, name);
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

    void print_Shop() {
        Container* temp = start;
        while (temp != NULL) {
            cout << temp->name << "-" << temp->containerno << "\n";
            temp = temp->link;
        }
    }


    

    void delete_Chain(int containerindex) {
        Container* temp = start, * prev = NULL;
        while (temp != NULL && temp->containerno != containerindex) {
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

    void Sort_Chain() {
        bool swapped;
        Container* ptr1, * lptr = NULL;

        do {
            swapped = false;
            ptr1 = start;

            while (ptr1->link != lptr) {
                if (ptr1->containerno > ptr1->link->containerno) {
                    swap(ptr1->containerno, ptr1->link->containerno);
                    swap(ptr1->name, ptr1->link->name);
                    swapped = true;
                }
                ptr1 = ptr1->link;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void update_name_at_containerNumber(int containerindex, char* name) {
        Container* temp = start;
        while (temp != NULL) {
            if (temp->containerno == containerindex) {
                delete[] temp->name;
                size_t nameLen = strlen(name) + 1;
                temp->name = new char[nameLen];
                strcpy_s(temp->name, nameLen, name);
                return;
            }
            temp = temp->link;
        }
    }

    void remove_Duplicate() {
        Container* ptr1, * ptr2, * dup;
        ptr1 = start;

        while (ptr1 != NULL && ptr1->link != NULL) {
            ptr2 = ptr1;
            while (ptr2->link != NULL) {
                if (strcmp(ptr1->name, ptr2->link->name) == 0) {
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

    void findContainer(int containerindex) {
        Container* temp = start;
        while (temp != NULL) {
            if (temp->containerno == containerindex) {
                cout << temp->name << "\n";
                return;
            }
            temp = temp->link;
        }
        // If not found, it should print nothing.
    }

    void findContainer(int containerindex1, int containerindex2) {
        Container* temp = start;
        while (temp != NULL) {
            if (temp->containerno >= containerindex1 && temp->containerno <= containerindex2) {
                cout << temp->name << "\n";
            }
            temp = temp->link;
        }
    }


    ~Shop() {
        Container* current = start;
        while (current != NULL) {
            Container* next = current->link;
            delete[] current->name;
            delete current;
            current = next;
        }
        start = NULL;
    }
};

// The main function is not required as per your request.
