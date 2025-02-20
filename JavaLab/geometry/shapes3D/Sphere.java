package geometry.shapes3D;
import geometry.shapes2D.*;

public class Sphere extends Circle{
    public Sphere(double ra){
        super(ra);
    }
    public double vol(){
        return (4/3.0)*Math.PI*Math.pow(r, 3);
    }
}
