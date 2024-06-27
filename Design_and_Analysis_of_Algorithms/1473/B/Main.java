package B;

import java.util.Scanner;

/**
 * ClassName: A.B.C.D.E.F.Main
 * Package: PACKAGE_NAME
 * Description:
 *
 * @Author: lingdianshiren
 * @Create: 2024/5/10 - 下午9:25
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            int n = scanner.nextInt(); // 读取序列长度
            int[] sequence = new int[n ];
            for (int i = 0; i <n; i++) {
                sequence[i] = scanner.nextInt(); // 读取序列中的每个数字
            }

            int[] result = lis(sequence);
            for (int i : result) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
        scanner.close();

    }
    private static int[] lis(int arr[]) {
        int n=arr.length;
        int[] dp = new int[n];
        int[] pre=new int[n];
        dp[0]=1;
        int max=0;
        for (int i=1;i<n;i++) {
            max=0;
            for (int j=i-1;j>=0;j--) {
                if (arr[i]>arr[j]&&max<dp[j]) {
                    max=dp[j]+1;
                    pre[i]=j;
                }
            }
            dp[i]=max;
        }



        max=dp[0];
        int index=0;
        for (int i = 1; i<n; i++) {
            if (max<dp[i]) {
                max=dp[i];
                index=i;
            }
        }
        int[] res=new int[max];
        for(int i=max-1;i>=0;i--) {
            res[i]=arr[index];
            index=pre[index];
        }
        return res;
    }
}
