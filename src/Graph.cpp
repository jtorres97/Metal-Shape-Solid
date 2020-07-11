#include "Graph.h"

#include <cstdio>

Graph::Graph(int v)
{
	m_size = v;
	m_adjMatrix = new int* [m_size];
	for (auto i = 0; i < m_size; i++)
	{
		m_adjMatrix[i] = new int [m_size];
		for (auto j = 0; j < m_size; j++)
		{
			m_adjMatrix[i][j] = 0;
		}
	}
}

void Graph::AddEdge(int i, int j)
{
	SetEdge(i, j, 1);
}

void Graph::RemoveEdge(int i, int j)
{
	SetEdge(i, j, 0);
}

int Graph::Edge(int i, int j) const
{
	return m_adjMatrix[i][j];
}

void Graph::PrintGraph() const
{
	printf("The Matrix rep of the graph is \n");
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			printf("%d ", m_adjMatrix[i][j]);
		}
		printf("\n");
	}
}

void Graph::SetEdge(int i, int j, int e)
{
	if (i >= 0 && j >= 0 && i < m_size && j < m_size && (e == 0 || e == 1))
	{
		m_adjMatrix[i][j] = e;
	}
}
