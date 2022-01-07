
public class Manager extends Employee{
	private String dept;
	
	public Manager(String name, int age, long phno, String adrs, float salary,String dept){
		super(name,age,phno,adrs,salary);
		setDept(dept);
	}
	public String getDept(){
		return this.dept;
	}
	public void setDept(String dept){
		this.dept = dept;
	}

}

