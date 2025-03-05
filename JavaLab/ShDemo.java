import geometry.shapes3D.*;

public class ShDemo {
    public static void main(String[] args){
        Cub c = new Cub(2,3,4);
        Sphere sp = new Sphere(10);
        System.out.println("\nRectangle Area : "+c.area()+"\nRectangle Perimeter : "+c.peri()+"\nCuboid Volume : "+c.vol());
        System.out.println("\nCircle Area : "+sp.area()+"\nCircle Perimeter : "+sp.peri()+"\nSphere Volume : "+sp.volu());
    }
}
