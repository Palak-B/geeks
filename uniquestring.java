import java.util.Scanner;

public class uniquestring{


	public static boolean check(String a){
		for(int i=0;i<a.length();i++){
			for(int j=i+1;j<a.length();j++){
				if((a.charAt(i)^a.charAt(j))==0){
					return true;
				}
			}
		}
		return false;
	}

	public static void main(String[] args){
		String a;

		Scanner sc = new Scanner(System.in);
		a = sc.nextLine();

		if(a.length()==1){
			System.out.println("Yes");
		}
		else{
			if(check(a)){
			System.out.println("No");	
			}
			else{
				System.out.println("Yes");
			}
		}

	}
}
