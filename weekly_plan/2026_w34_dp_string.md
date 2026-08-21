# 周专题计划 2026 W34（2026/8/19 - 8/25）

## 目标
- 主力备战明年 5 月邀请赛，本周补两块最高性价比短板
- 17 题（不含个人 CF/VP，模板默写单算）

## 选题理由
- DP 是考频最高的短板：目前只会背包系，区间/状压/数位是"中档题"主力类别，有背包底子，上手快
- 字符串完全空白：KMP/Trie 学习成本低、性价比高，现在铺底
- 图论进阶（SCC/最短路变种）下周接力

## 每日安排

### 一（区间DP）
- [x] [P1880 石子合并](https://www.luogu.com.cn/problem/P1880) — 环→链拆法 + 破环成链模板
- [x] [P4170 涂色](https://www.luogu.com.cn/problem/P4170) — 区间端点相等特判
- [x] [P1220 关路灯](https://www.luogu.com.cn/problem/P1220) — 区间 + 人在左/右（三维状态）
- [x] [P3205 合唱队](https://www.luogu.com.cn/problem/P3205) — 状态由"最后一个进的是哪边"推导

### 二（状压DP）
- [x] [P1433 吃奶酪](https://www.luogu.com.cn/problem/P1433) — TSP 入门，dp[mask][i]
- [x] [P1879 玉米田](https://www.luogu.com.cn/problem/P1879) — 行合法预筛 + 兼容性判断
- [ ] [P2704 炮兵阵地](https://www.luogu.com.cn/problem/P2704) — 三行状态转移，滚动数组优化
- [ ] [P2831 愤怒的小鸟](https://www.luogu.com.cn/problem/P2831) — 抛物线预处理 + lowbit 枚举优化

### 三（数位DP + 提速）
- [ ] [P2602 数字计数](https://www.luogu.com.cn/problem/P2602) — 模板：limit/lead 双标记
- [ ] [CF 855E Salazar Slytherin's Locket](https://codeforces.com/problemset/problem/855/E) — 状压版数位DP（10 位 bitmask 状态）
- [ ] [P1063 能量项链](https://www.luogu.com.cn/problem/P1063) — 区间DP + 环，给半天的题提速

### 四（KMP）
- [ ] [P3375 KMP模板](https://www.luogu.com.cn/problem/P3375) — 默写 next 数组，边界必须自己写对
- [ ] [P4391 Radio Transmission](https://www.luogu.com.cn/problem/P4391) — next 周期性应用（最小循环节）
- [ ] [P4824 Censoring](https://www.luogu.com.cn/problem/P4824) — KMP + 栈回退（USACO 高频套路）

### 五（Trie）
- [ ] [P2580 于是他错误的点名开始了](https://www.luogu.com.cn/problem/P2580) — Trie 插入/查询计数
- [ ] [P4551 最长异或路径](https://www.luogu.com.cn/problem/P4551) — Trie 求异或最大 + 树上前缀异或

### 六（综合拔高）
- [ ] [P3805 manacher模板](https://www.luogu.com.cn/problem/P3805) — 字符串收尾
- [ ] 修完本周未 AC 的题 + 完成度训练（一次写对、结构清晰，避免 Show Hand 式代码混乱）

## 单算，不进 15-20
- 每天 10 分钟默写 SpeedList 模板：快速幂 / 矩阵快速幂 / 字符串哈希 / 线性筛 / 三分
- 个人 CF/VP 照常
- RedoList 复盘：小红的网格图构造2.0、Show Hand（周三晚加餐）

## 复盘
- 卡住的题按 RedoList 流程记录：错因、last_trial_time、下次重做日期
- 新增有效的解题套路到 SpeedList/模板笔记

## 下周预告
- 图论进阶：SCC 缩点 + 最短路变种 + 二分图/拓扑DP
