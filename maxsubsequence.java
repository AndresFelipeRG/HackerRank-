import java.io.*;
import java.util.*;

public class Solution {
    public static int findmax(int[]a){
       
       int i = 0;
       int sum = 0;
       int  max_so_far = 0;
       int max_ending_here = 0;
    
       for(i = 0; i< a.length; i++){
            
           
   
        max_ending_here = Math.max(0, max_ending_here + a[i]);
        max_so_far = Math.max(max_so_far, max_ending_here);
        
       }
       
        return max_so_far;
       
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        
        int [] array = new int[n];

        int i = 0;
        for(i = 0; i< n; i++){
            int number = in.nextInt();
            if(number == 0){number = -1000000000;}
            array[i] = number;
        }
        
       
        System.out.println(findmax(array));
    }
}
