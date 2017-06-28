import java.util.Scanner;

public class palinperm{

	public static boolean check(String a){
		int[] count = new int[128];
		int charcount=0;
		boolean occur=false;
		for(int i=0;i<a.length();i++){
			if(a.charAt(i)!=' '){
				charcount++;
				int ch = a.charAt(i);
				count[ch]++;				
			}
		}

		if(charcount%2==0){
			for(int i=0;i<128;i++){
				if(count[i]%2!=0){
					return false;
				}
			}
			return true;
		}
		else{
			for(int i=0;i<128;i++){
				if(!occur){
					if(count[i]%2==1){
						occur=true;
					}
				}
				else{
					if(count[i]%2==1){
						return false;
					}
				}

			}
		}

		return true;

	}
	public static void main(String[] args){
		String a;
		Scanner sc = new Scanner(System.in);
		a = sc.nextLine();
		if(a.length()==1){
			System.out.println("Nope");
		}
		else{
			if(check(a)){
				System.out.println("Yeah");
			}
			else{
				System.out.println("Nope");
			}

		}
	}
}