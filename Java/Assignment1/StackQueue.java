/* This file calls linkedList and readFile */
package Assignment1;
import java.io.IOException;
import java.util.*;

public class StackQueue {
    public static void main(String[] args) {
        readFile rf = new readFile(); //make an instance of readFile to call

        try { //try to read text file into string array & call palindrome function
            String[] textArray = rf.readThrough();
            String theOutputS = checkPalindromeStack(textArray);
            String theOutputQ = checkPalindromeQueue(textArray);
            System.out.println(theOutputS);
            System.out.println(theOutputQ);
        } catch (IOException e) {//throw exception if error reading file
            System.err.println("There was a problem reading the file");
        }
    }

    static String checkPalindromeStack(String[] textArray){
        linkedList.stack myStack = new linkedList().new stack(); //create an instance of stack

        StringBuilder answerS = new StringBuilder(); //print out only if palindrome
        for(String i : textArray){ //for each line of text file trim, make lowercase, and convert to char array
            boolean isOrIsnt = true; //if palindrome
            i = i.toLowerCase().trim().replaceAll(" ", "");
            char[] temp = i.toCharArray();
            int half = temp.length / 2;
            for (int j = 0; j < half; j++) { // push half of the string on the stack
                myStack.push(temp[j]);
            }
            if (temp.length % 2 != 0) {//if odd skip middle letter
                half++;
            }
            for (int j = half; j < temp.length; j++) {//pop off stack
                char temps = myStack.pop();
                if(temps != temp[j]){
                    isOrIsnt = false;
                }
            }
            if(isOrIsnt == true){
                answerS.append(i + " "); //append if palindrome
            }
        } 
        return answerS.toString();
    }
    
    static String checkPalindromeQueue(String[] textArray){
        linkedList.queue myQueue = new linkedList().new queue(); //create an instance of queue

        StringBuilder answerQ = new StringBuilder(); //print out only if palindrome
        return answerQ.toString();
        
    }
    
}