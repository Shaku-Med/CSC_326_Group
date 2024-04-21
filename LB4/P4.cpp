#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>

template <typename T>
class UndirectedGraph
{
private:
    std::unordered_map<T, std::list<T>> adjacencyList;

public:
    void addEdge(const T &src, const T &dest)
    {
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);
    }

    const std::unordered_map<T, std::list<T>> &getAdjacencyList() const
    {
        return adjacencyList;
    }
};

template <typename T>
void breadthFirstTraversal(const UndirectedGraph<T> &graph, const T &startNode)
{
    std::unordered_map<T, bool> visited;
    std::queue<T> queue;

    visited[startNode] = true;
    queue.push(startNode);

    while (!queue.empty())
    {
        T current = queue.front();
        std::cout << current << " ";
        queue.pop();

        for (const auto &neighbor : graph.getAdjacencyList().at(current))
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
}

template <typename T>
void depthFirstTraversal(const UndirectedGraph<T> &graph, const T &startNode)
{
    std::unordered_map<T, bool> visited;
    std::stack<T> stack;

    visited[startNode] = true;
    stack.push(startNode);
    std::cout << startNode << " ";

    while (!stack.empty())
    {
        T current = stack.top();
        stack.pop();

        for (const auto &neighbor : graph.getAdjacencyList().at(current))
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                std::cout << neighbor << " ";
                stack.push(current);
                stack.push(neighbor);
                break; // Break the loop after pushing the first unvisited neighbor
            }
        }
    }
}

int main()
{
    UndirectedGraph<int> myGraph;
    myGraph.addEdge(1, 2);
    myGraph.addEdge(2, 6);
    myGraph.addEdge(1, 3);
    myGraph.addEdge(3, 5);
    myGraph.addEdge(4, 5);
    myGraph.addEdge(5, 7);
    myGraph.addEdge(6, 7);

    std::cout << "Breadth-first traversal: ";
    breadthFirstTraversal(myGraph, 1);
    std::cout << std::endl;

    std::cout << "Depth-first traversal: ";
    depthFirstTraversal(myGraph, 1);
    std::cout << std::endl;

    return 0;
}
