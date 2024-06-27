import java.util.ArrayList;
import java.util.Scanner;

/**
 * ClassName: B.C.E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/24 - 下午8:28
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) {
            int n = scanner.nextInt();
            if (n == 0) break;
            ArrayList<Jiemu> jiemus = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int s = scanner.nextInt();
                int e = scanner.nextInt();
                jiemus.add(new Jiemu(s, e));
            }
            jiemus.sort((o1, o2) -> o1.et-o2.et);
            getcnt(jiemus);
        }
    }

    private static void getcnt(ArrayList<Jiemu> jiemus) {
        jiemus.get(0).selected=true;
        int j=0;
        int cnt=1;
        for (int i = 1; i < jiemus.size(); i++) {
            if (jiemus.get(i).st>= jiemus.get(j).et) {
                j=i;
                jiemus.get(i).selected=true;
                cnt++;
            }
        }
        System.out.println(cnt);
    }

    static class Jiemu {
        int st;
        int et;
        boolean selected;
        public Jiemu(int st, int et) {
            this.st = st;
            this.et = et;
            this.selected = false;
        }

    }
}
