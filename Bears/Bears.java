import java.util.*;
import java.io.*;

public class Bears{

	public static void main(String[] args){
		try{
			Scanner scan = new Scanner(new File("bears.dat"));
			
			int runs = Integer.parseInt(scan.nextLine());
			
			
			for (int i = 0; i < runs; i++){
				
				int bears = 0;
				
				for(int j = 0; j < 10; j++){
					String line = scan.nextLine();
					
					for(int k = 0; k < line.length(); k++){
						if(line.charAt(k) == 'B'){
							bears++;
						}
					}
				}
				
				System.out.println(bears);
				bears = 0;
				
			}
			
		}catch(Exception e){
			
		}
	}

}
