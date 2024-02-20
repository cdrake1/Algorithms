/* Algorithms Java Version - Using a singly linked list develop a stack and a queue.  */
package Assignment1; 
import java.util.*;

public class linkedList{
    public Node head; //head of linked list
    public Node tail; //tail of linked list

    public class Node{
        public Node next; //reference to next node
        public char data; //int value for data

        public Node(char data){
            this.data = data;
            this.next = null;
            //constructor for linked list nodes
        }
    }

    public boolean isEmpty(){
        if(head == null){//check if stack or queue is empty
            return true;
        }
        else{
            return false;
        }
    }

    class stack extends linkedList{
        void push(char data){ //add to beginning of stack
            Node newNode = new Node(data); //create new node to push onto the stack
        
            if(head == null){ //check if linked list is empty and assign the head to the new node
                head = newNode;
            }
            else{ //if list is not empty then make the newnode the head and reassign the pointers
                newNode.next = head;
                head = newNode;
            }
        }
        void pop(){ //remove from beginning of stack
            if(head == null){ //check if linked list is empty and throw exception
                throw new NoSuchElementException("The stack is empty");

            }
            else{
                head =  head.next; //set new head to next node
            }
        }

    }

    class queue extends linkedList{
        //add to end of list
        void enqueue(char data){
            Node newNode2 = new Node(data);
            if(head == null){ //check if que is empty from tail
                tail = newNode2;
                head = newNode2; //newNode becomes head and tail
            }
            else{ //if que is not empty add node to end of que and reassign pointers
                tail.next = newNode2;
                tail = newNode2;
            }
        }
        //remove from front of list
        void dequeue(){
            if(head == null){//check if queue is empty and throw exception
                throw new NoSuchElementException("The queue is empty");
            }
            else{//if queue is not empty assign new node to the head and head is reassigned to next node
                head = head.next;
            }

        }
    }

}