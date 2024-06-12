import java.util.*;
import java.io.*;

class Node implements Comparable<Node> {
    
    int index;
    int weight;
    
    Node(int index, int weight) {
        this.index = index;
        this.weight = weight;
    }
    
    @Override
    public int compareTo(Node o) {
        return Integer.compare(this.weight, o.weight);
    }
}

public class Main {
    
    static int INF = Integer.MAX_VALUE;
    static ArrayList<Node>[] graph;
    static int N, M, X;
    static int[] dist;
    static int[] distFromX;

    static void dijkstra(int startPoint) {
        Arrays.fill(dist, INF);
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(startPoint, 0));
        dist[startPoint] = 0;

        while (!pq.isEmpty()) {
            Node now = pq.poll();
            if (dist[now.index] < now.weight) continue;

            for (Node next : graph[now.index]) {
                if (dist[next.index] > dist[now.index] + next.weight) {
                    dist[next.index] = dist[now.index] + next.weight;
                    pq.add(new Node(next.index, dist[next.index]));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) graph[i] = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int T = Integer.parseInt(st.nextToken());
            graph[A].add(new Node(B, T));
        }

        dist = new int[N + 1];
        distFromX = new int[N + 1];

        dijkstra(X);
        System.arraycopy(dist, 0, distFromX, 0, N + 1);

        int answer = 0;
        for (int i = 1; i <= N; i++) {
            if (i == X) continue;
            dijkstra(i);
            int result = dist[X] + distFromX[i];
            answer = Math.max(answer, result);
        }

        System.out.println(answer);
    }
}