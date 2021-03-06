charAsset="ab#"
done={}
class Node(object):
    def __init__(self):
        self.value  = ''

def DFS(node: Node,dps):
    ## 探索済み
    done[node.value] = 1
    if dps != 0:
        for i in charAsset:
            newnode=Node()
            if i == '#':
                newnode.value = node.value + ''
            else:
                newnode.value = node.value + i
            
            ## 未探索なら引き続き探索
            if done.get(newnode.value) == None:
                DFS(newnode,dps-1)

if __name__ == '__main__':
    node = Node()
    node.value = ''
    DFS(node,2)
    # パスワードはdoneのkeyに格納される
    print([i for i in done.keys() if i != ""])
