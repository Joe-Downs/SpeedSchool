import java.util.Scanner;

public class dateFormatter
{
    public static void main(String[] args)
    {
	String month, day, year;
	Scanner scan = new Scanner(System.in);
	/* useDelimiter("/") sets the delimiter to / to separate the dates */
	scan.useDelimiter("/|\\s");
	
	System.out.print("Enter a date in the MM/DD/YYYY format: ");
	/* Scans the users input up to the /, marking each field */
	month = scan.next();
	day = scan.next();
	year = scan.next();

	System.out.println("European date format (DD.MM.YYYY): " + day + "." + month + "." + year);
    }
}
