# Swap Nodes in Pairs

本题要求将链表中的节点按照位置上0-1，2-3，4-5，...的结对方式对换（落单的节点无须处理），属于题意直观、难度较低的链表题，既然解答起来比较简单，不妨就尝试一下分别用递归和非递归的方式解答该问题吧。

对于线性表相关的问题，存在一类最基础的问题，这类问题的特点是

* 该线性表上的A问题可以转化为：该线性表的一个长度为常数的前缀上的A问题(记为$A_1$)与相应的后缀上的A问题(记为$A_2$)，以及分别解决两个子问题后的一些必要操作
* $A_2$的解决不依赖于$A_1$的解决
* $A_1$可以在不使用递归的情况下通过有限个指令解决（限定前缀长度为常数的情况下，这一点应该是可以满足的）

一旦确定问题具有这种格式，我们便可以使用如下的设计思路来设计递归

```
func Solve(lst){
	Solve(suffix(lst))
	Do sth to solve prefix(lst) 
	Do sth to combine two sub-problem
}
```



从而本题的递归解法便很显然了：

1. 检查参数，如果head为nullptr或head->next为nullptr，直接结束函数，返回head本身
2. 递归调用swapPairs函数处理swapPairs(head->next->next)，得到返回值（也即后缀在处理完毕后的新head）
3. 处理前缀，也即长度为2的链表，简单将head与head->next交换位置即可
4. 合并两个子问题，只需要将前缀的新nail的next设为后缀的新head即可
5. 返回整个链表的新head，也即前缀的新head



代码如下

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* next=head->next,*tmp=swapPairs(next->next);
        next->next=head;
        head->next=tmp;
        return next;
    }
};
```



该解法将原链表分解为长度为2的前缀与相应的后缀。事实上，你甚至可以将原链表分解为长度为4、6、8、...的前缀与相应的后缀，这是完全可以的，但这会极大程度上加大你不使用递归通过有限条指令解决前缀子问题的代码编写难度，因此在选取前缀长度的时候，应当遵循越小越好、不可再分的原则。



至于非递归的迭代法，则简单地从前往后即可。交换两个相邻节点，然后找到紧接着一对相邻节点，继续交换，直到到达链表末尾，代码如下

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* left=head,*right=head->next,*pre=dummy;
        while(left!=nullptr&&left->next!=nullptr){
            right=left->next;
            pre->next=right;
            left->next=right->next;
            right->next=left;
            pre=left;
            left=pre->next;
        }
        return dummy->next;
    }
};
```

由于在单向链表中交换一对相邻的节点，还需要知道靠前的节点的上一个节点是谁，因此需要pre变量。

迭代法看上去要比递归法稍显冗长，但其实在本题中二者的本质区别不大。只是迭代法中有大量的赋值运算暴露在外，而递归法中函数调用隐式地执行了一些赋值而已。