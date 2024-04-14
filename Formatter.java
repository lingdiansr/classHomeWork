import java.io.*;
import java.util.Scanner;

// class Data {
//     String name;
//     int cate;
//     double per;
//     int x1;
//     int y1;
//     int x2;
//     int y2;
//     public String getName() {
//         return name;
//     }
//     public void setName(String name) {
//         this.name = name;
//     }
//     public int getCate() {
//         return cate;
//     }
//     public void setCate(int cate) {
//         this.cate = cate;
//     }
//     public double getPer() {
//         return per;
//     }
//     public void setPer(double per) {
//         this.per = per;
//     }
//     public int getX1() {
//         return x1;
//     }
//     public void setX1(int x1) {
//         this.x1 = x1;
//     }
//     public int getY1() {
//         return y1;
//     }
//     public void setY1(int y1) {
//         this.y1 = y1;
//     }
//     public int getX2() {
//         return x2;
//     }
//     public void setX2(int x2) {
//         this.x2 = x2;
//     }
//     public int getY2() {
//         return y2;
//     }

//     public void setY2(int y2) {
//         this.y2 = y2;
//     }    
// }
public class Formatter {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = null;

        try {
            // 创建一个PrintWriter对象，用于写入文件
            writer = new PrintWriter(new FileWriter("formatted_data.txt"));

            System.out.println("请输入数据，每行数据用空格分隔，当输入完成时请输入'end'：");

            // 读取并处理每一行数据直到用户输入'end'
            while (true) {
                String line = scanner.nextLine();

                // 检查用户是否输入了'end'，如果是，则结束输入
                if ("end".equalsIgnoreCase(line)) {
                    break;
                }
                
                // 将输入的数据分割成数组
                String[] data = line.split(" ");

                // // 检查数据是否有足够的列
                // if (data.length < 7) {
                //     System.out.println("输入的数据列数不足，请确保每行有7列数据。");
                //     continue;
                // }
                
                // // 根据格式化规则进行处理
                StringBuilder formattedLine = new StringBuilder();

                // // 第一列：确保不会超出实际字符串长度
                String firstColumn = data[0];
                if (firstColumn.length() < 11) {
                    firstColumn = String.format("%-11s ", firstColumn);
                } 
                formattedLine.append(firstColumn+" ");

                // // 第二列：1位字符长度
                formattedLine.append(data[1]+" ");

                // // 第三列：11位长度，不足的在右侧补0
                String thirdColumn = String.format("%-11s", data[2]).replace(' ', '0');
                formattedLine.append(thirdColumn+" ");

                // // 第四到第七列：每列四位长度，右对齐
                for (int i = 3; i < 7; i++) {
                    String column = String.format("%4s", data[i]);
                    formattedLine.append(column+" ");
                }

                // // 将格式化后的数据写入文件，并添加换行符
                writer.println(formattedLine.toString());
            }

            System.out.println("所有数据已成功格式化并保存到文件中。");
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            // 关闭资源
            if (writer != null) {
                writer.close();
            }
            scanner.close();
        }
    }
}