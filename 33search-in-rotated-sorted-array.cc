class Solution {
public:
  int search(vector<int>& a, int target) {
    int last = a.size()-1, l = 0, h = last, m = 0;
    while (l < h) {
      m = l+h+1 >> 1;
      if (a[m] < a[l])
        h = m-1;
      else
        l = m;
    }
    if (target >= a[0])
      l = 0;
    else {
      l = h+1;
      h = last;
    }
    while (l <= h) {
      m = l+h >> 1;
      if (target < a[m])
        h = m-1;
      else if (target > a[m])
        l = m+1;
      else
        return m;
    }
    return -1;
  }
};

//one while loop
class Solution {
public:
  int search(vector<int> &a, int target) {
    int n = a.size(), l = 0, h = n;
    while (l < h) {
      int m = l+h >> 1;
      if (a[m] < target) {
        if (target < a[l] || a[l] < a[m])
          l = m+1;
        else
          h = m;
      } else if (a[m] > target) {
        if (a[l] <= target || a[l] > a[m])
          h = m;
        else
          l = m+1;
      } else
        return m;
    }
    return -1;
  }
};

//yet another one from MaskRay
class Solution {
public:
  int search(vector<int> &a, int target) {
    int n = a.size(), l = 0, h = n;
    while (l < h) {
      int m = l+h >> 1;
      if (a[m] == target) return m;
      if (a[l] < a[m]) {
        if (a[l] <= target && target < a[m])
          h = m;
        else
          l = m+1;
      } else {
        if (a[m] < target && target <= a[h-1])
          l = m+1;
        else
          h = m;
      }
    }
    return l < n && a[l] == target ? l : -1;
  }
};

// a brilliant one
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
        int mid = (lo + hi) / 2;

        double num = (nums[mid] < nums[0]) == (target < nums[0])
                   ? nums[mid]
                   : target < nums[0] ? -INFINITY : INFINITY;

        if (num < target)
            lo = mid + 1;
        else if (num > target)
            hi = mid;
        else
            return mid;
    }
    return -1;
}
