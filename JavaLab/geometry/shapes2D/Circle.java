package geometry.shapes2D;
import geometry.interfaces.*;

public class Circle implements calcarea,calcperi{
    public double r;
    public Circle(double ra){
        r=ra;
    }
    public double area(){
        return Math.PI*r*r ;
    }
    public double peri(){
        return 2*Math.PI*r;
    }
}
