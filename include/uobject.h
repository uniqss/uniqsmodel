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
    std::unordered_map<std::string, i64> m_properties_i64;
    std::unordered_map<std::string, u64> m_properties_u64;
    std::unordered_map<std::string, str> m_properties_str;

    // 多值不随机查询，一般需要配合一个idx一起用，或者是关注顺序的每次用循环找(性能会差一点，不能排序不能二分查找) arr
    std::unordered_map<std::string, std::vector<i64>> m_arr_i64;
    std::unordered_map<std::string, std::vector<u64>> m_arr_u64;
    std::unordered_map<std::string, std::vector<str>> m_arr_str;
    // 这里要不要 queue 类型？要的话就需要定义queue的最大长度。但是坏处是比如db进程，就需要同步这个最大长度，需要重启进程。
    // 没有queue的日子里，如果我们要循环用，只能自己存idx自己去索引并判超回置，当然也可以偷懒直接pop_front，性能会差一点，会发生一次memmove,而且里面的值不能存指针引用
    // 多值随机查询，注意这里面不能保证顺序，如果要有序，要显示层面之前做一次排序 set
    std::unordered_map<std::string, std::unordered_set<i64>> m_set_i64;
    std::unordered_map<std::string, std::unordered_set<u64>> m_set_u64;
    std::unordered_map<std::string, std::unordered_set<str>> m_set_str;

    // map
    std::unordered_map<std::string, std::unordered_map<int64_t, i64>> m_map_i64;
    std::unordered_map<std::string, std::unordered_map<int64_t, u64>> m_map_u64;
    std::unordered_map<std::string, std::unordered_map<int64_t, str>> m_map_str;

    // sub objects
    std::unordered_map<std::string, std::unordered_set<int64_t>> m_sub_objects_set;
    std::unordered_map<std::string, std::vector<int64_t>> m_sub_objects_arr;

   public:
    int64_t GetId() const { return m_object_id; }
    void SetId(int64_t id) { m_object_id = id; }
    // property
    i64 GetPropertyI64(const std::string& pname) const;
    void SetPropertyI64(const std::string& pname, i64 value);
    u64 GetPropertyU64(const std::string& pname) const;
    void SetPropertyU64(const std::string& pname, u64 value);
    const std::string& GetPropertyStr(const std::string& pname) const;
    void SetPropertyStr(const std::string& pname, const std::string& value);
    // arr
    const std::vector<i64>& GetArrI64(const std::string& pname) const;
    void SetArrI64(const std::string& pname, int idx, i64 value);
    int AppendArrI64(const std::string& pname, i64 value); // return idx
    int FindArrI64(const std::string& pname, i64 value); // return first idx, -1 if not found.
    const std::vector<u64>& GetArrU64(const std::string& pname) const;
    void SetArrU64(const std::string& pname, int idx, u64 value);
    int AppendArrU64(const std::string& pname, u64 value); // return idx
    int FindArrU64(const std::string& pname, u64 value); // return first idx, -1 if not found.
    const std::vector<str>& GetArrStr(const std::string& pname) const;
    void SetArrStr(const std::string& pname, int idx, const str& value);
    int AppendArrStr(const std::string& pname, const str& value); // return idx
    int FindArrStr(const std::string& pname, const str& value); // return first idx, -1 if not found.
    // set
    const std::unordered_set<i64>& GetSetI64(const std::string& pname) const;
    bool ExistsSetI64(const std::string& pname, i64 value) const;
    void SetSetI64(const std::string& pname, i64 value);
    const std::unordered_set<u64>& GetSetU64(const std::string& pname) const;
    bool ExistsSetU64(const std::string& pname, u64 value) const;
    void SetSetU64(const std::string& pname, u64 value);
    const std::unordered_set<str>& GetSetStr(const std::string& pname) const;
    bool ExistsSetStr(const std::string& pname, const std::string& value) const;
    void SetSetStr(const std::string& pname, const std::string& value);
    // map
    const std::unordered_map<int64_t, i64>& GetMapI64(const std::string& pname) const;
    bool ExistsMapI64(const std::string& pname, int64_t key) const;
    void SetMapI64(const std::string& pname, int64_t key, i64 value) const;
    const std::unordered_map<int64_t, u64>& GetMapU64(const std::string& pname) const;
    bool ExistsMapU64(const std::string& pname, int64_t key) const;
    void SetMapU64(const std::string& pname, int64_t key, u64 value) const;
    const std::unordered_map<int64_t, str>& GetMapStr(const std::string& pname) const;
    bool ExistsMapStr(const std::string& pname, int64_t key) const;
    void SetMapStr(const std::string& pname, int64_t key, const str& value) const;
    // sub
    const std::unordered_set<int64_t>& GetSubObjectSet(const std::string& pname) const;
    bool ExistsSubObjectSet(const std::string& pname, int64_t sub_id) const;
    void SetSubObjectSet(const std::string& pname, int64_t sub_id) const;
    const std::vector<int64_t>& GetSubObjectArr(const std::string& pname) const;
    bool ExistsSubObjectArr(const std::string& pname, int64_t sub_id) const;
    void AppendSubObjectArr(const std::string& pname, int64_t sub_id) const;
};
}  // namespace UniqsModel
