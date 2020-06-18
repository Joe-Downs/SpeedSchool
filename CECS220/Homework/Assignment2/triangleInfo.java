import java.util.Scanner;

public class triangleInfo
{
    public static void main(String[] args)
    {
	/* Creates new Triangle object */
	Triangle Triangle1 = new Triangle();

	Scanner scan = new Scanner(System.in);
	/* Sets delimiter to a comma or spaces for the coordinates */
	scan.useDelimiter(",|\\s");
	
	System.out.print("Enter the triangle's first vertex: ");
	Triangle1.setX1(scan.nextInt());
	Triangle1.setY1(scan.nextInt());
	System.out.print("Enter the triangle's second vertex: ");
	Triangle1.setX2(scan.nextInt());
	Triangle1.setY2(scan.nextInt());
	System.out.print("Enter the triangle's third vertex: ");
	Triangle1.setX3(scan.nextInt());
	Triangle1.setY3(scan.nextInt());
	
	System.out.println(Triangle1);
	
    }
    

    
}
