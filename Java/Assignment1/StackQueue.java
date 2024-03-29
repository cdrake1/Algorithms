/* This file is the main file and calls linkedList and readFile */
package Assignment1;
import java.io.IOException;
import java.util.*;

public class StackQueue {
    public static void main(String[] args) {
        readFile rf = new readFile(); //make an instance of readFile to call

        try { //try to read text file into string array & call palindrome function
            String[] textArray = rf.readThrough();
            String theOutput = checkPalindrome(textArray);
            System.out.println(theOutput);
        } catch (IOException e) {//throw exception if error reading file
            System.err.println("There was a problem reading the file");
        }
    }

    static String checkPalindrome(String[] textArray){
        linkedList.stack myStack = new linkedList().new stack(); //create an instance of stack
        linkedList.queue myQueue = new linkedList().new queue(); //create an instance of queue

        StringBuilder answerS = new StringBuilder(); //print out only if palindrome
        for(String i : textArray){ //for each line of text file trim, make lowercase, and convert to char array
            boolean isOrIsnt = true; //if palindrome
            i = i.toLowerCase().trim().replaceAll(" ", "");
            char[] temp = i.toCharArray();
            
            for(int j = 0; j < temp.length; j++){//push and enqueue each letter
                myStack.push(temp[j]);
                myQueue.enqueue(temp[j]);
            }

            while(!myStack.isEmpty() && !myQueue.isEmpty()){//until stack and queue are empty compare each letter and push/dequeue
                if(myStack.head.data != myQueue.head.data){
                    isOrIsnt = false; //if letters dont match. not palindrome
                }
                myStack.pop();
                myQueue.dequeue();
            }
            if(isOrIsnt == true){
                answerS.append(i + " ");//if palindrome add to stringbuilder
            }
        } 
        return answerS.toString(); //return only palindromes
    }
}
