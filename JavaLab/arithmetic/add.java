package arithmetic;
import arithmetic.interfaces.computable;

public class add implements computable{
    double a,b;
    public add(double am,double bm){
        a=am;
        b=bm;
    }
    public double calculate(){
        return a+b;
    }
}
