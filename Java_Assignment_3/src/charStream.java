import java.io.*;
public class charStream {

	public static void main(String[] args) throws IOException{
		FileReader fr = null;
		FileWriter fw = null;
		
		try {
			fr = new FileReader("input.txt");
			fw = new FileWriter("charStreamOutput.txt");
			int ch;
			ch = fr.read();
			while(ch != -1)
			{
				fw.write((char)ch);
				ch = fr.read();
			}
			}
		
		catch (Exception e){
			System.err.println(e);
		}
		
		finally {
			if(fr != null)
				fr.close();
			if(fw != null)
				fw.close();
		}
	}

}
