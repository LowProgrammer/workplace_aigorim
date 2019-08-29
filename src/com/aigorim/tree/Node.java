package com.aigorim.tree;

import java.util.List;

/**
 * @author feifei
 * @Classname Node
 * @Description TODO
 * @Date 2019/8/29 13:01
 * @Created by 陈群飞
 */
public class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int val,List<Node> children) {
        this.val = val;
        this.children = children;
    }
}
