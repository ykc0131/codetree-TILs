import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[][] arr = new int[n][n];

        int dy = -1, cnt = 0, y = n-1;
        for(int i=n-1; i>=0; i--){
            int x = i;
            arr[y][x] = ++cnt;
            
            while(y+dy>=0 && y+dy<n){
                y+=dy;
                arr[y][x] = ++cnt;
            }
            dy*=-1;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
}