package C;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // 读取图书数量
        Book[] books = new Book[n]; // 创建图书数组

        // 读取每一本书的信息
        for (int i = 0; i < n; i++) {
            String bookName = scanner.next();
            int bookSales = scanner.nextInt();
            double bookPrice = scanner.nextDouble();
            books[i] = new Book(bookName, bookSales, bookPrice);
        }

        // 使用Arrays类的sort方法进行排序
        Arrays.sort(books, new Comparator<Book>() {
            @Override
            public int compare(Book b1, Book b2) {
                // 先按销量降序排序
                int salesCompare = Integer.compare(b2.getSales(), b1.getSales());
                if (salesCompare != 0) {
                    return salesCompare;
                }
                // 对于销量相同的图书，按价格升序排序
                return Double.compare(b1.getPrice(), b2.getPrice());
            }
        });

        // 输出排序后的信息
        for (Book book : books) {
            System.out.printf("%s %d %.2f",book.getName(), book.getSales() , book.getPrice());
            System.out.println();
        }
    }

    // 定义Book类
    static class Book {
        private String name;
        private int sales;
        private double price;

        public Book(String name, int sales, double price) {
            this.name = name;
            this.sales = sales;
            this.price = price;
        }

        public String getName() {
            return name;
        }

        public int getSales() {
            return sales;
        }

        public double getPrice() {
            return price;
        }
    }
}