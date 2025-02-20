package geometry.shapes2D;
import geometry.interfaces.*;

public class Rect implements calcarea,calcperi{
    public double l,w;
    public Rect(double le, double wi){
        l=le;
        w=wi;
    }
    public double area(){
        return l*w;
    }
    public double peri(){
        return 2*(l+w);
    }
}
