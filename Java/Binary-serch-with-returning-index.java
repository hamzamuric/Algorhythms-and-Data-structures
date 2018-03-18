import java.util.Scanner;

public class MainClass {

    public static int binrec(int[] arr, int x, int left, int right) {
        if (left > right) return -1;

        int mid = left + (right - left) / 2;
        if (x == arr[mid]) {
            return mid;
        } else if (x < arr[mid]) {
            return binrec(arr, x, left, mid - 1);
        } else {
            return binrec (arr, x, mid + 1, right);
        }
    }

    public static int binarySearch(int[] arr, int x) {
        return binrec(arr, x, 0, arr.length - 1);
    }

    public static void main(String[] args) {

        int[] arr = new int[10];
        int position, key;
        Scanner scn = new Scanner(System.in);

        System.out.println("Enter elements:");
        for (int i = 0; i < arr.length; i++) {
            System.out.print("array[" + i + "] = ");
            arr[i] = scn.nextInt();
        }

        System.out.print("Number to search: ");
        key = scn.nextInt();

        position = binarySearch(arr, key);
        System.out.println("The number is at " + position + "th position");

    }
}