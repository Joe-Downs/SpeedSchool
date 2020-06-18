public class TaxReturn
{
    /* Personal info required for each tax return */
    private String firstName, lastName, address, city, state, zipCode;
    private String ssn, maritalStatus;
    private int income, taxesCollected, taxRate;

    /* 
     * Constructor which asks for values and sets income
     * and taxesCollected to 0
     */
    public TaxReturn(String first, String last, String address,
		    String city, String state, String zip,
		    String ssn, String status)
    {
	firstName = first;
	lastName = last;
	address = address;
	city = city;
	state = state;
	zipCode = zip;
	ssn = ssn;
	maritalStatus = status;
	income = 0;
	taxesCollected = 0;
    }

    /* Mutator functions for income and maritalStatus */
    public void setIncome(int income)
    {
	income = income;
	if (income <= 20000)
	    {
		taxRate = 0;
		return;
	    }
	else if (income <= 50000)
	    {
		taxRate = 0.15;
	    }
	else if (income <= 100000)
	    {
		taxRate = 0.20;
	    }
	else if (income > 100000)
	    {
		taxRate = 0.30;
	    }
	
	/* If the user is married, subtract 5% off the tax rate */
	if (Str.startsWith("M" || "m"))
	    {
		taxRate -= 0.05;
	    }

	taxesCollected = income * taxRate;
    }

    public void setMaritalStatus(String status)
    {
	maritalStatus = status;
    }

    /* Accessor methods for income, taxesCollected, and SSN */
    public int getIncome()
    {
	return income;
    }

    public int getTaxesCollected()
    {
	return taxesCollected();
    }

    public String getSSN()
    {
	return ssn;
    }

    /* toString method for printing the information */
    public String toString()
    {
	String info = "Tax Payer Information\n";
	info += String.format("Name: %s %s\n", firstName, lastName);
	info += String.format("SSN: %s\n", ssn);
	info += String.format("Address: %s, %s, %s, %s\n", address, city, state, zipCode);
	info += String.format("Annual Income: %d.00 USD\n", income);
	info += String.format("Tax Amount: %d.00 USD\n", taxesCollected);
    }
    
}
