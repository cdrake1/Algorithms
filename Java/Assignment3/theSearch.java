package Assignment3;
import java.io.IOException;

public class theSearch {
    public static void main(String[] args){
        readFile rf = new readFile(); //make an instance of readFile to call
        try{
            String[] textFile = rf.readThrough(); //try to read text file into string array 

            mergeSort sorted = new mergeSort(); //call merge sort and pass the text file
            String[] sortedFile = sorted.sort(textFile);

            linear linearSearch = new linear(); //create instance of linear class, generate list of 42 random items and call linear search
            String[] randomItems = linearSearch.random(sortedFile);
            double numLinear = linearSearch.search(sortedFile, randomItems);

            comparisons(numLinear);


        }catch (IOException e) {//throw exception if error reading file
            System.err.println("There was a problem reading the file");
        }
    }

    static void check(String[] sortedFile){ //prints out texst file if needed
        for(String i: sortedFile){
            System.out.println(i);
        }

    }

    static void comparisons(double linearComparisons){ //prints out number of comparisons for each search
        System.out.println("Linear Comparisons: " + linearComparisons);
    }
    
}
