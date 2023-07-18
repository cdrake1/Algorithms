package Assignment2;
import java.util.*;

public class mergeSort {
    public String[] sort(String[] textArray){
        int middle = textArray.length / 2; //find middle of the array

        String[] left = Arrays.copyOfRange(textArray, 0, middle); //grab the first half
        String[] right = Arrays.copyOfRange(textArray, middle, textArray.length); //grab the second half

        left = sort(left); //recursively call sort with left and right halves separately 
        right = sort(right);
        return merge(left, right); //call merge and return solution
    }
    String[] merge(String[] oneHalf, String[] theOther){

    }
    
}
