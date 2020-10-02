class Node { 
    int data; 
    Node left, right; 
  
    Node(int item) 
    { 
        data = item; 
        left = null; 
        right = null;
    } 
}
class BinaryTree { 
    Node root; 
  
    void MorrisTraversal(Node root) 
    { 
        Node current, pre; 
  
        if (root == null) 
            return; 
  
        current = root; 
        while (current != null) { 
            if (current.left == null) { 
                System.out.print(current.data + " "); 
                current = current.right; 
            } 
            else { 
                pre = current.left; 

                while (pre.right != null && pre.right != current) 
                    pre = pre.right; 
                // Create a temporary link between last node in left subarray and the current node
                if (pre.right == null) { 
                    pre.right = current; 
                    current = current.left; 
                } 
                // this means that left sub array has been traversed and now we remove the temporary link
                else { 
                    pre.right = null; 
                    System.out.print(current.data + " "); 
                    current = current.right; 
                }
            }
        }
    } 
  
    public static void main(String args[]) 
    { 
        BinaryTree tree = new BinaryTree(); 
        tree.root = new Node(1); 
        tree.root.left = new Node(3); 
        tree.root.right = new Node(5); 
        tree.root.left.left = new Node(2); 
        tree.root.left.right = new Node(6); 
  
        tree.MorrisTraversal(tree.root); 
    } 
} 