import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Stack<Integer> s = new Stack<>();
        for(int i=0; i<n; i++){
            String st = sc.next();
            
            if(st.equals("push")){
                int num = sc.nextInt();
                s.push(num);
            }
            else if(st.equals("size")){
                System.out.println(s.size());
            }
            else if(st.equals("empty")){
                if(s.isEmpty())
                    System.out.println(1);
                else
                    System.out.println(0);
            }
            else if(st.equals("pop")){
                System.out.println(s.peek()); s.pop();
            }
        }
    }
}