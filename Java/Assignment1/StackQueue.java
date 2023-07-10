/* This file calls linkedList and readFile */
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

        StringBuilder answer = new StringBuilder(); //print out onlyif palindrome
        for(String i : textArray){ //for each line of text file trim, make lowercase, and convert to char array
            boolean isOrIsnt = true; //if palindrome
            i.toLowerCase().trim();
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
                answer.append(i); //append if palindrome
            }
        } 
        return answer.toString();
    }
    
}
