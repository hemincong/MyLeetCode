class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var zero_count = 0
        let l = nums.filter{$0 != 0}
        let z = nums.filter{$0 == 0}
        nums = l + z
    }
}
