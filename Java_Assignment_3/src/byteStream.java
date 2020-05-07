import java.io.*;
public class byteStream {

	public static void main(String[] args) throws IOException{
		FileInputStream fi = null;
		FileOutputStream fo = null;
		
		try {
			fi = new FileInputStream("input.txt");
			fo = new FileOutputStream("byteStreamOutput.txt");
			int ch;
			ch = fi.read();
			while(ch != -1)
			{
				fo.write((char)ch);
				ch = fi.read();
			}
			}
		
		catch (Exception e){
			System.err.println(e);
		}
		
		finally {
			if(fi != null)
				fi.close();
			if(fo != null)
				fo.close();
		}
	}

}
