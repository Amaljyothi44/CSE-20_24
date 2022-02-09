import java.lang.Math;
import java.util.*;

public class Prime{
	public static void main(String[] args){
		int flag=0,i;
		double t;
		Scanner inp = new Scanner(System.in);
		System.out.println("Enter number: "); 
		int num = inp.nextInt();
		t=Math.sqrt(num);
		for(i=2;i<=t;i++){
			if(num%i==0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			System.out.println(num+" is a Prime number."); 
		}else{
			System.out.println(num+" is not a Prime number.");
		}
	}
}
