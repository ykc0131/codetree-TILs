import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n,m;
        n = sc.nextInt();
        m = sc.nextInt();

        int cnt = 0;
        int[][] arr = new int[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]!=0)
                    continue;
                int y = i;
                int x = j;

                while(x>=0 && y<n){
                    arr[y][x] = ++cnt;
                    y += 1;
                    x += -1;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                System.out.print(arr[i][j]+ " ");
            }
            System.out.println();
        }
    }
}