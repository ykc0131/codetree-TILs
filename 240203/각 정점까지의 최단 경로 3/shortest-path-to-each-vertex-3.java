import java.util.*;

public class Main {
    static class Node{
        int node;
        int cost;

        Node(int node, int cost){
            this.node = node;
            this.cost = cost;
        }
    }
    static final int MAX_N = 100001;
    static Scanner sc = new Scanner(System.in);
    static int n,m;
    static boolean[] visit;
    static int[] dist;
    static ArrayList<Node>[] graph;

    public static void init(){
        n = sc.nextInt();
        m = sc.nextInt();
        visit = new boolean[n+1];
        graph = new ArrayList[n+1];

        for(int i=0; i<n+1; i++){
            graph[i] = new ArrayList<>();
        }

        for(int i=0; i<m; i++){
            int u,v,cost;

            u = sc.nextInt();
            v = sc.nextInt();
            cost = sc.nextInt();
            graph[u].add(new Node(v,cost));
        }
    }

    public static void dij(){
        dist = new int[n+1];
        Arrays.fill(dist,MAX_N);
        PriorityQueue<Node> pq = new PriorityQueue<>(
            (a,b)->a.cost-b.cost //크면 바꾼다 = 오름차순
        );

        pq.add(new Node(1,0));
        dist[1]=0;
        
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            
            if(visit[cur.node])
                continue;
            visit[cur.node] = true;

            for(Node node : graph[cur.node]){
                int next = node.node;
                int nextCost = node.cost + cur.cost;

                if(!visit[next] && dist[next] > nextCost){
                    dist[next] = nextCost;
                    pq.add(new Node(next, nextCost));
                }
            }
        }
    }

    public static void solve(){
        dij();
        for(int i=2; i<=n; i++){
            if(dist[i]==MAX_N)
                dist[i] = -1;
            System.out.println(dist[i]);
        }
    }

    public static void main(String[] args) {
        init();
        solve();
    }
}