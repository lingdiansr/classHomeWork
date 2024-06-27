import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: C.E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/24 - 下午9:03
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int m = sc.nextInt();
            int n = sc.nextInt();
            Integer[] arr = new Integer[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            Arrays.sort(arr);
            int count = 0;
            int s=0;
            for (Integer i : arr) {
                s+=i;
                if (m>=s){
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}
