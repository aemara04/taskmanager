//
// Created by Anna on 10/5/2025.
//

#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
using namespace std;

class Category {
private:
    string name;

public:
    // Default constructor
    Category();
    Category(string n);

    // Getter
    string getName() const;
    // Setter
    void setName(string n);
};

#endif // CATEGORY_H


