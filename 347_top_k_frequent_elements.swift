//
//  main.swift
//  algoSwift
//
//  Created by mincong.he on 2024/8/5.
//

import Foundation

class Solution {
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
        var d : Dictionary<Int,Int> = [:]

        for n in nums {
            d[n] = d[n, default: 0] + 1
        }

        var l = d.sorted{ $0.value > $1.value }

        var ret : [Int] = []
        for i in 0..<k {
            ret.append(l[i].key)
        }
        return ret
    }
}

let s = Solution()

let nums_1 = [1,1,1,2,2,3]
let k_1 = 2
// [1,2]
print(s.topKFrequent(nums_1, k_1))


let nums_2 = [1]
let k_2 = 1
//输出: [1]
print(s.topKFrequent(nums_2, k_2))
