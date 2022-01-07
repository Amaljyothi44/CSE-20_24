import java.util.*;

class Matrix{
	int a[][] = new int[20][20];
	int b[][] = new int[20][20];
	int product[][] = new int[20][20];
	int i,j,k,m,n,p,q,sum=0;
	Scanner inp;
	
	public Matrix(){
		this.inp = new Scanner(System.in);
	}
	public void readOrder(){
		System.out.println("Enter order of First matrix:");
		this.m = inp.nextInt();
		this.n = inp.nextInt();
		System.out.println("Enter order of Second matrix:");
		this.p = inp.nextInt();
		this.q = inp.nextInt();
	}
	public void readMatrix(){
		System.out.println("Enter First matrix: ");
		for(i=0;i<this.m;i++){
			for(j=0;j<this.n;j++){
				this.a[i][j]=inp.nextInt();
			}
		}
		System.out.println("Enter Second matrix: ");
		for(i=0;i<this.p;i++){
			for(j=0;j<this.q;j++){
				this.b[i][j]=inp.nextInt();
			}
		}
	}
	public void multiply(){
		for(i=0;i<this.m;i++){
			for(j=0;j<this.q;j++){
				this.sum=0;
				for(k=0;k<this.n;k++){
					this.sum=this.sum+this.a[i][k]*this.b[k][i];
				}
				this.product[i][j]=this.sum;
			}
		}
		System.out.println("Result : ");
		for(i=0;i<this.m;i++){
			for(j=0;j<this.q;j++){
				System.out.print(product[i][j]+" ");
			}
			System.out.print("\n");
		}
	}
	
}
public class Test3{
	public static void main(String[] args){
		Matrix m1 = new Matrix();
		m1.readOrder();
		m1.readMatrix();
		m1.multiply();
	}
}
