# uniqsmodel

基于 gitee上的项目: [uniqsmodel](https://gitee.com/uniqs/uniqsmodel)
但又比gitee上的多抽象一层，不再需要有代码生成-编译-运行的步骤，只需要把基础功能稳定以后，修改定义文件就可以直接对model层起作用。

### model对象的不同存在类型:
* mem
* mem_subset
* db
* db_subset
* net
* net_subset

### 语言：
* c++
* lua
* javascript

### 备忘：
* 注意 subset 可能会有多个， subset 的定义是［对象的子集］。比如玩家有好友，好友能看到玩家的部分而非全部数据，那么我们就会有个subset_friend，里面是好友能看到的信息。subset 数据是独立的，不一定实时更新的，可独立从db查询的，可独立从network传输的，可独立存在于mem中的
* 在固定需求的情况下，uniqsmodel肯定会随着时间的推移趋向于稳定。所以从一开始，就定下目标：核心层面纯c++实现，暴接口到其他语言比如lua/javascript
* 一定要记住只做model层的事情，不要越界

