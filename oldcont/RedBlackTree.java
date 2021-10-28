
public class RedBlackTree<K, V> implements IRedBlack<K, V> {
    Node<K, V> root;
    int size;

    class Node<K, V> {
        K key;
        V val;

        Node<K, V> left, right, parent;
        boolean isLeftChild, black;
        public Node(K key, V val) {
            this.key = key;
            this.val = val;
            left = right = parent = null;
            black = false;
            isLeftChild = false;
        }
    }

    @Override
    public void add(K key, V val) {
        // TODO Auto-generated method stub
        Node<K, V> node = new Node<K, V>(key, val);
        if (root == null) {
            root = node;
            root.black = true;
            size++;
            return;
        }
        add(root, node);
        size++;
        return;
    }
    private void add(Node<K, V> parent, Node<K, V> newNode) {
        if (((Comparable<K>) newNode.key).compareTo(parent.key) > 0) {
            if (parent.right == null) {
                parent.right = newNode;
                newNode.parent = parent;
                newNode.isLeftChild = false;
            }
            add(parent.right, newNode);
        }
        else
        {
            if (parent.left == null) {
                parent.left = newNode;
                newNode.parent = parent;
                newNode.isLeftChild = true;
                return ;
            }
            add(parent.left, newNode);
        }
        // checkColor(newNode);
    } 
}