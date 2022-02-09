public class Student extends Person{
	private int sId;
	
	public Student(String name,String dob,int sId){
		super(name,dob);
		setSId(sId);
	}
	
	public void setSId(int sId){
		this.sId = sId;
	}
	public int getSId(){
		return this.sId;
	}
}
