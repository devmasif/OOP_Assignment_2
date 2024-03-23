#ifndef CALIST_H
#define CALIST_H

#include <iostream>
#include <string>

class Instructor {
private:
    std::string name;

public:
    Instructor();
    Instructor(const std::string& instructorName);
    Instructor(const Instructor& other);
    ~Instructor();

    Instructor& operator=(const Instructor& other);
    std::string getName() const;
    void setName(const std::string& newName);
    bool operator==(const Instructor& other) const;
};

class CourseEntry {
private:
    static const int MAX_INSTRUCTORS = 6;
    std::string courseName;
    Instructor instructors[MAX_INSTRUCTORS];
    int instructorCount;

public:
    CourseEntry();
    CourseEntry(const std::string& courseName);

    std::string getCourseName() const;
    void setCourseName(const std::string& newCourseName);
    bool addInstructor(const Instructor& instructor);
    bool removeInstructor(const Instructor& instructor);
    Instructor getInstructor(int index) const;
    void clearInstructors();
    int getInstructorCount() const;

    CourseEntry& operator=(const std::string& instructorName);
    CourseEntry& operator+=(const std::string& instructorName);
};

class CAList {
private:
    static const int MAX_COURSES = 7;
    CourseEntry courses[MAX_COURSES];
    int courseCount;

public:
    CAList();

    int findCourseIndex(const std::string& courseName) const;
    CourseEntry& operator[](const std::string& courseName);
    CAList& operator=(const std::string& instructorName);
    CAList& operator+=(const std::string& instructorName);
    CAList operator+(const CAList& other) const;
    CAList operator-(const CAList& other) const;
    bool addCourse(const CourseEntry& courseEntry);

    friend std::ostream& operator<<(std::ostream& os, const CAList& list);
};

#endif // CALIST_H