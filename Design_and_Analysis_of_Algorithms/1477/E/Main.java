package E;

import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/24 - 下午9:33
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int n = sc.nextInt();
            int c = sc.nextInt();
            box[] boxes = new box[n];
            for (int i = 0; i < n; i++) {
                boxes[i] = new box(sc.nextInt(), sc.nextInt());
            }
            Arrays.sort(boxes,(a,b)-> a.w-b.w);
            int sum = 0;
            int cnt=0;
            for (int i = 0; i < n; i++) {
                sum += boxes[i].w;
                if (c>=sum){
                    boxes[i].selected=true;
                    cnt++;
                }
            }
            System.out.println(cnt);
            for (box box : boxes) {
                if (box.selected) {
                    System.out.print(box.id+" ");
                }
            }
            System.out.println();
        }
    }
    static class box{
        boolean selected;
        int id;
        int w;

        public box(int id, int w) {
            this.id = id;
            this.w = w;
            this.selected = false;
        }
    }
}
