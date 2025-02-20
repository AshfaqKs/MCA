package arithmetic;
import arithmetic.interfaces.computable;;

public class mul implements computable{
    double a,b;
    public mul(double am,double bm){
        a=am;
        b=bm;
    }
    public double calculate(){
        return a*b;
    }
}
