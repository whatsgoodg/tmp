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
#include "node.h"
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
