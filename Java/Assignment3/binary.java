/* Binary Search Algorithm - searches through each element of the list by dividing the list each time after a comparison*/
package Assignment3;

import java.util.ArrayList;

public class binary {

    ArrayList<Integer> comparisonTotal = new ArrayList<>();

    public double search(String[] sortedMagic, String[] keyItems){ //binary search for 42 random items. count number of comparisons

        int itemsFound = 0; //count how many of the items have been found
        
        for(int i = 0; i < keyItems.length; i++){ //iterate through random items and count the number of comparisons
            int comparisons = 0;
            int beginning = 0; //vars for counter of beginning and keep track of end of the array
            int end = sortedMagic.length - 1;

            while(beginning <= end){
                int mid = beginning + ((end - beginning) / 2);

                if(sortedMagic[mid].compareTo(keyItems[i]) == 0){ //checks if equal and adds to comparisons and items found
                    comparisons++;
                    comparisonTotal.add(comparisons);
                    itemsFound++;
                    break; //breaks loop if found
                }

                else if(sortedMagic[mid].compareTo(keyItems[i]) < 0){ //checks if key is greater than left half and changes the start
                    beginning = mid + 1;
                    comparisons++;
                }

                else{ //changes the end of array
                    end = mid - 1;
                    comparisons++;
                }

            }
        }

        int total = 0;
        for (int num : comparisonTotal) { //calculate total of all comparisons
            total += num;
        }
        double comparisonAvg = (double) total / comparisonTotal.size(); //average out all comparisons made
        double avgRounded = Math.round(comparisonAvg * 100.0) / 100.0;

        return avgRounded;
    }
}
