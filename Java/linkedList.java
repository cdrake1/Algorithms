public class linkedList{
    private Node head; //head of linked list

    public class Node{
        private Node next; //reference to next node
        private int data; //int value for data

        public Node(int data){
            this.data = data;
            //constructor for linked list nodes
        }

        void push(int data){
            Node newNode = new Node(data);
           
        }

        void pop(){

        }
    }

}