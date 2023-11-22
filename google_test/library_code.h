/*
File: node.h
Copyright (c) 2023 김기정

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#ifndef LIBRARY_CODE_H
#define LIBRARY_CODE_H
template <typename ValType> class AVLTree;

// define Node
template <typename ValType> class Node {
  friend class AVLTree<ValType>;
  friend class Set;

public:
  // members
  ValType key_;
  Node *left_;
  Node *right_;
  int height_;

  // Node constructors
  Node();
  Node(ValType);
  // get key member
  ValType get_key();
  // set key member
  void set_key(ValType);
  // get height member
  int get_height();
  // set height member
  void set_height(int);
};

// Define AVLTree
template <typename ValType> class AVLTree {
public:
  // AVLTree constructor
  AVLTree();
  // insert a node
  Node<ValType> *insert_node(Node<ValType> *, ValType);
  // Single righr rotation
  Node<ValType> *single_right_rotation(Node<ValType> *);
  // single left rotation
  Node<ValType> *single_left_rotation(Node<ValType> *);
  // double right rotation
  Node<ValType> *double_right_rotation(Node<ValType> *);
  // double left rotation
  Node<ValType> *double_left_rotation(Node<ValType> *);
  // Find node matcheds a key
  Node<ValType> *find_node(Node<ValType> *, ValType);
  // set height of a given node
  void set_height(Node<ValType> *, int);
  // get height of a given node
  int get_height(Node<ValType> *);
  // check if AVL tree is balanced
  bool is_balanced(Node<ValType> *, Node<ValType> *);

public:
  // members
  Node<ValType> *root_;
  size_t num_of_nodes_;
};
#endif
