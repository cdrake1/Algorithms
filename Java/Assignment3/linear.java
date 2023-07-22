/* Linear Search Algorithm - searches through each element of the list linearly from start to finish */
package Assignment3;

import java.util.Random;

public class linear {
    public int search(String[] sortedMagic, String[] keyItems){

        return 0;
    }

    static String[] random(String[] sortedMagic){
        Random rand = new Random();

        String[] fortyTwoItems = new String[42]; //create new string array of length 42

        for(int i = 0; i < 42; i++){ //randomly select 42 items to search for linearly
            int randomItem = rand.nextInt(sortedMagic.length); // generate random numbers and add to new array
            fortyTwoItems[i] = sortedMagic[randomItem];
        }
        return fortyTwoItems;
    }


    
}
