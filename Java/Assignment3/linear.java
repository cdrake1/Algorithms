/* Linear Search Algorithm - searches through each element of the list linearly from start to finish */
package Assignment3;

import java.util.ArrayList;
import java.util.Random;

public class linear {
    
    ArrayList<Integer> comparisonTotal = new ArrayList<>();
    private double comparisonAvg = 0;

    public double search(String[] sortedMagic, String[] keyItems){ //linear search for 42 random items. count number of comparisons
        int itemsFound = 0; //to check if random item is found
        for(int i = 0; i < keyItems.length; i++){
            int comparisons = 0; //count comparisons for each item
            for(int j = 0; j < sortedMagic.length; j++){
                comparisons++;
                if(sortedMagic[j].equals(keyItems[i])){ //if item is found break loop and add comparison amount to list
                    itemsFound++;
                    comparisonTotal.add(comparisons);
                    break;
                }
            }
        }

        int total = 0;
        for (int num : comparisonTotal) { //calculate total of all comparisons
            total += num;
        }
        comparisonAvg = (double) total / comparisonTotal.size(); //average out all comparisons made
        double avgRounded = Math.round(comparisonAvg * 100.0) / 100.0;

        return avgRounded;
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
