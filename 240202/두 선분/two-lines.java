import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[][] coordi = new int[2][2];
        for(int i=0; i<2; i++){
            int x,y;
            x = sc.nextInt();
            y = sc.nextInt();

            coordi[i][0] = x;
            coordi[i][1] = y;
        }

        Arrays.sort(coordi, (a,b) -> a[0]==b[0] ? a[1]-b[1] : a[0] - b[0]);
        
        if(coordi[0][1] >= coordi[1][0])
            System.out.println("intersecting");
        else
            System.out.println("nonintersecting");
    }
}