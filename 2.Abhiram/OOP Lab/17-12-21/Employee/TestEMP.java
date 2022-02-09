
public class TestEMP{
	public static void main(String[] args){
		Officer of1 = new Officer("Abhi",20,7510981,"House",20000,"Mass");

		System.out.println("----Officer----");
		System.out.println("Name = "+of1.getName());
		System.out.println("Age = "+of1.getAge());
		System.out.println("Phone Number = "+of1.getPhno());
		System.out.println("Address = "+of1.getAdrs());
		of1.printSalary();
		System.out.println("Specialization = "+of1.getSpec());
		Manager mg1 = new Manager("Ram",19,7306499,"Home",25000,"IT");
		System.out.println("----Manager----");
		System.out.println("Name = "+mg1.getName());
		System.out.println("Age = "+mg1.getAge());
		System.out.println("Phone Number = "+mg1.getPhno());
		System.out.println("Address = "+mg1.getAdrs());
		mg1.printSalary();
		System.out.println("Department = "+mg1.getDept());
		
	}
}




