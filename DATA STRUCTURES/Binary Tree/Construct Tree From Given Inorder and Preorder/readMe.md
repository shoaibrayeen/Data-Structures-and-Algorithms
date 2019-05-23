## Let us consider the below traversals:
```
Inorder sequence: D B E A F C
Preorder sequence: A B D E C F

In a Preorder sequence, leftmost element is the root of the tree. So we know ‘A’ 
is root for given sequences. By searching ‘A’ in Inorder sequence, we can find 
out all elements on left side of ‘A’ are in left subtree and elements on right 
are in right subtree. So we know below structure now.



 

                 A
               /   \
             /       \
           D B E     F C
We recursively follow above steps and get the following tree.

         A
       /   \
     /       \
    B         C
   / \        /
 /     \    /
D       E  F
```
