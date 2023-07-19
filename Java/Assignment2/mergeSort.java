/* Implementation of merge sort - a sorting algorithm that divides an array recursively and then merges together the sorted product */
package Assignment2;
import java.util.*;

public class mergeSort {
    public String[] sort(String[] textArray){
        if(textArray.length <= 1){
            return textArray;
        }
        int middle = textArray.length / 2; //find middle of the array

        String[] left = Arrays.copyOfRange(textArray, 0, middle); //grab the first half
        String[] right = Arrays.copyOfRange(textArray, middle, textArray.length); //grab the second half

        left = sort(left); //recursively call sort with left and right halves separately 
        right = sort(right);
        return merge(left, right); //call merge and return solution
    }
    private String[] merge(String[] oneHalf, String[] theOther){

        String[] mergesorted = new String[oneHalf.length + theOther.length]; //create new array the size of the other 2 along with 3 marker vars
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < oneHalf.length && j < theOther.length){ //traverse throgh subarrays
            if(oneHalf[i].compareTo(theOther[j]) <= 0){ //check if string is less than or equal to other. Add string to array and iterate
                mergesorted[k] = oneHalf[i];
                i++;
            }
            else{
                mergesorted[k] = theOther[j];
                j++;
            }
            k++;
        }
        while(i < oneHalf.length){ //if the one is done, but the other is not then continue
            mergesorted[k] = oneHalf[i];
            i++;
            k++;
        }
        while(j < theOther.length){
            mergesorted[k] = theOther[j];
            j++;
            k++;
        }
        return mergesorted;


    }
    
}
