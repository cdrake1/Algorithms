package Assignment3;
import java.io.IOException;

public class theSearch {
    public static void main(String[] args){
        readFile rf = new readFile(); //make an instance of readFile to call
        try{
            String[] textFile = rf.readThrough(); //try to read text file into string array 
            mergeSort sorted = new mergeSort(); //call merge sort and pass the text file
            String[] sortedFile = sorted.sort(textFile);

        }catch (IOException e) {//throw exception if error reading file
            System.err.println("There was a problem reading the file");
        }
    }

    static void check(String[] sortedFile){
        for(String i: sortedFile){
            System.out.println(i);
        }

    }
    
}
