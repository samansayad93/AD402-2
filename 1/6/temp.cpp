#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countWaysToTarget(vector<int>& nums, int target) {
    // اضافه کردن memo به تابع باکترک
    unordered_map<string, int> memo;

    // تعریف تابع باکترک به صورت بازگشتی
    function<int(int, int)> backtrack = [&](int index, int current_sum) -> int {
        // اگر به انتهای آرایه رسیده باشیم
        if (index == nums.size()) {
            // اگر حاصل جمع برابر با target باشد، یک حالت جدید پیدا شده است
            return (current_sum == target) ? 1 : 0;
        }

        // بررسی آیا این محاسبه قبلاً انجام شده است
        string key = to_string(index) + "_" + to_string(current_sum);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // محاسبه تعداد حالات با افزودن "+" به عدد فعلی
        int ways_with_plus = backtrack(index + 1, current_sum + nums[index]);

        // محاسبه تعداد حالات با افزودن "-" به عدد فعلی
        int ways_with_minus = backtrack(index + 1, current_sum - nums[index]);

        // جمع تعداد حالات با هر دو نماد "+" و "-" را برمی‌گردانیم
        int result = ways_with_plus + ways_with_minus;

        // ذخیره نتیجه در memo
        memo[key] = result;

        return result;
    };

    // فراخوانی تابع با شروع از اولین عدد در آرایه
    return backtrack(0, 0);
}

int main() {
    // ورودی‌ها
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // چاپ تعداد حالات ممکن
    cout << countWaysToTarget(nums, target) << endl;

    return 0;
}