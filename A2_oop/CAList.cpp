// CAList.cpp

#include "CAList.h"

// Instructor class function implementations
Instructor::Instructor() : name("") {}

Instructor::Instructor(const std::string& instructorName) : name(instructorName) {}

Instructor::Instructor(const Instructor& other) : name(other.name) {}

Instructor::~Instructor() {}

Instructor& Instructor::operator=(const Instructor& other) {
    if (this != &other) {
        this->name = other.name;
    }
    return *this;
}

std::string Instructor::getName() const {
    return this->name;
}

void Instructor::setName(const std::string& newName) {
    this->name = newName;
}

bool Instructor::operator==(const Instructor& other) const {
    return name == other.name;
}

// CourseEntry class function implementations
CourseEntry::CourseEntry() : courseName(""), instructorCount(0) {}

CourseEntry::CourseEntry(const std::string& courseName) : courseName(courseName), instructorCount(0) {}

std::string CourseEntry::getCourseName() const {
    return this->courseName;
}

void CourseEntry::setCourseName(const std::string& newCourseName) {
    this->courseName = newCourseName;
}

bool CourseEntry::addInstructor(const Instructor& instructor) {
    if (instructorCount >= MAX_INSTRUCTORS) {
        return false;
    }
    for (int i = 0; i < instructorCount; i++) {
        if (instructors[i] == instructor) {
            return false;
        }
    }
    instructors[instructorCount++] = instructor;
    return true;
}

bool CourseEntry::removeInstructor(const Instructor& instructor) {
    for (int i = 0; i < instructorCount; i++) {
        if (instructors[i] == instructor) {
            for (int j = i; j < instructorCount - 1; j++) {
                instructors[j] = instructors[j + 1];
            }
            instructorCount--;
            return true;
        }
    }
    return false;
}

Instructor CourseEntry::getInstructor(int index) const {
    if (index >= 0 && index < instructorCount) {
        return instructors[index];
    }
    return Instructor("");
}

void CourseEntry::clearInstructors() {
    instructorCount = 0;
}

CourseEntry& CourseEntry::operator=(const std::string& instructorName) {
    this->addInstructor(Instructor(instructorName));
    return *this;
}

CourseEntry& CourseEntry::operator+=(const std::string& instructorName) {
    this->addInstructor(Instructor(instructorName));
    return *this;
}

int CourseEntry::getInstructorCount() const {
    return instructorCount;
}

// CAList class function implementations
CAList::CAList() : courseCount(0) {}

int CAList::findCourseIndex(const std::string& courseName) const {
    for (int i = 0; i < courseCount; ++i) {
        if (courses[i].getCourseName() == courseName) {
            return i;
        }
    }
    return -1;
}

CourseEntry& CAList::operator[](const std::string& courseName) {
    int index = findCourseIndex(courseName);
    if (index == -1) {
        if (courseCount < MAX_COURSES) {
            courses[courseCount] = CourseEntry(courseName);
            return courses[courseCount++];
        }
        // If the max courses limit is reached, return the last course
        return courses[courseCount - 1];
    }
    return courses[index];
}

CAList& CAList::operator=(const std::string& instructorName) {
    if (courseCount == 0) {
        std::cerr << "No course available to add an instructor." << std::endl;
        return *this;
    }
    CourseEntry& lastCourse = courses[courseCount - 1];
    lastCourse.clearInstructors(); // Make sure this method exists in CourseEntry
    lastCourse.addInstructor(Instructor(instructorName));
    return *this;
}

CAList& CAList::operator+=(const std::string& instructorName) {
    if (courseCount > 0) {
        courses[courseCount - 1].addInstructor(Instructor(instructorName));
    }
    return *this;
}

CAList CAList::operator+(const CAList& other) const {
    CAList newList = *this;
    for (int i = 0; i < other.courseCount; ++i) {
        int index = newList.findCourseIndex(other.courses[i].getCourseName());
        if (index == -1) {
            newList.addCourse(other.courses[i]);
        }
        else {
            for (int j = 0; j < other.courses[i].getInstructorCount(); ++j) {
                newList.courses[index].addInstructor(other.courses[i].getInstructor(j));
            }
        }
    }
    return newList;
}

CAList CAList::operator-(const CAList& other) const {
    CAList newList = *this;
    for (int i = 0; i < other.courseCount; ++i) {
        for (int j = 0; j < other.courses[i].getInstructorCount(); ++j) {
            int index = newList.findCourseIndex(other.courses[i].getCourseName());
            if (index != -1) {
                newList.courses[index].removeInstructor(other.courses[i].getInstructor(j));
            }
        }
    }
    return newList;
}

bool CAList::addCourse(const CourseEntry& courseEntry) {
    if (courseCount < MAX_COURSES) {
        courses[courseCount++] = courseEntry;
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const CAList& list) {
    os << "[ ";
    for (int i = 0; i < list.courseCount; ++i) {
        os << list.courses[i].getCourseName() << " : { ";
        for (int j = 0; j < list.courses[i].getInstructorCount(); ++j) {
            os << list.courses[i].getInstructor(j).getName();
            if (j < list.courses[i].getInstructorCount() - 1) os << ", ";
        }
        os << " }";
        if (i < list.courseCount - 1) os << ", ";
    }
    os << " ]" << std::endl;
    return os;
}