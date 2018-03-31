package M1_104502518;

public class MyPetDog extends dog {
	
	private String name;
	
	MyPetDog(String n, int w, String g){
		super(w,g);
		name = n;
	}
	
	void Hungry(){
		super.Hungry();
		System.out.println(" I am hungry, feed me!!");
	}
	
	void Poo(){
		System.out.println("I want to poo~");
	}
	
	void MessUp(){
		System.out.println("Good dog doesn't mess up.");
	}
	
	void ShakeHand(String s){
		System.out.println("My name is "+name);
		System.out.println(s+", shake~ shake~");
	}
}
