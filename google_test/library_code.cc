/*
File: node.cpp
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
#include "library_code.h"
#include <iostream>
/* Node constructors */
template <typename ValType> Node<ValType>::Node() {
  key_ = -1;
  left_ = right_ = NULL;
  height_ = 0;
}
template <typename ValType> Node<ValType>::Node(ValType key) {
  key_ = key;
  left_ = right_ = NULL;
  height_ = 0;
}

/* setters & getters */
template <typename ValType> void Node<ValType>::set_key(ValType key) {
  this->key_ = key;
}

template <typename ValType> ValType Node<ValType>::get_key() { return key_; }

template <typename ValType> void Node<ValType>::set_height(int height) {
  this->height_ = height;
}

template <typename ValType> int Node<ValType>::get_height() { return height_; }

/* AVL Tree basic constructor*/
template <typename ValType> AVLTree<ValType>::AVLTree() {
  root_ = NULL;
  num_of_nodes_ = 0;
}

/* root - left - left */
/* when cur_node's left child has bigger height than right child's height and
 * newly insterted node has smaller key than left child's one */
template <typename ValType>
Node<ValType> *
AVLTree<ValType>::single_right_rotation(Node<ValType> *cur_node) {
  Node<ValType> *left_child = cur_node->left_;
  cur_node->left_ = left_child->right_;
  left_child->right_ = cur_node;
  set_height(cur_node, 3);
  set_height(left_child, 1);
  return left_child;
}

/* root - right - right */
/* when cur_node's right child has bigger height than left child's height and
 * newly insterted node has bigger key than right child's one */
template <typename ValType>
Node<ValType> *AVLTree<ValType>::single_left_rotation(Node<ValType> *cur_node) {
  Node<ValType> *right_child = cur_node->right_;
  cur_node->right_ = right_child->left_;
  right_child->left_ = cur_node;
  set_height(cur_node, 3);
  set_height(right_child, 2);
  return right_child;
}

template <typename ValType>
bool AVLTree<ValType>::is_balanced(Node<ValType> *child_1,
                                   Node<ValType> *child_2) {
  return (get_height(child_1) - get_height(child_2) < 2);
}

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
        cur_node = single_left_rotation(cur_node);
      } else {
      }
    }
  }

  /* set height of current node */
  set_height(cur_node, 3);
  return cur_node;
}

/*
set_hegiht based on calling node's childs
children argument
  3: compare two children
  2: compare right child to calling node's height
  1: compare left child to calling node's height
*/
template <typename ValType>
void AVLTree<ValType>::set_height(Node<ValType> *cur_node, int chidren) {
  switch (chidren) {
  case 3:
    if (get_height(cur_node->left_) > get_height(cur_node->right_)) {
      cur_node->set_height(get_height(cur_node->left_) + 1);
    } else {
      cur_node->set_height(get_height(cur_node->right_) + 1);
    }
    break;
  case 2:
    if (get_height(cur_node->right_) > get_height(cur_node)) {
      cur_node->set_height(get_height(cur_node->right_) + 1);
    } else {
      cur_node->set_height(get_height(cur_node) + 1);
    }
  case 1:
    if (get_height(cur_node->left_) > get_height(cur_node)) {
      cur_node->set_height(get_height(cur_node->left_) + 1);
    } else {
      cur_node->set_height(get_height(cur_node) + 1);
    }
  }
}

/* returns -1 if cur_node is NULL, else height member */
template <typename ValType>
int AVLTree<ValType>::get_height(Node<ValType> *cur_node) {
  if (cur_node == NULL) {
    return -1;
  } else {
    return cur_node->get_height();
  }
}

template class AVLTree<int>;
template class Node<int>;
