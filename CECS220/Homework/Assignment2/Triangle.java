public class Triangle
{
    /* X & Y coordinates for each vertex of the triangle */
    private int x1, x2, x3, y1, y2, y3;
    /* Side lengths of the triangle */
    private double side1, side2, side3;

    /*
     * Constructor which sets each vertex to (0,0)
     * and each side length to 0 units
     */
    public Triangle()
    {
	x1 = 0;
	x2 = 0;
	x3 = 0;
	y1 = 0;
	y2 = 0;
	y3 = 0;
	side1 = 0;
	side2 = 0;
	side3 = 0;
    }

    /* Mutator functions for X coords */
    public void setX1(int value)
    {
	x1 = value;
    }

    public void setX2(int value)
    {
	x2 = value;
    }

    public void setX3(int value)
    {
	x3 = value;
    }

    /* Mutator functions for Y coords */
    public void setY1(int value)
    {
	y1 = value;
    }

    public void setY2(int value)
    {
	y2 = value;
    }

    public void setY3(int value)
    {
	y3 = value;
    }

    /* Accessor functions for X coords */
    public int getX1()
    {
	return x1;
    }

    public int getX2()
    {
	return x2;
    }

    public int getX3()
    {
	return x3;
    }

    /* Accessor functions for Y coords */
    public int getY1()
    {
	return y1;
    }

    public int getY2()
    {
	return y2;
    }

    public int getY3()
    {
	return y3;
    }

    /* Accessor functions for side lengths */
    public double getSide1()
    {
	int deltaX = x1 - x2;
	int deltaY = y1 - y2;
	side1 = Math.sqrt((deltaX * deltaX) + (deltaY * deltaY));
	return side1;
    }

    public double getSide2()
    {
	int deltaX = x2 - x3;
	int deltaY = y2 - y3;
	side2 = Math.sqrt((deltaX * deltaX) + (deltaY * deltaY));
	return side2;
    }
    
    public double getSide3()
    {
	int deltaX = x3 - x1;
	int deltaY = y3 - y1;
	side3 = Math.sqrt((deltaX * deltaX) + (deltaY * deltaY));
	return side3;
    }

    /* Perimeter and area methods */
    public double perimeter()
    {
	double perimeter = side1 + side2 + side3;
	return perimeter;
    }

    public double area(double perimeter)
    {
	double h = perimeter / 2;
	double area = Math.sqrt(h * (h - side1) * (h - side2) * (h - side3));
	return area;
    }

    /* Prints a formatted string of triangle's info */
    public String toString()
    {
	String info = "Triangle Vertices:\n";
	info += "Point 1: (" + getX1() + ", " + getY1() + "), ";
	info += "Point 2: (" + getX2() + ", " + getY2() + "), ";
	info += "Point 3: (" + getX3() + ", " + getY3() + ")\n";
	info += "Sides: " + getSide1() + ", " + getSide2() + ", and " + getSide3() + "\n";
	info += "Perimeter: " + perimeter() + "\n";
	info += "Area: " + area(perimeter()) + "\n";
	return info;
    }
}
