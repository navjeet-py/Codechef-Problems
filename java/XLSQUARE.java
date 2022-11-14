/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.lang.Math;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scanner = new Scanner(System.in);
        int T;
        T = scanner.nextInt();
        for(int test_case = 0; test_case < T; test_case++){
            int N;
            int A;
            N = scanner.nextInt();
            A = scanner.nextInt();
            int p = (int) (Math.sqrt(N));
            System.out.println(A * p);

        }
	}
}
