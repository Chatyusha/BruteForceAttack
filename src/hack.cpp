#include <iostream>
#include <string>
#include <vector>
#include <map>

std::string CharAsset = "ab#";
std::map<std::string,int> done;
std::vector<std::string> passList;

class Node {
	
public:
	Node();
	std::string value;
};
Node::Node() {
}

void DFS(Node node, int dps)
{
	// 探索済み
	done[node.value] = 1;
	if (dps != 0) 
	{
		for (int i = 0; i < CharAsset.size(); i++) {
		 	Node newnode = Node();
			if (CharAsset[i] == '#') {
				newnode.value = node.value + "";
			}
			else {
				newnode.value = node.value + CharAsset[i];
			}
			
			// 未探索なら引き続き探索
			if (done[newnode.value] == 0) {
				DFS(newnode,dps-1);
			}
		 } 
	}
}

int main(int argc, char* argv[])
{
	Node node = Node();
	node.value = "";
	DFS(node,2);

	// パスワードはdoneのkeyに格納される
	// 空文字のパスワードは考えないので消去
	done.erase("");
	auto begin = done.begin(), end = done.end();
	for (auto iter = begin; iter != end; iter++) {
			// first: key, second: value
			std::cout << iter->first << ", ";
	}
	printf("\n");
	return 0;
}
