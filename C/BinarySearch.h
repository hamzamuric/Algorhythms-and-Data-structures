#ifndef BINSRC_H
#define BINSRC_H

int binsrc(int arr[], int x, int l, int r) {
	if (l > r) return -1;

	int mid = l + (r - l) / 2;

	if (arr[mid] == x)
		return mid;
	if (x < arr[mid])
		return binsrc(arr, x, l, mid - 1);
	return binsrc(arr, x, mid + 1, r);
}

#endif // BINSRC_H
