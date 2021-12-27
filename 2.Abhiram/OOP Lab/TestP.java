import java.math.*;
class Prime{
	private int num;
	
	public Prime(int num){
		setNum(num);
	}
	
	public void setNum(int num){
		this.num = num;
	}
	
	public int getNum(){
		return num;
	}
	
	public void isPrime(){
		int f = 0;
		for(int i=0;i<=math.sqrt(num);i++){
			if(num%i==0){
				f=1;
				break;
			}
		}
		if(f==1){
			System.out.println(this.num+" is a Prime");
		}else
			System.out.println(this.num+" is not a Prime");
	}
}

public class TestP{
	public static void main(String[] args){
		Prime p = new Prime(25);
		p.isPrime();
	}
}
