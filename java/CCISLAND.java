/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		for(int testcase = 0; testcase < T; testcase++){
		      int x = input.nextInt();
		      int y = input.nextInt();
		      int xr = input.nextInt();
		      int yr = input.nextInt();
		      int D = input.nextInt();
		      if (xr * D <= x && yr * D <= y){
		            System.out.println("YES");
		      }else{
		            System.out.println("NO");
		      }
		}
	}
}
