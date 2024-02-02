import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.next();
        String s = sc.next();

        int result = str.indexOf(s);
        if(result==-1)
            System.out.println("No");
        else
            System.out.println(result);
    }
}