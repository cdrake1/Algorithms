/* Implementation of quick sort - a sorting algorithm that sorts elements around the arrays pivot */
package Assignment2;

public class quickSort {
    int comparisons = 0;
    public String[] sort(String[] textArray, int first, int last) {
        if (first < last) {
            int position = partition(textArray, first, last);
            sort(textArray, first, position - 1); //Iterate and sort the left side
            sort(textArray, position + 1, last); //Iterate and sort the right side
        }
        return textArray;
    }

    public int partition(String[] array, int first, int last) {
        String pivot = array[first]; //Create pivot using the first element of the array

        int left = first + 1; //Set pointer variables for left and right
        int right = last;

        while (left <= right) { //Iterate through the array
            while (left <= right && array[left].compareTo(pivot) <= 0) { //Find an element greater than the pivot
                comparisons++;
                left++;
            }
            while (left <= right && array[right].compareTo(pivot) > 0) { //Find an element smaller than or equal to the pivot
                comparisons++;
                right--;
            }
            if (left < right) { //Swap elements and iterate
                String temp = array[left];
                array[left] = array[right];
                array[right] = temp;
            }
        }

        //Move the pivot to its correct position
        String temp = array[first];
        array[first] = array[right];
        array[right] = temp;

        return right;
    }

    public int comparisonsGet(){
        return comparisons;
    }
}

 