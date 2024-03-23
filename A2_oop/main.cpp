// main.cpp

#include "CAList.h"

int main() {
    CAList tt, tt2, tt3;

    // Assigning instructors to courses using the overloaded [] and = operators
    tt["OOP"] = "Dr.Ali";
    tt["OOP"] = "Mr.Shehryar";
    tt["OOP"] = "Ms.Hida";
    tt["OOP"] = "Mr.Shams";
    tt["DLD"] = "Mr.Amir";
    tt["DLD"] = "Mr.Shams";
    tt["DLD"] = "Dr.Mehwish";

    // Displaying the CAList tt
    std::cout << tt;

    // Adding new instructors and creating new courses using the overloaded += operator
    tt2["Algo"] = "Mr.Owais";
    tt2["OOP"] += "Mr.Shehryar";
    tt2["Pak Stds"] = "Mr.Ajmal";
    tt2["Pak Stds"] += "Ms.Gul";
    tt2["Pak Stds"] += "Ms.Memoona";
    tt2["Islamiat"] = "Dr.Tayab";
    tt2["Islamiat"] += "Ms.Sobia";
    tt2["Islamiat"] += "Mr.Usman";
    tt2["Islamiat"] += "Ms.Gul";
    tt2["Islamiat"] += "Mr.Anas";

    // Displaying the CAList tt2
    std::cout << tt2;

    // Combining CAList tt and tt2 into CAList tt3 using the overloaded + operator
    tt3 = tt + tt2;

    // Displaying the combined CAList tt3
    std::cout << tt3;

    // Creating a new CAList tt4 by subtracting tt2 from tt using the overloaded - operator
    CAList tt4 = tt - tt2;

    // Displaying the CAList tt4 after the set difference operation
    std::cout << tt4;

    return 0;
}
