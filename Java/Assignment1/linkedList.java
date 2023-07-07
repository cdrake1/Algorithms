/* Algorithms Java Version - Using a singly linked list develop a stack and a queue.  */
package Assignment1;
import java.util.*;

public class linkedList{
    private Node head; //head of linked list

    public class Node{
        private Node next; //reference to next node
        private int data; //int value for data

        public Node(int data){
            this.data = data;
            //constructor for linked list nodes
        }

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

}

//not sure if I need to or can throw an exception. If not maybe make a function that returns a string if linked list is empty
//need to implement queue