public class Person{
	private String name;
	private String dob;
	
	public Person(String name,String dob){
		super();
		setName(name);
		setDob(dob);
	}
	
	public void setName(String name){
		this.name = name;
	}
	public void setDob(String dob){
		this.dob = dob;
	}
	public String getName(){
		return this.name;
	} 
	public String getDob(){
		return this.dob;
	}
}

