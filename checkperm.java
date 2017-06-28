import java.util.Scanner;

public class  checkperm{

	public static boolean checkpermu(String a,String b){
		int[] count1 = new int[128];
		int[] count2 = new int[128];

		for(int i=0;i<a.length();i++){
			int ch = a.charAt(i);
			count1[ch]++;
		}
		for(int i=0;i<b.length();i++){
			int ch = b.charAt(i);
			count2[ch]++;
		}
		for(int i=0;i<128;i++){
			if(count1[i]!=count2[i]){
				return false;
			}
		}
		return true;		
	}

	public static void main(String[] args){
		String a,b;
		Scanner sc = new Scanner(System.in);
		a = sc.nextLine();
		b = sc.nextLine();

		if(a.length()!=b.length()){
			System.out.println("Nope");
		}
		else{
			if(checkpermu(a,b)){
				System.out.println("Yes");
			}
			else{
				System.out.println("Nope");
			}
		}

	}
}