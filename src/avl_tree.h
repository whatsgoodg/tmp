/*
File: avl_tree.h
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

#include "node.h"
#include <iostream>
#ifndef AVLTREE_H
#define AVLTREE_H

// Define AVLTree
template <typename ValType> class AVLTree {
protected:
  // AVLTree constructor
  AVLTree();
  // insert a node
  Node<ValType> *insert_node(Node<ValType> *, ValType);
  // Single righr rotation
  Node<ValType> *single_right_rotation(Node<ValType> *);
  // check if AVL tree is balanced
  bool is_balanced(Node<ValType> *, Node<ValType> *);
  // set height of a given node
  void set_height(Node<ValType> *, int);
  // get height of a given node
  int get_height(Node<ValType> *);

protected:
  // members
  Node<ValType> *root_;
  size_t num_of_nodes_;
};
#endif
