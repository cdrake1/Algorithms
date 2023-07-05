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
            Node newNode = new Node(data); //create new node to push onto the stack
           
            if(head == null){ //check if linked list is empty and assign the head to the new node
                head = newNode;
            }
            else{ //if list is not empty then make the newnode the head and reassign the pointers
                newNode.next = head;
                head = newNode;
            }
        }

        void pop(){

        }
    }

}