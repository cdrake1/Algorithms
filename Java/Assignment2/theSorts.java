/* Assignment 2 main file - runs all sorts */
package Assignment2;
import java.io.*;

public class theSorts {
    public static void main(String[] args) {
        readFile rf = new readFile(); //make an instance of readFile to call
        try { //try to read text file into string array 
            String[] textFile = rf.readThrough();
            knuthShuffle(textFile); //randomly shuffle list of items
            selectionSort sorterS = new selectionSort(); //call all 4 sorts and pass the text file
            insertionSort sorterI = new insertionSort(); 
            mergeSort sorterM = new mergeSort();
            quickSort sorterQ = new quickSort();
            String[] sortedSelection = sorterS.sort(textFile);
            String[] sortedInsertion = sorterI.sort(textFile);
            String[] sortedMerge = sorterM.sort(textFile);
            String[] sortedQuick = sorterQ.sort(textFile, 0, textFile.length - 1);
            check(sortedMerge); //prints out the sorted list
            
            
        } catch (IOException e) {//throw exception if error reading file
            System.err.println("There was a problem reading the file");
        }
        
    }

    static String[] knuthShuffle(String[] theText){
        for(int i = 0; i < theText.length; i++){ //iterate through String array
            int j = (int) (Math.random() * (i + 1)); //generate random number to shuffle from
            String temp = theText[j]; //declare termp string and shuffle textarray to random generated numbers
            theText[j] = theText[i];
            theText[i] = temp;
        }
        return theText;
    }

    static void check(String[] theText){// iterate through returned array to check if sorted correctly
        for(String i: theText){
            System.out.println(i);
        }
    }
   
}
