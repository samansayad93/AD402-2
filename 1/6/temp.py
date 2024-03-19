def count_ways_to_target(nums, target):
    def backtrack(index, current_sum):
        # اگر به انتهای آرایه رسیده باشیم
        if index == len(nums):
            # اگر حاصل جمع برابر با target باشد، یک حالت جدید پیدا شده است
            return 1 if current_sum == target else 0

        # محاسبه تعداد حالات با افزودن "+" به عدد فعلی
        ways_with_plus = backtrack(index + 1, current_sum + nums[index])

        # محاسبه تعداد حالات با افزودن "-" به عدد فعلی
        ways_with_minus = backtrack(index + 1, current_sum - nums[index])

        # جمع تعداد حالات با هر دو نماد "+" و "-" را برمی‌گردانیم
        return ways_with_plus + ways_with_minus

    # فراخوانی تابع با شروع از اولین عدد در آرایه
    return backtrack(0, 0)

# ورودی‌ها
n = int(input())
target = int(input())
nums = list(map(int, input().split()))

# چاپ تعداد حالات ممکن
print(count_ways_to_target(nums, target))
