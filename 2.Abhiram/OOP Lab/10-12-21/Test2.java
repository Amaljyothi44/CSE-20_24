import java.util.*;

class Count{
	String s;
	char item;
	int i = 0, count = 0;
	Scanner inp;
	public Count(){
		this.inp = new Scanner(System.in);
	}
	
	public void readString(){
		System.out.println("Enter the String: ");
		this.s = inp.nextLine();
	}
	public void readItem(){
		System.out.println("Enter item(Character): ");
		this.item = inp.next().charAt(0);
	}
	public void getFrequency(){
		for(this.i=0;i<s.length();i++){
			if(s.charAt(i)==this.item)
				this.count++;
		}
		System.out.println(item+" occurs "+count+" times.");
		
	}
}

 public class Test2{
 	public static void main(String[] args){
 		Count c1 = new Count();
 		c1.readString();
 		c1.readItem();
 		c1.getFrequency();
 	}
 }
