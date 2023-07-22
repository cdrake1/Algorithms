package Assignment3;

import java.io.IOException;

public class theSearch {
    public static void main(String[] args){
        readFile rf = new readFile(); //make an instance of readFile to call
        try{
            String[] textFile = rf.readThrough(); //try to read text file into string array 

        }catch (IOException e) {//throw exception if error reading file
            System.err.println("There was a problem reading the file");
        }
    }
    
}
