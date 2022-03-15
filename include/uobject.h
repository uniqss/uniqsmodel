#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

#include "utypes.h"

namespace UniqsModel {
class UObject {
    int64_t m_object_id;

    // 一级属性
    // 这里要不要不用std::string做key???如果不用的话就是写死比如char[32]然后自己写hash算法。性能会差多少？？？
    std::unordered_map<std::string, i32> m_properties_i32;
    std::unordered_map<std::string, u32> m_properties_u32;
    std::unordered_map<std::string, i64> m_properties_i64;
    std::unordered_map<std::string, u64> m_properties_u64;
    std::unordered_map<std::string, str> m_properties_str;

    // 多值不随机查询 arr
    std::unordered_map<std::string, std::vector<i32>> m_arr_i32;
    std::unordered_map<std::string, std::vector<u32>> m_arr_u32;
    std::unordered_map<std::string, std::vector<i64>> m_arr_i64;
    std::unordered_map<std::string, std::vector<u64>> m_arr_u64;
    std::unordered_map<std::string, std::vector<str>> m_arr_str;
    // 多值随机查询 set
    std::unordered_map<std::string, std::unordered_set<i32>> m_set_i32;
    std::unordered_map<std::string, std::unordered_set<u32>> m_set_u32;
    std::unordered_map<std::string, std::unordered_set<i64>> m_set_i64;
    std::unordered_map<std::string, std::unordered_set<u64>> m_set_u64;
    std::unordered_map<std::string, std::unordered_set<str>> m_set_str;

    // map
    std::unordered_map<std::string, std::unordered_map<int64_t, i32>> m_map_i32;
    std::unordered_map<std::string, std::unordered_map<int64_t, u32>> m_map_u32;
    std::unordered_map<std::string, std::unordered_map<int64_t, i64>> m_map_i64;
    std::unordered_map<std::string, std::unordered_map<int64_t, u64>> m_map_u64;
    std::unordered_map<std::string, std::unordered_map<int64_t, str>> m_map_str;

    // sub objects
    std::unordered_map<std::string, std::unordered_set<int64_t>> m_sub_objects_set;
    std::unordered_map<std::string, std::vector<int64_t>> m_sub_objects_arr;
};
}  // namespace UniqsModel
