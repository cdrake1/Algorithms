package Assignment2;

import java.util.Arrays;

public class mergeSort {
    public String[] sort(String[] textArray){
        int middle = textArray.length / 2;

        String[] left = Arrays.copyOfRange(textArray, 0, middle);
        String[] right = Arrays.copyOfRange(textArray, middle, textArray.length) ;;

        left = sort(left);
        right = sort(right);
        return merge(left, right);
    }
    String[] merge(String[] oneHalf, String[] theOther){

    }
    
}
