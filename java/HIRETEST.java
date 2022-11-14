/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	      
	      Scanner reader = new Scanner(System.in);

        int T = reader.nextInt();
        for(int test_case = 0; test_case < T; test_case++){
            int N = reader.nextInt();
            int M = reader.nextInt();
            int X = reader.nextInt();
            int Y = reader.nextInt();
            String answer = "";
            reader.nextLine();
            for(int i = 0; i < N; i++){
                int full = 0;
                int partial = 0;
                String response = reader.nextLine();
                for (int j = 0; j < M; j++){
                    if (response.charAt(j) == 'F') {
                        full++;
                    }else if(response.charAt(j) == 'P'){
                        partial++;
                    }
                }
                if (full >= X || (full == X - 1 && partial >= Y)){
                    System.out.print(1);
                }else{
                    System.out.print(0);
                }
            }

            System.out.println();
        }

	}
}
