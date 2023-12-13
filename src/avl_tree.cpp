/*
File: avl_tree.cpp
Copyright (c) 2023 김기정, 변해광

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

/* AVL Tree basic constructor*/
template<typename ValType>
AVLTree<ValType>::AVLTree() {
  root_ = NULL;
  num_of_nodes_ = 0;
}

/* root - left - left */
/* when cur_node's left child has bigger height than right child's height and
   inserted node has smaller key than left child's one */
template<typename ValType>
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
template<typename ValType>
Node<ValType> *AVLTree<ValType>::single_left_rotation(Node<ValType> *cur_node) {
  Node<ValType> *right_child = cur_node->right_;
  cur_node->right_ = right_child->left_;
  right_child->left_ = cur_node;
  set_height(cur_node, 3);
  set_height(right_child, 2);
  return right_child;
}

/* root - left - right */
/* when cur_node's left child has bigger height than right child's height and
 * newly inserted node has bigger key than left child's one */
template<typename ValType>
Node<ValType> *
AVLTree<ValType>::double_right_rotation(Node<ValType> *cur_node) {
  cur_node->left_ = single_left_rotation(cur_node->left_);
  cur_node = single_right_rotation(cur_node);
  return cur_node;
}

/* root- right - left */
/* when cur_node's left child has bigger height than right child's height and
 * newly inserted node has bigger key than left child's one */
template<typename ValType>
Node<ValType> *AVLTree<ValType>::double_left_rotation(Node<ValType> *cur_node) {
  cur_node->right_ = single_right_rotation(cur_node->right_);
  cur_node = single_left_rotation(cur_node);
  return cur_node;
}

/* difference between heights have to be less than 2 to be balanced. */
template<typename ValType>
bool AVLTree<ValType>::is_balanced(Node<ValType> *child_1,
								   Node<ValType> *child_2) {
  return (get_height(child_1) - get_height(child_2) < 2);
}

/* find a node whose key matches a given key */
template<typename ValType>
Node<ValType> *AVLTree<ValType>::find_node(Node<ValType> *cur_node,
										   ValType key) {
  if (cur_node == NULL) {
	return NULL;
  } else if (cur_node->key_ == key) {
	return cur_node;
  } else if (cur_node->key_ > key) {
	return find_node(cur_node->left_, key);
  } else if (cur_node->key_ < key) {
	return find_node(cur_node->right_, key);
  }
}

/*
set_hegiht based on calling node's childs
children argument
  3: compare two children
  2: compare right child to calling node's height
  1: compare left child to calling node's height
*/
template<typename ValType>
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
template<typename ValType>
int AVLTree<ValType>::get_height(Node<ValType> *cur_node) {
  if (cur_node == NULL) {
	return -1;
  } else {
	return cur_node->get_height();
  }
}

/* find a node which has a smallest key in subtree whose root is a give node. */
template<typename ValType>
Node<ValType> *AVLTree<ValType>::FindMinNodeOfSubtree(Node<ValType> *cur_node) {
  if (cur_node == NULL) {
	return NULL;
  } else if (cur_node->left_ == NULL) {
	return cur_node;
  } else {
	return FindMinNodeOfSubtree(cur_node->left_);
  }
}

template<typename ValType>
Node<ValType> *AVLTree<ValType>::EraseNode(Node<ValType> *cur_node,
										   ValType key) {

  Node<ValType> *temp;
  if (cur_node == NULL) {
	return NULL;
  } else if (key < cur_node->key_) {
	cur_node->left_ = EraseNode(cur_node->left_, key);
  } else if (key > cur_node->key_) {
	cur_node->right_ = EraseNode(cur_node->right_, key);
  } else if (cur_node->left_ != NULL && cur_node->right_ != NULL) {
	temp = FindMinNodeOfSubtree(cur_node->right_);
	cur_node->key_ = temp->key_;
	cur_node->right_ = EraseNode(cur_node->right_, cur_node->key_);
  } else {
	temp = cur_node;
	if (cur_node->left_ == NULL) {
	  cur_node = cur_node->right_;
	} else if (cur_node->right_ == NULL) {
	  cur_node = cur_node->left_;
	}
	delete temp;
  }

  if (cur_node == NULL) {
	return NULL;
  }

  set_height(cur_node, 3);

  if (!is_balanced(cur_node->right_, cur_node->left_)) {
	if (get_height(cur_node->right_->right_) - get_height(cur_node->right_->left_) == 1) {
	  return single_left_rotation(cur_node);
	} else {
	  return double_left_rotation(cur_node);
	}
  } else if (!is_balanced(cur_node->left_, cur_node->right_)) {
	if (get_height(cur_node->left_->left_) - get_height(cur_node->left_->right_) ==
		1) {
	  return single_right_rotation(cur_node);
	} else {
	  return double_right_rotation(cur_node);
	}
  }
  return cur_node;
}

template<typename ValType>
class AVLTree;
template<typename ValType>
class Node;
