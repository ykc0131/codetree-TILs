import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n,m,cnt=0;
        n = sc.nextInt();
        m = sc.nextInt();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                System.out.print(++cnt + " ");
            }
            System.out.println();
        }
    }
}