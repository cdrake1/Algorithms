package Assignment2;

public class insertionSort {
    public String[] sort(String[] textArray){
        for(int i = 0; i < textArray.length - 1; i++){
            String marker = textArray[i];
            int j = i + 1;
            if(marker.compareTo(textArray[j]) < 0){
                String temp = textArray[j];
                textArray[j] = marker;
                textArray[i] = temp;
            }

        }
        return textArray;
    }
    
}
