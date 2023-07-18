/* Implementation of insertion sort - a sorting algorithm that iterates one by one through an array moving the unsorted numbers with the sorted  */
package Assignment2;

public class insertionSort {
    public String[] sort(String[] textArray){
        for(int i = 1; i < textArray.length; i++){ //iterate through array starting at 2nd element
            String temp = textArray[i]; //set temp to index
            int j = i - 1; //check with previous element
            while(j > 0 && temp.compareTo(textArray[j]) < 0){
                textArray[j + 1] = textArray[j]; //switch elements and move through array
                j = j - 1;
            }
            textArray[j + 1] = temp;

        }
        return textArray;
    }
    
}
