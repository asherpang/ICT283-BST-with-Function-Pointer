# Binary Search Tree (BST) with Function Pointers

This project demonstrates the concepts of Binary Search Trees (BSTs) by constructing a simple BST and implementing various tree traversal methods using function pointers. The project also explores the differences between recursive and iterative approaches to tree operations.

## Objectives

- Utilize function pointers in BST operations.

## Project Structure

The project includes the following files:

- `main.cpp`: The main driver file that demonstrates the BST operations.
- `BST.h`: The header file defining the BST class template.
- `Date.h`: The header file defining the Date class.
- `Date.cpp`: The implementation file for the Date class.
- `date.txt`: A sample data file containing dates to be loaded into the BST.

## Prerequisites

- Code::Blocks IDE (or any C++ compiler that supports C++11 or later).

## How to Compile and Run

1. Open Code::Blocks IDE.
2. Create a new project and add `main.cpp`, `BST.h`, `Date.h`, `Date.cpp`, and `date.txt` to the project.
3. Make sure to configure the project settings to include all the necessary files.
4. Compile and run the project.

## Files Description

### `main.cpp`

This file contains the main function, which demonstrates the following operations on the BST:

- Loading dates from a file into the BST.
- Performing in-order, pre-order, and post-order traversals using function pointers.
- Searching for a specific date in the BST.
- Deleting the entire BST.

### `BST.h`

This header file defines the `Bst` class template, which implements the following BST operations using function pointers:

- Insertion of a value.
- Deletion of all nodes.
- Searching for a value.
- In-order traversal.
- Pre-order traversal.
- Post-order traversal.

### `Date.h` and `Date.cpp`

These files define and implement the `Date` class, which represents a date with day, month, and year components. The class provides methods for setting and getting these components, as well as overloaded operators for comparison and input/output operations.

### `date.txt`

This file contains a list of dates in the format `dd/mm/yyyy`, which are loaded into the BST during the execution of the program.

## Example Usage

Here is an example of how the BST is used in the `main.cpp` file:

```cpp
#include "BST.h"
#include "Date.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

// Function to print a Date object
void PrintDate(Date date) {
    std::cout << date << " ";
}

// Function to load dates from a single file into the BST
void LoadDates(const std::string& filename, Bst<Date>& dateTree) {
    std::ifstream infile(filename);
    std::string line;

    while (std::getline(infile, line)) {
        std::istringstream dateStream(line);
        Date date;
        dateStream >> date;
        dateTree.Insert(date);
    }
}

// Function to read the list of data files from datasource.txt
std::vector<std::string> ReadDataFiles(const std::string& dataSource) {
    std::ifstream infile(dataSource);
    std::string line;
    std::vector<std::string> files;

    while (std::getline(infile, line)) {
        files.push_back(line);
    }

    return files;
}

// Function to process the tree by value
void ProcessTreeByValue(Bst<Date> tree) {
    std::cout << "In-Order Traversal in ProcessTreeByValue: ";
    tree.InOrder(PrintDate);
    std::cout << std::endl;
    // Example: Add a new date and check traversal
    tree.Insert(Date(12, 12, 2023));
    std::cout << "In-Order Traversal after modification in ProcessTreeByValue: ";
    tree.InOrder(PrintDate);
    std::cout << std::endl;
}

// Function to process the tree by const reference
void ProcessTreeByConstReference(const Bst<Date>& tree) {
    std::cout << "In-Order Traversal in ProcessTreeByConstReference: ";
    tree.InOrder(PrintDate);
    std::cout << std::endl;
}

// Function to process the tree by reference
void ProcessTreeByReference(Bst<Date>& tree) {
    std::cout << "In-Order Traversal in ProcessTreeByReference (before modification): ";
    tree.InOrder(PrintDate);
    std::cout << std::endl;
    // Example: Add a new date and check traversal
    tree.Insert(Date(25, 12, 2024));
    std::cout << "In-Order Traversal after modification in ProcessTreeByReference: ";
    tree.InOrder(PrintDate);
    std::cout << std::endl;
}

int main() {
    Bst<Date> dateTree;

    // Load dates from date.txt file into the BST
    LoadDates("date.txt", dateTree);

    // Basic operations demonstration
    std::cout << "In-Order Traversal: ";
    dateTree.InOrder(PrintDate);
    std::cout << std::endl;

    std::cout << "Pre-Order Traversal: ";
    dateTree.PreOrder(PrintDate);
    std::cout << std::endl;

    std::cout << "Post-Order Traversal: ";
    dateTree.PostOrder(PrintDate);
    std::cout << std::endl;

    // Search for a specific date
    Date searchDate(1, 1, 2022);
    if (dateTree.Search(searchDate)) {
        std::cout << "Date " << searchDate << " found in the tree." << std::endl;
    } else {
        std::cout << "Date " << searchDate << " not found in the tree." << std::endl;
    }

    // Pass the tree by value
    ProcessTreeByValue(dateTree);
    // Ensure dateTree is still intact after passing by value
    std::cout << "In-Order Traversal after ProcessTreeByValue: ";
    dateTree.InOrder(PrintDate);
    std::cout << std::endl;

    // Pass the tree by const reference
    ProcessTreeByConstReference(dateTree);

    // Pass the tree by reference
    ProcessTreeByReference(dateTree);

    // Delete the tree
    dateTree.DeleteTree();

    return 0;
}
