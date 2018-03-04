class Tree {

    private class Node {
        Node left, right;
        int data;
        public Node(int data) {
            this.data = data;
        }
    }

    private Node root;

    Tree() {
        root = null;
    }

    public void insert(int value) {
        root = insertRec(root, value);
    }

    private Node insertRec(Node root, int value) {

        if (root == null) {
            root = new Node(value);
            return root;
        }

        if (value < root.data) {
            root.left = insertRec(root.left, value);
        } else if (value > root.data) {
            root.right = insertRec(root.right, value);
        }

        return root;
    }

    public boolean contains(int value) {
        return contains(root, value);
    }
    public boolean contains(Node root, int value) {
        if (value == root.data) {
            return true;
        } else if (value < root.data) {
            if (root.left == null) {
                return false;
            } else {
                return contains(root.left, value);
            }
        } else {
            if (root.right == null) {
                return false;
            } else {
                return contains(root.right, value);
            }
        }
    }

    public void printInOrder() {
        printInOrder(root);
    }

    public void printInOrder(Node root) {
        if (root != null) {
            printInOrder(root.left);
            System.out.println(root.data);
            printInOrder(root.right);
        }
    }
}