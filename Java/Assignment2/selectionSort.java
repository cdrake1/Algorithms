package Assignment2;

public class selectionSort {
    public void sort(String[] textArray) {
        
        for (int i = 0; i < textArray.length; i++) { //read through each line of array to sort and set minimum to current index
            String min = textArray[i];
            for(int j = i + 1; j < textArray.length; j++){ //read through each line after index
                if(textArray[j].compareTo(min) < 0){// compare strings to find lesser and set new min
                    min = textArray[j];
                }

            }
        }
    }
}
