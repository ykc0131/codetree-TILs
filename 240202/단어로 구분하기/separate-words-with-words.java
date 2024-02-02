import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        String result = "";
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)==' '){
                System.out.println(result);
                result = "";
            }
            else
                result += s.charAt(i);
        }
        System.out.println(result);
    }
}