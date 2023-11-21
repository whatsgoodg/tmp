# Naive_AVL_Tree
This is a Repository of Naive AVL Tree implementation for school project. 
## Structure
* Each node stores a 32-bit integer      
* The depth of root node is 0    
## Functions
### Minimum(x)
* returns a minimum value of node from a subtree whose root node is x    
* Time complexity: O(log(n))     
### Maximum(x)
* returns a maximum value of node from a subtree whose root node is x     
* Time complexity: O(log(n))     
### Empty()
* returns whether the AVL Tree is empty.    
* Time complexity: O(1)    
### Size()
* returns the number of nodes in the AVL Tree    
* * Time complexity: O(1)    
### find(x)
* returns the depth of node x if found, else returns 0    
* Time complexity: O(log(n))    
### insert(x)
* insert node x and print the depth of node x    
* Time complexity: O(log(n))     
### rank(x)
* print the depth and rank of node x if found, else print 0     
* rank is defined as the number of nodes that have smaller values than x plus one     
* Time complexity: O(log(n))
### erase(x)     
* print the depth of node x and erase it if found, else print 0     
* Time complexity: O(log(n))     

