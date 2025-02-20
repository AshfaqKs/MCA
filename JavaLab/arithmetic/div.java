package arithmetic;
import arithmetic.interfaces.computable;;

public class div implements computable{
    double a,b;
    public div(double am,double bm){
        a=am;
        b=bm;
    }
    public double calculate(){
        return a/b;
    }
}
