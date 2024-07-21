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
