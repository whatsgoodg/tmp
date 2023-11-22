/*
File: insert.cpp
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
#include "avl_tree.h"

/*
    insert a node storing a given key to AVL tree
    1. this function traverse nodes recursively from root untill it meets
   NULL(leaf).
    2. then, check if tree is balanced at each node this function traversed.
*/

template <typename ValType>
Node<ValType> *AVLTree<ValType>::insert_node(Node<ValType> *cur_node,
                                             ValType key) {

  /* if meets leaf(NULL), make a new node */
  if (cur_node == NULL) {
    cur_node = new Node<ValType>(key);
  }

  /* if new key is smaller than current node's key, become a left child */
  else if (cur_node->key_ > key) {
    cur_node->left_ = insert_node(cur_node->left_, key);
    /* balancing */
    if (!is_balanced(cur_node->left_, cur_node->right_)) {
      if (cur_node->left_->key_ > key) {
        cur_node = single_right_rotation(cur_node);
      } else {
      }
    }
  }

  /* if new key is bigger than current node's key, become a right child */
  else {
    cur_node->right_ = insert_node(cur_node->right_, key);
    if (!is_balanced(cur_node->right_, cur_node->left_)) {
      if (cur_node->right_->key_ < key) {

      } else {
      }
    }
  }

  /* set height of current node */
  set_height(cur_node, 3);
  return cur_node;
}

template class AVLTree<int>;
template class Node<int>;
