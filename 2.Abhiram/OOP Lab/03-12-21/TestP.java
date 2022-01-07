import java.util.*;
import java.lang.Math;

class Prime{
	int num;
	double t;
	boolean flag = false;
	Scanner inp;
	
	
	public Prime(){
		inp = new Scanner(System.in);
	}
	public void read(){
		System.out.println("Enter the number:");
		this.num = inp.nextInt();
	}
	public void isPrime(){ 
		this.t = Math.sqrt(num);
		for(int i=2;i<=(int)t;i++){
			if(this.num%i==0){
				flag=true;
				break;
			}
		}
		if(this.num<=1){
			System.out.println(this.num+" is not a prime");
		}else if(flag){
			System.out.println(this.num+" is not a prime number.");
		}else{
			System.out.println(this.num+" is a prime number.");
		}
	}
	
}

public class TestP{
	public static void main(String[] args){
		Prime p1 = new Prime();
		p1.read();
		p1.isPrime();
	}
}
