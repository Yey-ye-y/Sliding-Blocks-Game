# Sliding-Blocks-Game
#### 滑动积木游戏(A*算法)  
#### 广州大学  人工智能作业 2019/11/10

### 文档要求  
滑动积木块游戏的初始排列是：BBWWE，B表示黑牌，W表示白牌，E表示空格。规定：任一牌移入相邻空格，或跳过一张牌移入空格，耗散为1；跳过两张牌移入空格，耗散为2；不能跳过3或更多牌移入空格。目标排列为白牌均在黑牌之左，空格位置不计。  
#### 1、定义h(n)，用A算法求搜索树；  
    本程序h(n)定义为：h(n)=2-最左边两位置时白牌(W)的数量  


