import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int sum = 0, cnt = 0;
        for(int i=0; i<10; i++){
            int n = sc.nextInt();
            if(n>250)
                break;
            sum+=n;
            cnt++;
        }

        System.out.printf("%d %.1f", sum , (double)sum/cnt);
    }
}