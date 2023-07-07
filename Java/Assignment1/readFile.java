/* Created to read lines from file into an array */
package Assignment1;
import java.io.*;
import java.util.*;

public class readFile {
    public static void main(String[] args)  throws IOException{
        Scanner getFilePath = new Scanner(System.in);
        System.out.print("Enter the file path: "); //get file path
        String filePath = getFilePath.nextLine();
        BufferedReader reader = new BufferedReader(new FileReader(filePath)); //create a buffer/file reader for the filepath
        List<String> fileLines = new ArrayList<String>(); 
        String line = null;
        //try to read lines from a file until null
        try{
            while((line = reader.readLine()) != null){ 
                fileLines.add(line); //add lines to arraylist
            }
        }
        //error catching for problems reading file
        catch(IOException e){
            System.err.println("There was a problem reading the file");
        }
        fileLines.toArray(); //convert list into array
        reader.close(); //close readers
    }
    
}

//need to return to other files