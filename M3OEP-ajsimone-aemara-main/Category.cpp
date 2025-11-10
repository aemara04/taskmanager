//
// Created by Anna on 10/5/2025.
//

#include "Category.h"

Category::Category() : name("general") {}

Category::Category(string n) {
    name = n;
}

string Category::getName() const {
    return name;
}

void Category::setName(string n) {
    name = n;
}

