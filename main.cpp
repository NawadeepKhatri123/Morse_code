
#include <iostream>
#include <fstream>
#include <string>
#include "Binary_Tree.h"



void insert_into_tree(Binary_Tree<char>& tree, char letter, const std::string& morse_code) {
    BTNode<char>* current = tree.get_root();  // Start at the root
    for (char c : morse_code) {
        if (c == '.') {
            if (!current->left) current->left = new BTNode<char>('*');  // Create empty node if missing
            current = current->left;
        } else if (c == '-') {
            if (!current->right) current->right = new BTNode<char>('*');
            current = current->right;
        }
    }
    current->data = letter;  // Store letter in correct position
}


Binary_Tree<char> build_morse_tree(const std::string& filename) {
    Binary_Tree<char> tree('*');  // Root is empty ('*' for placeholder)
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file.\n";
        exit(1);
    }
    
    char letter;
    std::string morse_code;
    while (file >> letter >> morse_code) {
        insert_into_tree(tree, letter, morse_code);
    }
    file.close();
    return tree;
}



std::string encode_message(const Binary_Tree<char>& tree, const std::string& message) {
    std::string morse_message = "";
    for (char ch : message) {
        if (ch == ' ') {
            morse_message += "   ";  // Space between words
            continue;
        }
        std::string morse_code = tree.find_morse_code(ch);  // You need a function to find Morse for a letter
        if (!morse_code.empty()) morse_message += morse_code + " ";
    }
    return morse_message;
}



std::string decode_message(const Binary_Tree<char>& tree, const std::string& morse_code) {
    std::string decoded_message = "";
    BTNode<char>* current = tree.get_root();
    
    for (char ch : morse_code) {
        if (ch == '.') current = current->left;
        else if (ch == '-') current = current->right;
        else if (ch == ' ') {  // Space means end of a letter
            decoded_message += current->data;
            current = tree.get_root();
        }
    }
    decoded_message += current->data;  // Last letter
    return decoded_message;
}




int main() {
    Binary_Tree<char> morse_tree = build_morse_tree("morse.txt");

    while (true) {
        std::cout << "1. Encode a message\n";
        std::cout << "2. Decode a Morse code message\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();  // Ignore leftover newline

        if (choice == 1) {
            std::string message;
            std::cout << "Enter message to encode: ";
            std::getline(std::cin, message);
            std::cout << "Encoded message: " << encode_message(morse_tree, message) << "\n";
        } 
        else if (choice == 2) {
            std::string morse;
            std::cout << "Enter Morse code to decode: ";
            std::getline(std::cin, morse);
            std::cout << "Decoded message: " << decode_message(morse_tree, morse) << "\n";
        } 
        else if (choice == 3) {
            break;
        } 
        else {
            std::cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
