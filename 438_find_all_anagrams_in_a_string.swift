//
//  main.swift
//  algoSwift
//
//  Created by mincong.he on 2024/8/5.
//

import Foundation

class Solution {
    func findAnagrams(_ s: String, _ p: String) -> [Int] {
        var ret : [Int] = []

        let p_array = Array(p)
        let s_array = Array(s)

        let p_len = p_array.count;
        let s_len = s_array.count;

        guard p_len <= s_len else {
            return ret
        }

        var c_map = [Int](repeating:0, count:26)
        var p_map = [Int](repeating:0, count:26)

        for c in p_array {
            let c_i = Int(c.asciiValue! - Character("a").asciiValue!)
            p_map[c_i] = p_map[c_i] + 1
        }

        for i in 0..<p_len {
            let c_i = Int(s_array[i].asciiValue! - Character("a").asciiValue!)
            c_map[c_i] = c_map[c_i] + 1
        }

        if c_map == p_map {
            ret.append(0)
        }

        guard s_len - p_len >= 1 else {
            return ret;
        }

        for i in 1 ... s_len - p_len {
            let head = Int(s_array[i - 1].asciiValue! - Character("a").asciiValue!)
            let tail = Int(s_array[i + p_len - 1].asciiValue! - Character("a").asciiValue!)

            c_map[head] = c_map[head] - 1
            c_map[tail] = c_map[tail] + 1

            if c_map == p_map {
                ret.append(i)
            }
        }
        return ret
    }
}

let s = Solution()

let s1 = "cbaebabacd"
let p1 = "abc"
print(s.findAnagrams(s1, p1))

let s2 = "abab"
let p2 = "ab"
print(s.findAnagrams(s2, p2))

let s3 = "aa"
let p3 = "bb"
print(s.findAnagrams(s3, p3))

let s4 = "baa"
let p4 = "aa"
print(s.findAnagrams(s4, p4))

let s5 = "aaaaaaaaaa"
let p5 = "aaaaaaaaaaaaa"
print(s.findAnagrams(s5, p5))

let s6 = "ab"
let p6 = "ba"
print(s.findAnagrams(s6, p6))
