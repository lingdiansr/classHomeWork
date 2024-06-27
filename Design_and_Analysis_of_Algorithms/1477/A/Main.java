import java.util.Scanner;

/**
 * ClassName: A.C.E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/24 - 下午8:09
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int n = scanner.nextInt();
            long[] nums = new long[n];
            long max = 0;
            double s=0;
            for (int i = 0; i < n; i++) {
                nums[i] = scanner.nextInt();
                max = Math.max(max, nums[i]);
//                s+=nums[i];
            }
            for (int i = 0; i < n; i++) {
                s+=max-nums[i];
            }
            System.out.printf("%.0f",s);
            System.out.println();
//            System.out.println(n*max-s);
        }
        scanner.close();
    }
}
