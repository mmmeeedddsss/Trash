/*
PROG:transform
LANG:JAVA
NAME:mmmeeed1
*/
import java.io.*;
import java.util.Scanner;

public class Usaco6
{
	static Scanner scanner;
	static FileWriter fw;
	static char[][] FArray;
	static char[][] tempArray;
	static int n;
	
	public static void Init() throws IOException
	{
		scanner = new Scanner(new File("transform.in"));
		n = scanner.nextInt();
		fw = new FileWriter(new File("transform.out"));
		FArray = new char[n][n];
		tempArray = new char[n][n];
	    
	    for( int i=0; i<n; i++ )
	    {
	    	String line = scanner.next();
			for( int j=0; j<n; j++ )
				tempArray[i][j] = line.charAt(j); //Before
	    }
	    for( int i=0; i<n; i++ )
	    {
	    	String line = scanner.next();
			for( int j=0; j<n; j++ )
				FArray[i][j] = (char)line.charAt(j); //After
	    }
	}
	
	public static int run()
	{
		if( equals(tempArray, FArray) )
			return 6;
		rotate90();
		if( equals(tempArray, FArray) )
			return 1;
		rotate90(); // 2 x 90
		if( equals(tempArray, FArray) )
			return 2;
		rotate90(); // 3 x 90
		if( equals(tempArray, FArray) )
			return 3;
		rotate90();
		Reflect();
		if( equals(tempArray, FArray) )
			return 4;
		rotate90();
		if( equals(tempArray, FArray) )
			return 5;
		rotate90(); // 2 x 90
		if( equals(tempArray, FArray) )
			return 5;
		rotate90(); // 3 x 90
		if( equals(tempArray, FArray) )
			return 5;
		return 7;
	}
	
	public static void rotate90()
	{
		char[][] tArray = new char[n][n];
		copy(tempArray, tArray);
		for( int i=0; i<n; i++ )
			for( int j=0; j<n; j++ )
				tempArray[j][(n-1)-i] = tArray[i][j];
	}
	
	public static void Reflect()
	{
		char[][] tArray = new char[n][n];
		copy(tempArray, tArray);
		for( int i=0; i<n; i++ )
			for( int j=0; j<n; j++ )
				tempArray[i][n-1-j] = tArray[i][j];
	}
	public static void copy(char[][] a,char[][] b) 
	{
	    for(int i=0 ; i<n ; i++)
	    	for(int j=0 ; j<n ; j++)
	    		b[i][j] = a[i][j];
	}
	
	public static boolean equals(char[][] a, char[][] b) 
	{
	    int i, j;
	    for(i=0 ; i<n ; i++)
	      for(j=0 ; j<n ; j++)
	        if(a[i][j] != b[i][j])
	          return false;
	    return true;
	 }
	
	public static void main (String [] args) throws IOException {
	    Init();
	    fw.write(""+run()+"\n");
	    fw.flush();
	    fw.close();
	    System.exit(0);
	  }
	
}