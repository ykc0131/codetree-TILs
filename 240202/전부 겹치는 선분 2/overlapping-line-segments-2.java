import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[][] arr = new int[n][2];
        for(int i=0; i<n; i++){
            arr[i][0] = sc.nextInt();
            arr[i][1] = sc.nextInt();
        }

        Arrays.sort(arr, (a,b)->a[0]==b[0]?a[1]-b[1]:a[0]-b[0]);

        int cnt = 0;
        for(int i=1; i<n; i++){
            if(arr[i-1][1] < arr[i][0])
                cnt++;
        }

        if(cnt>1)
            System.out.println("No");
        else
            System.out.println("Yes");

    }
}