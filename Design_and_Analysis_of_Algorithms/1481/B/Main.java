import java.util.Arrays;
import java.util.Scanner;

/**
 * ClassName: B.C.D.E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/30 - 下午8:49
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int c = scanner.nextInt();
        int[] gifts = new int[n];
        for (int i = 0; i < gifts.length; i++) {
            gifts[i]=scanner.nextInt();
        }
        Arrays.sort(gifts);
        int cnt = 0;
        int nowSum;
        for (int i = n - 1; i >= 0; i--) {
            int maxValue = c+1;
            if (gifts[i]<c) {
                for (int j = i - 1; j >= 0; j--) {
                    nowSum = gifts[i] + gifts[j];
                    if (nowSum<=c) {
                        cnt++;
                        gifts[i]= maxValue;
                        gifts[j]= maxValue;
//                        break;
                    }
                }
                if (gifts[i]!= maxValue){
                    cnt++;
                    gifts[i]= maxValue;
                }
            } else if (gifts[i]==c) {
                cnt++;
                gifts[i]= maxValue;
            }
        }

//        for (int i = 0; i < gifts.length; i++) {
//
//        }
//            for (int gift : gifts) {
//                if (nowC - gift < 0 || cnt % 2 == 0) {
//                    nowC = c;
//                    cnt++;
//                    System.out.println();
//                }
//                nowC -= gift;
//                System.out.printf(gift+" ");
//            }
        System.out.println(cnt);
    }
}
