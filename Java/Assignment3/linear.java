/* Linear Search Algorithm - searches through each element of the list linearly from start to finish */
package Assignment3;

import java.util.Random;

public class linear {

    private int comparisons = 0; //count comparisons

    public int search(String[] sortedMagic, String[] keyItems){ //linear search for 42 random items. count number of comparisons
        int itemsFound = 0; //to check if random item is found
        for(int i = 0; i < keyItems.length; i++){
            for(int j = 0; j < sortedMagic.length; j++){
                comparisons++;
                if(sortedMagic[j].equals(keyItems[i])){ //if item is found break loop
                    itemsFound++;
                    break;
                }
            }
        }
        return comparisons;
    }

    static String[] random(String[] sortedMagic){ //randomly select 42 items to search for linearly
        Random rand = new Random();

        String[] fortyTwoItems = new String[42]; //create new string array of length 42

        for(int i = 0; i < 42; i++){
            int randomItem = rand.nextInt(sortedMagic.length); // generate random numbers and add to new array
            fortyTwoItems[i] = sortedMagic[randomItem];
        }
        return fortyTwoItems;
    }


    
}
