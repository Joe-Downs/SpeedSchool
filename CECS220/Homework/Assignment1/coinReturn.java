import java.util.Scanner;
public class coinReturn
{
    public static void main(String[] args)
    {
	int price;
	int totalChange;
	int change;
	int quarters, dimes, nickels = 0;
	Scanner scan = new Scanner(System.in);

	/* Takes input from the user */
	System.out.print("Enter price of item (25-100 cents, 5-cent increments): ");
	price = scan.nextInt();
	totalChange = 100 - price;
	change = totalChange;

	/*
	 * Divides the change by 25 and trucates the decimal, giving the whole number
	 * of quarters that can be returned. Then the modulo is performed on change so
	 * as to reduce its value. This process is repeated for dimes and nickels,
	 * with the divisors altered for each relevant coin value.
	 */
	quarters = (int) change / 25;
	change %= 25;
	dimes = (int) change / 10;
	change %= 10;
	nickels = (int) change / 5;
	change %= 5;
	
	System.out.println("Your item cost " + price + " cents.");
	System.out.println("Out of one dollar, your total change is " + totalChange);
	System.out.println("That is...");
	System.out.println(quarters + " quarter(s)");
	System.out.println(dimes + " dime(s)");
	System.out.println(nickels + " nickel(s)");   
    }
    
}
