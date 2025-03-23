
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "BTNode.h"

template<typename Item_Type>
class Binary_Tree {
public:
    /** Construct an empty Binary_Tree. */
    Binary_Tree() : root(NULL) {}

    /** Construct a Binary_Tree with two subtrees. */
    Binary_Tree(const Item_Type& the_data, 
                const Binary_Tree<Item_Type>& left_child = Binary_Tree(),
                const Binary_Tree<Item_Type>& right_child = Binary_Tree()) :
        root(new BTNode<Item_Type>(the_data, left_child.root, right_child.root)) {}

    /** Virtual destructor */
    virtual ~Binary_Tree() { destroy_tree(root); }

    /** Return the left subtree. */
    Binary_Tree<Item_Type> get_left_subtree() const {
        return Binary_Tree<Item_Type>(root ? root->left : NULL);
    }

    /** Return the right subtree. */
    Binary_Tree<Item_Type> get_right_subtree() const {
        return Binary_Tree<Item_Type>(root ? root->right : NULL);
    }

    /** Return the data field of the root. */
    const Item_Type& get_data() const {
        if (root) return root->data;
        throw std::invalid_argument("Tree is empty.");
    }

    /** Indicate that this is the empty tree. */
    bool is_null() const { return root == NULL; }

    /** Indicate that this tree is a leaf. */
    bool is_leaf() const { return root && !root->left && !root->right; }

    /** Return a string representation of this tree. */
    virtual std::string to_string() const {
        std::ostringstream os;
        if (is_null()) os << "NULL\n";
        else {
            os << *root << '\n';
            os << get_left_subtree().to_string();
            os << get_right_subtree().to_string();
        }
        return os.str();
    }

    /** Read a binary tree from input */
    static Binary_Tree<Item_Type> read_binary_tree(std::istream& in) {
        std::string next_line;
        getline(in, next_line);
        if (next_line == "NULL") {
            return Binary_Tree<Item_Type>();
        } else {
            Item_Type the_data;
            std::istringstream ins(next_line);
            ins >> the_data;
            Binary_Tree<Item_Type> left = read_binary_tree(in);
            Binary_Tree<Item_Type> right = read_binary_tree(in);
            return Binary_Tree<Item_Type>(the_data, left, right);
        }
    }

    /** Return the root node (needed for Morse tree) */
    BTNode<Item_Type>* get_root() const { return root; }

    /** Find Morse code for a given letter */
    std::string find_morse_code(char target) const {
        std::string result;
        if (find_morse_code_helper(root, target, "", result)) {
            return result;
        }
        return "";  // Return empty string if not found
    }

protected:
    /** Protected constructor */
    Binary_Tree(BTNode<Item_Type>* new_root) : root(new_root) {}

    /** Destroy tree recursively */
    void destroy_tree(BTNode<Item_Type>* node) {
        if (node) {
            destroy_tree(node->left);
            destroy_tree(node->right);
            delete node;
        }
    }

private:
    BTNode<Item_Type>* root;

    /** Helper function to find Morse code */
    bool find_morse_code_helper(BTNode<Item_Type>* node, char target, std::string path, std::string& result) const {
        if (!node) return false;  // Base case: Empty node

        if (node->data == target) {  // Found the letter
            result = path;
            return true;
        }

        // Recursively search left (dot) and right (dash)
        if (find_morse_code_helper(node->left, target, path + ".", result) ||
            find_morse_code_helper(node->right, target, path + "-", result)) {
            return true;
        }

        return false;
    }
};

// Overloading the ostream insertion operator.
template<typename Item_Type>
std::ostream& operator<<(std::ostream& out, const Binary_Tree<Item_Type>& tree) {
    return out << tree.to_string();
}

// Overloading the istream extraction operator
template<typename Item_Type>
std::istream& operator>>(std::istream& in, Binary_Tree<Item_Type>& tree) {
    tree = Binary_Tree<Item_Type>::read_binary_tree(in);
    return in;
}

#endif
