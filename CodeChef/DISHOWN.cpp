#include <cstdio>

using namespace std;

#define gc getchar_unlocked
int score[10001];

typedef struct GraphNode
{
	int chef;
	struct GraphNode* parent;
	int rank;
} Dish;


/**
 * Description: Add a set to disjoint-set  data structure with only one element.
 *       i.e, Create new set {x} with representative x
 * Input: Element (Graph Node).
 * Output: NA.
 */
inline void MakeSet(GraphNode* x, int chef)
{
	x->parent = x;
	x->rank = 0;
	x->chef = chef;
}


/**
 * Description: Get the representative of the set that given element belongs to.
 * Input: an element (Graph Node).
 * Output:Representative element (Graph Node).
 */
inline GraphNode* FindSet(GraphNode* x)
{
	if(x != x->parent)
		x->parent = FindSet(x->parent);
	return x->parent;
}



/**
 * Description: Link a given element (y) to another another element (x) or vice-versa
 *          and adjust rank if needed.Called by Union
 * Input: Two elements (Graph Node).
 * Output: NA.
 */
inline void Link(GraphNode* x, GraphNode* y)
{
	int winnerChef, scoreX, scoreY, rankX, rankY, chefX, chefY;
	
	chefX = x->chef;
	chefY = y->chef;
	scoreX = score[chefX];
	scoreY = score[chefY];
	if(scoreX == scoreY) return;
	winnerChef = (scoreX > scoreY) ? chefX : chefY;
	rankX = x->rank;
	rankY = y->rank;
	if(rankX > rankY)
	{
		y->parent = x;
		x->chef = winnerChef;
	}
	else
	{
		x->parent = y;
		if(rankX == rankY)
			y->rank = rankY + 1;
		y->chef = winnerChef;
	}
}


/**
 * Description: Join two subsets (of Graph Nodes) into a single subset.
 * Input: Two elements (Graph Node).
 * Output: NA.
 */
inline bool Union(GraphNode* x, GraphNode* y)
{
	Dish *parentX, *parentY;
	
	parentX = FindSet(x);
	parentY = FindSet(y);
	if(parentX != parentY)
	{
		Link(parentX, parentY);
		return true;
	}
	else
		return false;
}


inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c < 48 || c > 57); c = gc());
    for(; c > 47 && c < 58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}


int main()
{
	int T, N, Q, q, x, y, i;
	Dish dishes[10001], *parentX;
	
	scanint(T);
	while(T--)
	{
		scanint(N);
		for(i = 1; i <= N; i++)
		{
			scanint(score[i]);
			MakeSet(&dishes[i], i);
		}
		
		scanint(Q);
		while(Q--)
		{
			scanint(q);
			switch(q)
			{
				case 0: 
					scanint(x);
					scanint(y);
					if(!Union(&dishes[x], &dishes[y]))
						printf("Invalid query!\n");
					break;
				case 1:
					scanint(x);
					parentX = FindSet(&dishes[x]);
					printf("%d\n", parentX->chef);
					break;
			}
		}
	}
	return 0;
}