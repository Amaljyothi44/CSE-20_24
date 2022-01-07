
public class Officer extends Employee{
	private String spec;
	
	public Officer(String name, int age, long phno, String adrs, float salary,String spec){
		super(name,age,phno,adrs,salary);
		setSpec(spec);
	}
	public String getSpec(){
		return this.spec;
	}
	public void setSpec(String spec){
		this.spec = spec;
	}

}

