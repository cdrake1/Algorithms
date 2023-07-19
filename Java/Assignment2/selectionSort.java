/* Implementation of selection sort - a sorting algorithm that itereates through an array switching the min index with another unsorted element */
package Assignment2;

public class selectionSort {
    public int sort(String[] textArray) {
        int comparisons = 0;
        for (int i = 0; i < textArray.length; i++) { //read through each line of array to sort and set minimum to current index
            int min = i;
            for(int j = i + 1; j < textArray.length; j++){ //read through each line after index
                if(textArray[j].compareTo(textArray[min]) < 0){//compare strings to find lesser and set new min
                    comparisons++;
                    min = j;
                }
            }
            String temp = textArray[i]; //use temp variable to swap
            textArray[i] = textArray[min];
            textArray[min] = temp;
        }
        return comparisons;
    }
}
