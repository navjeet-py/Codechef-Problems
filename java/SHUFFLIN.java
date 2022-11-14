/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scanner = new Scanner(System.in);
        int T;
        T = scanner.nextInt();
        for(int testcase = 0; testcase < T; testcase++){
            int N = scanner.nextInt();
            int odd = (N + 1) / 2;
            int even = (N) / 2;
            int o = 0;
            int e = 0;
            for(int i = 0; i < N; i++){
                int p;
                p = scanner.nextInt();
                if (p % 2 == 0) e++;
                else o++;
            }
            int ans = Math.min(even, o) + Math.min(odd, e);
            System.out.println(ans);
        }

	}
}
