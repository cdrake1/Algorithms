/* Implementation of quick sort - a sorting algorithm that sorts elements around the arrays pivot */
package Assignment2;

public class quickSort {
    public String[] sort(String[] textArray, int first, int last){
        if(first < last){
            int position = partition(textArray, first, last);
            sort(textArray, first, position - 1); //iterate and sort left side
            sort(textArray, position + 1, last); //iterate and sort right side

        }
        return textArray;
    }

    public int partition(String[] array, int first, int last){ //divides the array into parts

        String pivot = array[first]; // create pivot using the first element of the array

        

    }
    
}
 