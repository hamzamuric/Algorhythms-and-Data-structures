public class BinarySearch {

    public static boolean search(int[] arr, int x, int left, int right) {

        if (left > right) {
            return false;
        }
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return true;
        } else if (x < arr[mid]) {
            return search(arr, x, left, mid - 1);
        } else {
            return search(arr, x, mid + 1, right);
        }
    }

    public static boolean search(int[] arr, int x) {
        return search(arr, x, 0, arr.length);
    }
}
