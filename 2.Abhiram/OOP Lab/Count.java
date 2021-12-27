import java.util.*;

class Frequency{
	Scanner inp;
	String word;
	char c;
	int count=1;
	
	public Frequency(){
		this.inp = new Scanner(System.in);
	}
	public void read(){
		System.out.println("Enter the String: ");
		this.word = inp.nextLine();
		System.out.println("Enter the letter: ");
		this.c = inp.next().charAt(0);
	}
	public void getFreq(){
		for(int i = 0;i<word.length();i++){
			if(word.charAt(i)==c)
				this.count++;
		}
		System.out.println(this.c+" occurs "+this.count+" times.");
	}
}
public class Count{
	public static void main(String[] args){
		Frequency f1 = new Frequency();
		f1.read();
		f1.getFreq();
	}
}
