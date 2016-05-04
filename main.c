#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define SIZE 5

//prints a 2d int array
void printArray(int array[][SIZE]){
    int i,j=0;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            printf("%d \t",array[i][j]);
        }
        printf("\n");
    }
}

//prints a 1d int array
void printOned(int array[SIZE]){
    int i=0;
    for(i=0;i<SIZE;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

//finds the min between 2 positive ints (to check for overflow because inf+x<0)
int min(int a,int b){
    if(a<b && a>0){
        return a;
    }
    else{
        return b;
    }
}

//finds the minimum distance from node s towards the unvisited nodes
int min_dist(int dist[SIZE], bool checked[SIZE]){
    int i=0;
    int min=INT_MAX;
    int min_node=-1;
    for(i=0;i<SIZE;i++){
        if(checked[i]==false && dist[i]<min){
            min=dist[i];
            min_node=i;
        }

    }

    return min_node;
}

//returns the minimum distance from s to all the other nodes
int * dijkstra(int grid[SIZE][SIZE], int s){
    static int dist[SIZE];    //distance from s (starting node)
    bool checked[SIZE]; //checks if we visited the node or not
    int num_checked=0;  //how many nodes we've found
    int i,j=0;
    int min_node=-1;
    for(i=0;i<SIZE;i++){
        if(grid[s][i]!=0){      //if they are connected with start, give the weight to the distance, else give INF
            dist[i]=grid[s][i];
        }
        else{
            dist[i]=INT_MAX;
        }
        checked[i]=false;     //no node visited from start
    }
    dist[s]=0;  //distance from start:0
    checked[s]=true;  //starting node visited
    num_checked++;

    while(num_checked<SIZE){
        min_node=min_dist(dist,checked); //node with min distance
        checked[min_node]=true;   // add it to visited nodes
        num_checked++;
        printf("minNode: %d\n",min_node);

        for(i=0;i<SIZE;i++){
            if(checked[i]==false && grid[i][min_node]!=0){
                dist[i]=min(dist[i],dist[min_node]+grid[i][min_node]);  //the dist is the min between the dist we had and
                                                                        //the dist from the new node (if they connect)
            }
        }



    }



    return dist;
}

int main()
{

    int weights[SIZE][SIZE]={{0, 5, 6, 8, 0},{5, 0, 0, 0, 1},{6, 0, 0, 15, 0},{8, 0, 15, 0, 20},{0, 1, 0, 20, 0}};
    int start=4;
    int *minDistance=dijkstra(weights,start);
    int i=0;
    for(i=0;i<SIZE;i++){
        printf("%d ",*(minDistance+i));
    }


    return 0;
}




