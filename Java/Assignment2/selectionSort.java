package Assignment2;

public class selectionSort {
    public String[] sort(String[] textArray) {
        
        for (int i = 0; i < textArray.length; i++) { //read through each line of array to sort and set minimum to current index
            int min = i;
            for(int j = i + 1; j < textArray.length; j++){ //read through each line after index
                if(textArray[j].compareTo(textArray[min]) < 0){// compare strings to find lesser and set new min
                    min = j;
                }
                String temp = textArray[i];
                textArray[i] = textArray[min];
                textArray[min] = temp;
            }
        }
        return textArray;
    }
}
