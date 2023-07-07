/* This file calls linkedList and readFile */
package Assignment1;
import java.io.IOException;

public class StackQueue {
    public static void main(String[] args) {
        readFile rf = new readFile();
        try {
            String[] answer = rf.readThrough();
            System.out.print("Done");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
}
