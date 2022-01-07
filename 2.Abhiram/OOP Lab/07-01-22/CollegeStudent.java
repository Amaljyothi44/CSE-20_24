public class CollegeStudent extends Student{
	private String clgName;
	private String YoS;
	
	public CollegeStudent(String name,String dob,int sId,String clgName,String YoS){
		super(name,dob,sId);
		setClgName(clgName);
		setYoS(YoS);
	}
	
	public void setClgName(String clgName){
		this.clgName = clgName;
	}
	public String getClgName(){
		return this.clgName;
	}
	public void setYoS(String YoS){
		this.YoS = YoS;
	}
	public String getYoS(){
		return this.YoS;
	}
}
