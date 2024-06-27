package G;

import java.util.Scanner;

/**
 * ClassName: Main
 * Package: G
 * Description:
 * 普普通通的递推和组合数，也可以用递归
 * @Author: lingdianshiren
 * @Create: 2024/6/23 - 下午4:57
 * @Version: v1.0
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int n = scanner.nextInt();
        int[] nums = new int[n+1];
        nums[1] = 1;
        nums[2] = 1;
        for (int i = 3; i <= n; i++) {
            nums[i] = nums[i-1] + nums[i-2];
        }
        System.out.println(nums[x]*nums[y-x-1]*nums[n-y]);
    }
}
