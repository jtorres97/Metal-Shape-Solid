#pragma once

class Graph
{
public:
	Graph() = default;
	explicit Graph(int v);
	
	void AddEdge(int i, int j);
	void RemoveEdge(int i, int j);
	int Edge(int i, int j) const;
	void PrintGraph() const;
private:
	void SetEdge(int i, int j, int e);
	
	int** m_adjMatrix;
	int m_size;
};
