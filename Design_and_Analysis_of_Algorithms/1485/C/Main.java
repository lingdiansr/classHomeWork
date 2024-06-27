import java.util.Scanner;

/**
 * ClassName: C.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/6/8 - 下午12:32
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < t; i++) {
            sc.nextLine();
            String s = sc.nextLine();
            int cnt=0;
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == '.') {
                    cnt++;
                    j+=2;

                }
            }
            System.out.println(cnt);
        }
    }
}
