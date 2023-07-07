/* Algorithms Java Version - Using a singly linked list develop a stack and a queue.  */
package Assignment1;
import Assignment1.readFile;
import java.util.*;

public class linkedList{
    private Node head; //head of linked list
    private Node tail; //tail of linked list

    public class Node{
        private Node next; //reference to next node
        private int data; //int value for data

        public Node(int data){
            this.data = data;
            //constructor for linked list nodes
        }
    }

    class stack extends linkedList{
        void push(int data){ //add to beginning of stack
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
                Node current  = head; //create new node to remove head of stack
                head =  head.next; //set new head to next node
                // return value if need be
                //return current.data;
            }
        }

    }

    class Queue extends linkedList{
        Node newNode2 = new Node(data);
        //add to end of list
        void enqueue(){
            if(tail == null){ //check if que is empty from tail
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
                throw new NoSuchElementException("The que is empty");
            }
            else{//if queue is not empty assign new node to the head and head is reassigned to next node
                Node current = head;
                head = head.next;
                // return value if need be
                //return current.data;
            }

        }
    }

}