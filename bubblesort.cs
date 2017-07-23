using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {
    
    static void Main(String[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        string[] a_temp = Console.ReadLine().Split(' ');
        int[] a = Array.ConvertAll(a_temp,Int32.Parse);
        int swaps2 = 0;
        for(int i = 0; i < n; i++){
            int swaps = 0;
            for(int j = 0; j < n-1; j++){
                if(a[j] > a[j+1]){
                    int temp = a[j+1];
                    a[j+1] = a[j];
                    a[j] = temp;
                    swaps = swaps +1;
                    swaps2 = swaps2 + 1;
                }
            }
            if(swaps == 0){
                break;
            }
        }
        Console.WriteLine("Array is sorted in {0} swaps.\nFirst Element: {1}\nLast Element: {2}", swaps2, a[0],a[n-1]);
    }
}
