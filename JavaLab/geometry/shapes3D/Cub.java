package geometry.shapes3D;
import geometry.shapes2D.*;

public class Cub extends Rect{
    public double h;
    public Cub(double l,double w,double he){
        super(l,w);
        h=he;
    }
    public double vol(){
        return area()*h;
    }
}
