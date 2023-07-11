package Assignment2;

import java.io.IOException;

public class theSorts {
    public static void main(String[] args) {
        readFile rf = new readFile(); //make an instance of readFile to call
        try { //try to read text file into string array 
            String[] textFile = rf.readThrough();
            selectionSort(textFile);
            /*
            insertionSort(textFile);
            mergeSort(textFile);
            quickSort(textFile); 
            */
            
            
        } catch (IOException e) {//throw exception if error reading file
            System.err.println("There was a problem reading the file");
        }
        
    }

    static void selectionSort(String[] theText){

    }
    static void insertionSort(String[] theText){

    }
    static void mergeSort(String[] theText){

    }
    static void quickSort(String[] theText){

    }
}
