package arithmetic;
import arithmetic.interfaces.computable;;

public class sub implements computable{
    double a,b;
    public sub(double am,double bm){
        a=am;
        b=bm;
    }
    public double calculate(){
        return a-b;
    }
}
