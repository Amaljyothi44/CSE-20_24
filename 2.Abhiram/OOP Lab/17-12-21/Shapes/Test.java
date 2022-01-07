public class Test{
      
        public static void printAllSlides(Shapes shape)
        {
        shape.numberOfSides();
        }
	public static void main(String[] args){
		Shapes rect = new Rectangle();
		Shapes tri = new Triangle();
		Shapes hex = new Hexagon();
		printAllSlides(rect);
		printAllSlides(tri);
		printAllSlides(hex);
	}
}
