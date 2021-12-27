import java.util.*;

class Matrix{
	Scanner inp;
	int mat[][] = new int[10][10];
	int m,n;
	
//Constructor
	public Matrix(){
		this.inp = new Scanner(System.in);
	}
	
//Method to read matrix
	public void readMat(){
		System.out.println("Enter order of matrix");
		this.m = inp.nextInt();
		this.n = inp.nextInt();
		System.out.println("Enter matrix");
		for(int i =0;i<this.m;i++){
			for(int j=0;j<this.n;j++){
				mat[i][j] = inp.nextInt();
			}
		}
	}
}

class MatMul{

//Declaring two matrices of Matrix class
	Matrix a = new Matrix();
	Matrix b = new Matrix();
	int res[][] = new int[10][10];
	int sum ;
	
//Constructor of MatMul class
	public MatMul(){
	//Method to read the two matrices 
		a.readMat();
		b.readMat();
	}
	
//Method to multiply the two matrices and print the result
	public void printRes(){
	//Loop for multiplication starts
		for(int i=0;i<a.m;i++){	//Loop to control the row of the resultant matrix
			for(int j=0;j<b.n;j++){	//Loop to control the column of the resultant Matrix
				sum = 0;	//Ini nokki manasilaakk
				for(int k =0;k<a.n;k++){		//Katheelel WA me @ wa.me/917510862981
					sum = sum + a.mat[i][k]*b.mat[k][i];
				}
				res[i][j] = sum;
			}
		}
	//Multiplication ends here
	
	//Now to print the resultant Matrix
		System.out.println("Resultant Matrix: ");
		for(int i =0;i<a.m;i++){
			for(int j=0;j<b.n;j++){
				System.out.print(res[i][j]+" ");
				
			}
			System.out.print("\n");
		}
	}
		
}

public class Multiplication{
	public static void main(String[] args){
	//Calling an object of MatMul class
		MatMul m1 = new MatMul();	
		m1.printRes();		//Printing method
	}
}
